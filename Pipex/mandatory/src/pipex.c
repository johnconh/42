/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:58 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/14 20:36:53 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	ft_hijo(int *fd, char **argv, char **envp)
{
	int		infile;
	char	*ruta;
	char	**cmd;

	ruta = ruta_cmd(envp, &argv[2]);
	cmd = get_cmd(&argv[2]);
	close(fd[READ_END]);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		perror("Error");
	dup2(fd[WRITE_END], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[WRITE_END]);
	execve(ruta, cmd, envp);
}

void	ft_padre(int *fd, char **argv, char **envp)
{
	int		outfile;
	char	*ruta;
	char	**cmd;

	ruta = ruta_cmd(envp, &argv[3]);
	cmd = get_cmd(&argv[3]);
	close(fd[WRITE_END]);
	outfile = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (outfile == -1)
		perror("Error");
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[READ_END]);
	execve(ruta, cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		status;
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
		perror("Error");
	if (argc == 5)
	{
		if (pid == 0)
			ft_hijo(fd, argv, envp);
		else
			ft_padre(fd, argv, envp);
	}
	wait(&status);
	return (0);
}
