/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_group_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnidorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:49:05 by jnidorin          #+#    #+#             */
/*   Updated: 2022/02/23 15:49:09 by jnidorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Устанавливает, что поколение отсортировано, перекидывает верхний элемент вниз
void	inverse_stack(t_all *all)
{
	all->stack_a->flag = -1;
	ra(all, 1);
}

void	stack_b_sorting_three(t_all *all)
{
	int	main_index;
	int	next_index;
	int	previous_index;

	if (all->size_b == 0)
		return ;
	main_index = all->stack_b->index;
	next_index = all->stack_b->next->index;
	previous_index = all->stack_b->prev->index;
	if (next_index > main_index && next_index > previous_index)
		rrb(all, 1);
	else if (main_index > next_index && main_index > previous_index)
		rb(all, 1);
	main_index = all->stack_b->index;
	next_index = all->stack_b->next->index;
	if (main_index > next_index)
		sb(all, 1);
}

// Продолжение сортировки стек Б 5 элементов
void	aftermath_sorting_three(t_all *all, int flag)
{
	stack_b_sorting_three(all);
	if (all->stack_a->index > all->stack_a->next->index && \
		all->stack_a->flag == all->stack_a->next->flag)
		sa(all, 1);
	while (all->size_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || \
			all->stack_a->flag == -1)
		{
			pa(all, 1);
			inverse_stack(all);
		}
		else
			inverse_stack(all);
	}
	while (all->stack_a->flag == flag && flag != -1 && \
			all->stack_a->index +1 == all->stack_a->prev->index)
		inverse_stack(all);
}

// Перебирает числа, порядок элемента равен минимальному -
// перекидываем, стек разворачиваем
void	stack_b_sorting_five(t_all *all)
{
	int		flag;
	int		min;
	int		i;

	i = all->size_b;
	min = all->stack_a->prev->index + 1;
	flag = all->stack_a->flag;
	while (i > 3)
	{
		if (all->stack_b->index == min)
		{
			pa(all, 1);
			inverse_stack(all);
			min++;
		}
		else
			pa(all, 1);
		i--;
	}
	aftermath_sorting_three(all, flag);
}

// Из Б в А перекидываем мминимальные элементы/разбиваем по поколениям
void	send_from_b_to_a(t_all *all)
{
	int	i;

	stack_b_find_minmax_med(all);
	i = all->size_b;
	while (i-- > 0)
	{
		if (search_min_b_to_a(all))
			continue ;
		if (all->stack_b->index > all->med)
		{
			all->stack_b->flag++;
			pa(all, 1);
		}
		else
		{
			all->stack_b->flag++;
			rb(all, 1);
		}
	}
}
