#include <stdio.h>
#include <string.h>

int a4toi(char* c)
{
    int i=0;
    int res=0;
    while(c[i])
    {
        res*=10;
        res+=c[i]-'0';
        i++;
    }
    return res;
}

int main(int argc, char *argv[])
{
    if (argc!=4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int a=a4toi(argv[1]);
    int b=a4toi(argv[2]);
    char* c=argv[3];
    if (strlen(c)>=b-1)
    {
        int g=strlen(c);
        printf("Error\n");
        return 0;
    }
    if (a<=2)
    {
        printf("Error\n");
        return 0;
    }
    int m=(a+1)/2-1;
    int u=b-2-strlen(c);
    u=u/2;
    for (int j=0; j<b; j++)
    {
        printf("*");
    }
    printf("\n");
    for (int i=1; i<a-1; i++)
    {
        printf("*");
        if (i!=m)
        {
            for (int j=1; j<b-1; j++)
            {
                printf(" ");
            }
            printf("*\n");
        }
        else
        {
            for (int j=1;j<=u;j++)
            {
                printf(" ");
            }
            printf("%s",c);
            for (int j=1;j<=b-2-strlen(c)-u;j++)
            {
                printf(" ");
            }
            printf("*\n");
        }
    }
    for (int j=0; j<b; j++)
    {
        printf("*");
    }
    return 0;
}
