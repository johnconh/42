/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:34:42 by jdasilva          #+#    #+#             */
/*   Updated: 2022/12/02 16:49:32 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
	write(1, "\n", 1);
}

static void	ft_putnbr (int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
	}
	else
	{
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

static int	ft_manager(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'C')
	{
		game->map[i][j] = '0';
		game->rupias--;
		if (game->rupias == 0)
			game->exit = 0;
		return (1);
	}
	else if (game->map[i][j] == 'E' && game->exit == 1)
		return (2);
	else if (game->map[i][j] == 'E' && game->exit == 0)
		ft_end_game(game);
	return(0);
}

static void	ft_link_move(t_game *game, int i, int j, int s)
{
	int	manager;

	manager = ft_manager(game, i , j);
	mlx_put_image_to_window(game->mlx, game->win, game->img[0], \
		game->link_pos[1] * 16, game->link_pos[0] * 16);
	if (game->map[game->link_pos[0]][game->link_pos[1]] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img[2], \
			game->link_pos[1] * 16, game->link_pos[0] * 16);
	if (manager == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->img[0], \
			j * 16, i * 16);
	else if (manager == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->img[3], \
			j * 16, i * 16);
	mlx_put_image_to_window(game->mlx, game->win, game->img[s],\
		j * 16, i * 16);
	game->link_pos[0] = i;
	game->link_pos[1] = j;
	game->mov++;
	ft_putnbr(game->mov);
}

int ft_key_hook (int keycode, t_game *game)
{
	if(keycode == 0 && game->map[game->link_pos[0]][game->link_pos[1] - 1] != '1')
		ft_link_move(game, game->link_pos[0], game->link_pos[1] - 1, 6);
	else if(keycode == 2 && game->map[game->link_pos[0]][game->link_pos[1] + 1] != '1')
		ft_link_move(game, game->link_pos[0], game->link_pos[1] + 1, 7);
	else if(keycode == 1 && game->map[game->link_pos[0] - 1][game->link_pos[1]] != '1')
		ft_link_move(game, game->link_pos[0] - 1, game->link_pos[1], 4);
	else if(keycode == 13 && game->map[game->link_pos[0] + 1][game->link_pos[1]] != '1')
		ft_link_move(game, game->link_pos[0] + 1, game->link_pos[1], 5);
	else if (keycode == 53)
		ft_end_game(game);
	return (0);
}
