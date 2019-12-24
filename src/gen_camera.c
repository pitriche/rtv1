/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:22:13 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/24 18:10:50 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	gen_camera(t_cam *c)
{
	int i;
	int j;

	if (are_parallel(c->or, c->up))
	{
		ft_putstr("Orientation and up are paralle\n");
		c->up.z -= 1;
		normv3(&c->up);
	}
	cpv3p(&c->inc_camx, c->up, c->or);
	normv3(&c->inc_camx);
	cpv3p(&c->inc_camy, c->or, c->inc_camx);
	assign_v3(c->vec[0],
	c->or.x - c->inc_camx.x * c->fovx / 2 + c->inc_camy.x * c->fovy / 2,
	c->or.y - c->inc_camx.y * c->fovx / 2 + c->inc_camy.y * c->fovy / 2,
	c->or.z - c->inc_camx.z * c->fovx / 2 + c->inc_camy.z * c->fovy / 2);
	c->inc_camx = c->inc_camx;
	mult_v3(&c->inc_camx, c->fovx / WIN_SIZEX);
	mult_v3(&c->inc_camy, c->fovy / WIN_SIZEY);
	j = 0;
	while (j < WIN_SIZEY)
	{
		i = 1;
		while (i < WIN_SIZEX)
		{
			
			i -= -1;
		}
		j -= -1;
	}
	/*ft_printf("top left pix [%.3f,%.3f,%.3f]\n",
	c->vec[0][0].x, c->vec[0][0].y, c->vec[0][0].z)*/;
}
