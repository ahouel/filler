/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:06:05 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/27 19:56:21 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	usage(void)
{
	ft_putstr("Usage : ./filler_vm [commands] | ./visu\n");
}

int			main(int ac, char **av)
{
	int		ret;

	ret = 0;
	if (ac != 1)
	{
		usage();
		return (-1);
	}
	ret = visual();
	if (ret == -1)
		usage();
	if (ret == -2)
		ft_putstr("A problem occured during the process\n");
	if (**av)
		return (ret);
	return (ret);
}
