/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:21:44 by mbico             #+#    #+#             */
/*   Updated: 2024/01/04 18:56:57 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
#include <stdio.h>
#include "FDF.h"
#include <stdlib.h>

int	ft_close(int keycode, void *vars)
{
	t_mlx *v;

	v = (t_mlx *) vars;
	printf("%d\n", keycode);
	if (keycode == 41)
	{
		mlx_destroy_window(v->mlx, v->win);
		mlx_destroy_display(v->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(void)
{
	void	*img;
	t_mlx	*vars;
	int		img_width;
	int		img_height;

	printf("test");
	vars = malloc(sizeof(t_mlx));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1024, 600, "FdF");
	mlx_on_event(vars->mlx, vars->win, 0, ft_close, vars);
	mlx_loop(vars->mlx);
}
//test