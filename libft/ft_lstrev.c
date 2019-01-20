/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlahorba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:40:38 by vlahorba          #+#    #+#             */
/*   Updated: 2018/12/01 19:40:41 by vlahorba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrev(t_list **alst)
{
	t_list	*last;
	t_list	*cur;
	t_list	*next;

	last = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = last;
		last = cur;
		cur = next;
	}
	*alst = last;
}
