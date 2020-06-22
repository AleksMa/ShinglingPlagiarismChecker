#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

void fandlstr(int count) { // первая и последняя строка
    for (int i=0; i<count-1; i++) {
        printf("%s", "*");
    }
    printf("%s\n", "*");
}

void promesh(int count) { // промежуточные строки
    printf("%s", "*");
    for (int i=0; i<count-2;i++) {
        printf("%s", " ");
    }
    printf("%s\n", "*");
}

void slovo(int count, char *word) { // строчка со словом

    printf("%s", "*");
    for (int i=0; i<(count-2-strlen(word)) / 2 ; i++) {
        printf("%s", " ");
    }
    printf("%s", word);
    for (int i=0; i<(count-strlen(word)-1)/2 ; i++) {
        printf("%s", " ");
    }
    printf("%s\n", "*");
}

void tabl(int w, int h, char *word) {
    fandlstr(h);
    if ((w % 2)==1) { // если нечетное
        for (int i=0; i<(w-2)/2; i++) {
            promesh(h);
        }
        slovo(h, word);
        for (int i=0; i<(w-2)/2; i++) {
            promesh(h);
        }
    } else { //если четное
        for (int i=0; i<(w-2-1)/2; i++) {
            promesh(h);
        }
        slovo(h, word);
        for (int i=0; i<(w-2)/2; i++) {
            promesh(h);
        }
    }
    fandlstr(h);
}

int main(int argc, char **argv) {

    int w=atoi(argv[2]), h=atoi(argv[1]);
    if (argc != 4) {
        printf ("Usage: frame <height> <width> <text>\n");
        return 0;
    } else {
        int l = strlen(argv[3]);
        if (h < 3 || l > w - 2){
            printf("Error");
        } else {
            tabl(h, w, argv[3]);
            printf ("\n");
        }
        return 0;
    }




}