#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1024

int main(int argc, char **argv) 
{
        if (argc!=4) 
	{
		printf("Usage: frame <height> <width> <text>\n"); 
		return 0; 
	}
	int h=atoi(argv[1]);
	int w=atoi(argv[2]);
	int len=strnlen(argv[3],MAX);
	char *s=(char*)malloc(MAX*sizeof(char));
	if ((len>(w-2)) || (h<3))
	{
	        printf("Error");
	        return 0;
	}
	strncpy(s,argv[3],len+1);	
	int i=0;
	int j=1;
	int p=0;
	char k[2]="*";
	char d[2]=" ";
	int serh=(h-1)/2;
	int serw=(w-2-len)/2;
	char m[w+1];
	for (;i<h;++i)
	{
		m[0]='\0';
		strncpy(m,k,2);
		for (j=1;j<(w-1);++j)
		{
			if ((i==0) || (i==h-1))
				strncat(m,k,2);
			else
			{
				if (i==serh)
				{
					if ((j-1)==serw)
					{
						strncat(m,s,len+1);
						j+=len-1;
					}
					else
						strncat(m,d,2);
				}
				else
					strncat(m,d,2);
			}
		}
		strncat(m,k,2);
		printf("%s\n",m);
	}
	free(s);
	return 0;
}