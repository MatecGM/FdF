/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:18:40 by mbico             #+#    #+#             */
/*   Updated: 2024/01/14 19:20:10 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_mousewheel(int keycode, void *vars)
{
	t_vars	*v;

	v = (t_vars *) vars;
	if (keycode == 1 && v->zoom < 8 || keycode == 2  && v->zoom > 1)
	{
		ft_clear_img(vars);
		if (keycode == 1 && v->zoom < 8)
			v->zoom ++;
		else if (keycode == 2 && v->zoom > 1)
			v->zoom --;
		ft_fdf(vars);
	}
	return (0);
}

int	ft_mousedown(int keycode, void *vars)
{
	t_vars	*v;

	v = (t_vars *) vars;
	v->click = 1;
	mlx_mouse_get_pos(v->mlx, &v->init_viewx, &v->init_viewy);
	v->init_viewx -= v->viewx;
	v->init_viewy -= v->viewy;
	return (0);
}

int	ft_mouseup(int keycode, void *vars)
{
	t_vars	*v;

	v = (t_vars *) vars;
	v->click = 0;
	return (0);
}

int	ft_position(void *vars)
{
	t_vars	*v;

	v = (t_vars *) vars;
	if (v->click == 1)
	{
		mlx_mouse_get_pos(v->mlx, &v->viewx, &v->viewy);
		v->viewx -= v->init_viewx;
		v->viewy -= v->init_viewy;
		ft_clear_img(v);
		ft_fdf(v);
	}
}
