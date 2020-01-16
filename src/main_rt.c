/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:11:47 by pitriche          #+#    #+#             */
/*   Updated: 2020/01/07 06:50:19 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	print_objs(t_al *al)
{
	t_obj *ob;

	ft_printf("Cam [%.2f,%.2f,%.2f] or [%.3f,%.3f,%.3f] fov[%.2f,%.2f]\n\n", al->c.pos.x, al->c.pos.y, al->c.pos.z,
	al->c.or.x, al->c.or.y, al->c.or.z, al->c.fovx, al->c.fovy);
	for (unsigned i = 0; i < al->nb_obj; i++)
	{
		ob = al->obj + i;
	
		ob->type == SPHERE ? ft_printf("Sphere [%.2f,%.2f,%.2f] size %.2f color>%#x\n",
	ob->co.pos.x, ob->co.pos.y, ob->co.pos.z, ob->size, 0,0,0,0, ob->color) : 0;
	
		ob->type == CONE ? ft_printf("Cone [%.2f,%.2f,%.2f] or [%.3f,%.3f,%.3f] angle>%.3f deg color>%#x\n",
	ob->co.pos.x, ob->co.pos.y, ob->co.pos.z, ob->co.or.x, ob->co.or.y, ob->co.or.z, ob->size, 0,0,0,0,0,0,0,
	ob->color) : 0;

		ob->type == CYLINDER ? ft_printf("Cylinder [%.2f,%.2f,%.2f] or [%.3f,%.3f,%.3f] size>%.3f color>%#x\n",
	ob->co.pos.x, ob->co.pos.y, ob->co.pos.z, ob->co.or.x, ob->co.or.y, ob->co.or.z, ob->size, 0,0,0,0,0,0,0,
	ob->color) : 0;
	
		ob->type == PLAN ? ft_printf("Plan [%.2f,%.2f,%.2f] or [%.3f,%.3f,%.3f] color>%#x\n",
	ob->co.pos.x, ob->co.pos.y, ob->co.pos.z, ob->co.or.x, ob->co.or.y, ob->co.or.z, 0,0,0,0,0,0,
	ob->color) : 0;
	}
	for (unsigned i = 0; i < al->nb_light; i++)
	{
		ob = al->light + i;
		ft_printf("Light [%.2f,%.2f,%.2f], %.1f lumen\n", ob->co.pos.x, ob->co.pos.y, ob->co.pos.z, ob->size);
	}
}

int		main(int ac, char **av)
{
	t_al *al;

	al = 0;
	if (ac < 2)
		return (0);
	if (!(al = ft_memalloc(sizeof(t_al))))
		exit(0);
	init(al, av[1]);
	print_objs(al);
	mlx_loop(al->mlx);
	return (0);
}
