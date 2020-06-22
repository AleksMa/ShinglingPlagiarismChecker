#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw_frame(long w, long h, const char *s)
{
    size_t sz = strlen(s);
    for (long i = 0; i < h; ++i)
    {
        for (long j = 0; j < w; ++j)
        {
            if (i == (h - 1) / 2 && j == (w - sz) / 2)
            {
                printf("%s", s);
                j += sz;
            }

            if (i == 0 || j == 0 || i == h - 1 || j == w - 1)
                putc('*', stdout);
              else
                putc(' ', stdout);
        }
        putc('\n', stdout);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }

    long h = atol(argv[1]),
         w = atol(argv[2]);

    if (h <= 2 || (w - 2) < strlen(argv[3]))
    {
        printf("Error");
        return 0;
    }

    draw_frame(w, h, argv[3]);
    return 0;
}