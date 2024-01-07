/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:21:44 by mbico             #+#    #+#             */
/*   Updated: 2024/01/07 20:52:36 by mbico            ###   ########.fr       */
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
	int		tmp;

	vars = malloc(sizeof(t_vars));
	max = malloc(sizeof(int) * 2);
	fd = open("test_maps/pyra.fdf", O_RDONLY);
	max = ft_parse(&links, fd, max);
	ft_printf("%d\n", max[1]);
	max[0] --;
	max[1] --;
	tmp = max[0];
	max[0] = max[1];
	max[1] = tmp;

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1024, 600, "FdF");

	vars->img = mlx_new_image(vars->mlx, 1024, 600);

	ft_placer(links, max);

	ft_position_links(vars, links, max);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);

	mlx_on_event(vars->mlx, vars->win, 0, ft_keyboard, vars);
	mlx_on_event(vars->mlx, vars->win, 5, ft_window, vars);
	mlx_loop(vars->mlx);
}
