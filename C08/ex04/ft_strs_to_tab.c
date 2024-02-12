/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:35:37 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/31 09:36:02 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(s2);
	s1 = (char *)malloc(sizeof(char) * size + 1);
	if (!(s1))
	{
		return (0);
	}
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*obj;	

	i = 0;
	obj = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!(obj))
	{
		return (0);
	}
	while (i < ac)
	{
		obj[i].size = ft_strlen(av[i]);
		obj[i].str = av[i];
		obj[i].copy = ft_strcpy(obj[i].copy, obj[i].str);
		i++;
	}
	obj[i].size = 0;
	obj[i].str = 0;
	obj[i].copy = 0;
	return (obj);
}
