/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:11:46 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/13 16:54:53 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			move_up(t_wolf *wolf)
{
	wolf->player.y--;
}

void			move_down(t_wolf *wolf)
{
	wolf->player.y++;
}

void			move_left(t_wolf *wolf)
{
	wolf->player.x--;
}

void			move_right(t_wolf *wolf)
{
	wolf->player.x++;
}
