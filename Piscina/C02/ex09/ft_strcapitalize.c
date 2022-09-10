/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:36:10 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/11 19:40:08 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str, int i)
{
	if (str[i] >= 65 && str[i] <= 90)
	{
		return (1);
	}
	if (str[i] >= 97 && str[i] <= 122)
	{
		return (1);
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		return (1);
	}
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		if (ft_str_is_alpha(str, i) == 1 && ft_str_is_alpha(str, i - 1) == 0)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = str[i] - 32;
			}
		}
		i++;
	}
	return (str);
}
