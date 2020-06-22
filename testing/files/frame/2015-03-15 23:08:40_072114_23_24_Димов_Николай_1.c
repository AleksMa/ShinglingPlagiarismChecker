
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void draw(void *H, void *W,
          void *T)
{
    int l,i,j,h=0,w=0,t,p;
    char *y=(char *)W;
    w=atoi(y);
    char *x=(char *)H;
    h=atoi(x);
    p=((h-1)/2);
    char *text=(char *)T;
    for(l=0;text[l]!='\0';l++);
    if((h<3)||(w<(l+2)))printf("Error\n");
    else{
      for(j=0;j<w;j++)printf("*");
      printf("\n");
      for(i=1;i<h-1;i++){
	if(i==p){
	  printf("*");
	  t=(w-2-l)/2;
	  for(j=0;j<t;j++)printf(" ");
	  for(j=0;j<l;j++)printf("%c",text[j]);
	  for(j=0;j<(w-2-l-t);j++)printf(" ");
	  printf("*\n");
	}
	else {
	  printf("*");
	  for(j=0;j<(w-2);j++)printf(" ");
	  printf("*\n");
	}
      }
    for(j=0;j<w;j++)printf("*");
    printf("\n");
    }
}
int main (int argc, char **argv)
{
    if(argc!=4)printf("Usage: frame <height> <width> <text>\n");
    else draw(argv[1],argv[2],argv[3]);
    return 0;
}