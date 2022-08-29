/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:44:52 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/14 21:31:36 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	c;
	int	ia;

	if (to_find [0] == '\0')
		return (str);
	else
	{
		i = 0;
		while (str[i])
		{
			ia = i;
			c = 0;
			while (str[ia] == to_find[c])
			{
				if (to_find[c + 1] == '\0')
					return (&str[i]);
				ia++;
				c++;
			}
			i ++;
		}
		return (0);
	}
}
