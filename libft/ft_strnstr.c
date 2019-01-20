/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlahorba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:57:30 by vlahorba          #+#    #+#             */
/*   Updated: 2018/12/01 19:57:33 by vlahorba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	var;

	if (!(*needle))
		return ((char *)haystack);
	var = ft_strlen(needle);
	while (*haystack && var <= len--)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, var) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return ((void *)0);
}
