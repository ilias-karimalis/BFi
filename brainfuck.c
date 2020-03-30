#include <stdio.h>
#include <stdlib.h>

void interpret (char* arr) {
    unsigned char mem[30000] = {0};
    unsigned char* ptr = mem;
    for (int i = 0; arr[i] != '\0'; i++) {
        char current_char = arr[i];
        switch (arr[i]) {
            case '>':
                ptr++;
                break;
            case '<':
                ptr--;
                break;
            case '+':
                (*ptr)++;
                break;
            case '-':
                (*ptr)--;
                break;
            case '.':
                putchar(*ptr);
                break;
            case ',':
                (*ptr) = getchar();
                break;
            case '[':
                if (!(*ptr)) {
                    int loop = 1;
                    while (loop > 0) {
                        current_char = arr[++i];
                        if (current_char == ']') {
                            --loop;
                        } else if (current_char == '[') {
                            ++loop;
                        }
                    }
                }
                break;
             case ']':
                if (*ptr) {
                    int loop = 1;
                    while (loop > 0) {
                        current_char = arr[--i];
                        if (current_char == '[') {
                            --loop;
                        } else if (current_char == ']') {
                            ++loop;
                        }
                    }
                }
                break;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        puts("Usage: BFi <sourcecode>");
        exit(1);
    }
    FILE* fp = fopen(argv[1], "r");
    int arr[32768] = {0};
    fread(arr, sizeof(char), 32768, fp);
    fclose(fp);
    interpret((char*) arr);
}
