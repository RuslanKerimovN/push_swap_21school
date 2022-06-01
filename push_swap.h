/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:04:37 by botilia           #+#    #+#             */
/*   Updated: 2022/06/01 18:25:25 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int				par;
	int				score_rev_a;
	int				score_rr_a;
	int				score_rev_b;
	int				score_rr_b;
	int				rb_rr;
	int				ra_rr;
	int				rrb_rrr;
	int				rra_rrr;
	int				ra_rrb;
	int				rra_rb;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;

//ft_lists
t_list	*ft_lst_new(int par);
void	ft_lst_add_front(t_list *lst, int arr);
void	ft_lst_add_back(t_list **lst, int par);
int		ft_atoi(const char *str);
t_list	*make_stack_a(t_list *stack_a, char **argv);
//command
void	swap(t_list **stack_a);
void	rev(t_list **stack_a);
void	rr(t_list **stack_a);
void	push(t_list **lst, t_list **tmp);
void	del_back(t_list **lst);
//command_go
void	go_swap(t_list **stack_a, t_list **stack_b, char flag);
void	go_rev(t_list **stack_a, t_list **stack_b, char flag);
void	go_rr(t_list **stack_a, t_list **stack_b, char flag);
void	go_push(t_list **stack_a, t_list **stack_b, char flag);
//sort_int_mass
void	sort_bubble(int *mass, int j);
int		*sec_mass(char **argv, int argc);
int		*ft_strdup(int *s1, int argc);
//score
void	score_b(t_list **s_b);
void	score_a_piece(t_list **s_b, t_list *tmp_a);
void	score_a(t_list **s_a, t_list **s_b);
void	find_score(t_list **s_a, t_list **s_b);
//find_steps
int		rb_ra_rr(int rev_b, int rev_a);
int		rrb_rra_rrr(int rr_b, int rr_a);
int		ra_rrb(int rev_a, int rr_b);
int		rra_rb(int rev_b, int rr_a);
void	steps(t_list **s_b);
//tools
int		find_len_list(t_list **s_a);
t_list	*ft_lstlast(t_list *lst);
int		find_min(t_list **s_b, int min);
void	final_step(t_list **s_a, int max);
void	clear_stack(t_list **stack_a);
//tools_2
char	*ft_strjoin(char *s1, char *s2);
int		find_argc(char **argv);
void	sorting(t_list **stack_a, t_list **stack_b, int argc, int *mass);
void	clearing(t_list *stack_a, t_list *stack_b);
//pushing
void	rb_ra_rr_function(t_list **s_a, t_list **s_b, t_list **s_bp);
void	rrb_rra_rrr_function(t_list **s_a, t_list **s_b, t_list **s_bp);
void	ra_rrb_function(t_list **s_a, t_list **s_b, t_list **s_bp);
void	rra_rb_function(t_list **s_a, t_list **s_b, t_list **s_bp);
void	pushing(t_list **s_a, t_list **s_b, int min);
//sort_final
void	sort_min(t_list **s_a, char flag);
void	sort_three(t_list **s_a);
void	sort_five(t_list **s_a, t_list **s_b, int count, int *mass);
void	big_sorting(t_list **s_a, t_list **s_b);
void	sort(t_list **s_a, t_list **s_b, int count, int *mass);
//chekers
int		ft_strlen(char *s);
void	check_sym(char **argv, int argc);
int		*check_sorted(int *mass, int argc);
void	check_repeat(int *mass, int argc);
void	error(int i);
//split
int		ft_numstr(char *s, char c);
char	*ft_cpy(char *s1, char *s2, int size);
char	**ft_free(char **mass);
char	**ft_podstr(char *str, char **mass, char c);
char	**ft_split(char const *s, char c);

//////////////////////////////////////////////////////////////////////////////
void check(t_list *stack_a);

#endif
