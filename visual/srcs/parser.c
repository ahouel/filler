/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:36:02 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/29 10:43:05 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static char	**read_map(t_param *p, char **line)
{
	int	x;
	int	y;

	y = 0;
	get_next_line(0, line);
	while (y < p->map->y)
	{
		get_next_line(0, line);
		if (ft_strlen(*line) != (size_t)(4 + p->map->x))
			return (NULL);
		x = 4;
		while ((*line)[x] && x - 4 < p->map->x)
		{
			p->map->map[y][x - 4] = (*line)[x];
			++x;
		}
		p->map->map[y][p->map->x] = '\0';
		++y;
	}
	p->map->map[p->map->y] = NULL;
	return (p->map->map);
}

static int	valid_char(char c)
{
	if (c != '.' && c != 'O' && c != 'X' &&
			c != 'x' && c != 'o' && c != ' ')
		return (0);
	return (1);
}

static int	check_map(t_param *p)
{
	int	x;
	int	y;

	y = -1;
	while (p->map->map[++y])
	{
		x = -1;
		while (p->map->map[y][++x])
		{
			if (!(valid_char(p->map->map[y][x])))
				return (0);
		}
	}
	return (1);
}

static char	**grab_map(t_param *p, char **line)
{
	int	i;

	i = 0;
	while (!ft_isdigit((*line)[i]))
		++i;
	p->map->y = ft_atoi((*line) + i);
	while (ft_isdigit((*line)[i]))
		++i;
	while (!ft_isdigit((*line)[i]))
		++i;
	p->map->x = ft_atoi((*line) + i);
	if (p->map->x < 1 || p->map->y < 1)
		return (NULL);
	if (!p->map->map)
		if (!(p->map->map = ft_malloc_2d(p->map->x, p->map->y)))
			return (NULL);
	p->map->map[4][4] = 'O';
	if (!(p->map->map = read_map(p, line)) || !check_map(p))
		return (NULL);
	return (p->map->map);
}

int			parser(void *param)
{
	t_param	*p;

	p = (t_param*)param;
	if (get_next_line(0, p->line))
	{
		if (ft_strstr(*(p->line), "Plateau"))
		{
			if (!(p->map->map = grab_map(p, p->line)))
			{
				free_all(p);
				exit(EXIT_FAILURE);
			}
			if (p->win)
				drawer(p);
			return (2);
		}
		else if (ft_strstr(*(p->line), "fin"))
			final_draw(p);
		return (1);
	}
	return (-1);
}
