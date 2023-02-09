/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:30:10 by dgarizad          #+#    #+#             */
/*   Updated: 2022/12/01 15:42:48 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
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
