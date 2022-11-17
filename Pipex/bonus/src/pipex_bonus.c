/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:58 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/17 21:22:45 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

void	ft_hijo(int *fd, char **argv, char **envp, int i)
{
	char	*ruta;
	char	**cmd;

	ruta = ruta_cmd(envp, argv);
	cmd = get_cmd(argv);
	close(fd[READ_END]);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	execve(ruta, cmd, envp);
	ft_free_split(cmd);
}

void	ft_padre(int *fd, char **argv, char **envp, int i)
{
	char	*ruta;
	char	**cmd;

	ruta = ruta_cmd(envp, argv);
	cmd = get_cmd(argv);
	close(fd[WRITE_END]);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	execve(ruta, cmd, envp);
	ft_free_split(cmd);
}

void	ft_pipe(char **argv, char **envp, int i)
{
	int		fd[2];
	pid_t	pid;
	char	*ruta;
	char	**cmd;
	
	ruta = ruta_cmd(envp, argv);
	cmd = get_cmd(argv);
	pipe(fd);
	pid = fork();
	printf("entra\n");
	if (pid == -1)
		perror("Error");
	if (pid == 0)
		ft_hijo(fd, argv, envp, );
	else
	{
		waitpid(pid, NULL, 0);
		ft_padre(fd, argv, envp, );
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;
	int	i;

	if (argc >= 5)
	{
	/* 	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			ft_heredoc(argv);
			outfile = open(argv[argc - 1], O_CREAT | O_APPEND | O_WRONLY, 0644);
			if (outfile == -1)
				perror("Error");
			dup2(outfile, STDOUT_FILENO);
		} */
	
			infile = open(argv[1], O_RDONLY);
			if (infile == -1)
				perror("Error");
			outfile = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
			if (outfile == -1)
				perror("Error");
			dup2(infile, STDIN_FILENO);
			dup2(outfile, STDOUT_FILENO);

		i = 1;
		while (++i < argc - 2)
		{
			ft_pipe(argv, envp, i);
		}
	}
	else
		write(2, "Error\n", 7);
	return (0);
}
