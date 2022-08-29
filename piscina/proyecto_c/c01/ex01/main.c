/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:41:15 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/06 21:41:19 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void ft_ultimate_ft(int *********nbr);
int main()
{
    int nbr;
    int *n1;
    n1=&nbr;
    int **n2;
    n2=&n1;
    int ***n3;
    n3=&n2;
    int ****n4;
    n4=&n3;
    int *****n5;
    n5=&n4;
    int ******n6;
    n6=&n5;
    int *******n7;
    n7=&n6;
    int ********n8;
    n8=&n7;
    int *********n9;
    n9=&n8;
    ft_ultimate_ft(n9);
    printf ("%d", nbr);
}