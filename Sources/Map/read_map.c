/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:20:17 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/21 23:12:44 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int			open_map(const char *path)
{
	int				ret;

	if (!path)
		ft_crash("Bad path provided!");
	if (check_file(path, IS_E) <= 0)
		ft_crash("No such file - %s!", path);
	if ((ret = open(path, O_RDONLY)) < 0)
		ft_crash("Can't open that file - %s!", path);
	if (!check_file(path, IS_R))
		ft_crash("Can't read from that file - %s!", path);
	if (check_file(path, IS_D))
		ft_crash("It's a directory - %s!", path);
	return (ret);
}

static int			is_wall(const char c)
{
	return (c >= CHAR_WALL_1 && c < CHAR_WALLS_END);
}

static void			check_line(char *line, const int h, t_player *player)
{
	register int	i;
	char			c;

	i = -1;
	while (line[++i])
	{
		c = line[i];
		if (!is_wall(c) && c != CHAR_PLAYER && c != CHAR_EMPTY)
			ft_crash("Map error on [%d] line: unknown symbol - [%c]!",
					h + 1, c);
		if (c == CHAR_PLAYER)
		{
			player->x = i;
			player->y = h;
			line[i] = CHAR_EMPTY;
		}
	}
}

static void			check_map(char **map, t_player *player)
{
	register int	h;
	register int	i;
	char			*line;
	int				player_n;

	i = -1;
	player_n = 0;
	line = map[0];
	while (!(h = 0) && line[++i])
		if (!is_wall(line[i]))
			ft_crash("Map error on [%d] line: "WALL_ERROR, h + 1);
	while (map[++h + 1])
	{
		if (!is_wall(map[h][0]) || !is_wall(map[h][ft_strlen(map[h]) - 1]))
			ft_crash("Map error on [%d] line: "WALL_ERROR, h + 1);
		player_n += ft_char_count(map[h], CHAR_PLAYER);
		check_line(map[h], h, player);
	}
	line = map[h];
	i = -1;
	while (line && line[++i])
		if (!is_wall(line[i]))
			ft_crash("Map error on [%d] line: "WALL_ERROR, h + 1);
	if (player_n != 1)
		ft_crash("Map error: there have to be one player on map!");
}

void				read_map(const char *path, t_map *map_s, t_player *player)
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
		if (ft_strlen(line) > map_s->map_w)
			map_s->map_w = ft_strlen(line);
		map = add_to_text(map, line);
	}
	close(fd);
	if (!line || !*line)
		ft_crash("Path [%s] is empty!", path);
	check_map(map, player);
	map_s->map = map;
	map_s->map_h = h;
	map_s->rect_w = WIDTH_H / map_s->map_w / 2 / (WIDTH / HEIGHT);
	map_s->rect_h = HEIGHT_H / map_s->map_h / 2;
}
