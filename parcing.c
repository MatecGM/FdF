/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:59:46 by mbico             #+#    #+#             */
/*   Updated: 2024/01/10 19:41:07 by mbico            ###   ########.fr       */
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

void	ft_closesplit(char **splitted_char)
{
	int	i;

	i = 0;
	while (splitted_char[i])
	{
		free(splitted_char[i]);
		i ++;
	}
	free(splitted_char);
}

void	ft_parse(t_vars *vars, int fd)
{
	char	*line;
	char	**splitted_word;
	t_list	*lst_map;
	t_list	*start_lst;

	lst_map = ft_lstnew(get_next_line(fd));
	line = get_next_line(fd);
	vars->maxy = 0;
	while (line)
	{
		//free(line);
		ft_lstadd_back(&lst_map, ft_lstnew(line));
		line = get_next_line(fd);
		vars->maxy ++;
	}
	vars->links = calloc(sizeof(t_point *), vars->maxy + 1);
	vars->maxy = 0;
	start_lst = lst_map;
	while (lst_map)
	{
		splitted_word = ft_split((char *)(lst_map->content), ' ');
		vars->links[vars->maxy] = calloc(sizeof(t_point), ft_countrow(splitted_word) + 1);
		vars->maxx = 0;
		while (splitted_word[vars->maxx])
		{
			vars->links[vars->maxy][vars->maxx].z = ft_atoi(splitted_word[vars->maxx]);
			vars->maxx ++;
		}
		ft_closesplit(splitted_word);
		lst_map = lst_map->next;
		vars->maxy ++;
	}
	ft_lstclear(&start_lst, free);
}
