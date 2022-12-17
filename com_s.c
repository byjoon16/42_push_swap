/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:55:59 by byjeon            #+#    #+#             */
/*   Updated: 2022/11/11 15:05:07 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *every)
{
	int	tmp;

	if (every->a_size <= 1)
		return ;
	tmp = every->a_top->num;
	every->a_top->num = every->a_top->next->num;
	every->a_top->next->num = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *every)
{
	int	tmp;

	if (every->b_size <= 1)
		return ;
	tmp = every->b_top->num;
	every->b_top->num = every->b_top->next->num;
	every->b_top->next->num = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *every)
{
	int	tmp;

	if (every->a_size <= 1)
		return ;
	if (every->b_size <= 1)
		return ;
	tmp = every->a_top->num;
	every->a_top->num = every->a_top->next->num;
	every->a_top->next->num = tmp;
	tmp = every->b_top->num;
	every->b_top->num = every->b_top->next->num;
	every->b_top->next->num = tmp;
	write(1, "ss\n", 3);
}
