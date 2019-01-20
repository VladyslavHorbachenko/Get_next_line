/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlahorba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:06:58 by vlahorba          #+#    #+#             */
/*   Updated: 2018/12/01 20:07:12 by vlahorba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		count;
	int		size;
	char	c;

	size = ft_strlen(str);
	count = size;
	while (count > size / 2)
	{
		c = str[size - count];
		str[size - count] = str[count - 1];
		str[count - 1] = c;
		count--;
	}
	return (str);
}
