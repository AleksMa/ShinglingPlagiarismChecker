#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStr(char * a, int b);//func dly vivoda stroki

int main(int argc, char ** argv)
{
        int x = atoi(argv[1]);//visota
	int y = atoi(argv[2]);//dlina
	if(argv[3] == NULL)
	{
		printf("Usage: frame <height> <width> <text> \n");
		return 1;
	}
	int k = strlen(argv[3]);
	if((k > (y - 2)) || (x < 3))
	{
		printf("Error \n");
		return 1;
	}
	int i = 0;
	int j = 0;
	const char p = '*';
	int z = 0;
	if(x % 2 == 0) //peremennaya dla vivoda stroki po visote
	{
		z = x / 2 - 1;
	}
	else
	{
		z = x / 2;
	}
	for(i = 0; i < x; i++)
	{
		if(i == 0 || i == (x -1))//vivod dla pervoi i posledney stroki (zapolnenue vsego *)
		{
			for(j = 0; j < y; j++)
			{
				printf("%c", p);
			}
			printf("\n");
		}
		else
		{
			if(i == z)//vivod dla nashey stroki
			{
				printf("%c", p);
				printStr(argv[3], y);// func vivioda stroki
				printf("%c \n", p);
			}
			else//viviod dly vseh ostalnyh strok (zapolnenye tolko pervogo i poslednego elemta *)
			{
				printf("%c", p);
				for(j = 2; j < y; j++)
				{
					printf(" ");
				}
				printf("%c \n", p);
			}
			
		}
	}
	return 0;
}

void printStr(char * a, int b)//func dly vivoda stroki
{
	b = b - 2;
	int k = 0;
	int n = 0;
	int j = 0;
	k = (b - strlen(a))/2; // otstup pered strokoy
	n = (b - strlen(a)) - k;// otstup posle stroki
	for(j = 0; j < k; j++)//vivod otstupa pered
	{
		printf(" ");
	}
	printf("%s", a);//vivod stroki
	for(j = 0; j < n; j++)//vivod posle stroki
	{
		printf(" ");
	}	
}