/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:18:30 by pitriche          #+#    #+#             */
/*   Updated: 2020/01/16 17:38:08 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	dtime(t_al *al)
{
	struct timeval	tv;
	char			poi[420];

	gettimeofday(&tv, poi);
	al->curr_time = tv.tv_sec * 1000000 + tv.tv_usec;
	if (al->curr_time < al->tgt_time)
	{
		usleep(al->tgt_time - al->curr_time);
		al->curr_time = al->tgt_time;
	}
	al->dtime = al->curr_time - al->last_time;
	al->last_time = al->curr_time;
	al->tgt_time = al->last_time + 1000000 / al->fps;
}

int			func_loop(t_al *al)
{
	gen_camera(&al->c);
	render(al);
	mlx_put_image_to_window(al->mlx, al->win, al->img, 0, 0);
	dtime(al);
	ft_printf("gen image: %.3f s\t fps:%.2f \n", al->dtime / 1000000.0, 1000000.0 / al->dtime);
	return (0);
}
