/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:19:21 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/29 10:41:19 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_point(t_pt *pt)
{
	pt->dist = 0;
	pt->x = 0;
	pt->y = 0;
}

static void	fill_point(t_pt *pt, size_t tmp, int j, int i)
{
	pt->dist = tmp;
	pt->x = j;
	pt->y = i;
}

void		filler(t_e *e)
{
	t_pt	pt;
	int		i;
	int		j;
	size_t	tmp;

	i = -1;
	tmp = 0;
	init_point(&pt);
	while (++i < e->map->y)
	{
		j = -1;
		while (++j < e->map->x)
		{
			if (check_point(e, i, j) > 0)
			{
				tmp = check_dist(e, i, j);
				if (pt.dist == 0 || tmp < pt.dist)
					fill_point(&pt, tmp, j, i);
			}
		}
	}
	ft_printf("%d %d\n", pt.y, pt.x);
}
