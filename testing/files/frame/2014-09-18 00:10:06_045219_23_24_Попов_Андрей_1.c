#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
        if (argc < 4) {
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	int a = atoi(argv[1]), b = atoi(argv[2]);
	if (strnlen(argv[3], 100) > b - 2 || a < 3) {
		printf("Error\n");
		return 0;
	}
	char m[b],*s = m;
	s = argv[3];
	int i, q, top = (a - 1) / 2, left = (b - strnlen(s, b)) / 2;
	for (i = 0; i < a; i++) {
		for (q = 0; q < b; q++) {
			if (!i || !q || i == a - 1 || q == b - 1) printf("*");
			else {
				if (i == top && (left <= q && q <= left + strnlen(s, b) - 1)) printf("%c", s[q - left]);
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}