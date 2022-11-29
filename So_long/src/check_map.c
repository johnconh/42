/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:34:15 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/29 20:55:41 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static void	ft_checkwalls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while(*(*(game->map + i) + ++j))
	{
		if((game->map[i][++j]!= '1') && (game->map != '\0'))
			ft_invalid_map(game);
	}
	while(game->map_size - 1 > ++i)
	{
		if(game->map[i][0] != '1' || game->map[i][ft_strlen(game->map) - 1] != '1')
			ft_invalid_map(game);
	}
	j = -1;
	while(*(*(game->map + i) + ++j))
	{
		if((game->map[i][++j]!= '1') && (game->map != '\0'))
			ft_invalid_map(game);
	}
}

static void ft_checkrectangle(t_game *game)
{
	int i;
	int width;
	
	i = 0;
	width = ft_strlen(*(game->map + i));
	while (*(game->map + i))
	{
		if(*(game->map + 1) != width ||  game->map_size == width)
			ft_invalid_map(game);
		i++;
	}
}

void	ft_checkmap(t_game *game)
{
	ft_checkrectangle(game);
	ft_checkwalls(game);
	
}