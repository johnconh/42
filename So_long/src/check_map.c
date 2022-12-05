/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:34:15 by jdasilva          #+#    #+#             */
/*   Updated: 2022/12/05 21:30:29 by jdasilva         ###   ########.fr       */
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
		while(game->map[i][++j])
		{
			if(game->map[i][j] != '0' && game->map[i][j] != '1'\
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'\
					&& game->map[i][j] != 'P' && game->map[i][j] != '\n')
			{
				printf("4entra\n");
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
	{
		printf("error:5\n");
		ft_invalid_map(game);
	}
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
			printf("error:1\n");
			ft_invalid_map(game);
		}
	}
	while (game->map_size - 1 > ++i)
	{
		if (game->map[i][0] != '1' || game->map[i][ft_strlen(game->map[i]) - 2] != '1')
		{
			printf("error:2\n");
			ft_invalid_map(game);
		}
	}
	j = -1;
	while (*(*(game->map + i) + ++j))
	{
		if ((game->map[i][j]!= '1') && (game->map[i][j] != '\n'))
		{
			printf("%s\n", game->map[i]);
			printf("error:3\n");
			ft_invalid_map(game);
		}
	}
}

static int ft_checkrectangle(t_game *game, size_t i, size_t j)
{
	size_t	map_line;

	map_line = ft_strlen(game->map[0]) - 1;
 	if (j != map_line  && (int)i != game->map_size - 1)
	{
		printf("map_line I:%zu J:%zu\n",i, j);
		return (1);
	}
	else if ((int)i == game->map_size - 1 && j != map_line  && game->map[i][j + 1] == '\n')
	{
		printf("map_line I:%zu J:%zu\n",i, j);
		printf("entra\n");
		return (2);
	}
	else if ((int)i == game->map_size - 1 && j != map_line  && game->map[i][j] == '\n') 
	{
		game->map_size--;
		printf("entra map_size\n");
		return (3);
	}
	return(0); 
}

void	ft_checkmap(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t size;

	size = ft_strlen(game->map[0]);
	i = -1;
	printf("map_size:%d\n", game->map_size);
	printf("map_len:%zu\n", size);
	while (game->map[++i])
	{
		j = -1;
		while(game->map[i][++j])
			ft_checkrectangle(game, i, j);
	}
	ft_checkwalls(game);
	ft_checkelements(game);
}