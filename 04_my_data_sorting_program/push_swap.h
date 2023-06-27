/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:32:46 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/01/24 19:26:13 by mcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
}				t_node;

long int	ft_atol(char *nptr);
t_node		*ft_last(t_node *lst);
t_node		*ft_lstnew(int nbr);
t_node		*fill_stack(int argc, char **av);
size_t		ft_strlen(char *s);
void		ft_add_back(t_node **lst, t_node *new);
void		transform_index(t_node *lst_a, int *array, int size);
int			ft_isdigit(int c);
int			*get_array(int ac, char **av);
int			validation(int ac, char **av);
int			ft_strcmp(char *s1, char *s2);
int			is_repeated(char **av);
int			is_nbr(int ac, char **av);
int			nbr_range(char **av);
char		**ft_one_arg(int *argc, char **argv);
char		*ft_strjoin(char *s1, char *s2);
void		push(t_node **src, t_node **dest);
void		push_pb(t_node **a_list, t_node **b_list);
void		push_pa(t_node **b_list, t_node **a_list);
void		rotate(t_node **lst);
void		rotate_ra(t_node **a_list);
void		rotate_rb(t_node **b_list);
void		rotate_rr(t_node **a_list, t_node **b_list);
void		swap(t_node **lst);
void		sa_swap(t_node **a_list);
void		sb_swap(t_node **b_list);
void		ss_swap(t_node **a_list, t_node **b_list);
void		reverse(t_node **lst);
void		reverse_rra(t_node **a_list);
void		reverse_rrb(t_node **b_list);
void		reverse_rrr(t_node **a_list, t_node **b_list);
void		sort_three(t_node **lst);
void		sort_five(t_node **a_list, t_node **b_list, int *aux);
void		sort_four(t_node **a_list, t_node **b_list, int *aux);
void		radix_sort(t_node **a_list, t_node **b_list, int max_bits);
void		to_b(t_node **a_list, t_node **b_list, int bit);
void		find_shorter(t_node **a_list, t_node **b_list, int *aux);
int			is_sorted(t_node **a_list);
int			get_bits(int size);
int			get_size(t_node **lst);

#endif
