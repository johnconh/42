/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:49:53 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/12 13:47:22 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

#define READ_END  0  /* index pipe extremo escritura */
#define WRITE_END 1  /* index pipe extremo lectura */

//##### UTILS #####
char	**get_rutas(char **envp, char **argv);
char	**get_cmd(char **argv);
char	*ruta_cmd(char **envp, char **argv);
//###### LIBFT ######
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif