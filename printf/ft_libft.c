/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:57:10 by mbico             #+#    #+#             */
/*   Updated: 2023/11/22 18:51:16 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*occ;

	occ = NULL;
	while (*s != 0)
	{
		if (*s == (unsigned char)c)
			occ = (char *)s;
		s ++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return (occ);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i ++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len ++;
		s ++;
	}
	return (len);
}
