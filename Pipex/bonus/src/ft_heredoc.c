/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:24:33 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/17 20:31:25 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

void ft_heredoc(char **argv)
{
	int		fd[2];
	char	*delimiter;
	char	*line;
	pid_t	pid;

	delimiter = argv[2];
	pipe(fd);
	pid = fork();
	if (pid == -1)
		perror("Error");
	if (pid == 0)
	{
		while(1)
		{
			line = get_next_line(STDIN_FILENO);
			if(ft_strncmp(line, delimiter, ft_strlen(delimiter) - 1) == 0)
			{
				free(line);
				break ;
			}
			free(line);
		}
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}
