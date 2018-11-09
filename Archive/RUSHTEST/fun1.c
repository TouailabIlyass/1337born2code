#include <stdlib.h>
#include "struc.h"

arbre    *create_arbre(sudoku *l)
{
    arbre    *element;
    
    element = (arbre*)malloc(sizeof(arbre));
    element->debut = l;
    element->next = NULL;
    return (element);
}

void    add_arbre(arbre **head, sudoku *l)
{
    arbre *tmp;
    arbre *elem;
    
    tmp = *head;
    elem = create_arbre(l);
    if (*head == NULL)
    {
        *head = elem;
        return ;
    }
    *head = elem;
    elem->next = tmp;
}

sudoku    *create_posibilite(int value, int i, int j)
{
    sudoku *element;
    
    element = (sudoku*)malloc(sizeof(sudoku));
    element->value = value;
    element->next = NULL;
    element->is_const = 'n';
    element->i = i;
    element->j = j;
    return (element);
}

void    add_posibilite(sudoku **head, int value, int i, int j)
{
    sudoku *elem;
    sudoku *tmp;
    
    elem = create_posibilite(value, i, j);
    if (*head == NULL)
    {
        *head = elem;
        return ;
    }
    tmp = *head;
    *head = elem;
    elem->next = tmp;
}

void    supp_posibilite(sudoku **head, int value)
{
    sudoku *tmp;
    
    tmp = *head;
    if (*head == NULL)
    {
        return ;
    }
    if (tmp->value == value)
    {
        *head = tmp->next;
        free(tmp);
        return ;
    }
    if (tmp->next == NULL)
    {
        return ;
    }
    while (tmp->next->next && tmp->next->value != value)
    {
        tmp = tmp->next;
    }
    if (tmp->next->value == value)
    {
        sudoku *dp;
        
        dp = tmp->next;
        tmp->next = tmp->next->next;
        free(dp);
    }
}
