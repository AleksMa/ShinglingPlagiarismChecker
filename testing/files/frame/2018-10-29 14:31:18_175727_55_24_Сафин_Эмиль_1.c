int main(int argc, char** argv)
{
    // 4 - потому что первый аргумент это название программы
    if (argc < 4) {
        printf("Usage: frame <height> <width> <text>");
        exit(1);
    }
    
    int w, h, x, y, i, j,j1, n;
    
    // аргументы ком. строки конверт. в числа
    h = atoi(argv[1]);
    w = atoi(argv[2]);

    n = strlen(argv[3]);
    
    if (h < 3 || w - 2 < n) {
        printf("Error");
        exit(1);
    }
    
    i = (h - 1) / 2;
    j = (w - n) / 2 - 1;
    j1 = w - n - 2 - j;
    
    // верхняя планка
    for (x = 0; x < w; ++x) {
        printf("*");
    }
    printf("\n");
    
    // центр
    for (y = 1; y < h - 1; ++y) {
        printf("*");
        
        // если в этой строке текст
        if (y == i) {
            
            // пишем пустышки слева/справа и текст по центру
            for (x = 0; x < j; ++x) 
                printf(" ");
        
            printf("%s", argv[3]);
            
            for (x = 0; x < j1; ++x) 
                printf(" ");
        } else {
            
            // иначе заполняем её пробелами
            for (x = 0; x < w - 2; ++x) {
                printf(" ");
            }
        }
        
        printf("*\n");
    }
    
    // нижняя планка
    for (x = 0; x < w; ++x) {
        printf("*");
    }
    printf("\n");
    
    return 0;
}

