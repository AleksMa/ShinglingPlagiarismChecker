//
//  main.c
//  17 ramka
//
//  Created by Никифоров Иван on 17.10.14.
//  Copyright (c) 2014 NIkif. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
    
    if (argc!=4){
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    
    int height, wight, n, i, j, help=0, k;
    char *s;
//    s=(char*)malloc(100);
    
    
    height = atoi(argv[1]);
    wight = atoi(argv[2]);
    s=argv[3];
//    scanf("%d", &height);
//    scanf("%d", &wight);
//    gets (s);
    
    n = (int)strlen(s);
//    printf("n = %d ", n);
    if ((n>wight-2)||(height<3)) {
        printf("Error\n");
        return 0;
    }
    
    for (i=1; i<=wight; i++)
        printf("*");
    printf("\n");
    
    if (height==3) {
        printf("*");
        if (n==wight-2) {
            printf("%s", s);
            
        }
        if ((wight%2==0)&&(n<wight-2)) {
            for (k=1; k<=(wight-2-n)/2; k++) {
                printf(" ");
            }
            printf("%s", s);
            for (k=1; k<=(wight-2-n)/2; k++) {
                printf(" ");
            }
        }
        if ((wight%2==1)&&(n%2==0)&&(n<wight-2)) {
            for (k=1; k<=((wight-2-n)/2); k++) {
                printf(" ");
            }
            printf("%s", s);
            for (k=1; k<=((wight-2-n)/2)+1; k++) {
                printf(" ");
            }
        }
        if ((wight%2==1)&&(n%2==1)&&(n<wight-2)) {
            for (k=1; k<=((wight-2-n)/2); k++) {
                printf(" ");
            }
            printf("%s", s);
            for (k=1; k<=((wight-2-n)/2); k++) {
                printf(" ");
            }
        }
        
        //-----------------------------------------------
        
        printf("*");
        printf("\n");
    }else{
        for (i=1; i<=height-2; i++){
            printf("*");
            for (j=1; j<=wight-2; j++) {
                if (i==((height-3)/2)+1) {   //нашел нужную высоту
                    //                printf("j = %d", j);
                    
                    if (n==wight-2) {
                        printf("%s", s);
                        break;
                    }
                    //-----------------------------------------------
                    
                    if ((n%2==1)&&(help==0)&&(wight%2==0)&&(n<=wight-2)) {
                        for (k=1; k<=((wight-2-n)/2); k++) {
                            printf(" ");
                        }
                        printf("%s", s);
                        for (k=1; k<=((wight-2-n)/2)+1; k++) {
                            printf(" ");
                        }
                        help+=1;
                    }
                    //-----------------
                    if ((n%2==1)&&(help==0)&&(wight%2==1)&&(n<=wight-2)) {
                        for (k=1; k<=((wight-2-n)/2); k++) {
                            printf(" ");
                        }
                        printf("%s", s);
                        for (k=1; k<=((wight-2-n)/2); k++) {
                            printf(" ");
                        }
                        help+=1;
                    }
                    
                    //-----------------
                    if ((n%2==0)&&(wight%2==0)&&(help==0)&&(n<=wight-2)) {
                        for (k=1; k<=((wight-2-n)/2); k++) {
                            printf(" ");
                        }
                        printf("%s", s);
                        for (k=1; k<=((wight-2-n)/2); k++) {
                            printf(" ");
                        }
                        help+=1;
                    }
                    //------------------
                    if ((n%2==0)&&(wight%2==1)&&(help==0)&&(n<=wight-2)) {
                        for (k=1; k<=((wight-2-n)/2); k++) {
                            printf(" ");
                        }
                        printf("%s", s);
                        for (k=1; k<=((wight-2-n)/2); k++) {
                            printf(" ");
                        }
                        help+=1;
                        printf(" ");
                    }
                }
                if (i!=((height-3)/2)+1)
                    printf(" ");
            }
            
            printf("*\n");
        }
    }
    
    for (i=1; i<=wight; i++)
        printf("*");
    printf("\n");

//    free(s);
    
    return 0;
}
