/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:46:58 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/13 17:48:56 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char				**add_to_text(char **text, char *add)
{
	register size_t	i;
	register size_t	len;
	char			**ret;

	i = 0;
	len = 0;
	if (text)
		while (text[len])
			len++;
	ret = ft_malloc(sizeof(char*) * (len + 2));
	while (i < len)
	{
		ret[i] = text[i];
		i++;
	}
	ret[i] = add;
	ret[i + 1] = NULL;
	text ? free(text) : NULL;
	return (ret);
}
