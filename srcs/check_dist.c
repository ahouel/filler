/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:40:43 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/22 17:52:08 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		round_piece(t_e *e, t_tmp *t)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	j = -1;
	t->y = 0;
	t->x = 0;
	while (++j < e->piece->y)
	{
		i = -1;
		while (++i < e->piece->x)
		{
			if (e->piece->piece[j][i] != '.')
			{
				t->y += j;
				t->x += i;
				nb += 1;
			}
		}
	}
	if (nb == 0)
		return ;
	t->y /= nb;
	t->x /= nb;
}

static size_t	calc_dist(int ax, int ay, int bx, int by)
{
	int	x;
	int	y;

	x = ft_abs(ax - bx);
	y = ft_abs(ay - by);
	return ((size_t)(x + y));
}

size_t			check_dist(t_e *e, int y, int x)
{
	int		i;
	int		j;
	size_t	ret;
	t_tmp	t;

	ret = 0;
	t.tmp = 0;
	round_piece(e, &t);
	j = -1;
	while (++j < e->map->y)
	{
		i = -1;
		while (++i < e->map->x)
		{
			if (e->map->map[j][i] == e->e || e->map->map[j][i] == e->le)
			{
				t.tmp = calc_dist(j, i, y + t.y, x + t.x);
				if (ret == 0 || t.tmp < ret)
					ret = t.tmp;
			}
		}
	}
	return (ret);
}
