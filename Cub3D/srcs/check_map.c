/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:53:07 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/05 17:02:38 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	save_token(char *argv, t_data *data)
{
	int		fd;
	char	*line;

	fd = ft_open(argv);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == 'N' && line[1] == 'O' )
			get_image(line, "NO", data, fd);
		else if (line[0] == 'S' && line[1] == 'O')
			get_image(line, "SO", data, fd);
		else if (line[0] == 'W' && line[1] == 'E')
			get_image(line, "WE", data, fd);
		else if (line[0] == 'E' && line[1] == 'A')
			get_image(line, "EA", data, fd);
		else if (line[0] == 'F')
			get_color(line, 'F', data, fd);
		else if (line[0] == 'C')
			get_color(line, 'C', data, fd);
		else
			free(line);
	}
	ft_close(fd);
}

void	map(char *line, int fd)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'\
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'\
			&& line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
		{
			printf("Error: Archivo no valido\n");
			ft_close(fd);
			exit(-1);
		}
	}
}

size_t	check_spaces(char *line)
{
	size_t	c_line;
	int		i;

	c_line = 0;
	i = -1;
	while (line[++i])
		if (line[i] == '\t' || line[i] == '\n' || line[i] == '\v'\
			|| line[i] == '\f' || line[i] == '\r' || line[i] == ' ')
			c_line++;
	return (c_line);
}

void	cont_token(char *argv)
{
	int		fd;
	char	*line;
	size_t	c_line;
	int		cont;

	cont = 0;
	fd = ft_open(argv);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		c_line = check_spaces(line);
		if (ft_strlen(line) != c_line)
			cont ++;
		if (cont > 6)
			map(line, fd);
		free(line);
	}
	free(line);
	ft_close(fd);
}

void	check_map(char *argv, t_data *data)
{
	cont_token(argv);
	save_token(argv, data);
	save_map(argv, data);
}
