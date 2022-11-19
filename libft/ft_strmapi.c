/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:32:46 by jnidorin          #+#    #+#             */
/*   Updated: 2021/10/21 14:17:30 by jnidorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mem;
	size_t	i;

	if (s == NULL)
		return (NULL);
	mem = ft_strdup(s);
	if (!(mem))
		return (NULL);
	i = 0;
	while (mem[i])
	{
		mem[i] = (*f)(i, mem[i]);
		i++;
	}
	return (mem);
}
