/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 20:40:04 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/20 16:10:21 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		add_dist_or_step(t_wolf *wolf, const int *keys)
{
	if (keys[SDL_SCANCODE_LSHIFT])
	{
		if (wolf->ray_step > 0.0001)
		{
			wolf->ray_step /= 1.1;
			printf("Ray step now is [%lf]\n", wolf->ray_step);
		}
	}
	else if (wolf->ray_dist < 200)
	{
		wolf->ray_dist += 1;
		printf("Maximum ray distance now is [%u]\n", wolf->ray_dist);
	}
	fflush(0);
}

void		sub_dist_or_step(t_wolf *wolf, const int *keys)
{
	if (keys[SDL_SCANCODE_LSHIFT])
	{
		if (wolf->ray_step < 0.1)
		{
			wolf->ray_step *= 1.1;
			printf("Ray step now is [%lf]\n", wolf->ray_step);
		}
	}
	else if (wolf->ray_dist > 1)
	{
		wolf->ray_dist -= 1;
		printf("Maximum ray distance now is [%u]\n", wolf->ray_dist);
	}
	fflush(0);
}
