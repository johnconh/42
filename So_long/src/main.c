/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:27:08 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/30 21:30:32 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static void ft_startgame(t_game *game)
{
	int x;
	int y;
	
	x = ft_strlen(game->map[0] - 1);
	y = game->map_size;
	game->mlx = mlx_init();
	if(game->mlx == NULL)
		ft_exit_and_free;
	game->win = mlx_new_window(game->mlx, x * 16, y * 16, "so_long");
	if(game->win == NULL)
		ft_exit_and_free;
	ft_places_imgs(game->map, game);
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

int main (int argc, char **argv)
{
	t_game *game;

	if(argc != 2)
		return (0);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		exit (-1);
	ft_initgame(game);
	ft_getmap(argv[1], game);
	ft_checkmap(game);
	ft_startgame(game); 
}