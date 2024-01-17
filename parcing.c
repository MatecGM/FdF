/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:59:46 by mbico             #+#    #+#             */
/*   Updated: 2024/01/17 18:38:06 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_countrow(char **s_word)
{
	int	i;

	i = 0;
	while (s_word[i])
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

t_list	*get_file_line(t_vars *vars, t_list *lst_map)
{
	char	*line;
	t_list	*lst_tmp;

	line = get_next_line(vars->fd);
	if (!line)
		ft_close(vars);
	lst_map = ft_lstnew(line);
	if (!lst_map)
		ft_close(vars);
	line = get_next_line(vars->fd);
	while (line)
	{
		lst_tmp = ft_lstnew(line);
		if (!lst_tmp)
		{
			ft_lstclear(&lst_map, free);
			ft_close(vars);
		}
		ft_lstadd_back(&lst_map, lst_tmp);
		line = get_next_line(vars->fd);
		vars->maxy ++;
	}
	return (lst_map);
}

void	ft_z_filler(t_vars *vars, t_list *lst_map, t_list *lst_tmp)
{
	char	**s_word;

	s_word = ft_split((char *)(lst_map->content), ' ');
	if (!s_word)
	{
		ft_lstclear(&lst_tmp, free);
		ft_close(vars);
	}
	vars->links[vars->maxy] = ft_calloc(sizeof(t_point),
			ft_countrow(s_word) + 1);
	if (!vars->links[vars->maxy]
		|| (ft_countrow(s_word) != vars->maxx && vars->maxx != 0))
	{
		ft_closesplit(s_word);
		ft_lstclear(&lst_tmp, free);
		ft_close(vars);
	}
	vars->maxx = 0;
	while (s_word[vars->maxx])
	{
		vars->links[vars->maxy][vars->maxx].z = ft_atoi(s_word[vars->maxx]);
		if (vars->links[vars->maxy][vars->maxx].z > vars->maxz)
			vars->maxz = vars->links[vars->maxy][vars->maxx].z;
		else if (vars->links[vars->maxy][vars->maxx].z < vars->minz)
			vars->minz = vars->links[vars->maxy][vars->maxx].z;
		vars->maxx ++;
	}
	ft_closesplit(s_word);
}

void	ft_parse(t_vars *vars)
{
	t_list	*lst_map;
	t_list	*lst_tmp;

	lst_map = get_file_line(vars, lst_map);
	vars->links = ft_calloc(sizeof(t_point *), vars->maxy + 1);
	vars->maxy = 0;
	if (!vars->links)
	{
		ft_lstclear(&lst_map, free);
		ft_close(vars);
	}
	lst_tmp = lst_map;
	while (lst_map)
	{
		ft_z_filler(vars, lst_map, lst_tmp);
		lst_map = lst_map->next;
		vars->maxy ++;
	}
	ft_lstclear(&lst_tmp, free);
}
