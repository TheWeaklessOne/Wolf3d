/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:06:02 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/13 16:21:21 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF_H
#define WOLF3D_WOLF_H

# if defined(unix) || defined(__unix__) || defined(__unix)
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_image.h>
# else
#  include <SDL.h>
#  include <SDL_image.h>
# endif

# include <float.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "list.h"

# define WIDTH			1024
# define HEIGHT			540

typedef struct			s_wolf
{
	SDL_Rect			hero;
}						t_wolf;

typedef struct			s_sdl
{
	SDL_Window			*win;
	SDL_Renderer		*ren;
	int					running;
	SDL_Texture			*texture;
	unsigned			pixels[WIDTH * HEIGHT];
	void				(*do_key[SDL_NUM_SCANCODES])(t_wolf *wolf);
	int					keys[SDL_NUM_SCANCODES];
}						t_sdl;

void					*ft_malloc(size_t size);

void					move_up(t_wolf *wolf);
void					move_down(t_wolf *wolf);
void					move_left(t_wolf *wolf);
void					move_right(t_wolf *wolf);

void					sdl_init(t_sdl *sdl);
void					sdl_quit(t_sdl *sdl);
void					manage_keys(t_sdl *sdl, t_wolf *wolf);
void					manage_event(SDL_Event e, t_sdl *sdl);

#endif
