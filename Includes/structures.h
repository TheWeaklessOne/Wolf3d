/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 00:43:48 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/20 19:13:20 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_STRUCTURES_H
# define WOLF3D_STRUCTURES_H

# include "wolf.h"

# define WIDTH			1280
# define HEIGHT			720

# define WIDTH_H		640
# define HEIGHT_H		360

# define RAY_STEP_DEF	0.01
# define RAY_DIST_DEF	20

# define THREADS_N		16

# define ANIM_TIME		100

# define MIN_FRAME_TIME	16

# define WALL_ERROR		"there have to be walls around all the map!"

# define FLOOR_COLOR	0x83918e
# define ROOF_COLOR		0xb4e3f0

# define BUFF_SIZE		20

# define IS_E			0
# define IS_R			1
# define IS_W			2
# define IS_X			4
# define IS_D			8

# define ITOA_LOWER		0x0
# define ITOA_UPPER		0x1
# define ITOA_SIGNED	0x2
# define ITOA_GROUPED	0x4
# define ITOA_PLUS		0x8
# define ITOA_NOT_ONE	0x10
# define ITOA_ABC		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

enum					e_chars
{
	CHAR_PLAYER = '0',
	CHAR_EMPTY = ' ',
	CHAR_WALL_1 = '1',
	CHAR_WALL_2 = '2',
	CHAR_WALL_3 = '3',
	CHAR_WALL_4 = '4',
	CHAR_WALL_5 = '5',
	CHAR_WALL_6 = '6',
	CHAR_WALL_7 = '7',
	CHAR_WALLS_END,
	WALLS_N = CHAR_WALLS_END - CHAR_WALL_1
};

typedef struct			s_time
{
	Uint32				step;
	Uint32				delta;
	Uint32				since_frame;
}						t_time;

typedef struct			s_xy
{
	double				x;
	double				y;
}						t_xy;

typedef struct			s_rect
{
	unsigned			x;
	unsigned			y;
	unsigned			w;
	unsigned			h;
}						t_rect;

typedef struct			s_player
{
	double				x;
	double				y;
	double				a;
	double				fov;
}						t_player;

typedef struct			s_map
{
	char				**map;
	unsigned			map_w;
	unsigned			map_h;
	unsigned			rect_w;
	unsigned			rect_h;
}						t_map;

typedef struct			s_wall
{
	unsigned			frames;
	t_list				*textures;
}						t_wall;

typedef struct			s_wolf
{
	t_map				map;
	t_wall				*walls;
	t_player			player;
	unsigned			*pixels;
	unsigned			show_map;
	unsigned			ray_dist;
	double				ray_step;
}						t_wolf;

typedef struct			s_thread
{
	t_wolf				*wolf;
	unsigned			*pixels;
	unsigned			thread_n;
}						t_thread;

typedef struct			s_texture
{
	int					w;
	int					h;
	unsigned			*pixels;
}						t_texture;

typedef struct			s_sdl
{
	SDL_Window			*win;
	SDL_Surface			*surf;
	int					running;
	void				(*do_key[SDL_NUM_SCANCODES])
							(t_wolf *wolf, const int *keys);
	int					keys[SDL_NUM_SCANCODES];
}						t_sdl;

typedef struct			s_get_next_line
{
	char				*lp_cmp;
	char				*lp_prev;
	char				*line;
	size_t				line_count;
	size_t				interval;
	size_t				tmp;
	ssize_t				count;
	char				buffer[BUFF_SIZE];
}						t_get_next_line;

typedef struct			s_itoa
{
	char				*str;
	char				*start;
	char				*buffer;
	uintmax_t			value;
	uint_fast8_t		base;
	uint_fast8_t		option;
	uintmax_t			tmp;
	uint_fast8_t		b_op;
	uint_fast8_t		i;
	uint_fast8_t		count;
	char				*alphabet;
}						t_itoa;

#endif
