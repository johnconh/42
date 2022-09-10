/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:09:32 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/18 15:11:20 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = argc - 1;
	while (i > 0)
	{
		j = 0;
		while (argv[i][j] && argc)
		{
			write(1, &argv[i][j], 1);
			j ++;
		}
		write(1, "\n", 1);
		i --;
	}
	return (0);
}
