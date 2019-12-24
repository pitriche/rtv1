/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:22:13 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/24 16:10:43 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	gen_camera(t_v3 **ca, t_v3 tgt, t_v3 up)
{
	t_v3 unit_camx;
	t_v3 unit_camy;

	cpv3p(&unit_camx, up, tgt);
	normv3(&unit_camx);
	cpv3p(&unit_camy, tgt, unit_camx);
	ft_printf("tgt[%.3f,%.3f,%.3f]\n", tgt.x, tgt.y, tgt.z);
	ft_printf("x[%.3f,%.3f,%.3f], y[%.3f,%.3f,%.3f]\n",
	unit_camx.x, unit_camx.y, unit_camx.z,
	unit_camy.x, unit_camy.y, unit_camy.z);
}
