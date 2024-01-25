/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:20:42 by mbico             #+#    #+#             */
/*   Updated: 2024/01/25 18:16:56 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_gradient(t_point p1, t_point p2, int i, int max)
{
	unsigned int	color;

	if (p1.r < p2.r)
		p1.r = p1.r + (p2.r - p1.r) * (i / (double)max);
	else if (p1.r > p2.r)
		p1.r = p1.r - (p1.r - p2.r) * (i / (double)max);
	if (p1.g < p2.g)
		p1.g = p1.g + (p2.g - p1.g) * (i / (double)max);
	else if (p1.g > p2.g)
		p1.g = p1.g - (p1.g - p2.g) * (i / (double)max);
	if (p1.b < p2.b)
		p1.b = p1.b + (p2.b - p1.b) * (i / (double)max);
	else if (p1.b > p2.b)
		p1.b = p1.b - (p1.b - p2.b) * (i / (double)max);
	color = (255 << 24) + (p1.r << 16) + (p1.g << 8) + p1.b;
	return (color);
}

void	ft_color(t_point *p, t_vars *v, int z)
{
	double			midz;

	midz = (v->maxz - v->minz) / (double)2 + v->minz;
	p->r = 0;
	p->g = 0;
	p->b = 255;
	if (z > v->minz && z <= midz)
	{
		p->g = 255 * ((z - v->minz) / (double)(midz - v->minz));
		p->b = 255 - 255 * ((z - v->minz) / (double)(midz - v->minz));
	}
	else if (z > midz && z <= v->maxz)
	{
		p->r = 255 * ((double)(z - midz) / (v->maxz - midz));
		p->g = 255 - 255 * ((z - midz) / (double)(v->maxz - midz));
		p->b = 0;
	}
}
