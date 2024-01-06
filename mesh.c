/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:19:38 by mbico             #+#    #+#             */
/*   Updated: 2024/01/06 19:57:14 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_link_point(t_vars *vars, t_point p1, t_point p2)
{
	int		x;
	int		y;
	float	d;
	int		b;

	x = 0;
	y = 0;
	d = (float)(p2.y - p1.y) / (float)(p2.x - p1.x);
	b = (p1.x < p2.x) - (p1.x > p2.x);
	while (x + p1.x != p2.x || (p1.x == p2.x && y + p1.y != p2.y))
	{
		if (p1.x == p2.x && y + p1.y != p2.y && p1.y < p2.y)
			y ++;
		else if (p1.x == p2.x && y + p1.y != p2.y && p1.y > p2.y)
			y --;
		else
			y = x * d;
		mlx_set_image_pixel(vars->mlx, vars->img, p1.x + x, p1.y + y, 0xFFFFFFFF);
		x += b;
	}
}

void	ft_possible_links(t_vars *vars, t_point **links, int *coord, int *max)
{
	t_point	p2;

	if (coord[0] + 1 <= max[0] && coord[0] + 1 >= 0)
	{
		p2.x = links[coord[0] + 1][coord[1]].x;
		p2.y = links[coord[0] + 1][coord[1]].y;
		ft_link_point(vars, links[coord[0]][coord[1]], p2);
	}
	if (coord[1] + 1 <= max[1] && coord[1] + 1 >= 0)
	{
		p2.x = links[coord[0]][coord[1] + 1].x;
		p2.y = links[coord[0]][coord[1] + 1].y;
		ft_link_point(vars, links[coord[0]][coord[1]], p2);
	}
}

void	ft_position_links(t_vars *vars, t_point **links, int *max)
{
	int coord[2];

	coord[0] = 0;
	coord[1] = 0;
	while (coord[1] <= max[1])
	{
		while (coord[0] <= max[0])
		{
			ft_possible_links(vars, links, coord, max);
			coord[0] ++;
		}
		coord[1] ++;
		coord[0] = 0;
	}
}
