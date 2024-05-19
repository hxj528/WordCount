#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *option = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int count = 0;
    int c;
    if (strcmp(option, "-c") == 0) {
        while ((c = fgetc(file)) != EOF) {
            count++;
        }
        printf("字符数：%d\n", count);
    } else if (strcmp(option, "-w") == 0) {
        int inWord = 0;
        while ((c = fgetc(file)) != EOF) {
            if (c == ' ' || c == '\n' || c == '\t') {
                inWord = 0;
            } else if (!inWord) {
                count++;
                inWord = 1;
            }
        }
        printf("单词数：%d\n", count);
    } else {
        printf("Invalid option. Please use -c or -w.\n");
        return 1;
    }

    fclose(file);
    return 0;
}