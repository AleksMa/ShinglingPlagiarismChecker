#include "stdio.h"
#include "string.h"

int main(int argc, char *argv[])
{
        if (argc != 4) {
		printf("%s\n", "Usage: frame <height> <width> <text>");
		return 0;
	}

	int height = atoi(argv[1]), width = atoi(argv[2]);
	char *string = argv[3];

	if ((height < 3) || (width < strlen(string) + 2))	{
		printf("%s\n", "Error");
		return 0;
	}

	int i, j = 0, k = 0;
	for (j = 0; j < height; ++j) {
		for (i = 0; i < width; ++i){
			if ((j == 0) || (j == height - 1) || (i == 0) || (i == width - 1)) printf("%c", '*'); // Первая и последняя строки заполняются полностью, как и первый и посл. столбцы
			else if((j == (height - 1) / 2) && (i > (width - 2 - strlen(string)) / 2) && (k < strlen(string))) printf("%c", string[k++]); // Строка выравнивается по ценру. Width - 2, чтобы не учитывать столбцы, заполненные *
			else printf("%c", ' ');
		}
		printf("\n");
	}
	return 0;
}