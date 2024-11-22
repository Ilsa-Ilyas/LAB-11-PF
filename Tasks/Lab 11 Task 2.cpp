#include <stdio.h>

int main() {
    char filename[100], c;
    FILE *file;
    int line = 1;

    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    printf("%d ", line++);
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
        if (c == '\n' && !feof(file)) {
            printf("%d ", line++);
        }
    }

    fclose(file);
    return 0;
}

