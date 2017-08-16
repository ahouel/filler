/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 13:48:38 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/27 19:19:54 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define PLAYER "ahouel"

# include "libft.h"

/*
**	Tmp vars in check_dist()
*/
typedef struct	s_tmp
{
	int		x;
	int		y;
	size_t	tmp;
}				t_tmp;

/*
**	Tmp position of a piece in filler()
*/
typedef struct	s_pt
{
	int		x;
	int		y;
	size_t	dist;
}				t_pt;

/*
**	Map vars
*/
typedef struct	s_m
{
	int		x;
	int		y;
	char	**map;
}				t_m;

/*
**	Piece vars
*/
typedef	struct	s_p
{
	int		x;
	int		y;
	char	**piece;
}				t_p;

/*
**	Environment keeping map, piece, players's vars
*/
typedef struct	s_e
{
	int		num;
	char	p;
	char	lp;
	char	e;
	char	le;
	t_m		*map;
	t_p		*piece;
}				t_e;
void			visual(t_e *e, int y, int x);
size_t			check_dist(t_e *e, int y, int x);
int				check_point(t_e *e, int y, int x);
void			free_2d(char **str);
char			**malloc_2d(int x, int y);
t_m				*grab_map(t_e *e, char **line);
t_p				*grab_piece(t_e *e, char **line);
char			**set_map(t_e *e, char **line);
void			filler(t_e *e);
int				filler_init(void);
#endif
