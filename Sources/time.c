/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 19:26:31 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/20 19:26:34 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_time				*ft_time(void)
{
	static t_time	ret = (t_time){0};

	return (&ret);
}
