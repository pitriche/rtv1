/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:34:00 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/24 17:31:55 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	assign_v3(t_v3 *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

int		are_parallel(t_v3 v1, t_v3 v2)
{
	normv3(&v1);
	normv3(&v2);
	if ((v1.x == v2.x && v1.y == v2.y && v1.z == v2.z) ||
		(v1.x == -v2.x && v1.y == -v2.y && v1.z == -v2.z))
		return (1);
	return (0);
}

t_v3	cpv3(t_v3 v1, t_v3 v2)
{
	t_v3 v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

void	cpv3p(t_v3 *v, t_v3 v1, t_v3 v2)
{
	v->x = v1.y * v2.z - v1.z * v2.y;
	v->y = v1.z * v2.x - v1.x * v2.z;
	v->z = v1.x * v2.y - v1.y * v2.x;
}

void	normv3(t_v3 *v)
{
	double	div;

	div = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	if (div == 0)
		return ;
	v->x /= div;
	v->y /= div;
	v->z /= div;
}

