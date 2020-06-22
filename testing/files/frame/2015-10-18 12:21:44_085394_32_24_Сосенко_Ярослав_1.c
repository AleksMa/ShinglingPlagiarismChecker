
#include <string.h>

int main(int argc, char *argv[])
{
    //Неправильное число элементов
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }

    int width = atoi(argv[2]);
    int height = atoi(argv[1]);
    int len = strlen(argv[3]);

    //Слишком маленькая рамка
    if ((len > width - 2) || (height < 3))
    {
        printf("Error");
        return 0;
    }

    int vPos = (height - 1) / 2;
    int hPos = (width - len) / 2;

    // Верхняя линия
    int i;
    for (i = 0; i < width; i ++)
    {
        printf("*");
    }
    printf("\n");

    // Середка
    int j;
    for (j = 0; j < height - 2; j ++)
    {
        printf("*");
        if (j == vPos - 1)
        {
            for (i = 1; i < hPos; i ++)
            {
                printf(" ");
            }

            printf(argv[3]);

            for (i = hPos + len; i < width - 1; i ++)
            {
                printf(" ");
            }
        }
        else
            for (i = 0; i < width - 2; i ++)
            {
                printf(" ");
            }

        printf("*");
        printf("\n");
    }

    // Нижняя линия
    for (i = 0; i < width; i ++)
    {
        printf("*");
    }
    printf("\n");
}