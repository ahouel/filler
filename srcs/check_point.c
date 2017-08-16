/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:57:59 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/29 10:41:11 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_used(t_e *e, int y, int x)
{
	if (e->map->map[y][x] == e->p ||
			e->map->map[y][x] == e->lp)
		return (1);
	return (0);
}

int			check_point(t_e *e, int y, int x)
{
	int		i;
	int		j;
	int		ret;

	ret = 0;
	j = -1;
	while (++j < e->piece->y)
	{
		i = -1;
		while (++i < e->piece->x)
		{
			if (e->piece->piece[j][i] != '.')
			{
				if (y + j >= e->map->y || x + i >= e->map->x)
					return (0);
				if (e->map->map[y + j][x + i] != e->p &&
						e->map->map[y + j][x + i] != e->lp
						&& e->map->map[y + j][x + i] != '.')
					return (0);
				if ((ret += is_used(e, y + j, x + i)) > 1)
					return (0);
			}
		}
	}
	return (ret);
}
