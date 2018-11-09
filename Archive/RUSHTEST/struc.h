typedef	struct sudoku	sudoku;
		struct	sudoku
{
	int		value;
	sudoku	*next;
	char	is_const;
	int		i;
	int		j;
};

typedef	struct arbre	arbre;
		struct	arbre
{
	sudoku	*debut;
	arbre	*next;
};