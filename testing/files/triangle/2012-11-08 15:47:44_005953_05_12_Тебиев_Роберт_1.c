#include <stdio.h>
#include <math.h>

int divs(int a, short *T, short *P) {
        int ds=1, nr, i, j;
        if (T[a-1]!=0){
		return T[a-1];
	}
	nr=a;
	for (i=0; P[i]<sqrt(a) && nr!=1; i++){
		for (j=0; nr%P[i]==0 ;j++)
			nr/=P[i];
		ds*=(j+1);
	}
	if (nr!=1)
		ds*=2;
	T[a-1]=ds;
	return ds;
}

int main() {
	long A, i;
	int ds=0,a, b, j, mv, k=0;
	short *T=malloc(460000*sizeof(short));
	short *P=malloc(700*sizeof(short));
	short *P0=malloc(700*sizeof(short));
	for (i=0; i<460000; i++)
		T[i]=0;
	for (i=0; i<700; i++)
		P[i]=i+2;
	for (i=0; ; i++) {
		for (j=0; j<700 && P[j]==0; j++);
		if (j==700)
			break;
		mv=P[j];
		P0[k]=mv, k++;
		for (j=mv-2; j<700; j+=mv)
			P[j]=0;
	}
	free(P),P=malloc(k*sizeof(short));
	for (i=0; i<k; i++)
		P[i]=P0[i];
	free(P0);
	for (i=1; ds<3001; i++){
		if (i%2==0)
			a=i/2, b=i+1;
		else
			a=i, b=(i+1)/2;
		ds=divs(a,T,P)*divs(b,T,P);
	}
	i--;
	A=(i+1)*i/2;
	printf("%ld\n",A);
	free(T);
	free(P);
	return 0;
}
