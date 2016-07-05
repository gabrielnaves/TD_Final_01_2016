#include <utils.h>

void readLine(char *buffer, int size) {
    char c;
    int i = 0;
    do {
        c = getchar();
        buffer[i++] = c;
    } while (c != '\n' && i < size);
    buffer[i-1] = '\0';
}
