/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:03:01 by mbico             #+#    #+#             */
/*   Updated: 2024/01/23 17:43:19 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	ft_init_matrix(int row, int col)
{
	int			i;
	t_matrix	m;

	m.row = row;
	m.col = col;
	m.content = ft_calloc(sizeof(double *), row);
	if (!m.content)
		return (m);
	i = 0;
	while (i < row)
	{
		m.content[i] = ft_calloc(sizeof(double), col);
		if (!m.content[i])
			return (m);
		i ++;
	}
	return (m);
}

void	ft_clear_matrix(t_matrix *m)
{
	int			i;

	i = 0;
	while (i < m->row)
	{
		free(m->content[i]);
		i ++;
	}
	free(m->content);
}


void	ft_cmatrix_application(t_vars *vars, int i, int j)
{
	int			x;
	int			y;
	double		z;
	double		**m;

	x = i - vars->maxx / 2;
	y = j - vars->maxy / 2;
	z = vars->links[j][i].z / (double)10 * vars->ampl;
	m = vars->cmatrix.content;
	vars->links[j][i].x = x * m[0][0] + y * m[0][1] + z * m[0][2] + WIDTH / 2 + vars->viewx;
	vars->links[j][i].y = x * m[1][0] + y * m[1][1] + z * m[1][2] + HEIGHT / 2 + vars->viewy;
}

void	ft_matrix_mult_one(t_matrix *m, double nb)
{
	int	i;
	int	j;

	j = 0;
	while (j < m->row)
	{
		i = 0;
		while (i < m->col)
		{
			m->content[j][i] *= nb;
			i ++;
		}
		j ++;
	}
}

void	ft_matrix_div_one(t_matrix *m, double nb)
{
	int	i;
	int	j;

	j = 0;
	while (j < m->row)
	{
		i = 0;
		while (i < m->col)
		{
			m->content[j][i] /= nb;
			i ++;
		}
		j ++;
	}
}

t_matrix	ft_matrix_multiplication(t_matrix m1, t_matrix m2)
{
	t_matrix	m3;
	int			i;
	int			j;
	int			k;

	m3 = ft_init_matrix(3, 3);
	j = 0;
	while(j < m1.row)
	{
		i = 0;
		while (i < m1.row)
		{
			k = 0;
			m3.content[j][i] = 0;
			while (k < m1.row)
			{
				m3.content[j][i] += m1.content[k][i] * m2.content[j][k];
				k ++;
			}
			i ++;
		}
		j ++;
	}
	return (m3);
}
