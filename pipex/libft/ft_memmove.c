/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:34:01 by dgarizad          #+#    #+#             */
/*   Updated: 2022/11/30 22:40:29 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int		i;

	if (!dst && !src)
		return (0);
	i = 0;
	if (dst > src)
	{
		while (len-- > 0)
		{
			*((char *)(dst + len)) = *((char *)(src + len));
		}
	}
	else
	{
		while (i < len)
		{
			*((char *)(dst + i)) = *((char *)(src + i));
			i++;
		}
	}
	return (dst);
}

/*int main () {
   const char src[50] = "AnitalavalatinA";
   char dest[8];
   strcpy(dest,"Hello!!");
   printf("Before memmove dest = %s\n", dest);
   memmove(dest, src, 8);
   printf("After memmove dest = %s\n", dest);

   return(0);
}*/
