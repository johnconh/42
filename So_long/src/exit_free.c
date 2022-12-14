/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:35:47 by jdasilva          #+#    #+#             */
/*   Updated: 2022/12/12 16:10:12 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static void	ft_free_map(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i])
			free(str[i]);
	}
	free(str);
}

void	ft_invalid_map(t_game *game)
{
	write(2, "Error: Invalid map\n", 19);
	ft_exit_and_free(game);
}

void	ft_exit_and_free(t_game *game)
{
	if (game->map)
		ft_free_map(game->map);
	free(game);
	exit(-1);
}

int	ft_end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	ft_exit_and_free(game);
	return (0);
}
