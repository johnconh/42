/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:24:33 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/16 20:58:49 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

void ft_heredoc(char **argv)
{
	int		fd[2];
	char	*delimiter;
	char	*line;

	delimiter = argv[2];

	while(1)
	{
		line = get_next_line(0);
		if(ft_strncmp(line, delimiter, ft_strlen(delimiter) - 1) == 0)
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
} 