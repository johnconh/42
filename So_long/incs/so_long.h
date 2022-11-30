/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:34:35 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/30 21:24:31 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
/*---GNL-----*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_size;
	void	*img[8];
	int		mov;
	int		rupias;
	int		link;
	int		exit;
	int		link_pos[2];
	int		exit_pos[2];
}	t_game;

/*----------MAP--------*/
void	ft_getmap(char *argv, t_game *game);
void	ft_checkmap(t_game *game);
/*----------GNL--------*/
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
/*--------FREE-EXIT---------*/
void	ft_exit_and_free(t_game *game);
void	ft_invalid_map(t_game *game);
/*-------PLACES-IMGS--------*/
void	ft_places_imgs(char **map, t_game *game);
#endif