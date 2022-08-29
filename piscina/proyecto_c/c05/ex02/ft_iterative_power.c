/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:01:19 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/19 19:08:34 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;

	if (power < 0 || (nb == 0 && power < 0))
		return (0);
	if ((nb == 0 && power == 0) || power == 0)
		return (1);
	i = 1;
	while (power >= 1)
	{
		i = nb * i;
		power--;
	}
	return (i);
}
