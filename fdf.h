/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:04:48 by mbico             #+#    #+#             */
/*   Updated: 2024/01/04 23:23:55 by mbico            ###   ########.fr       */
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

int		ft_keyboard(int keycode, void *vars);
int		ft_window(int keycode, void *vars);
void	ft_close(t_vars *vars);

#endif
