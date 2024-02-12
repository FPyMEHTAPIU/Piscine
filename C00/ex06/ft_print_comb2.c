/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:15:10 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/11 20:35:49 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_foo(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (a == '9' && b == '8' && c == '9' && d == '9')
	{
		return ;
	}
	write(1, ", ", 2);
}

void	print_combination(char a, char b, char c, char d)
{
	while (c <= '9')
	{
		while (d <= '9')
		{
			if (a < c || (a == c && b < d))
			{
				write_foo(a, b, c, d);
			}
			d++;
		}
		d = '0';
		c++;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	b = '0';
	c = '0';
	d = '1';
	while (a <= '9')
	{
		while (b <= '9')
		{
			print_combination(a, b, c, d);
			c = '0';
			b++;
		}
		b = '0';
		a++;
	}
}
