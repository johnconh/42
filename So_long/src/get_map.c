/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:35:48 by jdasilva          #+#    #+#             */
/*   Updated: 2022/12/12 16:11:30 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static void	ft_controlread(char *map)
{
	int		fd;
	char	buff[42];
	int		r;

	fd = open(map, O_RDONLY);
	r = read(fd, buff, 41);
	if (r <= 0)
	{
		close(fd);
		write(2, "Error: Mapa vacio\n", 18);
		exit (-1);
	}
	close(fd);
}

static void	ft_check_extension(const char *map, const char *ext)
{
	int	len;

	if (!map)
	{
		write(2, "Error: No hay mapa\n", 19);
		exit(-1);
	}
	len = ft_strlen(map) - 4;
	while (*(map + len) && *ext)
	{
		if (*(map + len) != *ext)
		{
			write(2, "Error: no es extension .ber\n", 28);
			exit (-1);
		}
		len++;
		ext++;
	}
}

static void	ft_save_map(int fd, char **map, t_game *game)
{
	char	*str;
	int		i;

	str = get_next_line(fd);
	i = 0;
	map[i++] = str;
	while (str)
	{
		str = get_next_line(fd);
		map[i++] = str;
	}
	if (map[i - 2][ft_strlen(map[i - 2]) - 1] == '\n')
		game->map_size--;
}

static int	ft_map_size(int fd)
{
	int		cont;
	char	buff[2];
	int		c;

	cont = 1;
	c = 1;
	while (c)
	{
		c = read(fd, buff, 1);
		buff[c] = '\0';
		if (buff[0] == '\n')
			cont++;
	}
	return (cont);
}

void	ft_getmap(char *map, t_game *game)
{
	int	fd;

	ft_check_extension(map, ".ber");
	ft_controlread(map);
	fd = open(map, O_RDONLY);
	if (fd < 3)
		exit (-1);
	game->map_size = ft_map_size(fd);
	close(fd);
	game->map = (char **)malloc(sizeof(char *) * (game->map_size + 1));
	fd = open(map, O_RDONLY);
	if (fd < 3)
		exit (-1);
	ft_save_map(fd, game->map, game);
	close(fd);
}
