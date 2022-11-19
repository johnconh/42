/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:49:53 by jdasilva          #+#    #+#             */
/*   Updated: 2022/11/19 20:37:25 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>

# define READ_END  0  /* index pipe extremo escritura */
# define WRITE_END 1  /* index pipe extremo lectura */

//##### UTILS #####
char	**get_rutas(char **envp);
char	**get_cmd(char **argv);
char	*ruta_cmd(char **envp, char **argv);
void	ft_free_split(char **str);
void	ft_perror(char *str);
//###### LIBFT ######
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif