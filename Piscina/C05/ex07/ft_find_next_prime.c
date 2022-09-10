/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:03:45 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/20 12:43:19 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_mid(unsigned long min, unsigned long max, unsigned long nb)
{
	unsigned long	mid;

	mid = (min + max) / 2;
	if (mid * mid == nb)
		return (mid);
	else if ((mid + 1 == max && mid -1 == min)
		|| mid == max || mid == min)
		return (0);
	else if (mid * mid > nb)
		return (ft_mid(0, mid, nb));
	else
		return (ft_mid(mid, max, nb));
}

int	ft_sqrt(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (0);
	if (nb == 1)
		return (1);
	return (ft_mid(0, nb, nb));
}

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= ft_sqrt(nb))
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) != 1)
	{
		nb ++;
	}
	return (nb);
}
