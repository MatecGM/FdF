/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:21:44 by mbico             #+#    #+#             */
/*   Updated: 2024/01/09 16:18:51 by mbico            ###   ########.fr       */
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

void	ft_fdf(t_vars *vars)
{
	ft_placer(vars);
	ft_position_links(vars);
}
int	main(void)
{
	t_vars	*vars;
	int		fd;
	
	vars = malloc(sizeof(t_vars));
	vars->ampl = 1;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1024, 600, "FdF");
	vars->img = mlx_new_image(vars->mlx, 1024, 600);

	fd = open("test_maps/42.fdf", O_RDONLY);
	ft_parse(vars, fd);
	ft_fdf(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);

	mlx_on_event(vars->mlx, vars->win, 0, ft_keyboard, vars);
	mlx_on_event(vars->mlx, vars->win, 5, ft_window, vars);
	mlx_loop(vars->mlx);
}
