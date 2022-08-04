#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* the structure proves to be more flexible than
   creating a two-dimensional array. Arrays in C
   are all single dimension anyhow, with the compiler
   doing the math for any dimensions specified.
   This approach allows the matrix to be dynamic
   and keeps all the details in a single package */
struct matrix {
	int rows;
	int cols;
	char *cells;
};

/* assign random characters to the matrix */
void fill_matrix(struct matrix g)
{
	int row,col;

	for( row=0; row<g.rows; row++ )
		for( col=0; col<g.cols; col++ )
			*(g.cells+(row*g.cols)+col) = (rand() % 26) + 'a';
}

/* output the matrix values */
void output_matrix(struct matrix g)
{
	int row,col;

	for( row=0; row<g.rows; row++ )
	{
		for( col=0; col<g.cols; col++ )
			printf(" %c",*(g.cells+(row*g.cols)+col));
		putchar('\n');
	}
}

/* use a temporary structure to rotate the matrix,
   writing the rotated contents back into the 
   original matrix */
/* if the matrix isn't passed as a pointer,
   modifications made to the rows and cols members
   remain local to this function */
void rotate_matrix(struct matrix *g)
{
	struct matrix *r;
	int rsize,x,y,i;

	/* create the new (temporary) matrix */
	r = (struct matrix *)malloc( sizeof(struct matrix) );
	if( r==NULL )
	{
		fprintf(stderr,"Unable to allocate new matrix\n");
		exit(1);
	}
	/* swap the rows and columns (for output) */
	r->rows = g->cols;
	r->cols = g->rows;
	rsize = r->rows*r->cols;
	r->cells = (char *)malloc( sizeof(char)*rsize );
	if( r->cells==NULL )
	{
		fprintf(stderr,"Unable to allocate cell memory\n");
		exit(1);
	}

	/* fill the new matrix with rotated contents */
	i = 0;
	for( x=0; x<g->cols; x++ )
	{
		for( y=g->rows-1; y>=0; y-- )
		{
			/* The cells are read in a rotated fashion,
			   from the bottom of the first column up
			   row-by-row, to the top of the last column.
			   The rotated cell's contents are filled
			   sequentially using variable 'i' */
			*(r->cells+i) = *(g->cells+(g->cols*y)+x);
			i++;
		}
	}

	/* copy back to the original matrix */
	for( i=0; i<rsize; i++ )
		*(g->cells+i) = *(r->cells+i);
	/* reset original matrix dimensions */
	g->cols = r->cols;
	g->rows = r->rows;

	/* free allocated memory */
	free(r->cells);
	free(r);
}

int main()
{
	/* using NULL pointers allows me to provide the
	   basic data without specifying a variable-size
	   character buffer */
	struct matrix grid[3] = {
		{ 8, 3, NULL },
		{ 5, 5, NULL },
		{ 4, 6, NULL }
	};
	int x;

	/* initialize the randomizer */
	srand( (unsigned)time(NULL) );

	/* allocate storage for the grids */
	for( x=0; x<3; x++ )
	{
		grid[x].cells = \
			(char *)malloc( sizeof(char)*grid[x].rows*grid[x].cols );
		if( grid[x].cells==NULL )
		{
			fprintf(stderr,"Memory allocation error on grid #%d\n",
					x
				   );
			exit(1);
		}
	}

	/* the heavy lifting is handled by the functions,
	   so the for loop here can be tight and readable */
	for( x=0; x<3; x++ )
	{
		fill_matrix(grid[x]);
		printf("Original matrix %d:\n",x+1);
		output_matrix(grid[x]);
		rotate_matrix(&grid[x]);
		printf("Rotated matrix: %d:\n",x+1);
		output_matrix(grid[x]);
	}

	return(0);
}
