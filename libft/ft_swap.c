/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:26 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/18 17:23:14 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_swap
** swap pointers
*/

void	ft_swap(void **a, void **b)
{
	void *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
