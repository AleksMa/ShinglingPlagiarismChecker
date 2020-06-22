# include <stdio.h>

int main (int argc , char **argv )
{
    if (argc != 4)
    {
        printf("%s", "Usage: frame <height> <width> <text>");
    }
    else
    {
        char *s = argv[3];
        int n = 0, m = 0, i = 0, j = 0, len = 0;
        n = atoi(argv[1]);
        m = atoi(argv[2]);
        while(s[len] != 0)
        {
            ++len;
        }
        if(len > m - 2 || n <= 2)
        {
            printf("%s", "Error"); 
        }
        else
        {
            for(i = 0; i < m; ++i)
            {
                printf("%s", "*");
            }
            printf("\n");
            ++j;
            while(j < (n - 1) / 2)
            {
                printf("%s" ,"*");
                for(i = 0; i < m - 2; ++i)
                {
                    printf("%s", " ");
                }
                printf("%s\n", "*");
                ++j;
            }
            printf("%s" ,"*");
            for(i = 1; i < (m - len) / 2; ++i)
            {
                printf("%s", " ");
            }
            printf("%s", s);
            for(i = i + len; i < m - 1; ++i)
            {
                printf("%s", " ");
            }
            printf("%s\n", "*");
            while(j < n - 2)
            {
                printf("%s" ,"*");
                for(i = 0; i < m - 2; ++i)
                {
                    printf("%s", " ");
                }
                printf("%s\n", "*");
                ++j;
            }
            for(i = 0; i < m; ++i)
            {
                printf("%s", "*");
            }
        }
    }
    return 0;
}