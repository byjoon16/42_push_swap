/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:27:27 by byjeon            #+#    #+#             */
/*   Updated: 2022/12/14 23:09:34 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int num)
{
	if (num == 1)
		write(2, "Error\n", 6);
	exit(1);
	return (-1);
}

int	ft_atoll(const char *str)
{
	long long	res;
	int			sign;
	int			cnt;

	res = 0;
	sign = 1;
	cnt = 0;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10;
		res += (*str - '0');
		str++;
		cnt++;
	}
	res *= sign;
	if (*str != '\0' || cnt > 10 || res > 2147483647 || res < -2147483648)
		ft_error(1);
	return ((int)res);
}

int	check_d(int i, int num, int *int_arr, int int_arr_size)
{
	int	j;

	j = i + 1;
	while (j < int_arr_size)
	{
		if (num == int_arr[j])
			return (1);
		j++;
	}
	return (0);
}

void	check_sorted(int *int_arr, int int_arr_size)
{
	int	i;
	int	j;
	int	tmp;
	int	checker;

	checker = 0;
	i = -1;
	while (++i < int_arr_size - 1)
	{
		if (check_d(i, int_arr[i], int_arr, int_arr_size))
			ft_error(1);
		j = -1;
		while (++j < int_arr_size - 1)
		{
			if (int_arr[j] > int_arr[j + 1])
			{
				tmp = int_arr[j];
				int_arr[j] = int_arr[j + 1];
				int_arr[j + 1] = tmp;
				checker++;
			}
		}
	}	
	if (checker == 0)
		ft_error(1);
}
