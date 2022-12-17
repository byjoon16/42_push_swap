/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:56:38 by byjeon            #+#    #+#             */
/*   Updated: 2022/11/10 19:46:28 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *every)
{
	t_node	*tmp;

	if (every->b_size <= 0)
		return ;
	tmp = every->b_top;
	if (every->b_size >= 2)
	{
		every->b_top = every->b_top->next;
		every->b_top->prev = NULL;
	}
	if (every->a_size == 0)
	{
		every->a_top = tmp;
		every->a_bot = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = every->a_top;
		every->a_top->prev = tmp;
		every->a_top = tmp;
	}
	every->a_size++;
	every->b_size--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *every)
{
	t_node	*tmp;

	if (every->a_size <= 0)
		return ;
	tmp = every->a_top;
	if (every->a_size >= 2)
	{
		every->a_top = every->a_top->next;
		every->a_top->prev = NULL;
	}
	if (every->b_size == 0)
	{
		every->b_top = tmp;
		every->b_bot = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = every->b_top;
		every->b_top->prev = tmp;
		every->b_top = tmp;
	}
	every->a_size--;
	every->b_size++;
	write(1, "pb\n", 3);
}
