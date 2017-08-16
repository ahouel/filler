/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:07:14 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/29 09:07:51 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# define COLOR_GRID 0x00555555
# define COLOR_P1A 0x00C00000
# define COLOR_P1B 0x00FF8585
# define COLOR_P2A 0x0000C000
# define COLOR_P2B 0x0085FF85
# define INIT_SCALE 25
# define SCOREBOARD 100
# include "libft.h"
# include <mlx.h>

/*
**	map vars
*/
typedef struct	s_map
{
	int		x;
	int		y;
	char	**map;
	char	**mapi;
}				t_map;

/*
**	mlx params
*/
typedef struct	s_param
{
	void	*mlx;
	void	*win;
	void	*img;
	t_map	*map;
	char	**line;
	int		x;
	int		y;
	int		scaling;
	char	*p1;
	char	*p2;
}				t_param;

void			free_all(t_param *p);
int				set_players(t_param *p);
void			final_draw(t_param *p);
void			init_grid(t_param *p);
void			mlx_launcher(t_param *p);
void			drawer(t_param *p);
int				visual(void);
int				parser(void *param);

#endif
