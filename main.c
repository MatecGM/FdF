/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:21:44 by mbico             #+#    #+#             */
/*   Updated: 2024/01/05 13:04:09 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_point **links;
	int		max[2];

	vars = malloc(sizeof(t_vars));
	links = malloc(sizeof(t_point) * 3);
	links[0] = malloc(sizeof(t_point) * 3);
	links[1] = malloc(sizeof(t_point) * 3);
	links[2] = malloc(sizeof(t_point) * 3);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1024, 600, "FdF");

	vars->img = mlx_new_image(vars->mlx, 1024, 600);

	links[0][0].x = 150;
	links[0][0].y = 150;
	links[0][1].x = 500;
	links[0][1].y = 150;
	links[0][2].x = 800;
	links[0][2].y = 150;

	links[1][0].x = 200;
	links[1][0].y = 300;
	links[1][1].x = 500;
	links[1][1].y = 300;
	links[1][2].x = 800;
	links[1][2].y = 300;

	links[2][0].x = 200;
	links[2][0].y = 450;
	links[2][1].x = 500;
	links[2][1].y = 450;
	links[2][2].x = 800;
	links[2][2].y = 450;

	mlx_set_image_pixel(vars->mlx, vars->img, links[0][0].x, links[0][0].y, 0xFFFFFFFF);
	mlx_set_image_pixel(vars->mlx, vars->img, links[0][1].x, links[0][1].y, 0xFFFFFFFF);
	mlx_set_image_pixel(vars->mlx, vars->img, links[0][2].x, links[0][2].y, 0xFFFFFFFF);

	mlx_set_image_pixel(vars->mlx, vars->img, links[1][0].x, links[1][0].y, 0xFFFFFFFF);
	mlx_set_image_pixel(vars->mlx, vars->img, links[1][1].x, links[1][1].y, 0xFFFFFFFF);
	mlx_set_image_pixel(vars->mlx, vars->img, links[1][2].x, links[1][2].y, 0xFFFFFFFF);

	mlx_set_image_pixel(vars->mlx, vars->img, links[2][0].x, links[2][0].y, 0xFFFFFFFF);
	mlx_set_image_pixel(vars->mlx, vars->img, links[2][1].x, links[2][1].y, 0xFFFFFFFF);
	mlx_set_image_pixel(vars->mlx, vars->img, links[2][2].x, links[2][2].y, 0xFFFFFFFF);

	//ft_link_point(vars, p1, p2);
	max[0]=2;
	max[1]=2;
	ft_position_link(vars, links, max);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);

	mlx_on_event(vars->mlx, vars->win, 0, ft_keyboard, vars);
	mlx_on_event(vars->mlx, vars->win, 5, ft_window, vars);
	mlx_loop(vars->mlx);
}
