/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:58 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/18 21:13:47 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

void ft_execve(char **argv, char **envp)
{
	char *ruta;
	char **cmd;

	ruta = ruta_cmd(envp, argv);
	cmd = get_cmd(argv);
	execve(ruta, cmd, envp);
}

void ft_pipex (char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		ft_perror("Error Pipe");
	pid = fork();
	if (pid == 0)
	{
		close(fd[READ_END]);
		if(dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
			ft_perror("Error");
		close(fd[WRITE_END]);
		ft_execve(argv, envp);
	}
	else
	{
		close(fd[WRITE_END]);
		if(dup2(fd[READ_END], STDIN_FILENO) == -1)
			ft_perror("ERROR");
		close(fd[READ_END]);
		waitpid(pid, NULL, 0);
	}
}
int	main(int argc, char **argv, char **envp)
{
	int num;
	int infile;
	int outfile;
	
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		num = 3;
		ft_heredoc(argc, argv);
		outfile = open(argv[argc -1], O_CREAT | O_WRONLY | O_APPEND, 0777);
	}
	else
	{
		num = 2;
		if((infile = open(argv[1],  O_RDONLY, 0777)) == -1)
			ft_perror("Error infile");
		if((outfile = open(argv[argc -1], O_CREAT | O_WRONLY | O_TRUNC, 0777)) == -1)
			ft_perror("Error outfile");
		if(dup2(infile, STDIN_FILENO) == -1)
			ft_perror("Error");
	}
	while (num < argc - 2)
		ft_pipex(&argv[num++], envp);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_perror("ERROR");
	ft_execve(&argv[argc - 2], envp);
}
