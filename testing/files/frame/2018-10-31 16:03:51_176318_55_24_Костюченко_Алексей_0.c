int main(int argc, char** argv)
{
    if (argc < 4) {
        printf("Usage: frame <height> <width> <text>");
        exit(1);
    }
    
    int w, h, x, y, i, j,j1, n;
    
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
    
    for (x = 0; x < w; ++x) {
        printf("*");
    }
    printf("\n");
    
    for (y = 1; y < h - 1; ++y) {
        printf("*");
        
        if (y == i) {
            
            for (x = 0; x < j; ++x)
                printf(" ");
            
            printf("%s", argv[3]);
            
            for (x = 0; x < j1; ++x)
                printf(" ");
        } else {
            
            for (x = 0; x < w - 2; ++x) {
                printf(" ");
            }
        }
        
        printf("*\n");
    }
    
    for (x = 0; x < w; ++x) {
        printf("*");
    }
    printf("\n");
    
    return 0;
}
