/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 18:14:03 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/27 19:55:22 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	free_all(t_param *p)
{
	if (p->map->map)
	{
		ft_free_2d(p->map->map);
		p->map->map = NULL;
	}
	if (p->map->mapi)
	{
		ft_free_2d(p->map->mapi);
		p->map->mapi = NULL;
	}
	if (p->p1)
	{
		free(p->p1);
		p->p1 = NULL;
	}
	if (p->p2)
	{
		free(p->p2);
		p->p2 = NULL;
	}
	if (*p->line)
	{
		free(*p->line);
		*p->line = NULL;
	}
}
