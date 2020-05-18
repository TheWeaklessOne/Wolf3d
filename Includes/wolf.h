/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:06:02 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/19 00:42:59 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF_H
# define WOLF3D_WOLF_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

# include <fcntl.h>
# include <float.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "list.h"
# include "structures.h"

void					wolf_init(t_wolf *wolf, int argc, char *argv[]);

void					read_map(const char *path, t_map *map_s,
									t_player *player);
char					**add_to_text(char **text, char *add);
int						check_file(const char *file, unsigned check);

void					walls_init(t_list **w, SDL_PixelFormat *fmt);
void					render_clear(unsigned pixels[WIDTH * HEIGHT]);
void					cast_rays(t_wolf wolf, double angle, int i,
									unsigned *pixels);

void					*ft_malloc(size_t size);
int						ft_strlen(const char *str);
int						get_nl(int fd, char **line);
int						ft_char_count(const char *str, char c);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);

void					add_dist(t_wolf *wolf, const int *keys);
void					sub_dist(t_wolf *wolf, const int *keys);
void					angle_left(t_wolf *wolf, const int *keys);
void					angle_right(t_wolf *wolf, const int *keys);
void					move_forward(t_wolf *wolf, const int *keys);
void					move_backward(t_wolf *wolf, const int *keys);

void					sdl_quit(t_sdl *sdl);
void					sdl_init(t_sdl *sdl, t_wolf *wolf);
void					manage_keys(t_sdl *sdl, t_wolf *wolf);
void					manage_event(SDL_Event e, t_sdl *sdl, t_wolf *wolf);
void					draw_rectangle(t_rect rect, unsigned color,
										unsigned  *pixels);
void					set_pixel(unsigned x, unsigned y, unsigned color,
									unsigned *pixels);

#endif
