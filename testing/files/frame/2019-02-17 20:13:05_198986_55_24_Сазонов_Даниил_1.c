#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
        if (argc == 4) {

		int textSize = strlen(argv[3]);
		int width = atoi(argv[2]);
		int height = atoi (argv[1]);

		if ((textSize < width - 1) && (height > 2)) {

			for (int i = 0; i < width; i++)
				printf("*");
			printf("\n");

			int k = (height % 2) ? 0 : 1;
			for (; k < (height - 2) / 2; k++) {
				printf("*");
				for (int i = 0; i < width - 2 ; i++)
					printf(" ");
				printf("*\n");
			}

			int horCenter = ((width - 2) - textSize) / 2;
			printf("*");
			for (int i = 0; i < horCenter; i++)
				printf(" ");
			printf("%s", argv[3]);
			for (int i = 0; i < horCenter; i++)
				printf(" ");
			if ((width - 2 - textSize) % 2)
				printf(" *\n");
			else
				printf("*\n");

			(height % 2) ? k += 2 : k++;
			for (; k < height - 1; k++) {
				printf("*");
				for (int i = 0; i < width - 2 ; i++)
					printf(" ");
				printf("*\n");
			}

			for (int i = 0; i < width; i++)
				printf("*");
			printf("\n");

		} else
			printf("Error\n");
	} else
		printf("Usage: frame <height> <width> <text>\n");
	return 0;
}
