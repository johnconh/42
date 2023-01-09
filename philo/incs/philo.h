/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:16:13 by jdasilva          #+#    #+#             */
/*   Updated: 2023/01/09 19:50:33 by jdasilva         ###   ########.fr       */
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
#include <limits.h>


typedef struct s_list
{
    int nb_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int nb_eat;
    int dead;
    long start;
    pthread_mutex_t *mutex;
    pthread_mutex_t print;
    pthread_mutex_t dead;
    t_philo *philo;
} t_list;

typedef struct s_philo
{
    int id;
    int d_fork;
    int i_fork;
    int nb_eat;
    long philo_start;
    pthread_t thread;
    t_list *philo_l;
} t_philo;

int     main(int argc, char **argv);
int     ft_init_list(int argc, char **argv, t_list *philo_l);
int     ft_init_philo(t_list *philo_l);
void    ft_philo_thread(t_list *philo_l);
//****** FREE ********
void    ft_destroy(t_list *philo_l);
void    ft_destroy_mutex(t_list *philo_l);
void    ft_destroy_philo(t_list *philo_l);
//**** PHILO_UTILS ******
int     ft_atoi(const char *str);
long    get_time(void);
void	ft_usleep(int time);
//***** PRINT *****
void    ft_print_fork(t_philo *philo);
void    ft_print_eat(t_philo *philo);
void    ft_print_sleeping(t_philo *philo);
void    ft_print_thinking(t_philo *philo);
void    ft_print_dead(t_philo *philo);
#endif