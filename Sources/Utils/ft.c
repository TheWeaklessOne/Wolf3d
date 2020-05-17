/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:15:24 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/17 15:17:49 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	register size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		*((char*)dst + i) = *((char*)src + i);
		i++;
	}
	return (dst);
}

void				*ft_memchr(const void *s, int c, size_t n)
{
	register size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char*)s + i) == (unsigned char)c)
			return ((void*)s + i);
		i++;
	}
	return (0);
}

int					ft_strlen(const char *str)
{
	register size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void					*ft_malloc(const size_t size)
{
	char				*ret;
	register size_t		i;

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
	write(2, "\n", 1);
	exit(msg ? msg[0] : 255);
}
