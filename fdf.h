/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:04:48 by mbico             #+#    #+#             */
/*   Updated: 2024/01/05 17:07:26 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H

# define	SOLONG_H

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
}			t_vars;

typedef struct s_point
{
	int	x;
	int	y;
	//int color;
}		t_point;

#include <stdio.h>
#include <math.h>
#include "MacroLibX/includes/mlx.h"

int		ft_keyboard(int keycode, void *vars);
int		ft_window(int keycode, void *vars);
void	ft_close(t_vars *vars);
void	ft_link_point(t_vars *vars, t_point p1, t_point p2);
void	ft_position_links(t_vars *vars, t_point **link, int *max);
t_point	**ft_placer(t_point **links, int *max);

#endif
