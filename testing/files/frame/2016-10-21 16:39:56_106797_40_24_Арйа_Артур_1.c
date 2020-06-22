#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void border(int, int, char*);
void print_line(int, int, int, char*);
int main(int argc, char **argv){
        if(argc < 4){
		printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	if(strlen(argv[3]) > atoi(argv[2])-2 || atoi(argv[1]) < 3){
		printf("Error");
		return 0;
	}	
	border(atoi(argv[1]), atoi(argv[2]), argv[3]);
	return 0;
}
void print_line(int n, int m, int k, char *c){
	if(k == 1 || k == n){
		for(int i=0; i<m; i++) printf("*");
		printf("\n");
		return;
	}
	int middle = (n%2 == 0)?n/2:(int)(n/2)+1;
	if(k != middle){
		printf("*");
		for(int i=1; i<m-1; i++) printf(" ");
		printf("*");
		printf("\n");
		return;
	}
	char *spaces = (char*)malloc(1000*(sizeof(char)));
	int counter_spaces_left = (m-strlen(c)-2)/2;
	int counter_spaces_right = ((m-strlen(c)-2)%2 == 0)?counter_spaces_left:counter_spaces_left+1;
	strcpy(spaces, "");
	for(int i=0; i<counter_spaces_left; i++){
		strcat(spaces, " ");
	}
	printf("*%s%s", spaces, c);
	strcpy(spaces, "");
	for(int i=0; i<counter_spaces_right; i++){
		strcat(spaces, " ");
	}
	printf("%s*\n", spaces);
}
void border(int n, int m, char *c){
	for(int i=1; i<=n; i++) print_line(n, m, i, c);
}