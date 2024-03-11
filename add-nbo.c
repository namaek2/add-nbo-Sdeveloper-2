// add-nbo.c

#include "add-nbo.h"
#include "stdio.h"
#include "stdint.h"

void add_nbo(char* argv[]) {
    FILE* file1= fopen(argv[1], "r");
    FILE* file2= fopen(argv[2], "r");

    if (file1 == NULL || file2 == NULL) {
        printf("파일 열기 실패\n");
        return;
    }

    uint32_t result, f1, f2;
    uint32_t t1, t2, t3, t4;

    fread(&f1, sizeof(uint32_t), 1, file1);
    fread(&f2, sizeof(uint32_t), 1, file2);

    return;
    t1 = (f1 & 0xFF000000) >> 24;
    t2 = (f1 & 0x00FF0000) >> 8;
    t3 = (f1 & 0x0000FF00) << 8;
    t4 = (f1 & 0x000000FF) << 24;

    f1 = t1|t2|t3|t4;

    t1 = (f2 & 0xFF000000) >> 24;
    t2 = (f2 & 0x00FF0000) >> 8;
    t3 = (f2 & 0x0000FF00) << 8;
    t4 = (f2 & 0x000000FF) << 24;

    f2 = t1|t2|t3|t4;

    result = f1 + f2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", f1, f1, f2, f2, result, result);

    fclose(file1);
    fclose(file2);
}
