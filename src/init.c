/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:42:19 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/24 15:43:18 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			func_key(int k, t_al *al)
{
	(void)al;
	k == 53 ? exit(0) : 0;
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
	mica_parser(al, str);
	al->cam_up.x = 0;
	al->cam_up.y = 1;
	al->cam_up.z = 0;
	gen_camera(al->ca, al->cam.or, al->cam_up);
	init_mlx(al);
	set_hooks(al);
	al->fps = 60;
}
