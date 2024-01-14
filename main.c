/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:21:44 by mbico             #+#    #+#             */
/*   Updated: 2024/01/14 20:06:29 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	ft_close(t_vars *vars)
{
	int	x;

	x = 0;
	if (vars->maxy != 0)
	{
		while (vars->maxy > 0)
		{
			vars->maxy --;
			free(vars->links[vars->maxy]);
		}
		free(vars->links);
	}
	if (vars->fd < 0)
		close(vars->fd);
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

void	ft_varsinit(t_vars *vars)
{
	vars->ampl = 1;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1024, 600, "FdF");
	vars->img = mlx_new_image(vars->mlx, 1024, 600);
	vars->maxx = 0;
	vars->maxy = 0;
	vars->fd = -1;
	vars->zoom = 1;
	vars->viewx = 0;
	vars->viewy = 0;
	vars->init_viewx = 0;
	vars->init_viewy = 0;
	vars->click = 0;
}

void	ft_read_file(t_vars *vars, int argc, char **argv)
{
	if (argc != 2 || ft_strlen(argv[1]) < 5
		|| ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".fdf", 4))
		ft_close(vars);
	vars->fd = open(argv[1], O_RDONLY);
	if (vars->fd < 0)
		ft_close(vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars[1];

	ft_varsinit(vars);
	ft_read_file(vars, argc, argv);
	ft_parse(vars);
	ft_fdf(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_on_event(vars->mlx, vars->win, 0, ft_keyboard, vars);
	mlx_on_event(vars->mlx, vars->win, 5, ft_window, vars);
	mlx_on_event(vars->mlx, vars->win, 4, ft_mousewheel, vars);
	mlx_on_event(vars->mlx, vars->win, 2, ft_mousedown, vars);
	mlx_on_event(vars->mlx, vars->win, 3, ft_mouseup, vars);
	mlx_loop_hook(vars->mlx, ft_position, vars);
	mlx_loop(vars->mlx);
}
