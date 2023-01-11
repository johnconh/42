/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:33:49 by jdasilva          #+#    #+#             */
/*   Updated: 2023/01/11 19:28:59 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	ft_print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_l->print);
	printf("%d %d has a taken fork\n", \
		get_time() - philo->philo_l->start, philo->id);
	pthread_mutex_unlock(&philo->philo_l->print);
}

void	ft_print_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_l->print);
	printf("%d %d \x1b[32mis eating\n\x1b[m", \
		get_time() - philo->philo_l->start, philo->id);
	pthread_mutex_unlock(&philo->philo_l->print);
}

void	ft_print_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_l->print);
	printf("%d %d \x1b[33mis sleeping\n\x1b[m", \
		get_time() - philo->philo_l->start, philo->id);
	pthread_mutex_unlock(&philo->philo_l->print);
}

void	ft_print_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_l->print);
	printf("%d %d \x1b[34mis thinking\n\x1b[m", \
		get_time() - philo->philo_l->start, philo->id);
	pthread_mutex_unlock(&philo->philo_l->print);
}

void	ft_print_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_l->print);
	printf("%d %d \x1b[31mdied\n\x1b[m", \
		get_time() - philo->philo_l->start, philo->id);
	pthread_mutex_unlock(&philo->philo_l->print);
}
