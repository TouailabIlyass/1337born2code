#ifndef __FT_AFFICHER__
# define __FT_AFFICHER__
# include "list.h"



t_list        *remove_par(t_list *tmp2, t_list **head);
t_list        *calculer(t_list *tmp2, t_list **head);
int            ft_prod(t_list **head, t_list *tmp2, t_list *ptr);
int            ft_plus(t_list **head, t_list *tmp2, t_list *ptr);

#endif
