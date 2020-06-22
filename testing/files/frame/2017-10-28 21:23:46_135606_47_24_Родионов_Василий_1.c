#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc!=4)
    {
        printf ("Usage: frame <height> <width> <text>");
        return 0;
    }
    if (atoi(argv[1])<3 || strlen(argv[3]) > (atoi(argv[2])-2))
        {
            printf ("Error");
            return 0;
        }
    int ser, nach=(atoi(argv[2])-strlen(argv[3])-2)/2;
    if (atoi(argv[1])%2==0) ser=atoi(argv[1])/2;
    else ser=atoi(argv[1])/2+1;
    for (int  i=0; i<atoi(argv[2]); i++) printf("*");
    for (int i=2 ; i<atoi(argv[1]); i++)
        {
            printf ("\n");
            if (i==ser)
            {
                printf ("*");
                int cnt=0;
                while (cnt<atoi(argv[2])-2)
                    {
                        if (cnt==nach)
                        {
                            printf ("%s", argv[3]);
                            cnt+=strlen(argv[3]);
                        }
                        else
                        {
                            printf (" ");
                            cnt++;
                        }
                    }
                printf ("*");
                continue;
            }

            for (int j=1; j<=atoi(argv[2]); j++)
            {

                if (j==1 || j==atoi(argv[2])) printf ("*");
                else printf (" ");
            }
        }
        printf ("\n");
        for (int  i=0; i<atoi(argv[2]); i++) printf("*");
}

