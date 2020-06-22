#include <stdio.h> 
#include <string.h>
int main(int argc, char** argv)
{
        int n = atoi(argv[1]), k = atoi(argv[2]), f, i, j, m, s;
        if(argc != 4) printf("Usage: frame <height> <width> <text>\n");
        else {
                s = strnlen(argv[3], k-2);
                if(argv[3][s] != 0 || n == 2) printf ("Error\n");
                else {
                        f = (n + 1)/2;
                        m = (k - s) / 2; 
                        for(i = 1; i <= n; ++i, printf("\n")) {
                                for(j = 0; j < k; ++j) {
                                                if(j == m && i == f) {
                                                        printf("%s", argv[3]);
	                                                j = j + s - 1;
	                                                continue;
                                                }
	                                        if(i == 1 || i == n || j == 0 || j == k - 1) printf ("*");
	                                        else printf(" "); 
                                }
                        }
                }
        }
        return 0;
}