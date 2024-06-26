/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:57:40 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/28 20:26:36 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isnum(char *c)
{
	int	isnum;

	isnum = 0;
	if (*c == '-' || *c == '+')
		c++;
	while (*c)
	{
		if (ft_isdigit(*c))
			isnum = 1;
		else
			return (0);
		c++;
	}
	return (isnum);
}
