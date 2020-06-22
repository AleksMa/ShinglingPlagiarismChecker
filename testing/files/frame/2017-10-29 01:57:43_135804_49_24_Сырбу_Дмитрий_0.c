#include <stdio.h>
#include <string.h>
int main(int amount, char **arg)
{   
    char *s;
    int k,n,i,j,z,x,d,m;
    if (amount!=4) 
        {
            printf("Usage: frame <height> <width> <text>");
            return 0;
           }
		
    s=arg[3];
    n=atoi(arg[1]);
    k=atoi(arg[2]);
    d=strlen(s)/2;
    m=strlen(s);
    if ((k-2-m==1) && (k%2==0))
    z=k/2-1;
    else
    z=k/2;
    if (n%2==0)
    x=n/2-1; //stroki
    else x=n/2;	
    char f[n][k];
       for (i=0;i<n;i++)
             for (j=0;j<k;j++)
                f[i][j]=' ';
                for (j=0;j<k;j++)
                f[0][j]='*';
                for (j=0;j<k;j++)
                f[n-1][j]='*';
                for (i=0;i<n;i++)
                f[i][0]='*';
                for (i=0;i<n;i++)
                f[i][k-1]='*';
         for (i=0,j=z-d;m>0;m--,j++,i++)
                f[x][j]=s[i];


      

        if ( (strlen(s)>k-2) || (n<=2) || (k<=2))
           {
            printf("Error");
            return 0;
           }

           for (i=0;i<n;i++)
          {
                for (j=0;j<k;j++)
                    printf("%c", f[i][j]);
            printf("\n");
          }


	return 0;
}