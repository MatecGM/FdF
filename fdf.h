/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:04:48 by mbico             #+#    #+#             */
/*   Updated: 2024/01/14 18:52:04 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <stdio.h>
# include <math.h>
# include "MacroLibX/includes/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include "printf/ft_printf.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	int		ampl;
	t_point	**links;
	int		maxx;
	int		maxy;
	int		fd;
	int		zoom;
	int		viewx;
	int		viewy;
	int		init_viewx;
	int		init_viewy;
	int		click;
}			t_vars;

int		ft_keyboard(int keycode, void *vars);
int		ft_window(int keycode, void *vars);
void	ft_close(t_vars *vars);
void	ft_link_point(t_vars *vars, t_point p1, t_point p2);
void	ft_position_links(t_vars *vars);
void	ft_placer(t_vars *vars);
void	ft_parse(t_vars *vars);
void	ft_clear_img(t_vars *vars);
void	ft_fdf(t_vars *vars);
int		ft_mousewheel(int keycode, void *vars);
int		ft_mousedown(int keycode, void *vars);
int		ft_mouseup(int keycode, void *vars);
int		ft_position(void *vars);

#endif
