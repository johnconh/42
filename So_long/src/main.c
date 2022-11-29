/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:27:08 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/29 16:45:18 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static void	ft_initgame(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_size = 0;
	game->img = NULL;
	game->mov = 0;
	game->rupias = 0;
	game->link = 0;
	game->exit = 0;
	game->link_pos = 0;
	game->rupias_pos = 0;
	game->exit_pos = 0;
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
}