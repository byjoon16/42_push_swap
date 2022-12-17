/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:50:54 by byjeon            #+#    #+#             */
/*   Updated: 2022/11/11 15:12:03 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			int_arr_size;
	int			*int_arr;
	t_stack		*every;

	if (ac < 2)
		ft_error(-1);
	int_arr_size = 0;
	every = new_stack();
	int_arr_size = count_size(ac, av);
	int_arr = make_int_arr(av, int_arr_size);
	make_stack(every, int_arr, int_arr_size);
	check_sorted(int_arr, int_arr_size);
	every->int_arr = int_arr;
	start_sort(every);
	ft_clean(every);
	return (0);
}
