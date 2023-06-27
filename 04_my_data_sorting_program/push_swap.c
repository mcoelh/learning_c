/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:14:21 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/24 19:23:40 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	get_free(t_node *a_list)
{
	t_node	*aux;

	aux = a_list;
	while (a_list->next != NULL)
	{
		a_list = a_list->next;
		free(aux);
		aux = NULL;
		aux = a_list;
	}
	free(a_list);
	a_list = NULL;
}

void	select_sort(int ac, t_node **a_list, t_node **b_list, int *array)
{
	if (ac == 3)
		sa_swap(a_list);
	else if (ac == 4)
		sort_three(a_list);
	else if (ac == 5)
		sort_four(a_list, b_list, array);
	else if (ac == 6)
		sort_five(a_list, b_list, array);
	else
	{
		transform_index((*a_list), array, ac - 1);
		radix_sort(a_list, b_list, get_size(a_list));
	}
}

t_node	*fill_stack(int argc, char **av)
{
	t_node	*lst;
	int		count;

	count = 1;
	lst = NULL;
	while (count < argc)
	{
		ft_add_back(&lst, ft_lstnew(ft_atol(av[count])));
		count++;
	}
	return (lst);
}

int	main(int argc, char **av)
{
	t_node	*a_list;
	t_node	*b_list;
	int		*array;

	a_list = NULL;
	b_list = NULL;
	if (argc == 1)
		return (0);
	av = ft_one_arg(&argc, av);
	if (validation(argc, av))
	{
		a_list = fill_stack(argc, av);
		if (!is_sorted(&a_list))
		{
			array = get_array(argc, av);
			select_sort(argc, &a_list, &b_list, array);
			free(array);
		}
		if (is_sorted(&a_list))
			get_free(a_list);
	}
	free_split(av);
	return (0);
}
