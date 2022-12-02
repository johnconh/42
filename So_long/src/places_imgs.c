/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   places_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:23:27 by jdasilva          #+#    #+#             */
/*   Updated: 2022/12/02 16:50:34 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static void	ft_get_imgs(t_game *game)
{
	int	width;
	int	height;

	game->img[0] = mlx_xpm_file_to_image(game->mlx, "./sprites/suelo.xpm", \
		&width, &height);
	game->img[1] = mlx_xpm_file_to_image(game->mlx, "./sprites/roca.xpm", \
		&width, &height);
	game->img[2] = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm", \
		&width, &height);
	game->img[3] = mlx_xpm_file_to_image(game->mlx, "./sprites/rupia.xpm", \
		&width, &height);
	game->img[4] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/link_down.xpm", &width, &height);
	game->img[5] = mlx_xpm_file_to_image(game->mlx, "./sprites/link_up.xpm", \
		&width, &height);
	game->img[6] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/link_left.xpm", &width, &height);
	game->img[7] = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/link_right.xpm", &width, &height);
}

static void	ft_put_image(t_game *game, char *img , int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	ft_places_imgs(char **map, t_game *game)
{
	int	i;
	int	j;

	ft_get_imgs(game);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
				ft_put_image(game, game->img[0], j, i);
			if (map[i][j] == '1')
				ft_put_image(game, game->img[1], j, i);
			if (map[i][j] == 'E')
				ft_put_image(game, game->img[2], j, i);
			if (map[i][j] == 'C')
				ft_put_image(game, game->img[3], j, i);
			if (map[i][j] == 'P')
				ft_put_image(game, game->img[4], j, i);
		}
	}
}
