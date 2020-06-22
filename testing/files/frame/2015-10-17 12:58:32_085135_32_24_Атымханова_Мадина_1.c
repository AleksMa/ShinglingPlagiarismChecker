#include<stdio.h>
#include<string.h>
int main(int args,char **argv)
{
  if (args<4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
  }
  int a,b,n,i,j,k,t,len;
  a=atoi(argv[1]);
  b=atoi(argv[2]);
  if (!(a%2)) t=a/2-1; 
  else t=a/2;
  len=strlen(argv[3]);
  if ((a<3)||(len>(b-2))||(len==0)) 
    printf("Error"); 
  else {
   for (i=0;i<a;i++) { 
     if ((i==0)||(i==(a-1))) {
       for (j=0;j<b;j++) printf("%c",'*');
     }
     if (i==t) {	     
	for (j=0;j<=((b-2-len)/2);j++) {
	        if (j==0) printf("%c",'*'); 
                else printf("%c",' ');
	}
	printf("%s",argv[3]);
	for (j=((b-2+len)/2);j<(b-2);j++) printf("%c",' ');
	printf("%c",'*');
      }
     if ((i!=t)&&(i!=0)&&(i!=(a-1))) {
             for (j=0;j<b;j++) {
             if ((j==0)||(j==b-1)) printf("%c",'*'); 
             else printf("%c",' ');
             }
     } 
     printf("\n"); 
    }
  }
}

