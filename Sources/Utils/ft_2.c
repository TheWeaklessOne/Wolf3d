/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 18:10:32 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/19 16:20:36 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void				lengths(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char					*ft_itoa(int n)
{
	size_t				len;
	int					weight;
	size_t				cur;
	char				*str;

	lengths(n, &len, &weight);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	cur = 0;
	if (n < 0)
	{
		str[cur] = '-';
		cur++;
	}
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		str[cur++] = -(n / weight % 10) + 48;
		weight /= 10;
	}
	str[cur] = '\0';
	return (str);
}

int						ft_free_r(void *to_free)
{
	if (!to_free)
		return (1);
	free(to_free);
	return (0);
}

char					*ft_strjoin(char const *s1, char const *s2,
										const int to_free)
{
	char				*str;
	register size_t		i;
	register size_t		k;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1)))
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i])
		str[k++] = s1[i++];
	i = 0;
	while (s2[i])
		str[k++] = s2[i++];
	str[k] = '\0';
	(to_free == 1) ? free((void*)s1) : 0;
	(to_free == 2) ? free((void*)s2) : 0;
	if (to_free == 3)
	{
		free((void*)s1);
		free((void*)s2);
	}
	return (str);
}

int						ft_char_count(const char *str, const char c)
{
	register int		i;
	int					ret;

	i = -1;
	ret = 0;
	while (str[++i])
		if (str[i] == c)
			ret++;
	return (ret);
}
