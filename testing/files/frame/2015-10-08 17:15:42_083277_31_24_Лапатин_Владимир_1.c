#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv){
        if (argc != 4){
		printf("%s\n", "Usage: frame <height> <width> <text>");
	}
	else {
		int i = 0, k = 0, j = 0;
		char tmp[100];
		int height = -1, width = -1;
		char *str = 0;

		height = atoi (argv[1]);
		width = atoi (argv[2]);
		str = argv[3];
		for (char *p = str; *p != '\0'; p++)k++;
		i = 1;
		int z = 0;
		char res[width + 1];
		int mid = round (((float) height)/2);
		for (int p = 0; p < width+1; p++)res[p] = ' ';
		if (width - k < 2 || height < 3) printf("%s\n", "Error");
		else{
			while (i != height + 1) {
				if (i == 1 || i == height) for (int j = 0; j < width; j++)res[j] = '*';
				else res[0] = res[width - 1] = '*';
				if (i == mid){
					for (int j = 0; j < width; j++)
						if (j > (width - k) / 2 && z < k) res[j-1] = str[z++];
				}
				i++;
				for (int p = 0; p < width; p++){
					printf("%c", res[p]);
					res[p] = ' ';
				}
				printf("\n");
			}
	}
}
	return 0;
}