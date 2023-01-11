/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:17:12 by jdasilva          #+#    #+#             */
/*   Updated: 2023/01/11 19:25:34 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	ft_check_error(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		if (argv[i][j] == '\0' || ft_atoi(argv[i]) == 0)
			return (0);
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	philo_l;

	if (argc != 5 && argc != 6)
		return (0);
	if (ft_check_error(argv) == 0)
		return (0);
	if (ft_init_list(argc, argv, &philo_l) == 0)
	{
		ft_destroy_mutex(&philo_l);
		return (0);
	}
	if (ft_init_philo(&philo_l) == 0)
	{
		ft_destroy_mutex(&philo_l);
		return (0);
	}
	ft_philo_thread(&philo_l);
	ft_destroy_mutex(&philo_l);
	return (0);
}
