/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:57:17 by byjeon            #+#    #+#             */
/*   Updated: 2022/11/10 18:51:07 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *every)
{
	t_node	*tmp;

	if (every->a_size <= 1)
		return ;
	tmp = every->a_bot;
	every->a_bot = every->a_bot->prev;
	every->a_bot->next = NULL;
	every->a_top->prev = tmp;
	tmp->next = every->a_top;
	every->a_top = tmp;
	every->a_top->prev = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *every)
{
	t_node	*tmp;

	if (every->b_size <= 1)
		return ;
	tmp = every->b_bot;
	every->b_bot = every->b_bot->prev;
	every->b_bot->next = NULL;
	every->b_top->prev = tmp;
	tmp->next = every->b_top;
	every->b_top = tmp;
	every->b_top->prev = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *every)
{
	t_node	*tmp;

	if (every->b_size <= 1 || every->a_size <= 1)
		return ;
	tmp = every->a_bot;
	every->a_bot = every->a_bot->prev;
	every->a_bot->next = NULL;
	every->a_top->prev = tmp;
	tmp->next = every->a_top;
	every->a_top = tmp;
	every->a_top->prev = NULL;
	tmp = every->b_bot;
	every->b_bot = every->b_bot->prev;
	every->b_bot->next = NULL;
	every->b_top->prev = tmp;
	tmp->next = every->b_top;
	every->b_top = tmp;
	every->b_top->prev = NULL;
	write(1, "rrr\n", 4);
}
