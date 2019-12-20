/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:45:14 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/20 15:00:17 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

/*
** INCLUDES ####################################################################
*/

# include "libft.h"
# include "mlx.h"

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

/*
** DEFINES #####################################################################
*/

# define WIN_TITLE "Minecraft"
# define WIN_SIZEX 1270
# define WIN_SIZEY 720

# define EV_KEY_PRESS	2
# define EV_KEY_RELEA	3
# define EV_CLOSE_WIN	17

/*
** TYPEDEFS ####################################################################
*/

/*
** these are to be used as fixed point real numbers
*/

typedef	uint64_t	t_u64;
typedef int64_t		t_s64;

/*
** ENUMS #######################################################################
*/

typedef enum	e_type
{
	SPHERE,
	PLAN,
	CYLINDER,
	CONE
}				t_type;

/*
** STRUCTURES ##################################################################
*/

/*
** 3d vector using signed fixed point 64 bits real number
*/

typedef struct	s_v3s
{
	t_s64	x;
	t_s64	y;
	t_s64	z;
}				t_v3s;

typedef struct	s_co
{
	t_v3s	pos;
	t_v3s	or;
}				t_co;

typedef struct	s_obj
{
	t_co		co;
	t_type		type;
	t_u64		size;
	t_u64		angle;
	unsigned	color;
}				t_obj;

/*
** fovh: projected screen width at 1 meter
** fovv: projected screen height at 1 meter
*/

typedef struct	s_al
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned		*pix;

	unsigned		fps;

	t_u64			fovh;
	t_u64			fovv;
	t_co			cam;

	unsigned		nb_obj;
	t_obj			*obj;

	unsigned		nb_light;
	t_v3s			*light;

	unsigned long	curr_time;
	unsigned long	last_time;
	unsigned long	tgt_time;
	unsigned		dtime;
}				t_al;

/*
** PROTOTYPES ##################################################################
*/

void			init(t_al *al);
void			render(t_al *al);
void			mica_parser(t_al *al, char *str);

int				func_loop(t_al *al);

#endif
