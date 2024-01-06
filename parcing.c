/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:59:46 by mbico             #+#    #+#             */
/*   Updated: 2024/01/06 22:49:51 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_countword(char **splitted_word)
{
	int	i;

	i = 0;
	while (splitted_word[i])
		i++;
	return (i);
}
//idee de merde fjiosigjuojdauibhn gijtodjguofhdgjfuioqgjfuiosfjiojfsjhiojkmprhio
t_point	**ft_add_line(t_point **tab, char **line, int *coord)
{
	t_point	**tmp;
	int		i;
	int		j;
	int		lenline;

	j = 0;
	i = 0;
	if (!tab)
	{
		tab = ft_calloc(sizeof(t_point *), 1);
	}
	else
	{
		tmp = tab;
		tab = ft_calloc(sizeof(t_point *), coord[1] + 1);
		while (j < coord[1])
		{
			while (i <= coord[0])
			{
				ft_printf("%d\n", i);
				tab[j][i] = tmp[j][i];
				i ++;
			}
			i = 0;
			j ++;
		}
		free(tmp);
		ft_printf("test %d\n", tab[0][0].z);
	}
	lenline = ft_countword(line);
	tab[j] = ft_calloc(sizeof(t_point), lenline);
	return (tab);
}

int	*ft_parse(t_point **links, int fd, int *coord)
{
	char	*line;
	char	**word_splitted;

	coord[1] = 0;
	links = NULL;
	line = get_next_line(fd);
	while(line)
	{
		word_splitted = ft_split(line, ' ');
		free(line);
		links = ft_add_line(links, word_splitted, coord);
		coord[0] = 0;
		while(word_splitted[coord[0]])
		{
			links[coord[1]][coord[0]].z = atoi(word_splitted[coord[0]]);
			coord[0]++;
		}
		coord[1]++;
		free(word_splitted);
		line = get_next_line(fd);
	}
	return (coord);
}
