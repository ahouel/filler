/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:38:55 by ahouel            #+#    #+#             */
/*   Updated: 2017/05/29 10:07:12 by ahouel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(int ac, char **av)
{
	int		ret;

	ret = 0;
	if (ac != 1 || av[1])
		return (-1);
	ret = filler_init();
	return (ret);
}