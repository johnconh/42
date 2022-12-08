/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:17:26 by jdasilva          #+#    #+#             */
/*   Updated: 2022/12/08 21:04:33 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void ft_floodfill(char **c_map, char p, t_point size, t_point p_link)
{
	
}

char **ft_copy_map(char **map, t_point size)
{
	char	**copy;
	int		x;
	int		y;
	
	copy = (char **)malloc(sizeof(char *) * size.y);
	y = -1;
	while(++y < size.y)
	{
		x = -1;
		copy[y] = (char *)malloc(sizeof(char) * size.x);
		while(map[y][++x])
			copy[y][x] = map[y][x];
	}
	return (copy);
}

void	ft_checkpath(t_game *game)
{
	char **c_map;
	char p;
	t_point size;
	t_point p_link;

	size.y = game->map_size;
	size.x = ft_strlen(game->map[0]);
	p_link.x = game->link_pos[1];
	p_link.y = game->link_pos[0];
	c_map = ft_copy_map(game->map, size);
	p = c_map[p_link.y][p_link.x];
	ft_floodfill(c_map, p, size, p_link);
}  