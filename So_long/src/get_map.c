/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:35:48 by jdasilva          #+#    #+#             */
/*   Updated: 2022/12/03 19:41:05 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static void	ft_check_extension(const char *map, const char *ext)
{
	int len;

	if	(!map)
	{
		write(2, "No hay mapa", 11);
		exit(-1);
	}
	len = ft_strlen(map) - 4;
	while (*(map + len) && *ext)
	{
		if (*(map + len) != *ext)
		{
			write(2, "no es extension .ber", 20);
			exit (-1);
		}
		len++;
		ext++;
	}
}

static void	ft_save_map(int fd, char **map)
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
		else if (buff[0] == '\0')
			cont--;
	}
	return (cont);
}

void	ft_getmap(char *map, t_game *game)
{
	int	fd;
	
	ft_check_extension(map, ".ber");
	fd = open(map, O_RDONLY);
	if (fd <= 0)
		exit (-1);
	game->map_size = ft_map_size(fd);
	close(fd);
	game->map = (char **)malloc(sizeof(char *) * (game->map_size + 1));
	fd = open(map, O_RDONLY);
	if (fd <= 0)
		exit (-1);
	ft_save_map(fd, game->map);
	close(fd);
}
