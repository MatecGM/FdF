/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:46:57 by mbico             #+#    #+#             */
/*   Updated: 2024/01/25 18:27:38 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	ft_clear_img(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_set_image_pixel(vars->mlx, vars->img, x, y, 0xFF000000);
			x ++;
		}
		y ++;
	}
}
