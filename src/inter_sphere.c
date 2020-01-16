/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 06:49:52 by pitriche          #+#    #+#             */
/*   Updated: 2020/01/10 11:46:01 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			inter_sphere_full(t_obj ray, t_rthit *hit, t_obj obj)
{
	t_v3	omc;
	double	det;
	double	tmp;

	omc = sub_v3(ray.co.pos, obj.co.pos);
	det = dpv3(ray.co.or, omc);
	tmp = det * det - dpv3(omc, omc) + obj.size * obj.size;
	if (tmp >= 0)
	{
		if ((hit->dist = -det - sqrt(tmp)) < 0)
			return (0);
		add_v3p(&hit->pos, mult_v3(ray.co.or, hit->dist), ray.co.pos);
		hit->normal = sub_v3(hit->pos, obj.co.pos);
		normv3(&hit->normal);
		hit->color = obj.color;
		return (1);
	}
	return (0);
}

int			inter_sphere(t_obj ray, t_obj obj)
{
	t_v3	omc;
	double	det;
	double	tmp;
	double	dst;

	omc = sub_v3(ray.co.pos, obj.co.pos);
	det = dpv3(ray.co.or, omc);
	tmp = det * det - dpv3(omc, omc) + obj.size * obj.size;
	if (tmp >= 0)
	{
		if ((dst = -det - sqrt(tmp)) < 0)
			return (0);
		return (1);
	}
	return (0);
}