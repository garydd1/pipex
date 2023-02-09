/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:25:24 by dgarizad          #+#    #+#             */
/*   Updated: 2022/12/05 23:30:51 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*substring;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	substring = (char *)malloc(len + 1);
	if (!substring)
		return (NULL);
	substring = ft_memcpy(substring, &s[start], len);
	substring[len] = '\0';
	return (substring);
}

/*int	main(void)
{
	char *str = "i just want this part #############";
	printf("result: '%s'", ft_substr(str, 3, 4));
	return (0);
}*/
