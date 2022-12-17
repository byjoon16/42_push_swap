/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:35:07 by byjeon            #+#    #+#             */
/*   Updated: 2022/12/14 22:42:50 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(int b_num, t_stack *every)
{
	int	pos;
	int	min;
	int	max;

	min = min_num(every->a_top);
	max = max_num(every->a_top);
	if (b_num < min)
		pos = min_position(every, min);
	else if (b_num > max)
		pos = max_position(every, max);
	else
		pos = mid_position(every, b_num);
	return (pos);
}

int	choose_better(int a, int b, int a_pos, int b_pos)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a_pos < 0)
		a_pos *= -1;
	if (b_pos < 0)
		b_pos *= -1;
	if ((a + b) > (a_pos + b_pos))
		return (1);
	return (0);
}

void	do_best(t_stack *every, int *rcommand_a, int *rcommand_b)
{
	rrcom(every, rcommand_a, rcommand_b);
	arcom(every, rcommand_a);
	brcom(every, rcommand_b);
}

void	find_best(t_stack *every, int *rcommand_a, int *rcommand_b)
{
	t_node	*b_stack;
	int		a_pos;
	int		b_pos;
	int		b_num;
	int		b_idx;

	b_idx = -1;
	b_stack = every->b_top;
	while (++b_idx < every->b_size)
	{
		if (b_idx >= (every->b_size + 1) / 2)
			b_pos = (every->b_size - b_idx) * -1;
		else
			b_pos = b_idx;
		b_num = b_stack->num;
		a_pos = find_position(b_num, every);
		if (choose_better(*rcommand_a, *rcommand_b, a_pos, b_pos) || !b_idx)
		{
			*rcommand_a = a_pos;
			*rcommand_b = b_pos;
		}
		b_stack = b_stack->next;
	}
	do_best(every, rcommand_a, rcommand_b);
}
