#ifndef __FT_OPER__
# define __FT_OPER__
# include "list.h"
# include "afficher.h"



void        ch_do_op(t_list *ptr, t_list **head);
int            ft_get_value(t_list **head);
int            ft_calc(t_list **head);
int            ft_is_oper(char c);
void        ft_put_into_list(t_list **head, char *str);
#endif
