/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:00:39 by byjeon            #+#    #+#             */
/*   Updated: 2022/11/11 15:04:29 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_av(char **av)
{
	int	i;

	if (av[1][0] == '\0')
		ft_error(-1);
	i = 1;
	while (av[i])
	{
		if ((av[i][0] == '-' && av[i][1] == '\0') \
			|| (av[i][0] == '+' && av[i][1] == '\0') \
			|| av[i][0] == '\0')
		{
			ft_error(1);
		}
		i++;
	}
	return (i - 1);
}

int	count_size(int ac, char **av)
{
	int		i;
	int		j;
	int		size;

	i = 1;
	size = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!((av[i][j] >= '0' && av[i][j] <= '9') \
				|| av[i][j] == '-' || av[i][j] == '+'))
				break ;
			j++;
		}
		if (av[i][j] != '\0')
			ft_error(1);
		i++;
	}
	size = size_av(av);
	return (size);
}

void	fill_int_arr(int *int_arr, int *arr_index, char **av)
{
	int	i;
	int	tmp;

	i = 1;
	while (av[i] != NULL)
	{
		tmp = ft_atoll(av[i]);
		int_arr[*arr_index] = tmp;
		(*arr_index)++;
		i++;
	}
}

int	*make_int_arr(char **av, int int_arr_size)
{
	int		arr_index;
	int		*int_arr;

	int_arr = (int *)malloc(sizeof(int) * int_arr_size);
	if (!int_arr)
		ft_error(-1);
	arr_index = 0;
	fill_int_arr(int_arr, &arr_index, av);
	int_arr[arr_index] = '\0';
	return (int_arr);
}

void	make_stack(t_stack *every, int *int_arr, int int_arr_size)
{
	int			idx;
	t_node		*new;

	idx = 0;
	while (idx < int_arr_size)
	{
		every->a_bot->num = int_arr[idx];
		if (idx == int_arr_size - 1)
		{
			every->a_size++;
			break ;
		}
		new = new_node();
		every->a_bot->next = new;
		new->prev = every->a_bot;
		every->a_bot = new;
		every->a_size++;
		idx++;
	}
}
