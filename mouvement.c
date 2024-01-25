/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:18:40 by mbico             #+#    #+#             */
/*   Updated: 2024/01/25 18:15:41 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_mousewheel(int keycode, void *vars)
{
	t_vars	*v;

	v = (t_vars *) vars;
	if (keycode == 1 || keycode == 2)
	{
		ft_clear_img(vars);
		if (keycode == 1 && v->zoom < 3)
		{
			v->zoom ++;
			ft_matrix_mult_one(&v->cmatrix, 2.0);
		}
		else if (keycode == 2 && v->zoom > -3)
		{
			v->zoom --;
			ft_matrix_div_one(&v->cmatrix, 2.0);
		}
		ft_fdf(vars);
	}
	return (0);
}

int	ft_mousedown(int keycode, void *vars)
{
	t_vars	*v;

	v = (t_vars *) vars;
	if (keycode == 1)
	{
		mlx_mouse_get_pos(v->mlx, &v->init_viewx, &v->init_viewy);
		v->init_viewx -= v->viewx;
		v->init_viewy -= v->viewy;
		v->left_click = 1;
	}
	else if (keycode == 3)
	{
		mlx_mouse_get_pos(v->mlx, &v->init_crz, &v->init_crx);
		v->bmatrix = v->cmatrix;
		v->right_click = 1;
	}
	return (0);
}

int	ft_mouseup(int keycode, void *vars)
{
	t_vars	*v;

	v = (t_vars *) vars;
	if (keycode == 1)
		v->left_click = 0;
	else if (keycode == 3)
		v->right_click = 0;
	return (0);
}

void	ft_rotation(t_vars *v)
{
	mlx_mouse_get_pos(v->mlx, &v->crz, &v->crx);
	v->crz -= v->init_crz;
	v->crx -= v->init_crx;
	ft_clear_matrix(&v->rz);
	v->rz = ft_rz(v->crz, v);
	if (v->cmatrix.content[2][2] > 0)
		v->minrx = v->crx;
	if (v->cmatrix.content[1][2] < 0)
		v->maxrx = v->crx;
	if (v->minrx <= v->crx && v->maxrx >= v->crx)
	{
		ft_clear_matrix(&v->rx);
		v->rx = ft_rx(v->crx, v);
	}
	v->cmatrix = ft_matrix_multiplication(v->rz, v->bmatrix, v);
	v->cmatrix = ft_matrix_multiplication(v->cmatrix, v->rx, v);
	ft_clear_img(v);
	ft_fdf(v);
}

int	ft_position(void *vars)
{
	t_vars	*v;

	v = (t_vars *) vars;
	if (v->left_click == 1)
	{
		mlx_mouse_get_pos(v->mlx, &v->viewx, &v->viewy);
		v->viewx -= v->init_viewx;
		v->viewy -= v->init_viewy;
		ft_clear_img(v);
		ft_fdf(v);
	}
	else if (v->right_click == 1)
	{
		ft_rotation(v);
	}
	return (0);
}
