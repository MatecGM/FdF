/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:59:46 by mbico             #+#    #+#             */
/*   Updated: 2024/01/25 18:23:34 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_countrow(char **s_w)
{
	int	i;

	i = 0;
	while (s_w[i])
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

t_list	*get_file_line(t_vars *vars)
{
	char	*line;
	t_list	*lst_tmp;
	t_list	*lst_map;

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

void	ft_z_filler(t_vars *v, t_list *lst_map, t_list *lst_tmp)
{
	char	**s_w;

	s_w = ft_split((char *)(lst_map->content), ' ');
	if (!s_w)
	{
		ft_lstclear(&lst_tmp, free);
		ft_close(v);
	}
	v->links[v->maxy] = ft_calloc(sizeof(t_point), ft_countrow(s_w) + 1);
	if (!v->links[v->maxy] || (ft_countrow(s_w) != v->maxx && v->maxx != 0))
	{
		ft_closesplit(s_w);
		ft_lstclear(&lst_tmp, free);
		ft_close(v);
	}
	v->maxx = -1;
	while (s_w[++ v->maxx])
	{
		v->links[v->maxy][v->maxx].z = ft_atoi(s_w[v->maxx]);
		if (v->links[v->maxy][v->maxx].z > v->maxz)
			v->maxz = v->links[v->maxy][v->maxx].z;
		else if (v->links[v->maxy][v->maxx].z < v->minz)
			v->minz = v->links[v->maxy][v->maxx].z;
	}
	ft_closesplit(s_w);
}

void	ft_parse(t_vars *vars)
{
	t_list	*lst_map;
	t_list	*lst_tmp;

	lst_map = get_file_line(vars);
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
