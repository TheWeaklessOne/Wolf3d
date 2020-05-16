/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:06:02 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/16 19:17:47 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF_H
# define WOLF3D_WOLF_H

# if defined(unix) || defined(__unix__) || defined(__unix)
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_image.h>
# else
#  include <SDL.h>
#  include <SDL_image.h>
# endif

# include <fcntl.h>
# include <float.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "list.h"

# define WIDTH			1920
# define HEIGHT			1000

# define WIDTH_H		(WIDTH / 2)
# define HEIGHT_H		(HEIGHT / 2)

# define BUFF_SIZE		20

# define IS_E			0
# define IS_R			1
# define IS_W			2
# define IS_X			4
# define IS_D			8

# define WALL_ERROR		"there have to be walls around all the map!"

# define FLOOR_COLOR	0x83918e
# define ROOF_COLOR		0xb4e3f0

enum					e_chars
{
	CHAR_PLAYER = '0',
	CHAR_EMPTY = ' ',
	CHAR_WALL_1 = '1',
	CHAR_WALL_2 = '2',
	CHAR_WALL_3 = '3',
	CHAR_WALLS_N
};

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

typedef struct			s_wolf
{
	t_map				map;
	t_player			player;
	unsigned			show_map;
}						t_wolf;

typedef struct			s_sdl
{
	SDL_Window			*win;
	SDL_Renderer		*ren;
	int					running;
	SDL_Texture			*texture;
	unsigned			pixels[WIDTH * HEIGHT];
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

void					wolf_init(t_wolf *wolf, int argc, char *argv[]);

void					read_map(const char *path, t_map *map_s,
									t_player *player);
char					**add_to_text(char **text, char *add);
int						check_file(const char *file, unsigned check);

void					render_clear(unsigned pixels[WIDTH * HEIGHT]);

void					*ft_malloc(size_t size);
int						ft_strlen(const char *str);
int						get_nl(int fd, char **line);
int						ft_char_count(const char *str, char c);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);

void					move_forward(t_wolf *wolf, const int *keys);
void					move_backward(t_wolf *wolf, const int *keys);
void					angle_left(t_wolf *wolf, const int *keys);
void					angle_right(t_wolf *wolf, const int *keys);

void					sdl_init(t_sdl *sdl);
void					sdl_quit(t_sdl *sdl);
void					manage_keys(t_sdl *sdl, t_wolf *wolf);
void					manage_event(SDL_Event e, t_sdl *sdl, t_wolf *wolf);

#endif
