/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:21:44 by mbico             #+#    #+#             */
/*   Updated: 2024/01/02 16:21:31 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
#include <stdio.h>
#include "FDF.h"

int	close(int keycode, t_mlx *mlx)
{
	(void) keycode;
	mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}

int	main(void)
{
	void	*img;
	t_mlx	mlx;
	int		img_width;
	int		img_height;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1024, 600, "So long");
	mlx_on_event(mlx.mlx, mlx.win);
	mlx_loop(mlx.mlx);
}
