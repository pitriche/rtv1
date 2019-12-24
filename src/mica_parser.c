/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mica_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:21:47 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/22 21:43:40 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
