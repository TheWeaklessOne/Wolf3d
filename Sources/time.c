/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 19:26:31 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/22 20:33:20 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				show_fps(const int show_fps, TTF_Font *font,
								SDL_Surface *win)
{
	static int		fps;
	char			*str;
	SDL_Rect		rect;
	SDL_Surface		*surf;
	static int		frames = 0;

	if (show_fps)
	{
		frames++;
		if (ft_time()->now - ft_time()->start > 1000)
		{
			fps = frames;
			frames = 0;
			ft_time()->start = ft_time()->now;
		}
		str = ft_itoa(fps);
		rect = (SDL_Rect){WIDTH - 100, HEIGHT - 75};
		surf = TTF_RenderText_Solid(font, str, (SDL_Color){252, 226, 5, 0});
		SDL_BlitSurface(surf, NULL, win, &rect);
		SDL_FreeSurface(surf);
		free(str);
	}
}

void				ft_time_init(void)
{
	ft_time()->start = SDL_GetTicks();
}

void				ft_time_update(void)
{
	ft_time()->now = SDL_GetTicks();
	ft_time()->delta = ft_time()->now - ft_time()->step;
	ft_time()->since_frame += ft_time()->delta;
}

t_time				*ft_time(void)
{
	static t_time	ret = (t_time){0};

	return (&ret);
}
