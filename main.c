/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:21:44 by mbico             #+#    #+#             */
/*   Updated: 2024/01/06 21:56:37 by mbico            ###   ########.fr       */
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
	int		*max;
	int		fd;

	vars = malloc(sizeof(t_vars));
	max = malloc(sizeof(int) * 2);
	fd = open("test_maps/42.fdf", O_RDONLY);
	max = ft_parse(links, fd, max);

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1024, 600, "FdF");

	vars->img = mlx_new_image(vars->mlx, 1024, 600);

	// links[0][0].z = 0;
	// links[0][1].z = 0;
	// links[0][2].z = 80;
	// links[0][3].z = 0;
	// links[0][4].z = 0;
	// links[0][5].z = 0;

	// links[1][0].z = 0;
	// links[1][1].z = 0;
	// links[1][2].z = 80;
	// links[1][3].z = 0;
	// links[1][4].z = 0;
	// links[1][5].z = 0;

	// links[2][0].z = 0;
	// links[2][1].z = 0;
	// links[2][2].z = 80;
	// links[2][3].z = 0;
	// links[2][4].z = 0;
	// links[2][5].z = 0;

	// links[3][0].z = 0;
	// links[3][1].z = 90;
	// links[3][2].z = 90;
	// links[3][3].z = 90;
	// links[3][4].z = 0;
	// links[3][5].z = 0;

	// links[4][0].z = 0;
	// links[4][1].z = 0;
	// links[4][2].z = 0;
	// links[4][3].z = 0;
	// links[4][4].z = 0;
	// links[4][5].z = 0;

	// links[5][0].z = 0;
	// links[5][1].z = 0;
	// links[5][2].z = 0;
	// links[5][3].z = 0;
	// links[5][4].z = 0;
	// links[5][5].z = 0;

	// links[6][0].z = 0;
	// links[6][1].z = 0;
	// links[6][2].z = 0;
	// links[6][3].z = 0;
	// links[6][4].z = 0;
	// links[6][5].z = 0;

	ft_placer(links, max);

	// mlx_set_image_pixel(vars->mlx, vars->img, links[0][0].x, links[0][0].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[0][1].x, links[0][1].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[0][2].x, links[0][2].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[0][3].x, links[0][3].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[0][4].x, links[0][4].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[0][5].x, links[0][5].y, 0xFFFFFFFF);

	// mlx_set_image_pixel(vars->mlx, vars->img, links[1][0].x, links[1][0].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[1][1].x, links[1][1].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[1][2].x, links[1][2].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[1][3].x, links[1][3].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[1][4].x, links[1][4].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[1][5].x, links[1][5].y, 0xFFFFFFFF);

	// mlx_set_image_pixel(vars->mlx, vars->img, links[2][0].x, links[2][0].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[2][1].x, links[2][1].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[2][2].x, links[2][2].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[2][3].x, links[2][3].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[2][4].x, links[2][4].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[2][5].x, links[2][5].y, 0xFFFFFFFF);

	// mlx_set_image_pixel(vars->mlx, vars->img, links[3][0].x, links[3][0].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[3][1].x, links[3][1].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[3][2].x, links[3][2].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[3][3].x, links[3][3].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[3][4].x, links[3][4].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[3][5].x, links[3][5].y, 0xFFFFFFFF);

	// mlx_set_image_pixel(vars->mlx, vars->img, links[4][0].x, links[4][0].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[4][1].x, links[4][1].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[4][2].x, links[4][2].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[4][3].x, links[4][3].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[4][4].x, links[4][4].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[4][5].x, links[4][5].y, 0xFFFFFFFF);

	// mlx_set_image_pixel(vars->mlx, vars->img, links[5][0].x, links[5][0].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[5][1].x, links[5][1].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[5][2].x, links[5][2].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[5][3].x, links[5][3].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[5][4].x, links[5][4].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[5][5].x, links[5][5].y, 0xFFFFFFFF);

	// mlx_set_image_pixel(vars->mlx, vars->img, links[6][0].x, links[6][0].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[6][1].x, links[6][1].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[6][2].x, links[6][2].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[6][3].x, links[6][3].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[6][4].x, links[6][4].y, 0xFFFFFFFF);
	// mlx_set_image_pixel(vars->mlx, vars->img, links[6][5].x, links[6][5].y, 0xFFFFFFFF);

	ft_position_links(vars, links, max);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);

	mlx_on_event(vars->mlx, vars->win, 0, ft_keyboard, vars);
	mlx_on_event(vars->mlx, vars->win, 5, ft_window, vars);
	mlx_loop(vars->mlx);
}
