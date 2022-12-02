/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:34:15 by jdasilva          #+#    #+#             */
/*   Updated: 2022/12/02 19:42:09 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static void ft_link_position(int i, int j, t_game *game)
{
	game->link_pos[0] = i;
	game->link_pos[1] = j;
	game->link++;
}

static void	ft_checkelements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while(game->map[i][++j] != '\n')
		{
			if(game->map[i][j] != '0' && game->map[i][j] != '1'\
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'\
					&& game->map[i][j] != 'P')
			{
				printf("4entra");
				ft_invalid_map(game);
			}
			if(game->map[i][j] == 'C')
				game->rupias++;
			if(game->map[i][j] == 'E')
				game->exit++;
			if(game->map[i][j] == 'P')
				ft_link_position(i, j, game);
		}
	}
	if (game->rupias == 0 || game->exit != 1 || game->link != 1)
		ft_invalid_map(game);
}

static void	ft_checkwalls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (*(*(game->map + i) + ++j))
	{
		if ((game->map[i][j]!= '1') && (game->map[i][j] != '\n'))
		{
			printf("1entra");
			ft_invalid_map(game);
		}
	}
	while (game->map_size - 1 > ++i)
	{
		if (game->map[i][0] != '1' || game->map[i][ft_strlen(game->map[i]) - 2] != '1')
		{
			printf("2entra: %c", game->map[i][ft_strlen(game->map[i]) - 2]);
			ft_invalid_map(game);
		}
	}
	j = -1;
	while (*(*(game->map + i) + ++j))
	{
		if ((game->map[i][j]!= '1') && (game->map[i][j] != '\n'))
		{
			printf("3entra");
			ft_invalid_map(game);
		}
	}
}

static void ft_checkrectangle(t_game *game)
{
	size_t	i;
	size_t	width;
	
	i = 0;
	width = ft_strlen(*(game->map + i));
	
	while (*(game->map + i))
	{
		if (ft_strlen(*(game->map + i)) != width)
			ft_invalid_map(game);
		i++;
	}
}

void	ft_checkmap(t_game *game)
{
	ft_checkrectangle(game);
	ft_checkwalls(game);
	ft_checkelements(game);
}