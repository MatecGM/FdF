/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:59:46 by mbico             #+#    #+#             */
/*   Updated: 2024/01/07 19:26:34 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_countrow(char **splitted_word)
{
	int	i;

	i = 0;
	while (splitted_word[i])
		i++;
	return (i);
}

int	*ft_parse(t_point ***links, int fd, int *coord)
{
	char	*line;
	char	**splitted_word;
	t_list	*lst_map;
	t_list	*start_lst;

	lst_map = ft_lstnew(get_next_line(fd));
	line = get_next_line(fd);
	coord[1] = 0;
	while (line)
	{
		ft_lstadd_back(&lst_map, ft_lstnew(line));
		line = get_next_line(fd);
		coord[1] ++;
	}
	*links = calloc(sizeof(t_point *), coord[1]);
	start_lst = lst_map;
	coord[1] = 0;
	while (lst_map)
	{
		splitted_word = ft_split((char *)(lst_map->content), ' ');
		links[0][coord[1]] = calloc(sizeof(t_point), ft_countrow(splitted_word));
		coord[0] = 0;
		while (splitted_word[coord[0]])
		{
			links[0][coord[1]][coord[0]].z = ft_atoi(splitted_word[coord[0]]);
			coord[0] ++;
		}
		lst_map = lst_map->next;
		coord[1] ++;
	}
	return (coord);
}
