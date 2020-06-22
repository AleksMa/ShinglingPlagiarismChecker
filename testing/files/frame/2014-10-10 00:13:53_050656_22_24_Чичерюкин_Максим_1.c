#include <stdio.h>
#include <string.h>

void main (int argc, char *argv[])
{
        if (argc<4) 
	{
	  printf("Usage: frame <height> <width> <text>\n");
	  return;
	}
	
	int j,i,n,p,width;
	
	n= atoi( argv[1]);
	width= atoi (argv[2]);
	
	char *s;
	
	s = argv[3];
	
	//printf("%d%d%s\n", n, width, s);
	
	if ((strlen(s)>width-2) || (n<3))
	{
	  printf("Error\n");
	  return;
	}
	
	p = (n%2) ? (n-1)/2 : n/2 -1;
	
	//printf("Таки рамочка\n");
	
	for (i=0;i<n;i++)
	{
	  if ((i == 0 ) || (i==n-1))
	  {
	    for (j=0;j<width;j++)
	    {
	      printf("*");
	    }
	    printf("\n");
	  }
	  else 
	    if (i==p)
	    {
	      int k;
	      k=(width-strlen(s))/2;
	      
	      printf("*");
	      for(j=1;j<k;j++)\
	      {
		printf(" ");
	      }
	      
	      printf("%s",s);
	      
	      for(j=k+strlen(s);j<width-1;j++)
	      {
		printf(" ");
	      }
	      printf("*\n");
	
	    }
	    else
	    {
	      printf("*");
	      for (j=1;j<width-1;j++)
	      {
		printf(" ");
	      }
	      printf("*\n");
	      
	    }
	 
	}
}