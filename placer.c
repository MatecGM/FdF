/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:46:57 by mbico             #+#    #+#             */
/*   Updated: 2024/01/17 18:34:52 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// 1          0           0
// 0          cos(teta)   sin(teta)
// 0          sin(teta)   cos(teta)

void	ft_matrix_rotation(t_vars *vars, int px, int py)
{
	int	x;
	int	y;
	int	z;

	x = vars->links[py][px].x;
	y = vars->links[py][px].y;
	z = vars->links[py][px].z * vars->ampl;
	vars->links[py][px].x += vars->viewx;
	vars->links[py][px].y = y * cos(1) - z * sin(1) + vars->viewy;
}

void	ft_bigcalcul(t_vars *vars, int x, int y)
{
	float	maxmax;

	maxmax = (vars->maxx * (vars->maxx >= vars->maxy)
			+ vars->maxy * (vars->maxy > vars->maxx));
	vars->links[y][x].x = 512+ (412 / maxmax * (x - y));
	vars->links[y][x].y = 100 + (200 / maxmax * (x + y)) - vars->links[y][x].z;
}



// taile de la fenêtre 1024 * 600
void	ft_placer(t_vars *vars)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < vars->maxy)
	{
		while (x < vars->maxx)
		{
			ft_cmatrix_application(vars, x, y);
			x++;
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
