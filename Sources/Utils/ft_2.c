/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 18:10:32 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/17 20:18:28 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int					ft_char_count(const char *str, const char c)
{
	register int	i;
	int				ret;

	i = -1;
	ret = 0;
	while (str[++i])
		if (str[i] == c)
			ret++;
	return (ret);
}
