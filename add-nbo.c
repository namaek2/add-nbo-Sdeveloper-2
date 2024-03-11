// add-nbo.c

#include "add-nbo.h"
#include "stdio.h"
#include "stdint.h"

void add_nbo(char* argv[]) {
    if(argv[1] == NULL || argv[2] == NULL) {
        printf("인수가 전달되지 않음\n");
        return;
    }

    FILE* file1= fopen(argv[1], "r");
    FILE* file2= fopen(argv[2], "r");

    if (file1 == NULL || file2 == NULL) {
        printf("파일이 존재하지 않거나 열기에 실패함\n");
        return;
    }


    uint32_t result, f1, f2;
    uint32_t t1, t2, t3, t4, f1_size, f2_size;
    
    fread(&f1, sizeof(uint32_t), 1, file1);
    fread(&f2, sizeof(uint32_t), 1, file2);
   
    fseek(file1,0,SEEK_END);
    f1_size = ftell(file1);
    fseek(file2, 0, SEEK_END);
    f2_size = ftell(file2);

    if(f1_size < sizeof(int) ||f2_size < sizeof(int)) {
        printf("파일의 크기가 32비트(4바이트) 보다 작음\n");
        return;
    }

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
