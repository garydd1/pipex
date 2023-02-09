/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:30:10 by dgarizad          #+#    #+#             */
/*   Updated: 2022/12/01 15:41:24 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}

/*int	main(void)
{
	char c;

	c = 'n';
	printf("\nletter before toupper: %c",c);
	c = ft_toupper(c);
	printf("\nletter after toupper: %c",c);
	return (0);
}*/
