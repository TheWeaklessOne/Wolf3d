/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:36:50 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/20 15:40:29 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				time_start(void)
{
	time()->start = SDL_GetTicks();
}

t_time				*time(void)
{
	static t_time	ret = (t_time){0};

	return (&ret);
}
