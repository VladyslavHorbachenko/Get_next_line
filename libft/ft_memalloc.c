/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlahorba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:40:57 by vlahorba          #+#    #+#             */
/*   Updated: 2018/12/01 19:40:59 by vlahorba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *m;

	m = (char *)malloc(size * sizeof(char));
	if (m == NULL)
	{
		return (NULL);
	}
	ft_bzero(m, size);
	return (m);
}
