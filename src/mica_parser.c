/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mica_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:21:47 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/20 16:08:41 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		parse_int(int *nb, char **str)
{
	*nb = ft_atoi(*str);
	printf("AAAAA [%d][%s]\n", *nb, *str);
	**str == '-' ? *str++ : 0;
	while (ft_isdigit(**str))
		*str++;
	if (!ft_isspace(**str) && **str)
		return (1);
	return (0);
}

void	parse_cam(t_al *al, char *str)
{
	int tmp;

	*str == ' ' ? str++ : 0;
	ft_printf("str  [>%s<]\n", str);
	parse_int(&tmp, &str);
	ft_printf("1>%d\n", tmp);
	al->cam.pos.x = (((t_s64)tmp) << 32) / 1000;
	parse_int(&tmp, &str);
	ft_printf("2>%d\n", tmp);
	al->cam.pos.y = (((t_s64)tmp) << 32) / 1000;
	parse_int(&tmp, &str);
	ft_printf("3>%d\n", tmp);
	al->cam.pos.y = (((t_s64)tmp) << 32) / 1000;
	ft_printf("cam [%.2f,%.2f,%.2f]\n", al->cam.pos.x, al->cam.pos.y, al->cam.pos.z);
}

void	parse_light(t_al *al, char *str)
{
	(void)al;
	ft_printf("light line [%s]\n", str);
}

void	parse_sphere(t_al *al, char *str)
{
	(void)al;
	ft_printf("sphere line [%s]\n", str);
}

void	parse_plane(t_al *al, char *str)
{
	(void)al;
	ft_printf("plane line [%s]\n", str);
}

void	parse_cone(t_al *al, char *str)
{
	(void)al;
	ft_printf("cone line [%s]\n", str);
}

void	parse_cylinder(t_al *al, char *str)
{
	(void)al;
	ft_printf("cylinder line [%s]\n", str);
}

void	parse_line(t_al *al, char *str)
{
	if (str[0] == 'c' && str[1] == 'a')
		parse_cam(al, str + 2);
	else if (str[0] == 's' && str[1] == 'p')
		parse_sphere(al, str + 2);
	else if (str[0] == 'p' && str[1] == 'l')
		parse_plane(al, str + 2);
	else if (str[0] == 'c' && str[1] == 'y')
		parse_cylinder(al, str + 2);
	else if (str[0] == 'c' && str[1] == 'o')
		parse_cone(al, str + 2);
	else if (str[0] == 'l' && str[1] == ' ')
		parse_light(al, str + 2);
	else
		ft_printf("Invalid identifier on line [%s]\n", str);
}

void	mica_parser(t_al *al, char *str)
{
	char	*buf;
	int		ret;
	int		fd;

	if ((fd = open(str, O_RDONLY)) < 0)
		exit(ft_dprintf(2, "Can't open [%s]\n", str));
	while ((ret = get_next_line(fd, &buf)))
	{
		ret == -1 ? exit(0) : 0;
		if (*buf != '#' && *buf)
			parse_line(al, buf);
	}
	ft_printf("Parsed %s successfully !\n", str);
	close(fd);
}
