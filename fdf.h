/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:04:48 by mbico             #+#    #+#             */
/*   Updated: 2024/01/23 00:30:36 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# ifndef PI
#  define PI 3.1415926535
# endif

//16 / 9
# ifndef WIDTH
#  define WIDTH 1024
# endif

# ifndef HEIGHT
#  define HEIGHT 600
# endif

# include <stdio.h>
# include <math.h>
# include "MacroLibX/includes/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}		t_point;

typedef struct s_matrix
{
	int		row;
	int		col;
	double	**content;
}		t_matrix;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	void		*img;
	int			ampl;
	t_point		**links;
	int			maxx;
	int			maxy;
	int			minz;
	int			maxz;
	int			fd;

	int			viewx;
	int			viewy;
	int			init_viewx;
	int			init_viewy;
	int			left_click;
	int			right_click;

	t_matrix	imatrix;
	t_matrix	cmatrix;
	t_matrix	bmatrix;
	t_matrix	rx;
	t_matrix	rz;
	
	int			minrx;
	int			maxrx;
	int			init_crz;
	int			crz;
	int			init_crx;
	int			crx;

}			t_vars;

int			ft_keyboard(int keycode, void *vars);
int			ft_window(int keycode, void *vars);
void		ft_close(t_vars *vars);
void		ft_link_point(t_vars *vars, t_point p1, t_point p2);
void		ft_position_links(t_vars *vars);
void		ft_placer(t_vars *vars);
void		ft_parse(t_vars *vars);
void		ft_clear_img(t_vars *vars);
void		ft_fdf(t_vars *vars);
int			ft_mousewheel(int keycode, void *vars);
int			ft_mousedown(int keycode, void *vars);
int			ft_mouseup(int keycode, void *vars);
int			ft_position(void *vars);
t_matrix	ft_imatrix(void);
t_matrix	ft_rx(double c);
t_matrix	ft_rz(int c);
t_matrix	ft_init_matrix(int row, int col);
void		ft_matrix_mult_one(t_matrix *m, double nb);
void		ft_matrix_div_one(t_matrix *m, double nb);
void		ft_cmatrix_application(t_vars *vars, int i, int j);
int			ft_printf(const char *str, ...);
t_matrix	ft_matrix_multiplication(t_matrix m1, t_matrix m2);
void		ft_check_cam_position(t_vars *v);

#endif
