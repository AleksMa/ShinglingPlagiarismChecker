#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
int main(int argc, char **argv)
{ 
        long int i, n, x, polynom, difpolynom, a;
        scanf ("%ld%ld", &n, &x);
        polynom = 0;
        difpolynom = 0;
        for (i = n; i >=0 ; i--)  {
		scanf ("%ld", &a);
		//схема Горнера
                if (i==n) {
		        polynom = a*x;
		        if (i>1) difpolynom = a*x*n;
		        else if (i==0)  difpolynom = difpolynom;
		        else if (i==1)  difpolynom = difpolynom + a;
                }				
		else if (i==(n-1)) {
			polynom = polynom + a;
			if (i>1) 	difpolynom = difpolynom + a*i;
			else if (i==0)  difpolynom = difpolynom;
			else if (i==1)  difpolynom = difpolynom + a;
                }					
                else if (i==1) {
		        difpolynom=difpolynom*x +a;
		        polynom = polynom*x + a;
                }	 					
		else if (i==0) { 
			difpolynom=difpolynom;
			polynom = polynom*x + a;
                }   		
		else    {    
			difpolynom = difpolynom*x + i*a;
			polynom = polynom*x + a;
                }
        }
	printf("%ld %ld", polynom, difpolynom); 
	return 0;
}