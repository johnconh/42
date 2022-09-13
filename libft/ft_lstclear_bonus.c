/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:45:26 by jdasilva          #+#    #+#             */
/*   Updated: 2022/09/12 20:00:09 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*sig;

	if (lst && del)
	{
		while (*lst)
		{
			sig = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = sig;
		}
	}
	*lst = NULL;
}
