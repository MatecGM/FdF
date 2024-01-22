/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_const.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:45:16 by mbico             #+#    #+#             */
/*   Updated: 2024/01/22 03:57:43 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	ft_rx(double c)
{
	t_matrix 	rx;
	double		teta;

	//printf(c);
	teta = -(c / (double)250);
	rx = ft_init_matrix(3, 3);
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

t_matrix	ft_rz(int c)
{
	t_matrix	rz;
	double		teta;

	teta = -(c / (double)100);
	rz = ft_init_matrix(3, 3);
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

t_matrix	ft_imatrix(void)
{
	t_matrix imatrix;

	imatrix = ft_init_matrix(3, 3);
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

// t_matrix	ft_imatrix(void)
// {
// 	t_matrix imatrix;

// 	imatrix = ft_init_matrix(3, 3);
// 	imatrix.content[0][0] = 1;
// 	imatrix.content[0][1] = 0;
// 	imatrix.content[0][2] = 0;
// 	imatrix.content[1][0] = 0;
// 	imatrix.content[1][1] = 1;
// 	imatrix.content[1][2] = 0;
// 	imatrix.content[2][0] = 0;
// 	imatrix.content[2][1] = 0;
// 	imatrix.content[2][2] = 1;
// 	return (imatrix);
// }