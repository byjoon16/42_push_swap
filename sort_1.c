/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:59:43 by byjeon            #+#    #+#             */
/*   Updated: 2022/12/14 19:58:13 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	help_chunk(t_stack *every, int pivot_small, int pivot_big)
{
	if (every->a_top->num < pivot_small)
	{
		pb(every);
		rb(every);
	}
	else if (every->a_top->num < pivot_big)
		pb(every);
	else
		ra(every);
}

void	chunk_all(t_stack *every)
{
	int	index;
	int	pivot_small;
	int	pivot_big;

	index = every->a_size * 1 / 3;
	pivot_small = every->int_arr[index];
	index = every->a_size * 2 / 3;
	pivot_big = every->int_arr[index];
	index = every->a_size;
	while (index)
	{
		help_chunk(every, pivot_small, pivot_big);
		index--;
	}
}

void	sort_three(t_stack *every)
{
	int	max;
	int	mid;
	int	min;

	max = every->a_top->num;
	mid = every->a_top->next->num;
	min = every->a_top->next->next->num;
	if (max > mid && max > min && mid > min)
	{
		sa(every);
		rra(every);
	}
	else if (max > mid && max > min && min > mid)
		ra(every);
	else if (mid > max && mid > min && min > max)
	{
		sa(every);
		ra(every);
	}
	else if (max > mid && min > max && min > mid)
		sa(every);
	else if (max > min && mid > max && mid > min)
		rra(every);
}

void	sort_all(t_stack *every)
{
	int	rcommand_a;
	int	rcommand_b;

	chunk_all(every);
	while (every->a_size >= 4)
		pb(every);
	if (every->a_size == 2)
	{
		if (every->a_top->num > every->a_top->next->num)
			sa(every);
	}
	if (every->a_size == 3)
		sort_three(every);
	while (every->b_size)
	{
		rcommand_a = 0;
		rcommand_b = 0;
		find_best(every, &rcommand_a, &rcommand_b);
	}
	finish_sort(every);
}

void	start_sort(t_stack *every)
{
	if (every->a_size == 2)
	{
		if (every->a_top->num > every->a_top->next->num)
			sa(every);
	}
	else if (every->a_size == 3)
		sort_three(every);
	else
		sort_all(every);
}
