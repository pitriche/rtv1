/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changuy <changuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:45:14 by pitriche          #+#    #+#             */
/*   Updated: 2019/12/25 20:55:21 by changuy          ###   ########.fr       */
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
# include <fcntl.h>
# include <math.h>

/*
** DEFINES #####################################################################
*/

# define WIN_TITLE "Minecraft"
# define WIN_SIZEX 1270
# define WIN_SIZEY 720

# define EV_KEY_PRESS	2
# define EV_KEY_RELEA	3
# define EV_CLOSE_WIN	17

# define MAX_OBJ	69420
# define MAX_LIGHT	420

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

typedef struct	s_v3
{
	double	x;
	double	y;
	double	z;
}				t_v3;

typedef struct	s_co
{
	t_v3	pos;
	t_v3	or;
}				t_co;

typedef struct	s_cam
{
	t_v3	pos;
	t_v3	or;
	t_v3	up;

	double	fovx;
	double	fovy;
	t_v3	inc_camx;
	t_v3	inc_camy;

	t_v3	vec[WIN_SIZEY][WIN_SIZEX];
}				t_cam;

typedef struct	s_obj
{
	t_type		type;
	t_co		co;
	double		size;
	double		angle;
	unsigned	color;
}				t_obj;

/*
** hit indicates a hit or not, use to compensate the lack of pointer to return
*/

typedef struct	s_rthit
{
	int			hit;

	t_v3		pos;
	t_v3		normal;
	unsigned	color;
	double		dist;
	double		lux;//lumen
}				t_rthit;

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

	t_cam			c;

	unsigned		nb_obj;
	t_obj			*obj;

	unsigned		nb_light;
	t_obj			*light;

	unsigned long	curr_time;
	unsigned long	last_time;
	unsigned long	tgt_time;
	unsigned		dtime;
}				t_al;

/*
** PROTOTYPES ##################################################################
*/

void			init(t_al *al, char *str);
void			render(t_al *al);
void			mica_parser(t_al *al, char *str);

int				func_loop(t_al *al);

void			gen_camera(t_cam *c);

/*
** maths 
*/

void			normv3(t_v3 *v);
void			cpv3p(t_v3 *v, t_v3 v1, t_v3 v2);
t_v3			cpv3(t_v3 v1, t_v3 v2);
int				are_parallel(t_v3 v1, t_v3 v2);
void			assign_v3(t_v3 *v, double x, double y, double z);
void			mult_v3p(t_v3 *v, double x);
t_v3			mult_v3(t_v3 v, double x);
void			add_v3p(t_v3 *v, t_v3 v1, t_v3 v2);
t_v3			sub_v3(t_v3 v1, t_v3 v2);
double			dpv3(t_v3 v1, t_v3 v2);

/*
** parse
*/

void			parse_light(t_al *al, char *str);
void			parse_cam(t_al *al, char *str);
int				parse_color(unsigned *c, char **str);
int				parse_v3(t_v3 *v, char **str);
int				parse_int(int *nb, char **str);
void			parse_sphere(t_al *al, char *str);
void			parse_plan(t_al *al, char *str);
void			parse_cone(t_al *al, char *str);
void			parse_cylinder(t_al *al, char *str);
void			parse_line(t_al *al, char *str);

#endif
