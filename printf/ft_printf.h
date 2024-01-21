/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:39:31 by mbico             #+#    #+#             */
/*   Updated: 2023/11/22 15:29:03 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

char	*ft_strrchr(const char *s, int c);
int		ft_putstr(char *s);
int		ft_putchar(char c);
size_t	ft_strlen(const char *s);
int		ft_putnbr_base(unsigned long n, char *base);
int		ft_putnbr(int n);
int		ft_nil(unsigned long n);
int		ft_printf(const char *str, ...);

#endif
