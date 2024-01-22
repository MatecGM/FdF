/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:19:38 by mbico             #+#    #+#             */
/*   Updated: 2024/01/22 01:51:00 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int ft_gradient(t_point p1, t_point p2, int i, int max)
{
	unsigned int	color;

	if(p1.r < p2.r)
		p1.r = p1.r + (p2.r - p1.r) * (i / (double)max);
	else if(p1.r > p2.r)
		p1.r = p1.r - (p1.r - p2.r) * (i / (double)max);
	if(p1.g < p2.g)
		p1.g = p1.g + (p2.g - p1.g) * (i / (double)max);
	else if(p1.g > p2.g)
		p1.g = p1.g - (p1.g - p2.g) * (i / (double)max);
	if(p1.b < p2.b)
		p1.b = p1.b + (p2.b - p1.b) * (i / (double)max);
	else if(p1.b > p2.b)
		p1.b = p1.b - (p1.b - p2.b) * (i / (double)max);
	color = (255<<24) + (p1.r<<16) + (p1.g<<8) + p1.b;
	return(color);
}

void	ft_link_point_y(t_vars *vars, t_point p1, t_point p2)
{
	int		x;
	int		y;
	float	d;
	int		b;
	unsigned int	color;

	x = 0;
	y = 0;
	d = (float)(p2.x - p1.x) / (float)(p2.y - p1.y);
	b = (p1.y < p2.y) - (p1.y > p2.y);
	while (y + p1.y != p2.y)
	{
		x = y * d;
		color = ft_gradient(p1, p2, y, p2.y - p1.y);
		if ((x + p1.x >= 0 && x + p1.x < WIDTH)
			&& (y + p1.y >= 0 && y + p1.y < HEIGHT))
			mlx_set_image_pixel(vars->mlx, vars->img,
				p1.x + x, p1.y + y, color);
		y += b;
	}
}

void	ft_link_point_x(t_vars *vars, t_point p1, t_point p2)
{
	int				x;
	int				y;
	float			d;
	int				b;
	unsigned int	color;

	x = 0;
	y = 0;
	d = (float)(p2.y - p1.y) / (float)(p2.x - p1.x);
	if (d > 1 || d < -1)
		ft_link_point_y(vars, p1, p2);
	else
	{
		b = (p1.x < p2.x) - (p1.x > p2.x);
		while (x + p1.x != p2.x)
		{
			y = x * d;
			color = ft_gradient(p1, p2, x, p2.x - p1.x);
			if ((x + p1.x >= 0 && x + p1.x < WIDTH)
				&& (y + p1.y >= 0 && y + p1.y < HEIGHT))
				mlx_set_image_pixel(vars->mlx, vars->img,
					p1.x + x, p1.y + y, color);
			x += b;
		}
	}
}

void	ft_color(t_point *p, t_vars *v, int z)
{
	unsigned int	color;
	double			midz;
	
	midz = (v->maxz - v->minz) / (double)2 + v->minz;
	p->r = 0;
	p->g = 0;
	p->b = 255;
	if (z > v->minz && z <= midz)
	{
		p->g = 255 * ((z - v->minz) / (double)(midz - v->minz));
		p->b = 255 - 255 * ((z - v->minz) / (double)(midz - v->minz));;
	}
	else if (z > midz && z <= v->maxz)
	{
		p->r = 255 * ((double)(z - midz) / (v->maxz - midz));
		p->g = 255 - 255 * ((z - midz) / (double)(v->maxz - midz));
		p->b = 0;
	}
	//color = (255<<24) + (r<<16) + (g<<8) + b;
}

void	ft_possible_links(t_vars *vars, int *c)
{
	t_point	p1;
	t_point	p2;

	p1.x = vars->links[c[1]][c[0]].x;
	p1.y = vars->links[c[1]][c[0]].y;
	ft_color(&p1, vars, vars->links[c[1]][c[0]].z);
	if (c[0] + 1 < vars->maxx && c[0] + 1 > 0)
	{
		p2.x = vars->links[c[1]][c[0] + 1].x;
		p2.y = vars->links[c[1]][c[0] + 1].y;
		ft_color(&p2, vars, vars->links[c[1]][c[0] + 1].z);
		ft_link_point_x(vars, p1, p2);
	}
	if (c[1] + 1 < vars->maxy && c[1] + 1 > 0)
	{
		p2.x = vars->links[c[1] + 1][c[0]].x;
		p2.y = vars->links[c[1] + 1][c[0]].y;
		ft_color(&p2, vars, vars->links[c[1] + 1][c[0]].z);
		ft_link_point_x(vars, p1, p2);
	}
}

void	ft_position_links(t_vars *vars)
{
	int	coord[2];

	coord[1] = 0;
	while (coord[1] < vars->maxy)
	{
		coord[0] = 0;
		while (coord[0] < vars->maxx)
		{
			ft_possible_links(vars, coord);
			coord[0]++;
		}
		coord[1]++;
	}
	ft_color(&vars->links[coord[1] - 1][coord[0] - 1], 
		vars, vars->links[coord[1] - 1][coord[0] - 1].z);
	mlx_set_image_pixel(vars->mlx, vars->img,
		vars->links[coord[1] - 1][coord[0] - 1].x,
		vars->links[coord[1] - 1][coord[0] - 1].y, 
		(unsigned int)(255<<24) 
		+ (vars->links[coord[1] - 1][coord[0] - 1].r<<16) 
		+ (vars->links[coord[1] - 1][coord[0] - 1].g<<8) 
		+ vars->links[coord[1] - 1][coord[0] - 1].b);
}
