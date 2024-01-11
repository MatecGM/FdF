/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:50:56 by mbico             #+#    #+#             */
/*   Updated: 2024/01/10 17:30:53 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_ampl(t_vars *vars, int key)
{
		ft_clear_img(vars);
		if (key == 82)
			vars->ampl += 1;
		else
			vars->ampl -= 1;
		ft_fdf(vars);
}

int	ft_keyboard(int keycode, void *vars)
{
	t_vars	*v;

	v = (t_vars *) vars;
	if (keycode == 41)
		ft_close(v);
	else if (keycode == 82 || keycode == 81)
	{
		ft_ampl(v, keycode);
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
