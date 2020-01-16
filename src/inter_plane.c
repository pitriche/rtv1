/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:46:18 by pitriche          #+#    #+#             */
/*   Updated: 2020/01/10 15:21:21 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			inter_plane_full(t_obj ray, t_rthit *hit, t_obj obj)
{
	double ldpn;

	ldpn = dpv3(ray.co.or, obj.co.or);
	if (!ldpn)
		return (0);
	hit->dist = dpv3(sub_v3(obj.co.pos, ray.co.pos), obj.co.or) / ldpn;
	if (hit->dist > 0)
	{
		hit->color = obj.color;
		hit->normal = obj.co.or;
		add_v3p(&hit->pos, mult_v3(ray.co.or, hit->dist), ray.co.pos);
		return (1);
	}
	return (0);
}

int			inter_plane(t_obj ray, t_obj obj)
{
	t_rthit yeey;
	
	return(0);
	//return (inter_plane_full(ray, &yeey, obj));
}
