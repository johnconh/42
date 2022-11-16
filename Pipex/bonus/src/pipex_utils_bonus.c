/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:03:15 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/16 17:56:22 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex_bonus.h"

char	**get_rutas(char **envp)
{
	int		i;
	char	**rutas;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			rutas = ft_split(envp[i] + 5, ':');
		i++;
	}
	return (rutas);
}

char	**get_cmd(char **argv)
{
	char	**cmd;

	cmd = ft_split(argv[0], ' ');
	return (cmd);
}

char	*ruta_cmd(char **envp, char **argv)
{
	char	**rutas;
	char	*temp;
	char	*ruta;
	char	**cmd;
	int		i;

	cmd = get_cmd(argv);
	rutas = get_rutas(envp);
	i = 0;
	while (rutas[i])
	{
		rutas[i] = ft_strjoin(rutas[i], "/");
		rutas[i] = ft_strjoin(rutas[i], cmd[0]);
		temp = rutas[i];
		if (access(temp, F_OK) == 0)
			ruta = temp;
		else
			free(temp);
		i++;
	}
	return (ruta);
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}
