/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:58:09 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/05 14:59:57 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

void        *ft_calloc(size_t nmemb, size_t size);
int         check(char **av);
int         inrange(char **av);
int         **put_in_stack(char **av, int ac);
int         sorted(int **a, int **b);
int         parse_all(char **av, int ac);
void        ft_putstr(const char *s);
long int	ft_atoi(const char *str);
void	    free_stack(int **stack);
void	    quit(int **stack_a, int **stack_b, int yayornay);
char	    **splitavs(int ac, char **av);
char	    **ft_split(char const *s, char c);
char        *ft_strdup(const char *src);
int         ft_strncmp(const char *s1, const char *s2, size_t n);
char	    *ft_strjoin(char const *s1, char const *s2);
char	    *ft_substr(char const *s, unsigned int start, size_t len);
int         ft_strlen(const char *s);
void	    free_input(char **argv);
char	    *argtostr(int ac, char **av);
int         argcount(char **av);
int         last_index(int **a);
// Moves
void        rotate(int **a);
void        revrot(int **a);
void        ft_putstr(const char *s);
void	    pb(int **stack_a, int **stack_b);
void	    pa(int **stack_a, int **stack_b);
void	    rrb(int **stack_b);
void	    rrr(int **stack_b, int **stack_a);
void	    rra(int **stack_a);
void	    sb(int **stack_b);
void	    ss(int **stack_b, int **stack_a);
void	    sa(int **stack_b);
void        rr(int **stack_b, int **stack_a);
void        ra(int **stack_b);
void        rb(int **stack_b);

//Printf Stuff
int         ft_printf(const char *format, ...);
int         ft_printptr(unsigned long long ptr);
int         ft_printunsigned(unsigned int n);
int         ft_printhex(unsigned int num, const char format);
size_t      intputnbr(int n);
size_t      uintputnbr(unsigned int n);
int         ft_printpercent(void);
int         ft_printstr(char *s);
size_t      ft_putchar(int c);

#endif