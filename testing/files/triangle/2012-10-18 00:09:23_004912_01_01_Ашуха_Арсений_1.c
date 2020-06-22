
#include <stdio.h>
#include <math.h>



long long divider(long long a){

    int i, k = 0 ;

    for (i = 1; i <= sqrt(a); i++ ){
        if (a % i == 0 ){
                k += 1;
        }
    }

    if ( sqrt(a) * sqrt(a) == a  ){
            return 2*k - 1;
    }
    return 2*k;
}


int main(int argc, char **argv){

    long long j = 1 , i = 1, kol = 1, temp = 0 ;

    while ( 1 ){

        temp = divider((j+1)/2);
        kol = divider(j) * temp;

        if ( kol >= 3000){
            break;
        }

        j ++;

        kol = temp * divider(j+1);

        if ( kol >= 3000){
            break;
        }

        j ++;
    }


    printf ("\tchislo %lld \n\tdeliteli %lld\n\n",j*(j+1)/2,kol);

    return 0;
}
