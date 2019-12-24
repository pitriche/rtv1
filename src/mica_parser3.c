/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mica_parser3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:21:47 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/24 15:47:37 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		parse_int(int *nb, char **str)
{
	*nb = ft_atoi(*str);
	**str == '-' ? (*str)++ : 0;
	if (!ft_isdigit(**str))
		return (1);
	while (ft_isdigit(**str))
		(*str)++;
	if (!ft_isspace(**str) && **str)
		return (1);
	else if (**str)
		(*str)++;
	return (0);
}

int		parse_v3(t_v3 *v, char **str)
{
	int tmp;

	if (parse_int(&tmp, str))
		return (1);
	v->x = tmp / 1000.0;
	if (parse_int(&tmp, str))
		return (1);
	v->y = tmp / 1000.0;
	if (parse_int(&tmp, str))
		return (1);
	v->z = tmp / 1000.0;
	return (0);
}

int		parse_color(unsigned *c, char **str)
{
	unsigned tmp;

	if (parse_int((int *)&tmp, str))
		return (1);
	*c += (tmp << 16) & 0xff0000;
	if (parse_int((int *)&tmp, str))
		return (1);
	*c += (tmp << 8) & 0xff00;
	if (parse_int((int *)&tmp, str))
		return (1);
	*c += tmp & 0xff;
	return (0);
}

void	parse_cam(t_al *al, char *str)
{
	int tmp;

	*str == ' ' ? str++ : 0;
	if (parse_v3(&al->cam.pos, &str))
		ft_dprintf(2, "Error parsing camera position [>%c<%s]\n", *str, str + 1);
	if (ft_strncmp("o ", str, 2))
		return ;
	str += 2;
	if (parse_v3(&al->cam.or, &str))
		ft_dprintf(2, "Error parsing camera orientation [>%c<%s]\n", *str, str + 1);
	normv3(&al->cam.or);
	if (ft_strncmp("f ", str, 2))
		return ;
	str += 2;
	parse_int(&tmp, &str);
	tmp = (tmp % 180);
	al->fovh = tan(tmp * M_PI / 360);
	al->fovv = al->fovh * WIN_SIZEY / WIN_SIZEX;
	/*ft_printf("cam [%.2f,%.2f,%.2f] or [%.2f,%.2f,%.2f] fov:[%.4f,%.4f]\n",
	al->cam.pos.x / (double)UINT32_MAX,
	al->cam.pos.y / (double)UINT32_MAX,
	al->cam.pos.z / (double)UINT32_MAX,
	al->cam.or.x / (double)UINT32_MAX,
	al->cam.or.y / (double)UINT32_MAX,
	al->cam.or.z / (double)UINT32_MAX,
	al->fovh / (double)UINT32_MAX,
	al->fovv / (double)UINT32_MAX);*/
}

void		parse_light(t_al *al, char *str)
{
	t_obj	*l;
	int		tmp;

	l = al->light + al->nb_light;
	if (parse_v3(&l->co.pos, &str))
		ft_dprintf(2, "Error parsing light position [>%c<%s]\n", *str, str + 1);
	if (ft_strncmp("i ", str, 2))
		return ;
	str += 2;
	parse_int(&tmp, &str);
	l->size = tmp;
	al->nb_light++; 
	/*ft_printf("light [%f,%f,%f] intensity %llu\n",
	l->co.pos.x / (double)UINT32_MAX,
	l->co.pos.y / (double)UINT32_MAX,
	l->co.pos.z / (double)UINT32_MAX,
	0,0,0, l->size);*/
}
