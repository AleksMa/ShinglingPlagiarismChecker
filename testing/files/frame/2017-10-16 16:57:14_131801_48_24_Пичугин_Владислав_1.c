#include<stdio.h>
#include<string.h>
int main(int argc, char **argv){
    if (argc<4)
        printf("Usage: frame <height> <width> <text>\n");
    else{
        if ((atoi(argv[1])<3)||(atoi(argv[2])<(strlen(argv[3])+2)))
            printf("Error\n");
        else{
            char sarr[atoi(argv[1])][atoi(argv[2])];
            int putJ=(atoi(argv[2])-strlen(argv[3]))/2;
            int putI=((atoi(argv[1])+1)/2)-1;
            for (int i=0;i<atoi(argv[1]);i++){
                if ((i==0)||(i==atoi(argv[1])-1)){
                    for (int j=0;j<atoi(argv[2]);j++)
                        sarr[i][j]='*';
                }else{
                    sarr[i][0]='*';
                    sarr[i][atoi(argv[2])-1]='*';
                    for (int j=1;j<(atoi(argv[2])-1);j++)
                        sarr[i][j]=' ';
                }
            }
            for (int i=0;i<atoi(argv[1]);i++){
                for (int j=0;j<atoi(argv[2]);j++){
                    if ((i==putI)&&(j==putJ)){
                        printf("%s",argv[3]);
                        j=putJ+strlen(argv[3]);
                    }
                    printf("%c",sarr[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
