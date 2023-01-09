/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:15:28 by jdasilva          #+#    #+#             */
/*   Updated: 2023/01/09 19:18:29 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void ft_destroy_philo(t_list *philo_l)
{
    int i;
    
    i = -1;
    while(++i < philo_l->nb_philo)
    {
        if(&philo_l->philo[i])
            free(&philo_l->philo[i]);
    }
    free(philo_l->philo);
}

void ft_destroy_mutex(t_list *philo_l)
{
    int i;

    i = -1;
    while(++i <= philo_l->nb_philo)
    {
        if(pthread_mutex_destroy(&philo_l->mutex[i]) != 0)
            return ;
    }
    if(pthread_mutex_destroy(&philo_l->print))
        return ;
    if(pthread_mutex_destroy(&philo_l->dead))
        return ;
}

void ft_destroy(t_list *philo_l)
{
    ft_destroy_mutex(philo_l);
    ft_destroy_philo(philo_l);
}
