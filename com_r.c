/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:55:17 by byjeon            #+#    #+#             */
/*   Updated: 2022/11/10 18:47:00 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *every)
{
	t_node	*tmp;

	if (every->a_size <= 1)
		return ;
	tmp = every->a_top;
	every->a_top = every->a_top->next;
	every->a_top->prev = NULL;
	every->a_bot->next = tmp;
	tmp->prev = every->a_bot;
	every->a_bot = tmp;
	every->a_bot->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *every)
{
	t_node	*tmp;

	if (every->b_size <= 1)
		return ;
	tmp = every->b_top;
	every->b_top = every->b_top->next;
	every->b_top->prev = NULL;
	every->b_bot->next = tmp;
	tmp->prev = every->b_bot;
	every->b_bot = tmp;
	every->a_bot->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack *every)
{
	t_node	*tmp;

	if (every->b_size <= 1 || every->a_size <= 1)
		return ;
	tmp = every->a_top;
	every->a_top = every->a_top->next;
	every->a_top->prev = NULL;
	every->a_bot->next = tmp;
	tmp->prev = every->a_bot;
	every->a_bot = tmp;
	every->a_bot->next = NULL;
	tmp = every->b_top;
	every->b_top = every->b_top->next;
	every->b_top->prev = NULL;
	every->b_bot->next = tmp;
	tmp->prev = every->b_bot;
	every->b_bot = tmp;
	every->a_bot->next = NULL;
	write(1, "rr\n", 3);
}
