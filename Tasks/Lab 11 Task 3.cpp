#include <stdio.h>
#include <ctype.h>

int main() {
    char source[100], destination[100];
    FILE *src, *dest;
    char ch;

    printf("Enter source file name: ");
    scanf("%s", source);
    printf("Enter destination file name: ");
    scanf("%s", destination);

    src = fopen(source, "r");
    if (src == NULL) {
        printf("Could not open source file.\n");
        return 1;
    }

    dest = fopen(destination, "w");
    if (dest == NULL) {
        fclose(src);
        printf("Could not open destination file.\n");
        return 1;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(toupper(ch), dest);
    }

    printf("File copied and converted to uppercase successfully.\n");
    fclose(src);
    fclose(dest);
    return 0;
}