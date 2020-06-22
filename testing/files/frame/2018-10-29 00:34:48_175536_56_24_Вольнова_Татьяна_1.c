#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stars(int n){
    char asterisks[n+1];
    strcpy(asterisks, "");
    for (int i = 0; i < n; i++){
        strncat(asterisks, "*", 2);
    }
    printf("%s\n", asterisks);
    return 0;
}

int space(int n){
    char gaps[n+1];
    strcpy(gaps, "");
    strncat(gaps, "*", 2);
    for (int i = 0; i < n - 2; i++) {
        strncat(gaps, " ", 2);
    }
    strncat(gaps, "*", 2);
    printf("%s\n", gaps);
    return 0;
}

int insert_text(int n, int ln, char *text){
    char new_text[n+1];
    strcpy(new_text, "");
    strncat(new_text, "*", 2);
    for (int i = 0; i < (n - 2 - ln)/2; i++) {
        strncat(new_text, " ", 2);
    }
    strncat(new_text, text, ln);
    for (int i = 0; i < (n - 2 - ln) / 2 + (n - 2 - ln) % 2; i++) {
        strncat(new_text, " ", 2);
    }
    strncat(new_text, "*", 2);
    printf("%s\n", new_text);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }

    int height = atoi(argv[1]), width = atoi(argv[2]), ln = strlen(argv[3]), i;

    if ((ln > width - 2) || (height < 3)){
        printf("Error");
        return 0;
    }

    char text[ln];
    strcpy(text, argv[3]);

    stars(width);
    for (i = 0; i < (height - 2) / 2 - 1 + (height - 2) % 2; i++) {
        space(width);
    }
    insert_text(width, ln, text);
    for (i = 0; i < (height - 2) / 2; i++) {
        space(width);
    }
    stars(width);

    return 0;
}