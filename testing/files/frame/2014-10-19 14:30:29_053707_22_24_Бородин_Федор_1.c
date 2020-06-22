#include <stdio.h>
#include <string.h>
int main(int argc , char ** argv)
{
        //проверка на ошибки
        if(argc!=4)
        {
                printf("Usage: frame <height> <width> <text>\n");
                return 0;
        }
        if(atoi(argv[2])-2<(int)strlen(argv[3])||atoi(argv[1])<3)
        {
                printf("Error\n");
                return 0;
        }
        int i,j;
        //первые звездочки
        for(i=0;i<atoi(argv[2]);i++)
                printf("*");
        printf("\n");
        //пустые строки с 2 звездами
        if(atoi(argv[1])%2==0)
        {
                for(i=2;i<atoi(argv[1])/2;i++)
                {
                        printf("*");
                        for(j=0;j<atoi(argv[2])-2;j++)
                                printf(" ");
                        printf("*\n");
                }
        }
        else
        {
               for(i=1;i<atoi(argv[1])/2;i++)
                {
                        printf("*");
                        for(j=0;j<atoi(argv[2])-2;j++)
                                printf(" ");
                        printf("*\n");
                } 
        }
        printf("*");
        //строчка со строкой
        for(i=0;i<(atoi(argv[2])-2-(int)strlen(argv[3]))/2;i++)
                printf(" ");
        printf("%s", argv[3]);
        for(i=0;i<atoi(argv[2])-2-(int)strlen(argv[3])-(atoi(argv[2])-2-(int)strlen(argv[3]))/2;i++) //ширина-две звезды-строка-уже напечатанные пробелы
                printf(" ");
        printf("*\n");
        //пустые строки с 2 звездами
        for(i=1;i<atoi(argv[1])/2;i++)
        {
                printf("*");
                for(j=0;j<atoi(argv[2])-2;j++)
                        printf(" ");
                printf("*\n");
        }
        //последняя строка со звездочками
        for(i=0;i<atoi(argv[2]);i++)
                printf("*");
	return 0;
}