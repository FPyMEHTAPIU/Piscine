/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:23:19 by msavelie          #+#    #+#             */
/*   Updated: 2024/01/12 12:28:54 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

// FOR TESTING
/* 
#include <stdio.h>

int main(void)
{
    int n = 0;
    int *pn = &n;
    int **pn2 = &pn;
    int ***pn3 = &pn2;
    int ****pn4 = &pn3;
    int *****pn5 = &pn4;
    int ******pn6 = &pn5;
    int *******pn7 = &pn6;
    int ********pn8 = &pn7;
    ft_ultimate_ft(&pn8);
    printf("%d", n);
    return (0);
}
*/