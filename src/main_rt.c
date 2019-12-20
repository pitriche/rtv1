/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:11:47 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/20 15:27:15 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	main(int ac, char **av)
{
	t_al *al;

	al = 0;
	if (ac < 2)
		return (0);
	if (!(al = ft_memalloc(sizeof(t_al))))
		exit(0);
	init(al, av[1]);
	mlx_loop(al->mlx);
	return (0);
}
