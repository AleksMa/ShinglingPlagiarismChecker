#include <stdio.h>
int main()
{        
int x, y, w;
long int t, r;
scanf("%d\n", &x);
scanf("\r %d", &y);
int Caf[x];
"\n\r";
r=0;
        int z;
    for(w=0; w < x+1; w++)
    {
	scanf("%d", &z);
    Caf[w]=z;
    }
int q;
r=Caf[0];	
t=Caf[0]*x;		 
for(q=1,x-=1; q<w;++q,--x){
	r=r*y;
    r+=Caf[q];
    if(x>0){
    t=t*y;
    t+=Caf[q]*x;
	}
    }
printf("%ld\n", r);
printf("%ld", t);   
return 0;
}