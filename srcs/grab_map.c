/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 13:21:31 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/29 10:54:19 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	**read_map(t_e *e, char **line)
{
	int	x;
	int	y;

	y = 0;
	get_next_line(0, line);
	while (y < e->map->y)
	{
		get_next_line(0, line);
		if (ft_strlen(*line) != (size_t)(4 + e->map->x))
			return (NULL);
		x = 4;
		while ((*line)[x] && x - 4 < e->map->x)
		{
			e->map->map[y][x - 4] = (*line)[x];
			++x;
		}
		e->map->map[y][e->map->x] = '\0';
		++y;
	}
	e->map->map[e->map->y] = NULL;
	return (e->map->map);
}

static int	valid_char(t_e *e, char c)
{
	if (c != '.' && c != e->p && c != e->lp &&
			c != e->e && c != e->le && c != ' ')
		return (0);
	return (1);
}

static int	check_map(t_e *e)
{
	int	x;
	int	y;
	int	p1;
	int	p2;

	p1 = 0;
	p2 = 0;
	y = -1;
	while (e->map->map[++y])
	{
		x = -1;
		while (e->map->map[y][++x])
		{
			if (!(valid_char(e, e->map->map[y][x])))
				return (0);
			if (e->map->map[y][x] == e->p || e->map->map[y][x] == e->lp)
				++p1;
			if (e->map->map[y][x] == e->e || e->map->map[y][x] == e->le)
				++p2;
		}
	}
	if (!p1 || !p2)
		return (0);
	return (1);
}

t_m			*grab_map(t_e *e, char **line)
{
	int	i;

	i = 0;
	while (!ft_isdigit((*line)[i]))
		++i;
	e->map->y = ft_atoi((*line) + i);
	while (ft_isdigit((*line)[i]))
		++i;
	while (!ft_isdigit((*line)[i]))
		++i;
	e->map->x = ft_atoi((*line) + i);
	if (e->map->x < 1 || e->map->y < 1)
		return (NULL);
	if (!e->map->map)
		if (!(e->map->map = ft_malloc_2d(e->map->x, e->map->y)))
			return (NULL);
	if (!(e->map->map = read_map(e, line)) || !check_map(e))
	{
		e->map->map ? ft_free_2d(e->map->map) : 0;
		return (NULL);
	}
	return (e->map);
}
