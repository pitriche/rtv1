/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:33:06 by pitriche          #+#    #+#             */
/*   Updated: 2020/01/17 18:58:53 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			inter_obj_full(t_obj ray, t_rthit *hit, t_obj obj)
{
	if (obj.type == SPHERE)
		return (inter_sphere_full(ray, hit, obj));
	else if (obj.type == PLAN)
		return (inter_plane_full(ray, hit, obj));
	else
		return (0);
}

int			inter_obj(t_obj ray, t_obj obj)
{
	if (obj.type == SPHERE)
		return (inter_sphere(ray, obj));
	else if (obj.type == PLAN)
		return (inter_plane(ray, obj));
	else
		return (0);
}

void		illuminance_light(t_al *al, t_rthit *hit, t_obj light)
{
	t_obj	ray;
	t_v3	vlight;
	double	dist;
	double	coef;
	int		i;

	vlight = sub_v3(light.co.pos, hit->pos);
	dist = sqrt(dpv3(vlight, vlight));
	normv3(&vlight);
	coef = dpv3(vlight, hit->normal);
	if (coef < 0)
		return ;
	ray.co.pos = hit->pos;
	ray.co.or = vlight;
	i = 0;
	while (i < al->nb_obj)
	{
		if (i != hit->obj_id)
			if (inter_obj(ray, al->obj[i]))
				i = 69420;
		i++;
	}
	i != 69421 ? hit->lux += coef * light.size / (12.56637 * dist * dist) : 0;
}

void		illuminance(t_al *al, t_rthit *hit)
{
	int i;

	i = 0;
	hit->lux = 0;
	while (i < al->nb_light)
	{
		illuminance_light(al, hit, al->light[i]);
		hit->lux < 0 ? ft_printf("yaya\n") : 0;
		i++;
	}
}

unsigned	apply_illum(t_rthit *hit, double iso)
{
	unsigned	r;
	unsigned	g;
	unsigned	b;
	double		coef;

	coef = hit->lux / iso;
	r = ((hit->color & 0xff0000) >> 16) * coef;
	g = ((hit->color & 0xff00) >> 8) * coef;
	b = (hit->color & 0xff) * coef;
	r > 0xff ? r = 0xff : 0;
	g > 0xff ? g = 0xff : 0;
	b > 0xff ? b = 0xff : 0;
	return ((r << 16) + (g << 8) + b);
}

unsigned	trace_ray(t_al *al, t_obj ray)
{
	t_rthit		hit;
	t_rthit		tmp_hit;
	unsigned	i;

	i = 0;
	hit.color = 0;
	hit.dist = INFINITY;

	while (i < al->nb_obj)
	{
		if (inter_obj_full(ray, &tmp_hit, al->obj[i]))
			if (tmp_hit.dist < hit.dist)
			{
				hit = tmp_hit;
				hit.obj_id = i;
			}
		i++;
	}
	hit.dist != INFINITY ? illuminance(al, &hit) : 0;
	//return (apply_illum(&hit, al->c.iso));
	return (hit.color);
}

void		render(t_al *al)
{
	unsigned	i;
	unsigned	j;
	t_obj		ray;

	j = 0;
	ray.co.pos = al->c.pos;
	while (j < WIN_SIZEY)
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
