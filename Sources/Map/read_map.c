/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:20:17 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/13 23:43:53 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int			open_map(const char *path)
{
	int				ret;

	if (!path)
		ft_crash("Bad path provided!\n");
	if (check_file(path, IS_E) <= 0)
		ft_crash("No such file - %s!\n", path);
	if ((ret = open(path, O_RDONLY)) < 0)
		ft_crash("Can't open that file - %s!\n", path);
	if (!check_file(path, IS_R))
		ft_crash("Can't read from that file - %s!\n", path);
	if (check_file(path, IS_D))
		ft_crash("It's a directory - %s!\n", path);
	return (ret);
}

static int			is_wall(const char c)
{
	return (c == CHAR_WALL_REG);
}

static void			check_line(const char *line, const int h, t_wolf *wolf)
{
	register int	i;
	char			c;

	i = -1;
	while (line[++i])
	{
		c = line[i];
		if (c != CHAR_PLAYER && c != CHAR_EMPTY && c != CHAR_WALL_REG)
			ft_crash("Map error on [%d] line: unknown symbol!", h);
		if (c == CHAR_PLAYER)
		{
			wolf->player.x = i * MAP_SCALE;
			wolf->player.y = (h - 1) * MAP_SCALE;
		}
	}
}

static void			check_map(char **map, t_wolf *wolf)
{
	register int	h;
	register int	i;
	char			*line;
	int				player;

	i = -1;
	player = 0;
	line = map[0];
	while (!(h = 0) && line[++i])
		if (!is_wall(line[i]))
			ft_crash("Map error on [%d] line: "WALL_ERROR, h + 1);
	while (map[++h + 1])
	{
		if (!is_wall(map[h][0]) || !is_wall(map[h][ft_strlen(map[h]) - 1]))
			ft_crash("Map error on [%d] line: "WALL_ERROR, h + 1);
		check_line(map[h], h + 1, wolf);
		player += ft_char_count(map[h], CHAR_PLAYER);
	}
	line = map[h];
	i = -1;
	while (line[++i])
		if (!is_wall(line[i]))
			ft_crash("Map error on [%d] line: "WALL_ERROR, h + 1);
	if (player != 1)
		ft_crash("Map error: there have to be one player on map!");
}

void				read_map(const char *path, t_wolf *wolf)
{
	int				h;
	int				fd;
	char			*line;
	char			**map;

	h = 0;
	map = NULL;
	line = NULL;
	fd = open_map(path);
	while (get_nl(fd, &line) == 1)
	{
		h++;
		if (ft_strlen(line) > wolf->map_w)
			wolf->map_w = ft_strlen(line);
		map = add_to_text(map, line);
	}
	if (!line || !*line)
		ft_crash("Path [%s] is empty!", path);
	check_map(map, wolf);
	wolf->map = map;
	wolf->map_h = h;
}
