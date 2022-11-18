/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:58 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/18 18:49:24 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	ft_cmd_1(int *fd, char **argv, char **envp)
{
	int		infile;
	char	*ruta;
	char	**cmd;

	ruta = ruta_cmd(envp, &argv[2]);
	cmd = get_cmd(&argv[2]);
	infile = open(argv[1], O_RDONLY);
	if(infile < 0)
		ft_perror("Error infile:");
	if(dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
		ft_perror("ERROR");
	if(dup2(infile, STDIN_FILENO) == -1)
		ft_perror("ERROR");
	close(fd[READ_END]);
	close(infile);
	close(fd[WRITE_END]);
	execve(ruta, cmd, envp);
}

void	ft_cmd_2(int *fd, char **argv, char **envp)
{
	int		outfile;
	char	*ruta;
	char	**cmd;

	ruta = ruta_cmd(envp, &argv[3]);
	cmd = get_cmd(&argv[3]);
	outfile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if(outfile < 0)
		ft_perror("Error infile:");
	if(dup2(fd[READ_END], STDIN_FILENO) == -1)
		ft_perror("ERROR");
	if(dup2 (outfile, STDOUT_FILENO) == -1)
		ft_perror("ERROR");
	close(fd[WRITE_END]);
	close(outfile);
	close(fd[READ_END]);
	execve(ruta, cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int fd[2];
	int	pid1;
	int pid2;
	
	if (argc != 5)
		ft_perror("Error arguments");
	if(pipe(fd) == -1)
		ft_perror("Pipe Error");
	pid1 = fork();
	if(pid1 == -1)
		ft_perror("Pid1 Error");
	if(pid1 == 0)
		ft_cmd_1(fd, argv, envp);
	pid2 = fork();
	if(pid2 == -1)
		ft_perror("Pid2 Error");
	if(pid2 == 0 )
		ft_cmd_2(fd,argv, envp);
	close(fd[READ_END]);
	close(fd[WRITE_END]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
