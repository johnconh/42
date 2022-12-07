/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:34:15 by jdasilva          #+#    #+#             */
/*   Updated: 2022/12/07 21:12:56 by jdasilva         ###   ########.fr       */
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
				ft_invalid_map(game);
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
			ft_invalid_map(game);
	}
	while (game->map_size - 1 > ++i)
	{
		if (game->map[i][0] != '1' || game->map[i][ft_strlen(game->map[i]) - 2] != '1')
			ft_invalid_map(game);
	}
	j = -1;
	while (*(*(game->map + i) + ++j))
	{
		if ((game->map[i][j]!= '1') && (game->map[i][j] != '\n'))
			ft_invalid_map(game);
	}
}

static int ft_checkrectangle(t_game *game)
{
	int		i;
	size_t	map_line;

	map_line = ft_strlen(game->map[0]);
	i = -1;
	while(++i < game->map_size - 2)
	{
		if(ft_strlen(game->map[i]) != map_line)
			ft_invalid_map(game);
	}
	i++;
	if(game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
	{
		if(ft_strlen(game->map[i]) != map_line)
			ft_invalid_map(game);
	}
	else if (game->map[i][ft_strlen(game->map[i]) - 1] == '1')
	{
		if(ft_strlen(game->map[i]) != map_line - 1)
			ft_invalid_map(game);
	}
	return(0); 
}

void	ft_checkmap(t_game *game)
{
	ft_checkrectangle(game);
	ft_checkwalls(game);
	ft_checkelements(game);
	//ft_checkpath(game);
}