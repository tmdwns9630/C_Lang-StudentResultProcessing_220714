#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SN1 2000000000
/*
랜덤 생성기 - 학과
일단 0~9까지의 번호를 주고 그걸 나중에 매칭시킨다.

*/
int main(void)
{
    int major[1000] = { 0 };
    //int sn2 = 0, sn3 = 0;
    int random = 0;
    int i;

    FILE* fp = NULL;
    fp = fopen("Student_Major.txt", "a+");

    srand(time(NULL));
    

    for (i = 0;i < sizeof(major)/4;i++) {
        
        major[i] = rand() % 10;
       
    }


    for (i = 0;i < sizeof(major) / 4;i++) {
        fprintf(fp, "%d\n", major[i]);
       printf("%d\n", major[i]);
    }


    
 
   
    fclose(fp);


    return 0;
}

