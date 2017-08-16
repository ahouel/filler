/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 13:28:43 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/24 18:32:31 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	**read_piece(t_e *e, char **line)
{
	int	x;
	int	y;

	y = 0;
	while (y < e->piece->y)
	{
		get_next_line(0, line);
		if (ft_strlen(*line) != (size_t)(e->piece->x))
			return (NULL);
		x = 0;
		while ((*line)[x] && x < e->piece->x)
		{
			e->piece->piece[y][x] = (*line)[x];
			++x;
		}
		e->piece->piece[y][x] = '\0';
		++y;
	}
	e->piece->piece[e->piece->y] = NULL;
	return (e->piece->piece);
}

static int	check_piece(t_e *e)
{
	int	x;
	int	y;
	int	nb;

	nb = 0;
	y = -1;
	while (e->piece->piece[++y])
	{
		x = -1;
		while (e->piece->piece[y][++x])
		{
			if (e->piece->piece[y][x] != '.'
					&& e->piece->piece[y][x] != '*')
				return (0);
			if (e->piece->piece[y][x] == '*')
				++nb;
		}
	}
	if (!nb)
		return (0);
	return (1);
}

t_p			*grab_piece(t_e *e, char **line)
{
	int	i;

	i = 0;
	if (e->piece->piece)
		ft_free_2d(e->piece->piece);
	while (!ft_isdigit((*line)[i]))
		++i;
	e->piece->y = ft_atoi((*line) + i);
	while (ft_isdigit((*line)[i]))
		++i;
	while (!ft_isdigit((*line)[i]))
		++i;
	e->piece->x = ft_atoi((*line) + i);
	if (e->piece->x < 1 || e->piece->y < 1)
		return (NULL);
	if (!(e->piece->piece = ft_malloc_2d(e->piece->x, e->piece->y)))
		return (NULL);
	if (!(e->piece->piece = read_piece(e, line)) || !check_piece(e))
		return (NULL);
	return (e->piece);
}
