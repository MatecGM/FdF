/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:21:44 by mbico             #+#    #+#             */
/*   Updated: 2024/01/04 23:54:27 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
#include <stdio.h>
#include "fdf.h"
#include <stdlib.h>

void	ft_close(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_display(vars->mlx);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	t_vars	*vars;
	t_point p1;
	t_point	p2;

	vars = malloc(sizeof(t_vars));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1024, 600, "FdF");

	vars->img = mlx_new_image(vars->mlx, 1024, 600);
	p1.x = 300;
	p1.y = 450;
	p2.x = 750;
	p2.y = 150;
	mlx_set_image_pixel(vars->mlx, vars->img, p1.x, p1.y, 0xFFFFFFFF);
	mlx_set_image_pixel(vars->mlx, vars->img, p2.x, p2.y, 0xFFFFFFFF);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);

	mlx_on_event(vars->mlx, vars->win, 0, ft_keyboard, vars);
	mlx_on_event(vars->mlx, vars->win, 5, ft_window, vars);
	mlx_loop(vars->mlx);
}
