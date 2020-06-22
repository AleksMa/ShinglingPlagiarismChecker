#include <stdio.h>
#include <string.h>

#define REQUIRED_ARGS_AMOUNT 4
#define HEIGHT_ARG_INDEX 1
#define WIDTH_ARG_INDEX 2
#define TEXT_ARG_INDEX 3

int parseIntegerArgValue(const char *);
int tryToRenderFrameWithText(const char **);
int isFrameCouldBeRendered(int, int, const char *);
int renderFrameWithText(int, int, const char *);
void repeatln(char, int);
void repeat(char, int);

int main(int argc, const char *argv[])
{
    if (argc != REQUIRED_ARGS_AMOUNT)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 1;
    }
    else
    {
        return tryToRenderFrameWithText(argv);
    }
}

int tryToRenderFrameWithText(const char *argv[])
{
    int height = parseIntegerArgValue(argv[HEIGHT_ARG_INDEX]);
    int width = parseIntegerArgValue(argv[WIDTH_ARG_INDEX]);
    const char *text = argv[TEXT_ARG_INDEX];
    if (isFrameCouldBeRendered(height, width, text))
    {
        return renderFrameWithText(height - 2, width, text);
    }
    else
    {
        printf("Error\n");
        return 2;
    }
}

int isFrameCouldBeRendered(int height, int width, const char *text)
{
    return strlen(text) <= (width - 2) && (height > 2);
}

int renderFrameWithText(int height, int width, const char *text)
{
    repeatln('*', width);
    int length = strlen(text);
    int center = ((height & 1) ? height + 1 : height) / 2;
    int spaces = ((width - 2) - length) / 2;
    for (int i = 1; i <= height; i++)
    {
        repeat('*', 1);
        if (i == center)
        {
            repeat(' ', spaces);
            printf("%s", text);
            repeat(' ', (width - 2 - spaces - length));
        }
        else
        {
            repeat(' ', width - 2);
        }
        repeatln('*', 1);
    }
    repeatln('*', width);
    return 0;
}

int parseIntegerArgValue(const char *str)
{
    int buf = 0;
    sscanf(str, "%d", &buf);
    return buf;
}

void repeat(char chr, int repeats)
{
    for (int i = 0; i < repeats; i++)
    {
        printf("%c", chr);
    }
}

void repeatln(char chr, int repeats)
{
    repeat(chr, repeats);
    printf("\n");
}