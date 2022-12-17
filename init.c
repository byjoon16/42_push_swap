/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:06:41 by byjeon            #+#    #+#             */
/*   Updated: 2022/11/11 15:07:52 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean(t_stack *every)
{
	t_node	*tmp;

	tmp = every->a_top;
	while (tmp)
	{
		every->a_top = every->a_top->next;
		free(tmp);
		tmp = every->a_top;
	}
	free(every->int_arr);
	free(every);
}

t_node	*new_node(void)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		exit(-1);
	new->num = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*new_stack(void)
{
	t_node		*a_stack;
	t_stack		*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(-1);
	a_stack = new_node();
	new->a_size = 0;
	new->b_size = 0;
	new->a_top = a_stack;
	new->a_bot = a_stack;
	new->b_top = NULL;
	new->b_bot = NULL;
	new->int_arr = NULL;
	return (new);
}
