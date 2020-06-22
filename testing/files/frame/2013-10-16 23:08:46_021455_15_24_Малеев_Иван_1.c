#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
        int height = (atoi(argv[1]) - 1), widht = atoi(argv[2]), i, middle = (height / 2), j;
        char *frame, *space, rez[height][widht];
        if (!(argc == 4)) {
	        printf("Usage: frame <height> <width> <text>\n");
	        return 1;
	}
	if ((strlen(argv[3]) > (widht - 2)) || (atoi(argv[1]) < 3)) {
	        printf("Error\n");
	        return 2;
	}
        frame = "*";
        space = " ";
        for (i = 0; i <= height; i++) {
                if ((i == 0) || (i == height)) {
                        rez[i][0] = '\0';
	                while (strlen(rez[i]) < widht)
	                        strcat(rez[i], frame);
	                printf("%s\n", rez[i]);
                }
                else {
                        if (i == middle) {
	                        rez[i][0] = '\0';
	                        for (j = 0; strlen(rez[i]) < widht; j++) {
	                                if ((strlen(rez[i]) == 0) || (strlen(rez[i]) == widht - 1)) 
	                                        strcat(rez[i], frame);
	                                else {
	                                        if (strlen(rez[i]) == ((widht - strlen(argv[3])) / 2))
	                                                strcat(rez[i], argv[3]);
	                                        else 
	                                                strcat(rez[i], space);
	                                }
	                        }
	                        printf("%s\n", rez[i]); 
                        }
                        else {
	                        for (j = 0; j < widht; j++) {
	                                if ((j == 0) || (j == widht - 1)) 
	                                        strcat(rez[i], frame);
	                                else
	                                        strcat(rez[i], space);
	                        }
	                printf("%s\n", rez[i]); 
                        }
                }
        }
        return 0;
}