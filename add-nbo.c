// add-nbo.c

#include "add-nbo.h"
#include "stdio.h"
#include "stdint.h"

void add_nbo(char* argv[]) {
    FILE* file1= fopen(argv[1], "r");
    FILE* file2= fopen(argv[2], "r");

    if (file1 == NULL) {
        printf("파일 열기 실패\n");
        return;
    } else if (file2 == NULL) {
        printf("파일 열기 실패\n");
        return;
    }

    uint32_t result = 0;
    uint32_t f1;
    uint32_t f2;
    size_t f_size;

    while ((f_size = fread(&f1, sizeof(uint32_t), 1, file1)) > 0) {
        printf("%08X ", f1);
    }

    result += f1;

    while ((f_size = fread(&f2, sizeof(uint32_t), 1, file2)) > 0) {
        printf("%08X ", f2);
    }

    result += f2;


    fclose(file1);
    fclose(file2);
    return;
}
