#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 int main (int argc, char * argv[])
 {
         int i = 0, j = 0, rows = atoi(argv[1]), cols = atoi(argv[2]), len = 0;
         if(argc == 4)
         {
            while(argv[3][len] != 00)
            {
                len+=1;
            }
            char s[len];
            i=0;
            while(argv[3][i] != 00)
            {
                s[i]=argv[3][i];
                i+=1;
            }
            s[i]=0;
            if((len>(cols-2))||(rows<3))
            {
                printf("Error");
            }
            else
            {
                for(i=1;i<=cols;i++)
                {
                    printf("*");
                }
                printf("\n");
                for(i=2;i<rows;i++)
                {
                    if(i==(rows+1)/2)
                    {
                        printf("*");
                        j=0;
                        while(j<(cols-2-len)/2)
                        {
                            printf(" ");
                            j+=1;
                        }
                        printf("%s", s);
                        j=0;
                        while(j<(cols-2-len-((cols-2-len)/2)))
                        {
                            printf(" ");
                            j+=1;
                        }
                        printf("*\n");
                    }
                    else
                    {
                        printf("*");
                        for(j=0;j<cols-2;j++)
                        {
                            printf(" ");
                        }
                        printf("*\n");
                    }
                }
                for(i=1;i<=cols;i++)
                {
                    printf("*");
                }
            }
         }
         else
         {
             printf("Usage: frame <height> <width> <text>");
         }
            return 0;
}