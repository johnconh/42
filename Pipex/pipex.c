/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:58 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/12 14:07:36 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	ft_hijo(int *fd, char **argv, char **envp, char **cmd, char *ruta)
{
	int	file;

	close(fd[READ_END]);
	file =  open(argv[1], O_RDONLY);
	if(file == -1)
		perror("Error");
	dup2(fd[WRITE_END], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	close(fd[WRITE_END]);
	execve(ruta, cmd, envp);
}

void ft_padre(int *fd, char **argv, char **envp, char **cmd, char *ruta)
{
	int file;
	
	close(fd[WRITE_END]);
	file =  open(argv[4], O_CREAT | O_TRUNC| O_RDWR, 0644);
	if(file == -1)
		perror("Error");
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[READ_END]);
	execve(ruta, cmd, envp);
}

int main (int argc, char **argv, char **envp)
{
	char	*ruta;
	char	**cmd;
	int		fd[2];
	int		status;
	pid_t	pid;

	pipe(fd);
	
	pid = fork();
	if(pid == -1)
		perror("Error");
	if(argc == 5)
	{
		if(pid == 0)
		{
			ruta =ruta_cmd(envp, &argv[2]);
			cmd = get_cmd(&argv[2]);
			ft_hijo(fd, argv, envp, cmd, ruta); 
		}
		else
		{
			ruta =ruta_cmd(envp, &argv[3]);
			cmd = get_cmd(&argv[3]);
			ft_padre(fd, argv, envp, cmd, ruta);
		}
	}
	wait(&status);
	return (0);
} 