#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(int width, int height, int lenght) {
  return ( (height < 3 || (width <= lenght) || (width - lenght < 2)) ? 1 : 0 );
}

void frame(int _a1, int _a2, char* _text) {
  int _textlen = strlen(_text);
  int diff = _a2 - _textlen;
  for (int i = 1; i <= _a1; printf("%s", "\n"), i++) {
    // TODO : borders fix
    if (i == 1 || i == _a1)
      for (int j = 0; j < _a2; j++) printf("%c", '*');
    else if (!(i - (_a1 + 1) / 2)) {
        printf("%c", '*');
        for (int j = 1; j < diff / 2; j++) printf("%c", ' ');
        printf("%s", _text);
        for (int j = diff / 2 + _textlen + 1; j <= _a2; j++)
          if (j == _a2) printf("%c", '*');
          else printf("%c", ' ');
      }
      else {
        for (int j = 1; j <= _a2; j++)
          if(j == 1 || j == _a2) printf("%c", '*');
          else printf("%c", ' ');
      }
    }
}

int main(int argc, char** argv) {
  if (argc != 4) {
        	printf("Usage: frame <height> <width> <text>");
		return 0;
	}

  int a1 = atoi(argv[1]),
      a2 = atoi(argv[2]);

  if (check(a2, a1, strlen(argv[3]))) {
		printf("Error");
		return 0;
	}

  frame(a1, a2, argv[3]);
	return 0;
}
