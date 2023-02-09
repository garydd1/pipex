/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:10:04 by dgarizad          #+#    #+#             */
/*   Updated: 2022/11/29 22:32:31 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <strings.h>
//#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return ;
	i = 0;
	while (i < n)
	{
		*((char *)(s + i)) = '\0';
		i++;
	}
}

/*int	main(void)
{
	char str[50] = "This is string.h library function";
	printf("%s",str);
	ft_bzero(str,52);
	printf("\nAqui: %s", str);
	return (0);
}*/
