/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mica_parser2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:21:47 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/24 15:46:58 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_sphere(t_al *al, char *str)
{
	t_obj	*sp;
	int		tmp;

	sp = al->obj + al->nb_obj;
	sp->type = SPHERE;
	*str == ' ' ? str++ : 0;
	if (parse_v3(&sp->co.pos, &str))
		ft_dprintf(2, "Error parsing sphere position [>%c<%s]\n", *str, str + 1);
	if (ft_strncmp("s ", str, 2))
		return ;
	str += 2;
	parse_int(&tmp, &str);
	sp->size = tmp / 1000.0;
	if (ft_strncmp("c ", str, 2))
		return ;
	str += 2;
	if (parse_color(&sp->color, &str))
		ft_dprintf(2, "Error parsing sphere color [>%c<%s]\n", *str, str + 1);
	al->nb_obj++;
	/*ft_printf("Sphere [%.2f,%.2f,%.2f] size %.2f color>%#x\n",
	sp->co.pos.x / (double)UINT32_MAX,
	sp->co.pos.y / (double)UINT32_MAX,
	sp->co.pos.z / (double)UINT32_MAX,
	0,0,0, sp->size / (double)UINT32_MAX, 0,
	sp->color);*/
}

void	parse_plan(t_al *al, char *str)
{
	t_obj	*pl;

	pl = al->obj + al->nb_obj;
	pl->type = PLAN;
	*str == ' ' ? str++ : 0;
	if (parse_v3(&pl->co.pos, &str))
		ft_dprintf(2, "Error parsing plan position [>%c<%s]\n", *str, str + 1);
	if (ft_strncmp("o ", str, 2))
		return ;
	str += 2;
	if (parse_v3(&pl->co.or, &str))
		ft_dprintf(2, "Error parsing plan orientation [>%c<%s]\n", *str, str + 1);
	normv3(&pl->co.or);
	if (ft_strncmp("c ", str, 2))
		return ;
	str += 2;
	if (parse_color(&pl->color, &str))
		ft_dprintf(2, "Error parsing plan color [>%c<%s]\n", *str, str + 1);
	al->nb_obj++;
	/*ft_printf("Plan [%.2f,%.2f,%.2f] or [%.3f,%.3f,%.3f] color>%#x\n",
	pl->co.pos.x / (double)UINT32_MAX,
	pl->co.pos.y / (double)UINT32_MAX,
	pl->co.pos.z / (double)UINT32_MAX,
	pl->co.or.x / (double)UINT32_MAX,
	pl->co.or.y / (double)UINT32_MAX,
	pl->co.or.z / (double)UINT32_MAX,
	0,0,0,0,0,0,
	pl->color);*/
}

void	parse_cone(t_al *al, char *str)
{
	t_obj		*co;
	unsigned	tmp;

	co = al->obj + al->nb_obj;
	co->type = CONE;
	*str == ' ' ? str++ : 0;
	if (parse_v3(&co->co.pos, &str))
		ft_dprintf(2, "Error parsing cone position [>%c<%s]\n", *str, str + 1);
	if (ft_strncmp("o ", str, 2))
		return ;
	str += 2;
	if (parse_v3(&co->co.or, &str))
		ft_dprintf(2, "Error parsing cone orientation [>%c<%s]\n", *str, str + 1);
	normv3(&co->co.or);
	if (ft_strncmp("a ", str, 2))
		return ;
	str += 2;
	parse_int((int *)&tmp, &str);
	co->size = tmp % 360;
	if (ft_strncmp("c ", str, 2))
		return ;
	str += 2;
	if (parse_color(&co->color, &str))
		ft_dprintf(2, "Error parsing cone color [>%c<%s]\n", *str, str + 1);
	al->nb_obj++;
	
	/*ft_printf("Cone [%.2f,%.2f,%.2f] or [%.3f,%.3f,%.3f] angle>%llu deg color>%#x\n",
	co->co.pos.x / (double)UINT32_MAX,
	co->co.pos.y / (double)UINT32_MAX,
	co->co.pos.z / (double)UINT32_MAX,
	co->co.or.x / (double)UINT32_MAX,
	co->co.or.y / (double)UINT32_MAX,
	co->co.or.z / (double)UINT32_MAX,
	0,0,0,0,0,0,
	co->size,
	co->color);*/
}

void	parse_cylinder(t_al *al, char *str)
{
	t_obj		*cy;
	unsigned	tmp;

	cy = al->obj + al->nb_obj;
	cy->type = CYLINDER;
	*str == ' ' ? str++ : 0;
	if (parse_v3(&cy->co.pos, &str))
		ft_dprintf(2, "Error parsing cylinder position [>%c<%s]\n", *str, str + 1);
	if (ft_strncmp("o ", str, 2))
		return ;
	str += 2;
	if (parse_v3(&cy->co.or, &str))
		ft_dprintf(2, "Error parsing cylinder orientation [>%c<%s]\n", *str, str + 1);
	normv3(&cy->co.or);
	if (ft_strncmp("s ", str, 2))
		return ;
	str += 2;
	parse_int((int *)&tmp, &str);
	cy->size = tmp / 1000.0;
	if (ft_strncmp("c ", str, 2))
		return ;
	str += 2;
	if (parse_color(&cy->color, &str))
		ft_dprintf(2, "Error parsing cylinder color [>%c<%s]\n", *str, str + 1);
	al->nb_obj++;
	/*ft_printf("Cylinder [%.2f,%.2f,%.2f] or [%.3f,%.3f,%.3f] size>%.3f color>%#x\n",
	cy->co.pos.x / (double)UINT32_MAX,
	cy->co.pos.y / (double)UINT32_MAX,
	cy->co.pos.z / (double)UINT32_MAX,
	cy->co.or.x / (double)UINT32_MAX,
	cy->co.or.y / (double)UINT32_MAX,
	cy->co.or.z / (double)UINT32_MAX,
	cy->size / (double)UINT32_MAX,
	0,0,0,0,0,0,0,
	cy->color);*/
}

void	parse_line(t_al *al, char *str)
{
	if (str[0] == 'c' && str[1] == 'a')
		parse_cam(al, str + 2);
	else if (str[0] == 's' && str[1] == 'p')
		parse_sphere(al, str + 2);
	else if (str[0] == 'p' && str[1] == 'l')
		parse_plan(al, str + 2);
	else if (str[0] == 'c' && str[1] == 'y')
		parse_cylinder(al, str + 2);
	else if (str[0] == 'c' && str[1] == 'o')
		parse_cone(al, str + 2);
	else if (str[0] == 'l' && str[1] == ' ')
		parse_light(al, str + 2);
	else
		ft_printf("Invalid identifier on line [%s]\n", str);
}
