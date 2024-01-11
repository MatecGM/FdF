/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:19:38 by mbico             #+#    #+#             */
/*   Updated: 2024/01/10 19:40:28 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_link_point_y(t_vars *vars, t_point p1, t_point p2)
{
	int		x;
	int		y;
	float	d;
	int		b;

	x = 0;
	y = 0;
	d = (float)(p2.x - p1.x) / (float)(p2.y - p1.y);
	b = (p1.y < p2.y) - (p1.y > p2.y);
	while (y + p1.y != p2.y)
	{
		x = y * d;
		mlx_set_image_pixel(vars->mlx, vars->img, p1.x + x, p1.y + y, 0xFFFFFFFF);
		y += b;
	}
}

void	ft_link_point_x(t_vars *vars, t_point p1, t_point p2)
{
	int		x;
	int		y;
	float	d;
	int		b;

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
			mlx_set_image_pixel(vars->mlx, vars->img, p1.x + x, p1.y + y, 0xFFFFFFFF);
			x += b;
		}
	}
}

void	ft_possible_links(t_vars *vars, int *coord)
{
	t_point	p2;

	if (coord[0] + 1 < vars->maxx && coord[0] + 1 > 0)
	{
		p2.x = vars->links[coord[1]][coord[0] + 1].x;
		p2.y = vars->links[coord[1]][coord[0] + 1].y;
		ft_link_point_x(vars, vars->links[coord[1]][coord[0]], p2);
	}
	if (coord[1] + 1 < vars->maxy && coord[1] + 1 > 0)
	{
		p2.x = vars->links[coord[1] + 1][coord[0]].x;
		p2.y = vars->links[coord[1] + 1][coord[0]].y;
		ft_link_point_x(vars, vars->links[coord[1]][coord[0]], p2);
	}
}

void	ft_position_links(t_vars *vars)
{
	int coord[2];

	coord[1] = 0;
	while (coord[1] < vars->maxy)
	{
		coord[0] = 0;
		while (coord[0] < vars->maxx)
		{
			ft_possible_links(vars, coord);
			coord[0] ++;
		}
		coord[1] ++;
	}
}
