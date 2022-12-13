#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SN1 2000000000
/*
학번 랜덤 생성기
2016244084
2*10^9 + (16~22)*10^7 + (1~999999)
*/
int main(void)
{
    int stuNum[1000] = { 0 };
    int sn2 = 0, sn3 = 0;
    int random = 0;
    int i;

    FILE* fp = NULL;
    fp = fopen("Student_Number.txt", "a+");

    srand(time(NULL));
    

    for (i = 0;i < sizeof(stuNum)/4;i++) {
        random = rand() % 10 + 13; // 학번의 연도 파트
        sn2 = random * 1000000;

        //random = rand();
        sn3 = rand();

        stuNum[i] = SN1 + sn2 + sn3;
        //printf("%d : %d\n", i, stuNum[i]);
    }


    for (i = 0;i < sizeof(stuNum) / 4;i++) {
        fprintf(fp, "%d\n", stuNum[i]);
    }


    
 
    //fputs(allname, fp);
    fclose(fp);


    return 0;
}

