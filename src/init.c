/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:42:19 by pitriche          #+#    #+#             */
/*   Updated: 2020/01/16 17:46:25 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			func_key(int k, t_al *al)
{
	(void)al;
	k == 53 ? exit(0) : 0;
	k == 126 ? rot_vec(&al->c.or, -0.02, 0, 0) : 0;
	k == 123 ? rot_vec(&al->c.or, 0, -0.02, 0) : 0;
	k == 125 ? rot_vec(&al->c.or, 0.02, 0, 0) : 0;
	k == 124 ? rot_vec(&al->c.or, 0, 0.02, 0) : 0;

	k == 13 ? transl_vec(&al->c.pos, 0, 0, 0.2) : 0;
	k == 0 ? transl_vec(&al->c.pos, -0.2, 0, 0) : 0;
	k == 1 ? transl_vec(&al->c.pos, 0, 0, -0.2) : 0;
	k == 2 ? transl_vec(&al->c.pos, 0.2, 0, 0) : 0;
	k == 49 ? transl_vec(&al->c.pos, 0, 0.2, -0) : 0;
	k == 257 ? transl_vec(&al->c.pos, 0, -0.2, 0) : 0;
	ft_printf("key >%d\n", k);
	return (0);
}

int			func_close(t_al *al)
{
	(void)al;
	exit(0);
}

void		set_hooks(t_al *al)
{
	mlx_loop_hook(al->mlx, func_loop, al);
	mlx_hook(al->win, EV_KEY_PRESS, 0, func_key, al);
	mlx_hook(al->win, EV_KEY_RELEA, 0, func_key, al);
	mlx_hook(al->win, EV_CLOSE_WIN, 0, func_close, al);
}

void	init_mlx(t_al *al)
{
	int poi;

	if (!(al->mlx = mlx_init()))
		exit(0);
	if (!(al->win = mlx_new_window(al->mlx, WIN_SIZEX, WIN_SIZEY, WIN_TITLE)))
		exit(0);
	if (!(al->img = mlx_new_image(al->mlx, WIN_SIZEX, WIN_SIZEY)))
		exit(0);
	if (!(al->pix = (unsigned *)mlx_get_data_addr(al->img, &poi, &poi, &poi)))
		exit(0);
	mlx_do_key_autorepeatoff(al->mlx);
}

void	init(t_al *al, char *str)
{
	al->obj = ft_memalloc(MAX_OBJ * sizeof(t_obj));
	al->light = ft_memalloc(MAX_LIGHT * sizeof(t_obj));
	al->iso = 10;
	mica_parser(al, str);
	/*al->light[0].co.pos.y *= 1000000;
	al->light[0].size *= 1e23 * 98;*/
	assign_v3(&al->c.up, 0, 1, 0);
	gen_camera(&al->c);
	init_mlx(al);
	set_hooks(al);
	al->fps = 60;
}
