/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:59:04 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/24 19:10:55 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	if (src == 0)
	{
		return (0);
	}
	while (src[i])
	{
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i));
	str = ft_strcpy(str, src);
	str[i] = 0;
	return (str);
}
