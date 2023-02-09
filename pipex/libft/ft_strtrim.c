/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:25:39 by dgarizad          #+#    #+#             */
/*   Updated: 2022/12/06 17:10:38 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	len;

	if (!s1 || !set)
		return (0);
	while (s1[0] != '\0' && ft_strchr(set, s1[0]))
			s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len]))
		len--;
	return (ft_substr(s1, 0, len + 1));
}

/*int main(void)
{
    char *s1 = "xxxz  test with x and z and x .  zx  xx z";
    char *set = "z.x ts";
    char *s2;
    s2 = ft_strtrim(s1,set);
    printf("\nS1:'%s'\nS2:'%s'\nresult:'%s'",s1,set,s2);
    return (0);
}*/
