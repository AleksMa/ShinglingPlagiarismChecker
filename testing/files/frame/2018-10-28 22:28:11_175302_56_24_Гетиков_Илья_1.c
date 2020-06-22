#include <stdio.h>
#include "stdlib.h"

int main(int argc, const char * argv[]) {
    
    if (argc<=3){
        printf("%s", "Usage: frame <height> <width> <text>");
        return 0;
    }
    else{
        int k = 0;
        while(argv[3][k])
            k = k + 1;
        if ((k>atoi(argv[2]) - 2) || (atoi(argv[1]) < 3)){
            printf("%s", "Error");
        }
        else{
            int j = (atoi(argv[2]) - 2 - k) / 2;
            for (int i = 0; i < atoi(argv[2]); i++){
                printf("%c", '*');
            }
            printf("\n");
            if (atoi(argv[1]) % 2 == 0){
                for (int i = 0; i < (atoi(argv[1]))/2 - 2; i++){
                    printf("%c", '*');
                    for (int i = 0; i < (atoi(argv[2]) - 2); i++)
                        printf("%c", ' ');
                    printf("%c\n", '*');
                }
                printf("%c", '*');
                for (int i = 0; i < j; i++){
                    printf("%c", ' ');
                }
                printf("%s", argv[3]);
                for (int i = 0; i < (atoi(argv[2]) - 2 - k) - j; i++){
                    printf("%c", ' ');
                }
                printf("%c\n", '*');
                for (int i = 0; i < (atoi(argv[1]))/2 - 1; i++){
                    printf("%c", '*');
                    for (int i = 0; i < (atoi(argv[2])-2); i++)
                        printf("%c", ' ');
                    printf("%c\n", '*');
                }
            }
            else{
                for (int i = 0; i < (atoi(argv[1]))/2 - 1; i++){
                    printf("%c", '*');
                    for (int i = 0; i < (atoi(argv[2])-2); i++)
                        printf("%c", ' ');
                    printf("%c\n", '*');
                }
                printf("%c", '*');
                for (int i = 0; i < j; i++){
                    printf("%c", ' ');
                }
                printf("%s", argv[3]);
                
                for (int i = 0; i<(atoi(argv[2]) - 2 - k) - j; i++){
                    printf("%c", ' ');
                }
                printf("%c\n", '*');
                for (int i = 0; i < (atoi(argv[1]))/2 - 1; i++){
                    printf("%c", '*');
                    for (int i = 0; i < (atoi(argv[2])-2); i++)
                        printf("%c", ' ');
                    printf("%c\n", '*');
                }
            }
            for (int i = 0; i < atoi(argv[2]); i++){
                printf("%c", '*');
            }
        }
    }
    return 0;
}