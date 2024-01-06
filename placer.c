/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:46:57 by mbico             #+#    #+#             */
/*   Updated: 2024/01/06 19:51:13 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// taile de la fenêtre 1024 * 600
t_point	**ft_placer(t_point **links, int *max)
{
	int	margin;
	int	coord[2];
	double	diago;

	coord[0] = 0;
	coord[1] = 0;
	margin = 100;

	while (coord[1] <= max[1])
	{
		while (coord[0] <= max[0])
		{
			links[coord[0]][coord[1]].x = 512 + ((412 / (float)(max[0] * (max[0] >= max[1]) + max[1] * (max[1] > max[0]))) * ((coord[0] - coord[1])));
			links[coord[0]][coord[1]].y = margin + ((400 / (float)((max[0] * (max[0] >= max[1]) + max[1] * (max[1] > max[0]))* 2) * (coord[0] + coord[1])) - links[coord[0]][coord[1]].z);
			coord[0]++;
		}
		coord[1]++;
		coord[0] = 0;
	}
	return (links);
}
