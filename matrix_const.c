/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_const.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:45:16 by mbico             #+#    #+#             */
/*   Updated: 2024/01/25 18:08:59 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	ft_init_matrix(int row, int col, t_vars *v)
{
	int			i;
	t_matrix	m;

	m.row = row;
	m.col = col;
	m.content = ft_calloc(sizeof(double *), row);
	if (!m.content)
		ft_close(v);
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

t_matrix	ft_rx(double c, t_vars *v)
{
	t_matrix	rx;
	double		teta;

	teta = -(c / (double)250);
	rx = ft_init_matrix(3, 3, v);
	rx.content[0][0] = 1;
	rx.content[0][1] = 0;
	rx.content[0][2] = 0;
	rx.content[1][0] = 0;
	rx.content[1][1] = cos(teta);
	rx.content[1][2] = -sin(teta);
	rx.content[2][0] = 0;
	rx.content[2][1] = sin(teta);
	rx.content[2][2] = cos(teta);
	return (rx);
}

t_matrix	ft_rz(int c, t_vars *v)
{
	t_matrix	rz;
	double		teta;

	teta = -(c / (double)100);
	rz = ft_init_matrix(3, 3, v);
	rz.content[0][0] = cos(teta);
	rz.content[0][1] = -sin(teta);
	rz.content[0][2] = 0;
	rz.content[1][0] = sin(teta);
	rz.content[1][1] = cos(teta);
	rz.content[1][2] = 0;
	rz.content[2][0] = 0;
	rz.content[2][1] = 0;
	rz.content[2][2] = 1;
	return (rz);
}

t_matrix	ft_imatrix(t_vars *v)
{
	t_matrix	imatrix;

	imatrix = ft_init_matrix(3, 3, v);
	imatrix.content[0][0] = 1;
	imatrix.content[0][1] = -1;
	imatrix.content[0][2] = 0;
	imatrix.content[1][0] = 1;
	imatrix.content[1][1] = 1;
	imatrix.content[1][2] = -1;
	imatrix.content[2][0] = 1;
	imatrix.content[2][1] = 1;
	imatrix.content[2][2] = 1;
	return (imatrix);
}

t_matrix	ft_tmatrix(t_vars *v)
{
	t_matrix	imatrix;

	imatrix = ft_init_matrix(3, 3, v);
	imatrix.content[0][0] = 1;
	imatrix.content[0][1] = 0;
	imatrix.content[0][2] = 0;
	imatrix.content[1][0] = 0;
	imatrix.content[1][1] = 1;
	imatrix.content[1][2] = 0;
	imatrix.content[2][0] = 0;
	imatrix.content[2][1] = 0;
	imatrix.content[2][2] = 1;
	return (imatrix);
}
