/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:23:20 by pitriche          #+#    #+#             */
/*   Updated: 2020/01/16 17:41:29 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rot_vec(t_v3 *v, double pitch, double yaw, double roll)
{
	t_v3 tmp;

	//roll
	tmp.x = v->x * cos(roll) - v->y * sin(roll);
	tmp.y = v->x * sin(roll) + v->y * cos(roll);
	tmp.z = v->z;
	*v = tmp;

	//pitch
	tmp.x = v->x;
	tmp.y = v->y * cos(pitch) - v->z * sin(pitch);
	tmp.z = v->y * sin(pitch) + v->z * cos(pitch);
	*v = tmp;

	//yaw
	tmp.x = v->x * cos(yaw) + v->z * sin(yaw);
	tmp.y = v->y;
	tmp.z = -v->x * sin(yaw) + v->z * cos(yaw);
	*v = tmp;
}

void	transl_vec(t_v3 *v, double x, double y, double z)
{
	v->x += x;
	v->y += y;
	v->z += z;
}
