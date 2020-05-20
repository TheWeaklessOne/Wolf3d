/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_symbol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 23:44:58 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/20 00:09:14 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int					check_for_symbol(const char c, const t_map map)
{
	register int	w;
	register int	h;

	h = -1;
	while (++h < map.map_h && (w = -1))
		while (++w < map.map_w)
			if (map.map[h][w] == c)
				return (1);
	return (0);
}
