/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:50:56 by mbico             #+#    #+#             */
/*   Updated: 2024/01/25 18:36:53 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_ampl(t_vars *vars, int key)
{
	ft_clear_img(vars);
	if (key == 82 && vars->ampl < 5 && vars->ampl >= 0)
		vars->ampl ++;
	else if (key == 81 && vars->ampl <= 5 && vars->ampl > 0)
		vars->ampl --;
	ft_fdf(vars);
}

void	ft_newprojection(int keycode, t_vars *v)
{
	int	maxmax;

	maxmax = (v->maxx * (v->maxx >= v->maxy)
			+ v->maxy * (v->maxy > v->maxx));
	v->viewx = 0;
	v->viewy = 0;
	ft_clear_matrix(&v->imatrix);
	ft_clear_matrix(&v->rx);
	ft_clear_matrix(&v->rz);
	if (keycode == 89 && !v->left_click && !v->right_click)
		v->imatrix = ft_imatrix(v);
	else if (keycode == 90 && !v->left_click && !v->right_click)
		v->imatrix = ft_tmatrix(v);
	v->cmatrix = v->imatrix;
	v->rx = ft_rx(0, v);
	v->rz = ft_rz(0, v);
	ft_matrix_mult_one(&v->imatrix, HEIGHT / 2 / maxmax);
	ft_clear_img(v);
	ft_fdf(v);
}

int	ft_keyboard(int keycode, void *vars)
{
	t_vars	*v;

	v = (t_vars *) vars;
	if (keycode == 41)
		ft_close(v);
	else if (keycode == 82 || keycode == 81)
		ft_ampl(v, keycode);
	else if (keycode == 21)
	{
		v->viewx = 0;
		v->viewy = 0;
		ft_clear_img(vars);
		ft_fdf(vars);
	}
	else if ((keycode == 89 || keycode == 90)
		&& !v->left_click && !v->right_click)
		ft_newprojection(keycode, v);
	return (0);
}

int	ft_window(int keycode, void *vars)
{
	t_vars	*v;

	v = (t_vars *) vars;
	if (keycode == 0)
		ft_close(v);
	return (0);
}
