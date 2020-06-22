#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int* simp(int z){
        int i,j;
        char *a;
	int *b;
	a=(char*)malloc(z*sizeof(char));
	b=(int*)malloc(z*sizeof(int));
	for (i=0;i<z;i++)
		a[i]=1;
	for (j=2;j<z;j++){
		if (a[j]!=0){
			for (i=j+1;i<z;i++){
				if (i%j==0&&a[i]!=0){
					a[i]=0;
					//printf ("выч %d\n",i);
				}
			}
		}
	}
	for (j=0,i=1;i<1000;i++){
		if (a[i]==1){
			b[j]=i;
			j++;
		}
	}
	return (b);
}

int tao(int x,int* a){
	int i,j,l,t;
	int *c,*b;
	if (x==1)
		return 1;
	//printf ("-1-\n");
	b=(int*)malloc(x*sizeof(int));
	c=(int*)malloc(x*sizeof(int));
	j=-1;
	for (i=1;a[i]<=sqrt(x);i++){
		//printf ("a[%d]=%d",i,a[i]);
		if ((x%a[i])==0&&x!=a[i]){
				j+=1;
				//printf ("j=%d i=%d",j,i);

			for (l=1;x%a[i]==0&&x!=a[i];l++){
				x=x/a[i];
				b[j]=a[i];
				c[j]=l;
			}
		}
	}
	//printf ("\nx=%d\n",x);
	//printf ("j=%d\nb[j]=%d\n",j,b[j]);
	if (x!=b[j]){
		j++;
		b[j]=x;
		c[j]=1;
	}
	else
		c[j]++;
	for (i=0;i<=j;i++)
		//printf ("%d^%d*",b[i],c[i]);
	//printf ("\n");
	t=1;
	for (i=0;i<=j;i++)
		t=t*(c[i]+1);
	//printf ("t=%d\n",t);
	free (b);
	free (c);
	return t;
}
int main (int argc,char** argv) {
	unsigned long x=0, j,i;
	int *a;
	int q1,q2,y;
	a=malloc(1000*sizeof(int));
	a=simp(1000);//printf ("%d",a[0]);
	y=3000;
	i=1;
	q1=q2=0;
	while (q1*q2<=y){
		i++;
		if (i%2==0){
			q1=tao(i/2,a);
			q2=tao(i+1,a);
		}
		else {
			q1=tao(i,a);
			q2=tao( (i+1)/2,a );
		}
		//printf ("\nq1+q2=%d|",q1*q2);
		//t++;
	}
	if (i%2==0){
		j=i/2;
		x=(i+1)*j;
	}
	else{
		j=(i+1)/2;
		x=j*i;
	}
	printf ("%lu\n",x);
	free (a);
	return 0;
}
