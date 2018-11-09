
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
////////////list



typedef struct sudoku sudoku;
struct sudoku {
	int value;
	sudoku *next;
	char is_const;
	int i;
	int j;
};
typedef struct arbre arbre;
struct arbre{
    sudoku* debut;
    arbre* next;
};

arbre* create_arbre(sudoku *l)
{
    arbre* element = (arbre*)malloc(sizeof(arbre));
    element->debut=l;
    element->next=NULL;
    return element;
}

void add_arbre(arbre **head,sudoku *l)
{
    arbre *elem=create_arbre(l);
    if(*head == NULL)
    {
        *head =  elem;
        return ;
    }
    arbre *tmp = *head;
    *head = elem;
    elem->next = tmp;
}

void	supp_arbre(arbre **head, sudoku *l)
{
	arbre *tmp = *head;
	if (tmp->debut == l)
	{
		(*head)->next = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp->next->next && tmp->next->debut !=l)
		tmp = tmp->next;
	if (tmp->next->debut == l)
	{
		arbre *dp = tmp->next;
		tmp->next = tmp->next->next;
		free(dp);
	}
}


sudoku *create_posibilite(int value,int i,int j)
{
	sudoku *element = (sudoku*)malloc(sizeof(sudoku));
	element->value = value;
	element->next = NULL;
	element->is_const = 'n';
	//element->count = 0;
	element->i=i;
	element->j=j;
	return (element);
}

void	add_posibilite(sudoku **head, int value,int i,int j)
{
	sudoku *elem = create_posibilite(value,i,j);
	
	if (*head == NULL)
	{
		*head = elem;
		return ;
	}
	sudoku *tmp = *head;
	*head = elem;
	elem->next = tmp;
}

void	supp_posibilite(sudoku **head, int value)
{
	sudoku *tmp = *head;
	if(*head==NULL) return;
	if (tmp->value == value)
	{
		*head = tmp->next;
		free(tmp);
		return ;
	}
	if(tmp->next==NULL) return;
	while (tmp->next->next && tmp->next->value !=value)
		tmp = tmp->next;
	if (tmp->next->value == value)
	{
		sudoku *dp = tmp->next;
		tmp->next = tmp->next->next;
		free(dp);
	}
}

void affpos(sudoku *l)
{
    while(l)
    {
        printf("%d |",l->value);
        l=l->next;
    }
}

void viderList(sudoku **l)
{
   if((*l)==NULL)
    {free(l);return ;}
    sudoku* tmp = *l;
    while(l)
    {
        tmp = *l;
        *l=(*l)->next;
        free(tmp);
    }
    
}

int count_list(sudoku* l)
{  
    int c=0;
    while(l)
    {
        c++;
        l=l->next;
    }
    return (c);
    
}

void suppArbre(arbre* a,int value)
{
    sudoku* tmp;
    while(a)
    {
        //tmp = a->debut;
        supp_posibilite(&(a->debut),value);
        a=a->next;
        
    }
}

sudoku  Union(arbre *a)
{   
    sudoku l1={0,NULL,'n',-1,-1};
    sudoku* l2;
    int cp;
    arbre* tmp=a;
    while(tmp)
    {
        if(count_list(tmp->debut) == 1)
        {
            l1.value=tmp->debut->value;
            l1.i=tmp->debut->i;
            l1.j=tmp->debut->j;
            suppArbre(a,tmp->debut->value);
            //return tmp->debut;
            break;
        }
        
        tmp=tmp->next;
    }
    /*
    tmp =a;
    int trouve=1;
    while(a)
    {   l1=a->debut;
        
        while(tmp)
        {   l2=tmp->next->debut;
            while(l2)
            {
                if(l1->value > l2->value) { trouve = 0; break ;}
                if (l1->value == l2->value) {  trouve = 1; break ;}
                l2=l2->next;
            }
            
        }
        
    }*/
    return l1;
}

void affArbre(arbre* a)
{
    sudoku* tmp;
    while(a)
    {
        tmp = a->debut;
        affpos(tmp);
        a=a->next;
        
    }
}


/////////////fin list

int is_in_square(int t[9][9],int row, int col, int value)
{
	int i,j;
	i =0;
	while (i< 3)
	{	j =0;
		while( j< 3)
		{
			if (t[i+row][j+col] == value)
				return (1);
			j++;	
		}
		i++;
	}
	return (0);
}

int is_in_row(int t[9][9], int row,int col, int value)
{
	int i;
	i = 0;
	while ( i< 9)
	{
		if (t[i][col] == value)
			return (1);
		i++;
	}
	return (0);
}

int is_in_col(int t[9][9], int row,int col, int value)
{
	int i;
	i = 0;
	while ( i< 9)
	{
		if (t[row][i] == value)
			return (1);
		i++;
	}
	return (0);
}
void	ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	affichage(int t[9][9])
{
	int i;
	int j;
	i = 0;
	while (i < 9 )
	{
	j = 0;
		while (j< 9)
		{
			printf("%d | ",t[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void posi(int t[9][9])
{
	int i,j;
	int k;
	int si;
	int sj;
	int l;
	int c;
	int cp;
	sudoku* debut=NULL;
	l = 0;
	si=0;
	sj=0;
	int d;
	arbre* a=NULL;
	
	while(l < 3)
	{
	    c =0;
	    si+=3;sj=0;
	    while(c<3)
	    {
	        sj+=3;
	        ///////
	        i=si-3;
	        while(i<si)
	        {   
	            j=sj-3;
		        while(j<sj)
	        	{	
		        	if(t[i][j] == 0)
			        {	k = 1;
			            cp=0;
			            debut=NULL;
				        while( k<= 9)
				        {
				            if(!is_in_square(t,i-i%3,j-j%3,k))
					        {
						        if(!is_in_row(t,i,j,k))
						        {
							        if(!is_in_col(t,i,j,k))
							        {
								
								        //printf("%d[%d,%d]| ",k,i,j);
								        add_posibilite(&debut,k,i,j);
								        cp++;
								        
							        }
						        }
					        }
				        k++;
			        	}
			        	//affpos(debut);
			        	//viderList(debut);
			        	//free(debut);
			        	add_arbre(&a,debut);
			        	//affArbre(a);
				       // printf("\n");
		    	    }   
			        j++;
			
		        }
		        i++;
	        }
	            d=1;
	            while(d)
	            {d=0;
	                
	            
	            sudoku x=Union(a);
	        if(x.value!=0) {printf("----> %d[%d,%d] :  ",x.value,x.i,x.j); 
	        
	            t[x.i][x.j]=x.value;
	          d=1;
	            
	        }
	        affArbre(a);
	        printf("\n");
	            }
	        //affichage(t);
	        
	        
	        a=NULL;
	      ////////
	      c++;  
	    }
	    l++;
	}


	i =0;
	
}


int main(int argc, char **argv)
{
/*	int Sudoku[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};*/

	//affichage(Sudoku);
	//posi(Sudoku);
	sudoku* debut=NULL;
	sudoku* elem1=create_posibilite(5,1,1);
    sudoku* elem2=create_posibilite(8,1,1);
	sudoku* elem3=create_posibilite(9,1,1);
	sudoku* elem4=create_posibilite(9,1,1);
	
	debut=elem1;
	elem1->next=elem2;
	elem2->next=elem3;
	elem3->next=elem4;
	affpos(debut);
	supp_posibilite(&debut,9);
	supp_posibilite(&debut,9);
	supp_posibilite(&debut,8);
	supp_posibilite(&debut,9);
	printf("\n");
	affpos(debut);
	

	return 0;
}
