/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:43:37 by jdasilva          #+#    #+#             */
/*   Updated: 2022/07/20 12:42:51 by jdasilva         ###   ########.fr       */
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
