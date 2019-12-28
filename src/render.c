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

int			inter_sphere(t_obj ray, t_rthit *hit, t_obj obj)
{
	double	d_proj;
	double	d;
	t_v3	l;

	l = sub_v3(obj.co.pos, ray.co.pos);
	hit->di sqrt(dpv3(l, l));
	d_proj = dpv3(ray.co.or, l);
	d = sqrt(dpv3(l, l) - d_proj * d_proj);
	if (d > 0 && d < obj.size)
		return (sqrt(dpv3(l, l)) - sqrt(obj.size * obj.size - d * d));
	return (0);
}

int			inter_obj(t_obj ray, t_rthit *hit, t_obj obj)
{
	if (obj.type == SPHERE)
		return (inter_sphere(ray, &hit, obj));
}

unsigned	trace_ray(t_al *al, t_obj ray)
{
	t_rthit		hit;
	t_rthit		tmp_hit;
	unsigned	i;
	unsigned	tmp_dst;

	i = 0;
	ft_bzero(&hit, sizeof(t_rthit));
	hit.dist = INFINITY;
	
	while (i < al->nb_obj)
	{
		if (inter_obj(ray, &tmp_hit, al->obj[i]))
		{
			if (tmp_dst < hit.dist)
			{
				hit.dist = tmp_dst;
				hit.color = al->obj[i].color;
			}
		}
		i++;
	}
	return (hit.color);
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
