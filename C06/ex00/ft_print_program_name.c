/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:34:22 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/23 16:03:11 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (argv[argc - argc][i] != '\0')
	{
		i++;
	}
	write(1, argv[0], i);
	write(1, "\n", 1);
	return (0);
}
