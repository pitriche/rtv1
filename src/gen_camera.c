/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:22:13 by pitriche          #+#    #+#             */
/*   Updated: 2020/01/07 06:50:08 by pitriche         ###   ########.fr       */
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
	mult_v3p(&c->inc_camx, c->fovx / WIN_SIZEX);
	mult_v3p(&c->inc_camy, -c->fovy / WIN_SIZEY); // negative for inverse cam coor
	j = 0;
	while (j < WIN_SIZEY)
	{
		i = 1;
		while (i < WIN_SIZEX)
		{
			add_v3p(c->vec[j] + i, c->vec[j][i - 1], c->inc_camx);
			i -= -1;
		}
		if ((++j) != WIN_SIZEY)
		{
			add_v3p(c->vec[j], c->vec[j - 1][i - 1],
			mult_v3(c->inc_camx, -WIN_SIZEX + 1));
			add_v3p(c->vec[j], c->vec[j][0], c->inc_camy);
			/*ft_printf("left pix [%.3f,%.3f,%.3f] [%.3f,%.3f,%.3f]\n",
	c->vec[j][0].x, c->vec[j][0].y, c->vec[j][0].z,
	c->vec[j - 1][i - 1].x, c->vec[j - 1][i - 1].y, c->vec[j - 1][i - 1].z);*/
		}
	}
	j = 0;
	while (j < WIN_SIZEY)
	{
		i = 0;
		while (i < WIN_SIZEX)
			normv3(c->vec[j] + (i++));
		/*ft_printf("left pix [%.3f,%.3f,%.3f] right pix[%.3f,%.3f,%.3f]\n",
	c->vec[j][0].x, c->vec[j][0].y, c->vec[j][0].z,
	c->vec[j - 1][i - 1].x, c->vec[j - 1][i - 1].y, c->vec[j - 1][i - 1].z);*/
		j++;
	}
}
