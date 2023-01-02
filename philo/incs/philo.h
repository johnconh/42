/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:16:13 by jdasilva          #+#    #+#             */
/*   Updated: 2023/01/02 20:15:41 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>

typedef struct s_list
{
    int nb_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int nb_eat;
    pthread_t *thread;
    pthread_mutex_t *mutex;
    t_philo *philo;
} t_list;

typedef struct s_philo
{
    int id;
    int d_fork;
    int i_fork;
    int dead;
    t_list philo_l;
} t_philo;

int main(int argc, char **argv);
int ft_init_list(int argc, char **argv, t_list *philo_l);
int ft_init_philo(t_list *philo_l);
//**** PHILO_UTILS ******
int ft_atoi(const char *str);

#endif