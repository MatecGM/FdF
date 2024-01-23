/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:19:38 by mbico             #+#    #+#             */
/*   Updated: 2024/01/23 16:22:02 by mbico            ###   ########.fr       */
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
	double			d;
	int				b;
	unsigned int	color;

	x = 0;
	y = 0;
	d = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
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

void	ft_possible_links(t_vars *vars, int *c, int *q, int *nav)
{
	t_point	p1;
	t_point	p2;

	p1.x = vars->links[c[1]][c[0]].x;
	p1.y = vars->links[c[1]][c[0]].y;
	ft_color(&p1, vars, vars->links[c[1]][c[0]].z);
	if (c[0] + q[0] != nav[2] && c[0] + q[0] != nav[0])
	{
		p2.x = vars->links[c[1]][c[0] + q[0]].x;
		p2.y = vars->links[c[1]][c[0] + q[0]].y;
		ft_color(&p2, vars, vars->links[c[1]][c[0] + q[0]].z);
		ft_link_point_x(vars, p1, p2);
	}
	if (c[1] + q[1] != nav[3] && c[1] + q[1] != nav[1])
	{
		p2.x = vars->links[c[1] + q[1]][c[0]].x;
		p2.y = vars->links[c[1] + q[1]][c[0]].y;
		ft_color(&p2, vars, vars->links[c[1] + q[1]][c[0]].z);
		ft_link_point_x(vars, p1, p2);
	}
}

int	*ft_init_navigation(t_vars *v, int *nav, int *q)
{
	nav[0] = 0;
	nav[1] = 0;
	nav[2] = v->maxx;
	nav[3] = v->maxy;
	if (q[0] == -1)
	{
		nav[0] = v->maxx -1;
		nav[2] = -1;
	}
	if (q[1] == -1)
	{
		nav[1] = v->maxy - 1;
		nav[3] = -1;
	}
	return (nav);
}

void	ft_navigation(t_vars *v, int *q)
{
	int	coord[2];
	int	*nav;

	nav = ft_calloc(sizeof(int), 4);
	nav = ft_init_navigation(v, nav, q);
	coord[1] = nav[1];
	while (coord[1] != nav[3])
	{
		coord[0] = nav[0];
		while (coord[0] != nav[2])
		{
			//ft_printf("%d et %d\n", coord[0], coord[1]);
			ft_possible_links(v, coord, q, nav);
			coord[0] += q[0];
		}
		coord[1] += q[1];
	}
	free(nav);
}

void	ft_check_cam_position(t_vars *v)
{
	double	**m;
	int		q[2];

	q[0] = 1;
	q[1] = 1;
	m = v->cmatrix.content;
	if (m[2][0] < 0 && m[2][1] >= 0)
		q[0] = -1;
	else if (m[2][0] < 0 && m[2][1] < 0)
	{
		q[0] = -1;
		q[1] = -1;
	}
	else if (m[2][0] >= 0 && m[2][1] < 0)
		q[1] = -1;
	ft_navigation(v, q);
}
