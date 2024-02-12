/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:36:19 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/31 09:36:43 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putnbr(int num)
{
	char	c;
	long	conv;

	conv = num;
	if (conv < 0)
	{
		write(1, "-", 1);
		conv *= -1;
	}
	if (conv > 9)
	{
		ft_putnbr(conv / 10);
		ft_putnbr(conv % 10);
	}
	else
	{
		c = conv + '0';
		write (1, &c, 1);
	}
}

int	ft_strlength(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	length;

	i = 0;
	while (par[i].str != 0)
	{
		length = ft_strlength(par[i].str);
		write(1, par[i].str, length);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		length = ft_strlength(par[i].copy);
		write(1, par[i].copy, length);
		write(1, "\n", 1);
		i++;
	}
}
