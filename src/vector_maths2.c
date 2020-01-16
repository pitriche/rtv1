/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_maths2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:49:08 by pitriche          #+#    #+#             */
/*   Updated: 2020/01/07 06:50:35 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	mult_v3p(t_v3 *v, double x)
{
	v->x *= x;
	v->y *= x;
	v->z *= x;
}

t_v3	mult_v3(t_v3 v, double x)
{
	v.x *= x;
	v.y *= x;
	v.z *= x;
	return (v);
}

void	add_v3p(t_v3 *v, t_v3 v1, t_v3 v2)
{
	v->x = v1.x + v2.x;
	v->y = v1.y + v2.y;
	v->z = v1.z + v2.z;
}

t_v3	sub_v3(t_v3 v1, t_v3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

double	dpv3(t_v3 v1, t_v3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
