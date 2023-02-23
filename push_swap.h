/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:04:48 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/12/14 19:47:01 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				index;
}	t_stack;

/********** Push Swap **************/
void	resolve_stack(t_stack **stack_a, t_stack **stack_b);
void	index_stack(t_stack **stack);
t_stack	*init_stack(char **argv);

/********** Bit Funtions ***********/
int		count_bits(int n);
int		is_bit_set(int index, int bit);

/********** Controller *************/
int		stack_a_error(t_stack *stack_a);
int		errors(int argc, char **argv);
int		check_args(char **argv);
int		check_string(char **argv);
int		check_chars(int n, char **argv);
int		checker(int argc, char **argv);
t_stack	*arg_checker(char **argv);
int		num_checker(char **argv);
int		num_checker_arg(char **argv);
int		repeated(t_stack *stack);

/********** Control Utils **********/
void	free_pointer(char **str);
int		is_space(char c);
int		minus_checker(char *str);
void	insert_end(t_stack **root, int value);
int		ft_atoi_max_min(const char *str);

/********** Element Funtions *******/
int		smallest_element(t_stack *curr);
void	del_element(t_stack **stack, int value);
int		fst_element(t_stack **stack);
int		fst_ele_index(t_stack **stack);
int		last_element(t_stack **stack);
int		last_ele_index(t_stack **stack);
void	insert_beginning(t_stack **stack, int value, int index);
int		find_position(t_stack *stack_a, int index);

/********** Element Move ***********/
void	swap_first(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	move_top(t_stack **stack_a, int index);
int		count_move_top(t_stack **stack_a, int index);

/********** List Funtions **********/
void	deallocate_lst(t_stack **root);
int		lst_size(t_stack *stack);
t_stack	*copy_lst(t_stack *stack);

/********** Movements **************/
void	sa(t_stack **stack);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	ra(t_stack **stack);
void	rra(t_stack **stack);

/********** Resolve Utils **********/
void	short_three(t_stack **stack_a);
void	short_four(t_stack **stack_a, t_stack **stack_b);
void	short_ten(t_stack **stack_a, t_stack **stack_b);
void	radix_short(t_stack **stack_a, t_stack **stack_b);

/********** Stack Funtions *********/
t_stack	*fill_string(char **argv);
t_stack	*fill_args(char **argv);
void	add_index(t_stack **stack, int value, int index);
int		is_ordened(t_stack *stack);

#endif