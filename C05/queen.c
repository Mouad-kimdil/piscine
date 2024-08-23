#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int	chess_board[20];
int	count;

int	my_abs(int n)
{
	return ((n < 0) ? -n : n);
}

int	placeholder(int row, int col)
{
	int	count;

	count = 1;
	while (count <= row - 1)
	{
		if(chess_board[count] == col)
			return (0);
		else
		{
			if(my_abs(chess_board[count] - col) == my_abs(count - row))
				return (0);
		}
		count++;
	}
	return (1);
}

void	display(int num)
{
	int	m;
	int	n;

	printf("\n\n\tPossible Solution %d:\n\n", ++count);
	m = 0;
	while (++m <= num)
		printf("\t[%d]", m);
	m = 0;
	while (++m <= num)
	{
		printf("\n\n[%d]", m);
		n = 0;
		while (++n <= num)
		{
			if(chess_board[m] == n)
				printf("\tQ");
			else
				printf("\t*");
		}
	}
}

void	nqueen_function(int row, int num)
{
	int	col;

	col = 1;
	while (col <= num)
	{
		if(placeholder(row, col))
		{
			chess_board[row] = col;
			if(row == num)
				display(num);
			else
				nqueen_function(row + 1, num);
		}
		col++;
	}
}

int	main()
{
	int	num;

	printf("\nEnter Number of Queens:\t");
	scanf("%d", &num);
	if(num <= 3)
		printf("\nNumber should be greater than 3 to form a Matrix\n");
	nqueen_function(1, num);
	printf("\n\n");
	return (0);
}
