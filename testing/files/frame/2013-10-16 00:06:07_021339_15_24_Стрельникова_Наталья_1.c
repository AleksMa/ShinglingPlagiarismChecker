#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
        if (argc != 4) {printf("Usage: frame <height> <width> <text>\n");}
	else {
		int a = atoi(argv[1]), b = atoi(argv[2]), c = strnlen(argv[3], 1000);
		if ((b < (c + 2)) || (a < 3)) {printf("Error\n");}
		else {
			int i,j,k = (b  - c) / 2;
			for (i = 0; i < a; i++) {
				for (j = 0; j < b; j++) {
					if ((i == 0) || (i == (a - 1)) || 
						(j == 0) || (j == (b - 1))) printf("*");
					else {
						if ((i != ((a - 1) / 2)) || (j < k) || (j >= (k + c))) printf(" ");
						else {
							printf("%s", argv[3]);
							j += c - 1;
						}
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}
