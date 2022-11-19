/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:23:37 by jnidorin          #+#    #+#             */
/*   Updated: 2021/10/20 15:24:44 by jnidorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*first;
	const unsigned char	*second;

	first = s1;
	second = s2;
	if (sizeof(first) != sizeof(second) || n == 0)
		return (0);
	while (n-- > 0)
	{
		if (*first != *second)
			return ((unsigned char) *first - (unsigned char) *second);
		first++;
		second++;
	}
	return (0);
}
