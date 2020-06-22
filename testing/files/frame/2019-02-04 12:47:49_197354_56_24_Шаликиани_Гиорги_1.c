#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char** argv) {
    int i=0;
    
    int b=0;
    int a=0;
    if(argc!=4){
       printf("Usage: frame <height> <width> <text>");
       return 0;
    }
    
    int j=0;
    
    int k=1;
    b = atoi(argv[2]);
    
    a = atoi(argv[1]);
    if( b <= strlen(argv[3]) + 1 || a < 3){
        printf("Error");
        return 0;
    }
    
    int x=(b-strlen(argv[3]))/2;
    
    for(i = 0 ; i <= a - 1 ; i = i + 1){
        for(j = 0 ; j <= b - 1 ; j = j + 1){
            if(i == 0 || i + 1 == a){
                printf("*");
            }
            else{
                if(j == 0 || j + 1 == b){
                    printf("*");
                }
                else{
                    if(!(j!=x || i!=(a+1)/2 - 1)){
                        printf("%s", argv[3]);
                        j+=strlen(argv[3]);
                        j--;
                    }
                    else{
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
