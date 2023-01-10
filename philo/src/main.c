/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:17:12 by jdasilva          #+#    #+#             */
/*   Updated: 2023/01/10 19:04:03 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int main(int argc, char **argv)
{
    t_list philo_l;

    if(argc !=5 && argc !=6)
        return(0);
    if(ft_init_list(argc, argv, &philo_l) == 0)
        return(0);
    if(ft_init_philo(&philo_l) == 0)
    {
        ft_destroy_mutex(&philo_l);
        return (0);
    }
    ft_philo_thread(&philo_l);
    ft_destroy_mutex(&philo_l);
    return (0);
}
