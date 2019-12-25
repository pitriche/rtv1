/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changuy <changuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:33:06 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/25 20:48:53 by changuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		inter_sphere(t_obj ray, t_obj obj)
{
	double	d_proj;
	double	d;
	t_v3	l;

	l = sub_v3(obj.co.pos, ray.co.pos);
	d_proj = dpv3(ray.co.or, l);
	d = sqrt(dpv3(l, l) - d_proj * d_proj);
	if (d > 0 && d < obj.size)
		return (sqrt(dpv3(l, l)) - sqrt(obj.size * obj.size - d * d));
	return (-1);
}

double		inter_obj(t_obj ray, t_obj obj)
{
	if (obj.type == SPHERE)
		return (inter_sphere(ray, obj));
	return (-1);
}

unsigned	trace_ray(t_al *al, t_obj ray)
{
	unsigned	i;
	unsigned	color;
	unsigned	tmp_dst;
	unsigned	min_dst;

	i = 0;
	min_dst = INFINITY;
	tmp_dst = 0;
	color = 0;
	while (i < al->nb_obj)
	{
		if ((tmp_dst = inter_obj(ray, al->obj[i])) != -1)
		{
			if (tmp_dst < min_dst)
			{
				min_dst = tmp_dst;
				color = al->obj[i].color;
			}
		}
		i++;
	}
	return (color);
}

void		render(t_al *al)
{
	unsigned	i;
	unsigned	j;
	t_obj		ray;

	j = 0;
	ray.co.pos = al->c.pos;
	while(j < WIN_SIZEY)
	{
		i = 0;
		while (i < WIN_SIZEX)
		{
			ray.co.or = al->c.vec[j][i];
			al->pix[j * WIN_SIZEX + i] = trace_ray(al, ray);
			i++;
		}
		j++;
	}
}
