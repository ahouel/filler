/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:31:04 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/29 10:39:29 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	init_params(t_param *p)
{
	p->mlx = NULL;
	p->win = NULL;
	p->img = NULL;
	*p->line = NULL;
	p->scaling = INIT_SCALE;
	p->map->mapi = NULL;
	p->map->map = NULL;
	p->map->x = 0;
	p->map->y = 0;
	p->x = 0;
	p->y = 0;
	p->p1 = NULL;
	p->p2 = NULL;
}

static int	init_mapi(t_param *p)
{
	int	x;
	int	y;

	y = -1;
	if (!(p->map->mapi = ft_malloc_2d(p->map->x, p->map->y)))
		return (0);
	while (++y < p->map->y)
	{
		x = -1;
		while (++x < p->map->x)
			p->map->mapi[y][x] = '.';
		p->map->mapi[y][x] = '\0';
	}
	p->map->mapi[y] = NULL;
	return (1);
}

int			init_map(t_param *p)
{
	p->x = p->scaling * p->map->x;
	p->y = p->scaling * p->map->y;
	while (p->x > 2000 || p->y + SCOREBOARD + 1 > 1500)
	{
		--p->scaling;
		if (p->scaling < 5)
			return (-1);
		p->x = p->scaling * p->map->x;
		p->y = p->scaling * p->map->y;
	}
	while (p->x < 500 || p->y + SCOREBOARD + 1 < 500)
	{
		++p->scaling;
		p->x = p->scaling * p->map->x;
		p->y = p->scaling * p->map->y;
	}
	if (p->map->x < 1 || p->map->y < 1 || !(init_mapi(p)))
	{
		free_all(p);
		return (-2);
	}
	mlx_launcher(p);
	return (0);
}

int			visual(void)
{
	int		ret;
	t_param	p;
	t_map	map;
	char	*line;

	ret = 0;
	p.line = &line;
	p.map = &map;
	init_params(&p);
	if (get_next_line(0, &line) < 1)
		return (-2);
	if (ft_strcmp(line, "# -------------- VM  version 1.1 ------------- #")
			!= 0)
		return (-1);
	if (set_players(&p) < 0)
	{
		free_all(&p);
		return (-2);
	}
	while ((ret = parser((void*)&p)) > 0)
		if (ret == 2)
			if ((ret = init_map(&p)) < 0)
				return (ret);
	return (ret);
}
