#include <stdio.h>

double phi(double g, int precision)
{
	if( precision )
		return(g + 1/phi(g,precision-1) );
	return(g);
}

int main()
{
	double gr;

	gr = phi(1.0,15);
	printf("The golden ratio is %f\n",gr);

	return(0);
}
