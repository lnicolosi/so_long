/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubachma <lubachma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:40:23 by lubachma          #+#    #+#             */
/*   Updated: 2023/12/21 10:18:43 by lubachma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_puthex(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16);
	if (n % 16 < 10)
		count += ft_putchar((n % 16) + '0');
	else
		count += ft_putchar((n % 16) - 10 + 'a');
	return (count);
}

int	ft_puthexx(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthexx(n / 16);
	if (n % 16 < 10)
		count += ft_putchar((n % 16) + '0');
	else
		count += ft_putchar((n % 16) - 10 + 'A');
	return (count);
}
