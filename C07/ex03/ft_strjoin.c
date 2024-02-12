/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:07:04 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/25 17:58:42 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dest);
}

void	fill_str(int size, char *str, char **strs, char *sep)
{
	int	i;
	int	str_len;

	i = 0;
	while (i < size)
	{
		str = ft_strcat(str, strs[i]);
		if (i == size - 1)
		{
			str_len = ft_strlen(str);
			str[str_len] = '\0';
		}
		else
		{
			str = ft_strcat(str, sep);
		}
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		str_len;
	int		i;

	str_len = 0;
	i = 0;
	if (size <= 0)
	{
		str = (char *)malloc(0);
		return (str);
	}
	while (i < size)
	{
		str_len += ft_strlen(strs[i++]);
	}
	str_len += ft_strlen(sep) * (size - 1) + 1;
	str = (char *)malloc(sizeof(char) * str_len);
	str[0] = '\0';
	fill_str(size, str, strs, sep);
	return (str);
}
