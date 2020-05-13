/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:15:24 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/13 15:15:27 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void					*ft_malloc(const size_t size)
{
	char				*ret;
	size_t				i;

	if (!(ret = (char*)malloc(size)))
		ft_crash("Malloc error");
	i = 0;
	while (i < size)
		ret[i++] = 0;
	return ((void*)ret);
}

void					ft_crash(const char *msg, ...)
{
	va_list				args;

	va_start(args, msg);
	vfprintf(stderr, msg, args);
	va_end(args);
	exit(msg ? msg[0] : 255);
}
