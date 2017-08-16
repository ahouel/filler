/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 18:20:32 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/27 19:56:01 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	init_scoreboard(t_param *p)
{
	mlx_string_put(p->mlx, p->win, 10, p->y + 1 + (SCOREBOARD * 30) / 100,
			COLOR_P1A, p->p1);
	mlx_string_put(p->mlx, p->win, 10, p->y + 1 + (SCOREBOARD * 60) / 100,
			COLOR_P2A, p->p2);
	mlx_string_put(p->mlx, p->win, 200, p->y + 1 + (SCOREBOARD * 30) / 100,
			COLOR_GRID, "Esc to close");
	mlx_string_put(p->mlx, p->win, 200, p->y + 1 + (SCOREBOARD * 60) / 100,
			COLOR_GRID, "Space to pause 10 sec");
}

void		init_grid(t_param *p)
{
	int	x;
	int	y;

	y = -1;
	while (++y < p->y + 1)
	{
		x = -1;
		while (++x < p->x + 1)
		{
			if (x % p->scaling == 0 || y % p->scaling == 0)
				mlx_pixel_put(p->mlx, p->win, x, y, COLOR_GRID);
		}
	}
	init_scoreboard(p);
}
