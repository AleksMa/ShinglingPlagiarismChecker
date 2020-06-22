#include <string.h>
#include <stdio.h>

int atoi(const char *s) {

        while (*s==' ' || *s=='\t' || *s=='\n') s++;
	int sign = 1, res;
	if (*s == '+') s++;
	else if (*s == '-') sign = -1, s++;
	for (res = 0; *s >= '0' && *s <= '9'; s++) { 
		res = res*10 + *s - '0';
	}
	return res * sign; 
}

int main(int argc, char **argv){
	if(argc<4){
		printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	char s[atoi(argv[1])][atoi(argv[2])];
	for (int i=0; i<atoi(argv[1]);++i){
		for(int j=0; j<atoi(argv[2]);j++){
			if(i==0 || i==atoi(argv[1])-1 || j==0 || j==atoi(argv[2])-1) s[i][j]='*';
			else s[i][j]=' ';
		}
	}
	int n=0;
	for(int i=0;argv[3][i]!='\0';++i){
		++n;
	}
	if (atoi(argv[1])==2 || atoi(argv[2])-2<n){
		printf("Error");
		return 0;
	}
	if (atoi(argv[1])%2==0){
		for(int i=0;argv[3][i]!='\0';++i){
			s[atoi(argv[1])/2-1][(atoi(argv[2])-n)/2+i]=argv[3][i];
		}
	}
	else{
		for(int i=0;argv[3][i]!='\0';++i){
			s[atoi(argv[1])/2][(atoi(argv[2])-n)/2+i]=argv[3][i];
		}
	}
	for (int i=0; i<atoi(argv[1]);++i){
		for(int j=0; j<atoi(argv[2]);j++){
			printf("%c", s[i][j]);
		}
		printf("%c",'\n');
	}
	return 0;
}

