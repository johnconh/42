/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:37:09 by jdasilva          #+#    #+#             */
/*   Updated: 2023/01/10 18:17:51 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int ft_init_philo(t_list *philo_l)
{
    int i;

    philo_l->philo = (t_philo *)malloc(sizeof(t_philo) * philo_l->nb_philo + 1);
    if (!philo_l->philo)
        return(0);
    i = -1;
    while (++i < philo_l->nb_philo)
    {
        philo_l->philo[i].id = i + 1;
        philo_l->philo[i].i_fork = i;
        philo_l->philo[i].d_fork = (i + 1) % philo_l->nb_philo;
        philo_l->philo[i].nb_eat = 0;
        philo_l->philo[i].philo_l = philo_l;  
    }
    return(1);
}