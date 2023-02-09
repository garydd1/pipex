/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:45:11 by dgarizad          #+#    #+#             */
/*   Updated: 2022/12/01 17:33:33 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((void *)s);
		s++;
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	s[] = "AnitalavalatinA";
	char	c = 'l';
	printf("first occurrence: '%c' in '%s': '%s' : ",c,s, ft_memchr(s,c,15));
	return (0);
}*/
