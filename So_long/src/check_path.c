/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:17:26 by jdasilva          #+#    #+#             */
/*   Updated: 2022/12/09 19:05:11 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static void	ft_free_c_map(char **c_map, t_point size)
{
	int	i;

	i = -1;
	while (++i < size.y)
		free(c_map[i]);
	free(c_map);
}

static void	ft_checkfloodfill(char **c_map, t_point size, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size.y)
	{
		j = -1;
		while (++j < size.x)
		{
			if (c_map[i][j] == 'E' || c_map[i][j] == 'C')
			{
				ft_free_c_map(c_map, size);
				ft_invalid_map(game);
			}
		}
	}
	ft_free_c_map(c_map, size);
}

static void	ft_floodfill(char **c_map, t_point size, int x, int y)
{
	if (c_map[y][x] != '1' && y < size.y && x < size.x)
	{
		if (c_map[y][x] == 'X')
			return ;
		c_map[y][x] = 'X';
		ft_floodfill(c_map, size, x, y + 1);
		ft_floodfill(c_map, size, x, y - 1);
		ft_floodfill(c_map, size, x + 1, y);
		ft_floodfill(c_map, size, x - 1, y);
	}
}

static char	**ft_copy_map(char **map, t_point size)
{
	char	**copy;
	int		x;
	int		y;

	copy = (char **)malloc(sizeof(char *) * size.y);
	y = -1;
	while (++y < size.y)
	{
		x = -1;
		copy[y] = (char *)malloc(sizeof(char) * size.x);
		while (map[y][++x])
			copy[y][x] = map[y][x];
	}
	return (copy);
}

void	ft_checkpath(t_game *game)
{
	char	**c_map;
	t_point	size;
	t_point	p_link;

	size.y = game->map_size;
	size.x = ft_strlen(game->map[0]);
	p_link.x = game->link_pos[1];
	p_link.y = game->link_pos[0];
	c_map = ft_copy_map(game->map, size);
	ft_floodfill(c_map, size, p_link.x, p_link.y);
	ft_checkfloodfill(c_map, size, game);
}
