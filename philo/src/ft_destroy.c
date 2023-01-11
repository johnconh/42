/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:15:28 by jdasilva          #+#    #+#             */
/*   Updated: 2023/01/11 19:08:05 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	ft_destroy_mutex(t_list *philo_l)
{
	int	i;

	i = -1;
	while (++i < philo_l->nb_philo)
	{
		if (pthread_mutex_destroy(&philo_l->mutex[i]) != 0)
			return ;
	}
	if (pthread_mutex_destroy(&philo_l->print))
		return ;
	if (pthread_mutex_destroy(&philo_l->mdead))
		return ;
	if (philo_l->mutex)
		free(philo_l->mutex);
	if (philo_l->philo)
		free(philo_l->philo);
}
