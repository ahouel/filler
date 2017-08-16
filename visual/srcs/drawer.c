/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:00:41 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/29 10:54:17 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	draw_case(t_param *p, int y, int x, char c)
{
	int	i;
	int	j;
	int	tx;
	int	color;

	color = 0x00FFFFFF;
	if (c == 'x')
		color = COLOR_P2B;
	else if (c == 'X')
		color = COLOR_P2A;
	else if (c == 'o')
		color = COLOR_P1B;
	else if (c == 'O')
		color = COLOR_P1A;
	y *= p->scaling;
	x *= p->scaling;
	j = y + p->scaling;
	i = x + p->scaling;
	while (++y < j)
	{
		tx = x;
		while (++tx < i)
			mlx_pixel_put(p->mlx, p->win, tx, y, color);
	}
}

void		drawer(t_param *p)
{
	int	x;
	int	y;

	y = -1;
	while (++y < p->map->y)
	{
		x = -1;
		while (++x < p->map->x)
		{
			if (p->map->map[y][x] == 'X' || p->map->map[y][x] == 'O'
					|| p->map->map[y][x] == ' ')
			{
				if (p->map->mapi[y][x] == '.')
				{
					draw_case(p, y, x, p->map->map[y][x]);
					p->map->mapi[y][x] = 'X';
				}
			}
			else if (p->map->map[y][x] != '.')
			{
				draw_case(p, y, x, p->map->map[y][x]);
				p->map->mapi[y][x] = '.';
			}
		}
	}
}
