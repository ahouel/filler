/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 18:19:36 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/27 19:54:33 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	final_draw(t_param *p)
{
	char	*p1;
	char	*p2;
	int		s1;
	int		s2;

	p1 = NULL;
	p2 = NULL;
	if (!(p1 = ft_strdup(*(p->line) + 9)))
		exit(EXIT_FAILURE);
	get_next_line(0, p->line);
	if (!(p2 = ft_strdup(*(p->line) + 9)))
		exit(EXIT_FAILURE);
	s1 = ft_atoi(p1);
	s2 = ft_atoi(p2);
	mlx_string_put(p->mlx, p->win, 10, p->y + 1 + (SCOREBOARD * 45) / 100,
			COLOR_P1A, p1);
	mlx_string_put(p->mlx, p->win, 10, p->y + 1 + (SCOREBOARD * 75) / 100,
			COLOR_P2A, p2);
	if (s1 > s2)
		mlx_string_put(p->mlx, p->win, 110, p->y + 1 +
				(SCOREBOARD * 30) / 100, COLOR_P1A, "WINNER !");
	else if (s2 > s1)
		mlx_string_put(p->mlx, p->win, 110, p->y + 1 +
				(SCOREBOARD * 60) / 100, COLOR_P2A, "WINNER !");
	free_all(p);
}
