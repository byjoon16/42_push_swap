/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:24:43 by byjeon            #+#    #+#             */
/*   Updated: 2022/12/14 22:42:43 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_num(t_node *a_stack)
{
	int	res;

	res = a_stack->num;
	while (a_stack)
	{
		if (res > a_stack->num)
			res = a_stack->num;
		a_stack = a_stack->next;
	}
	return (res);
}

int	max_num(t_node *stack)
{
	int	res;

	res = stack->num;
	while (stack)
	{
		if (res < stack->num)
			res = stack->num;
		stack = stack->next;
	}
	return (res);
}

int	min_position(t_stack *every, int min)
{
	t_node		*stack_a;
	int			pos;
	int			tmp;

	if (every->a_top->num == min)
		return (0);
	pos = 0;
	tmp = 0;
	stack_a = every->a_top;
	while (stack_a)
	{
		tmp = stack_a->num;
		if (tmp == min)
			break ;
		pos++;
		stack_a = stack_a->next;
	}
	if (pos >= (every->a_size + 1) / 2)
		pos = (every->a_size - pos) * -1;
	return (pos);
}

int	mid_position(t_stack *every, int num)
{
	t_node		*stack_a;
	int			pos;

	if (num < every->a_top->num && every->a_bot->num < num)
		return (0);
	stack_a = every->a_top;
	pos = 0;
	while (stack_a->next)
	{
		pos++;
		if (num > stack_a->num && num < stack_a->next->num)
			break ;
		stack_a = stack_a->next;
	}
	if (pos >= (every->a_size + 1) / 2)
		pos = (every->a_size - pos) * -1;
	return (pos);
}

int	max_position(t_stack *every, int max)
{
	t_node		*stack_a;
	int			pos;
	int			tmp;

	pos = 0;
	tmp = 0;
	stack_a = every->a_bot;
	while (stack_a)
	{
		tmp = stack_a->num;
		if (tmp == max)
			break ;
		pos++;
		stack_a = stack_a->prev;
	}
	if (pos <= (every->a_size + 1) / 2)
		pos *= -1;
	else
		pos = every->a_size - pos;
	return (pos);
}
