/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:06:02 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/20 17:09:02 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF_H
# define WOLF3D_WOLF_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_thread.h>

# include <stdio.h>
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

char					**add_to_text(char **text, char *add);
int						check_file(const char *file, unsigned check);
int						check_for_symbol(const char c, const t_map map);
void					read_map(const char *path, t_map *map_s,
									t_player *player);

void					walls_init(t_wall *walls, SDL_PixelFormat *fmt,
									const t_map map);
void					render_clear(unsigned pixels[WIDTH * HEIGHT]);
void					cast_rays(t_wolf *wolf, double angle, int i,
									unsigned *pixels);

char					*ft_itoa(int n);
void					*ft_malloc(size_t size);
int						ft_free_r(void *to_free);
int						ft_strlen(const char *str);
int						get_nl(int fd, char **line);
int						ft_char_count(const char *str, char c);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
char					*ft_strjoin(char const *s1, char const *s2,
										int to_free);

t_time					*ft_time(void);

void					angle_left(t_wolf *wolf, const int *keys);
void					angle_right(t_wolf *wolf, const int *keys);
void					move_forward(t_wolf *wolf, const int *keys);
void					move_backward(t_wolf *wolf, const int *keys);
void					add_dist_or_step(t_wolf *wolf, const int *keys);
void					sub_dist_or_step(t_wolf *wolf, const int *keys);

void					sdl_quit(t_sdl *sdl);
void					sdl_init(t_sdl *sdl, t_wolf *wolf);
void					manage_keys(t_sdl *sdl, t_wolf *wolf);
void					manage_event(SDL_Event e, t_sdl *sdl, t_wolf *wolf);
void					draw_rectangle(t_rect rect, unsigned color,
										unsigned  *pixels);
void					set_pixel(unsigned x, unsigned y, unsigned color,
									unsigned *pixels);

#endif
