/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:46:57 by mbico             #+#    #+#             */
/*   Updated: 2024/01/14 20:14:08 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// taile de la fenêtre 1024 * 600
void	ft_placer(t_vars *vars)
{
	int		margin;
	int		x;
	int		y;
	float	maxmax;

	x = 0;
	y = 0;
	margin = 100;
	maxmax = (vars->maxx * (vars->maxx >= vars->maxy)
			+ vars->maxy * (vars->maxy > vars->maxx));
	while (y < vars->maxy)
	{
		while (x < vars->maxx)
		{
			vars->links[y][x].x = 512 + ((412 / maxmax) * -(y - x) + vars->viewx / vars->zoom) * vars->zoom;
			vars->links[y][x].y = margin + ((200 / maxmax * (x + y))
						- vars->links[y][x].z * vars->ampl + vars->viewy / vars->zoom) * vars->zoom;
			x++;
			//ft_printf("==============\nx = %d / y = %d\ninit x  = %d / init y = %d\n", vars->links[y][x].x, vars->links[y][x].y, x, y);
		}
		y++;
		x = 0;
	}
}

void	ft_clear_img(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < 600)
	{
		x = 0;
		while (x < 1024)
		{
			mlx_set_image_pixel(vars->mlx, vars->img, x, y, 0xFF000000);
			x ++;
		}
		y ++;
	}
}
