/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:22:30 by byjeon            #+#    #+#             */
/*   Updated: 2022/12/14 20:04:17 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arcom(t_stack *every, int *rcommand_a)
{
	while (*rcommand_a)
	{
		if (*rcommand_a > 0)
		{
			ra(every);
			(*rcommand_a)--;
		}
		else
		{
			rra(every);
			(*rcommand_a)++;
		}
	}
}

void	brcom(t_stack *every, int *rcommand_b)
{
	while (*rcommand_b)
	{
		if (*rcommand_b > 0)
		{
			rb(every);
			(*rcommand_b)--;
		}
		else
		{
			rrb(every);
			(*rcommand_b)++;
		}
	}
	pa(every);
}

void	rrcom(t_stack *every, int *rcommand_a, int *rcommand_b)
{
	while (*rcommand_a && *rcommand_b && (*rcommand_a > 0 && *rcommand_b > 0))
	{
		rr(every);
		(*rcommand_a)--;
		(*rcommand_b)--;
	}
	while (*rcommand_a && *rcommand_b && (*rcommand_a < 0 && *rcommand_b < 0))
	{
		rrr(every);
		(*rcommand_a)++;
		(*rcommand_b)++;
	}
}

void	finish_sort(t_stack *every)
{
	int	min;
	int	min_pos;

	min = min_num(every->a_top);
	min_pos = min_position(every, min);
	while (min_pos)
	{
		if (min_pos > 0)
		{
			ra(every);
			min_pos--;
		}
		else
		{
			rra(every);
			min_pos++;
		}
	}
}
