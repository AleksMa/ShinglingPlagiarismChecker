#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_LEN 200
void UsageExit(void)
{
    printf("Usage: frame <height> <width> <text>");
    exit(1);
}

void ErrorExit(void) 
{
    printf("Error");
    exit(1);
}

char inp_buf[BUF_LEN];

void out_hline(FILE *fout, char ch, int n)
{
int i;
    for(i = 0; i < n; i++)
        fputc(ch, fout);
}

void out_frame(int height, int width, char *string, int string_len) 
{
int i;
    out_hline(stdout, '*', width); printf("\n");
    for(i = 0; i < (height - 3)/2; i++) 
    {
	printf("%c%*c\n", '*', width - 1, '*');
    }
    fprintf(stdout,"%c%*s%*c\n", '*', (width - string_len - 2)/2 + string_len,
    	string, (width - string_len - 1)/2 + 1,'*');
    for(i = 0; i < (height - 2)/2; i++)
    {
	printf("%c%*c\n", '*', width - 1, '*');
    }
    out_hline(stdout, '*', width); printf("\n");
}

int main(int argc, char *argv[])
{
int height, width; 
int string_len;
    if(argc != 4) 
    {
    	UsageExit();
    }
    if(sscanf(argv[1], "%d", &height) != 1) 
    {
    	UsageExit();
    }
    if(sscanf(argv[2], "%d", &width) != 1)
    {
    	UsageExit();
    }
    sscanf(argv[3], "%s", inp_buf);
    string_len = strlen(inp_buf);
    if(width < string_len + 2) 
    {
    	ErrorExit();
    }
    if(height < 3) 
    {
    	ErrorExit();
    }
    out_frame(height, width, inp_buf, string_len);
}

