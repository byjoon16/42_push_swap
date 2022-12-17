/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:52:06 by byjeon            #+#    #+#             */
/*   Updated: 2022/12/14 23:08:43 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int				*int_arr;
	int				a_size;
	int				b_size;
	struct s_node	*a_top;
	struct s_node	*a_bot;
	struct s_node	*b_top;
	struct s_node	*b_bot;
}	t_stack;

// com_psr.c
void		pa(t_stack *every);
void		pb(t_stack *every);
void		sa(t_stack *every);
void		sb(t_stack *every);
void		ss(t_stack *every);
void		ra(t_stack *every);
void		rb(t_stack *every);
void		rr(t_stack *every);
void		rra(t_stack *every);
void		rrb(t_stack *every);
void		rrr(t_stack *every);

// init.c
t_node		*new_node(void);
t_stack		*new_stack(void);
void		ft_clean(t_stack *every);

// setting_1.c, setting_2.c
int			size_av(char **av);
int			count_size(int ac, char **av);
void		fill_int_arr(int *int_arr, int *arr_index, char **av);
int			*make_int_arr(char **av, int int_arr_size);
void		make_stack(t_stack *every, int *int_arr, int int_arr_size);
int			ft_error(int num);
int			ft_atoll(const char *str);
int			check_d(int i, int num, int *int_arr, int int_arr_size);
void		check_sorted(int *int_arr, int int_arr_size);

// sort_1234.c
void		start_sort(t_stack *every);
void		help_chunk(t_stack *every, int pivot1, int pivot2);
void		chunk_all(t_stack *every);
void		sort_three(t_stack *every);
void		sort_all(t_stack *every);
int			find_position(int b_num, t_stack *every);
int			choose_better(int a, int b, int a_pos, int b_pos);
void		do_best(t_stack *every, int *rcommand_a, int *rcommand_b);
void		find_best(t_stack *every, int *rcommand_a, int *rcommand_b);
void		finish_sort(t_stack *every);
int			min_num(t_node *stack);
int			max_num(t_node *stack);
int			min_position(t_stack *every, int min);
int			mid_position(t_stack *every, int num);
int			max_position(t_stack *every, int max);
void		arcom(t_stack *every, int *rcommand_a);
void		brcom(t_stack *every, int *rcommand_b);
void		rrcom(t_stack *every, int *rcommand_a, int *rcommand_b);

#endif