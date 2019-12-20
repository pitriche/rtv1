/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:33:06 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/20 11:22:13 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

unsigned	trace_ray(t_al *al, t_obj ray)
{
	(void)al;
	(void)ray;
	return (0);
}

void		render(t_al *al)
{
	ft_bzero(al->pix, WIN_SIZEX * WIN_SIZEY * 4);
}
