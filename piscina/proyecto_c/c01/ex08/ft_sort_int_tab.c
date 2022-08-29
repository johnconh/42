/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:41:11 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/08 10:25:23 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	a;

	i = 0;
	while (i < size -1)
	{
		if (tab [i] > tab [i +1])
		{
			a = tab[i];
			tab [i] = tab[i +1];
			tab[i +1] = a;
			ft_sort_int_tab(tab, size);
		}
		i++;
	}
}
