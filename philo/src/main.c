/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:17:12 by jdasilva          #+#    #+#             */
/*   Updated: 2023/01/13 18:08:20 by jdasilva         ###   ########.fr       */
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
		if (i == 1 || i == 2 || i == 5)
			if (argv[i][0] == '0')
				return (printf("0 is an invalid value\n"), 0);
		if (ft_atoi(argv[i]) == -1)
			return (printf("Invalid digits\n"), 0);
		if (argv[i][0] == 0)
			return (printf("Empty argument\n"), 0);
		j = -1;
		while (argv[i][++j])
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (printf("Only digits\n"), 0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	philo_l;

	if (argc != 5 && argc != 6)
		return (printf("Invalid arguments\n"), 0);
	if (ft_check_error(argv) == 0)
		return (0);
	if (ft_init_list(argc, argv, &philo_l) == 0)
	{
		ft_destroy_mutex(&philo_l);
		return (printf("init list create failed\n"), 0);
	}
	if (ft_init_philo(&philo_l) == 0)
	{
		ft_destroy_mutex(&philo_l);
		return (printf("init philo create failed\n"), 0);
	}
	ft_philo_thread(&philo_l);
	ft_destroy_mutex(&philo_l);
	return (0);
}
