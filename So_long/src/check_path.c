/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:17:26 by jdasilva          #+#    #+#             */
/*   Updated: 2022/12/07 21:20:51 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static int ft_paint(char **map, int i, int j)
{
	if(map[i][j] == '0' || map[i][j]== 'C' || map[i][j] == 'E' || map[i][j] == 'P')
	{
		
	}
}

void	ft_checkpath(t_game *game)
{
	int	i;
	int	j;
	char **ptr;

	ptr = game->map;
	while(ptr[++i])
	{
		j = -1;
		while(ptr[i][++j])
		{
			if(ptr[i][j] == 'P')
			{
				if(!ft_paint(ptr, i, j))
					ft_invalid_map(game);
			}
		}
	}
}