/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:46:36 by jdasilva          #+#    #+#             */
/*   Updated: 2023/01/02 19:34:52 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int  ft_create_mutex(t_list *philo_l)
{
    int i;

    i = -1;
    philo_l->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)\
        * (philo_l->nb_philo + 1));
    if(!philo_l->mutex)
        return(0);
    while (++i <= philo_l->nb_philo)
        if (pthread_mutex_init(&philo_l->mutex[i], NULL) != 0)
            return(0);
    return(1);
}

static int  ft_check_error(int argc, char **argv)
{
    int i;
    int j;

    i = -1;
    while (argv[++i])
    {
        if (argv[i][j] == '\0')
            return(0);
        j = -1;
        while (argv[i][++j])
            if ((argv[i][j] >= 0 && argv[i][j] <= 9))
                return(0);
    }
    return(1);
}

int ft_init_list(int argc, char **argv, t_list *philo_l)
{
    if (ft_check_error(argc, argv) == 0)
        return(0);
    philo_l->nb_philo = ft_atoi(argv[1]);
    philo_l->t_die = ft_atoi(argv[2]);
    philo_l->t_eat = ft_atoi(argv[3]);
    philo_l->t_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        philo_l->nb_eat = ft_atoi(argv[5]);
    else
        philo_l->nb_eat = -1;
    if (ft_create_mutex(philo_l) == 0)
        ft_destroy_mutex(philo_l->mutex);
            return(0);
    return(1);
}
