/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:27:08 by jdasilva          #+#    #+#             */
/*   Updated: 2022/12/16 12:30:37 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static void	ft_startgame(t_game *game)
{
	int	x;
	int	y;

	x = ft_strlen(game->map[0]) - 1;
	y = game->map_size;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_end_game(game);
	game->win = mlx_new_window(game->mlx, x * 16, y * 16, "so_long");
	if (game->win == NULL)
		ft_end_game(game);
	ft_places_imgs(game);
	mlx_hook(game->win, 2, (1L << 1),  ft_key_hook, game);
	mlx_hook(game->win, 17, 1L << 17, ft_end_game, game);
	mlx_loop(game->mlx);
}

static void	ft_initgame(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_size = 0;
	game->mov = 0;
	game->rupias = 0;
	game->link = 0;
	game->exit = 0;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		exit (-1);
	ft_initgame(game);
	ft_getmap(argv[1], game);
	ft_checkmap(game);
	ft_startgame(game);
	return (0);
}
