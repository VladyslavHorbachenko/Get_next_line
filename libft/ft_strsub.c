/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlahorba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:08:10 by vlahorba          #+#    #+#             */
/*   Updated: 2018/12/01 20:08:11 by vlahorba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s || start > ft_strlen(s))
		return (NULL);
	res = ft_strnew(len);
	if (res == NULL)
		return (0);
	if (res && s)
	{
		i = 0;
		while (s[start] && i < len)
		{
			res[i] = s[start];
			i++;
			start++;
		}
	}
	return (res);
}
