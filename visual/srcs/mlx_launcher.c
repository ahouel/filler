/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_launcher.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:00:32 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/29 09:06:20 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int	win_keys(int keycode, void *param)
{
	t_param *p;

	p = (t_param*)param;
	if (keycode == 53)
	{
		free_all(p);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 49)
		sleep(5);
	return (0);
}

void		mlx_launcher(t_param *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, p->x + 1, p->y + 1 + SCOREBOARD,
			"Filler");
	init_grid(p);
	mlx_loop_hook(p->mlx, parser, (void*)p);
	mlx_key_hook(p->win, win_keys, (void*)p);
	mlx_loop(p->mlx);
}
