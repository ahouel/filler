/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:46:38 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/29 10:31:01 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	set_player(t_e *e, char *line)
{
	if (ft_strlen(line) < 31)
		return (0);
	if (ft_strstr(line, PLAYER))
	{
		e->num = line[10] - '0';
		if (e->num == 1)
		{
			e->p = 'O';
			e->lp = 'o';
			e->e = 'X';
			e->le = 'x';
		}
		else if (e->num == 2)
		{
			e->p = 'X';
			e->lp = 'x';
			e->e = 'O';
			e->le = 'o';
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	filler_reader(t_e *e, char **line)
{
	if (!get_next_line(0, line))
		return (-1);
	if (e->num == 0 && **line == '$')
	{
		if (!set_player(e, *line))
			return (-1);
	}
	while (get_next_line(0, line))
	{
		if (ft_strstr(*line, "Plateau"))
		{
			if (!(e->map = grab_map(e, line)))
				return (-2);
		}
		else if (ft_strstr((*line), "Piece"))
		{
			if (!(e->piece = grab_piece(e, line)))
				return (-2);
			filler(e);
		}
		else
			return (-1);
	}
	return (0);
}

int			filler_init(void)
{
	t_e		e;
	t_m		m;
	t_p		p;
	char	*line;
	int		ret;

	ret = 0;
	line = NULL;
	m.map = NULL;
	p.piece = NULL;
	e.map = &m;
	e.piece = &p;
	e.num = 0;
	ret = filler_reader(&e, &line);
	if (ret < 0)
	{
		if (e.map)
			e.map->map ? ft_free_2d(e.map->map) : 0;
		if (e.piece)
			e.piece->piece ? ft_free_2d(e.piece->piece) : 0;
	}
	return (ret);
}
