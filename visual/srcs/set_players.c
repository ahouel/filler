/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 19:59:55 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/29 08:45:11 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int	p_reader(t_param *p, int player)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = NULL;
	i = 0;
	j = 0;
	tmp = ft_strstr(*(p->line), ".filler");
	while (i > -10 && tmp[i] != '/')
		--i;
	++i;
	if (player == 1)
		if (!(p->p1 = ft_strnew(-i)))
			return (-1);
	if (player == 2)
		if (!(p->p2 = ft_strnew(-i)))
			return (-1);
	while (tmp[i] && tmp[i] != '.')
	{
		if (player == 1)
			p->p1[j++] = tmp[i++];
		if (player == 2)
			p->p2[j++] = tmp[i++];
	}
	return (0);
}

int			set_players(t_param *p)
{
	int		player;

	player = 1;
	while (get_next_line(0, p->line))
	{
		if (ft_strstr(*(p->line), "launched"))
		{
			if (p_reader(p, player) < 0)
				return (-1);
			++player;
			if (player == 3)
				return (0);
		}
	}
	return (-1);
}
