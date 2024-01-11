/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:46:57 by mbico             #+#    #+#             */
/*   Updated: 2024/01/10 14:08:03 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// taile de la fenêtre 1024 * 600
void	ft_placer(t_vars *vars)
{
	int	margin;
	int	coord[2];
	double	diago;

	coord[0] = 0;
	coord[1] = 0;
	margin = 100;

	while (coord[1] < vars->maxy)
	{
		while (coord[0] < vars->maxx)
		{
			vars->links[coord[1]][coord[0]].x = 512 + ((412 / (float)(vars->maxx * (vars->maxx >= vars->maxy) + vars->maxy * (vars->maxy > vars->maxx))) * -((coord[1] - coord[0])));
			vars->links[coord[1]][coord[0]].y = margin + ((400 / (float)((vars->maxx * (vars->maxx >= vars->maxy) + vars->maxy * (vars->maxy > vars->maxx))* 2) * (coord[0] + coord[1])) - vars->links[coord[1]][coord[0]].z * vars->ampl);
			coord[0]++;
		}
		coord[1]++;
		coord[0] = 0;
	}
}

void	ft_clear_img(t_vars *vars)
{
	int	x;
	int	y;
	
	y = 0;
	while(y < 600)
	{
		x = 0;
		while(x < 1024)
		{
			mlx_set_image_pixel(vars->mlx, vars->img, x, y, 0xFF000000);
			x ++;
		}
		y ++;
	}
}
