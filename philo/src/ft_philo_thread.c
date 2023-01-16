/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:44:14 by jdasilva          #+#    #+#             */
/*   Updated: 2023/01/16 21:03:15 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	ft_checkdead(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_l->mdead);
	if (philo->philo_l->dead == 1)
	{
		pthread_mutex_unlock(&philo->philo_l->mdead);
		return (1);
	}
	if (get_time() - philo->philo_start >= philo->philo_l->t_die)
	{
		ft_print_dead(philo);
		philo->philo_l->dead = 1;
		pthread_mutex_unlock(&philo->philo_l->mdead);
		return (1);
	}
	pthread_mutex_unlock(&philo->philo_l->mdead);
	return (0);
}

static void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_l->mutex[philo->i_fork]);
	if (ft_checkdead(philo))
	{
		pthread_mutex_unlock(&philo->philo_l->mutex[philo->i_fork]);
		pthread_mutex_unlock(&philo->philo_l->mutex[philo->d_fork]);
		return ;
	}
	ft_print_fork(philo);
	pthread_mutex_lock(&philo->philo_l->mutex[philo->d_fork]);
	if (ft_checkdead(philo))
	{
		pthread_mutex_unlock(&philo->philo_l->mutex[philo->i_fork]);
		pthread_mutex_unlock(&philo->philo_l->mutex[philo->d_fork]);
		return ;
	}
	ft_print_fork(philo);
	ft_print_eat(philo);
	philo->philo_start = get_time();
	ft_usleep(philo->philo_l->t_eat, philo->philo_l);
	if (philo->philo_l->nb_eat != -1)
		philo->nb_eat ++;
	pthread_mutex_unlock(&philo->philo_l->mutex[philo->i_fork]);
	pthread_mutex_unlock(&philo->philo_l->mutex[philo->d_fork]);
	return ;
}

static void	*ft_routine(void *philo_v)
{
	t_philo	*philo;

	philo = (t_philo *)philo_v;
	philo->philo_start = get_time();
	if (philo->id % 2 == 0)
	{
		usleep(250);
		usleep(250);
	}
	while (philo->philo_l->dead == 0)
	{
		if (ft_checkdead(philo))
			return (0);
		ft_eat(philo);
		if (philo->nb_eat == philo->philo_l->nb_eat)
			break ;
		if (ft_checkdead(philo))
			return (0);
		ft_print_sleeping(philo);
		ft_usleep(philo->philo_l->t_sleep, philo->philo_l);
		if (ft_checkdead(philo))
			return (0);
		ft_print_thinking(philo);
	}
	return (0);
}

void	ft_philo_thread(t_list *philo_l)
{
	int	i;

	i = -1;
	philo_l->start = get_time();
	if (philo_l->nb_philo == 1)
	{
		ft_usleep(philo_l->t_sleep, philo_l);
		ft_print_dead(philo_l->philo);
		return ;
	}
	while (++i < philo_l->nb_philo)
	{
		if (pthread_create(&philo_l->philo[i].thread, NULL, \
			&ft_routine, &philo_l->philo[i]) != 0)
		{
			printf ("Failed create thread\n");
			return ;
		}
	}
	i = -1;
	while (++i < philo_l->nb_philo)
		if (pthread_join(philo_l->philo[i].thread, NULL) != 0)
			return ;
}
