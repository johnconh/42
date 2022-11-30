/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:35:47 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/30 21:12:14 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"
static void	ft_free_map(char **str)
{
	int	i;

	i = -1;
	while(str[++i])
	{
		if(str[i])
			free(str[i]);
	}
	free(str);
}

void ft_invalid_map(t_game *game)
{
	write(2, "Invalid map\n", 12);
	ft_exit_and_free(game);
}

void	ft_exit_and_free(t_game *game)
{
	if(game->map)
		ft_free_map(game->map);
	free(game);
	exit (-1);
}