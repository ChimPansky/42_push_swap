/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:57:40 by tkasbari          #+#    #+#             */
/*   Updated: 2023/10/28 21:11:17 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_sign(char **s, int *neg_mult)
{
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*neg_mult = -1;
		(*s)++;
	}
}
// check for -0
int	ft_str_isint(char *s, int *target)
{
	int		isnum;
	int		neg_mult;
	size_t	result;

	*target = 0;
	neg_mult = 1;
	result = 0;
	handle_sign(&s, &neg_mult);
	while (*s)
	{
		if (ft_isdigit(*s))
		{
			result = result * 10 + *s - '0';
			if ((neg_mult == -1 && (result * neg_mult) < (size_t)INT_MIN)
				|| (neg_mult == 1 && result > (size_t)INT_MAX))
				return (0);
			isnum = 1;
		}
		else
			return (0);
		s++;
	}
	*target = result * neg_mult;
	return (isnum);
}
