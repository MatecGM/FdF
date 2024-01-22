/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:50:56 by mbico             #+#    #+#             */
/*   Updated: 2024/01/22 03:28:50 by mbico            ###   ########.fr       */
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
		v->ampl = 1;
		v->cmatrix = v->imatrix;
		ft_clear_img(vars);
		ft_fdf(vars);
	}
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
