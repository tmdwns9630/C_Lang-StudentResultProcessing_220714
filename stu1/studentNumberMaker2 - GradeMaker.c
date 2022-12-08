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
    int grade[1000] = { 0 };
    //int sn2 = 0, sn3 = 0;
    int random = 0;
    int i;

    FILE* fp = NULL;
    fp = fopen("Student_Grade.txt", "a+");

    srand(time(NULL));
    

    for (i = 0;i < sizeof(grade)/4;i++) {
        
        grade[i] = rand() % 4 + 1;
       
    }


    for (i = 0;i < sizeof(grade) / 4;i++) {
        fprintf(fp, "%d\n", grade[i]);
    }


    
 
    //fputs(allname, fp);
    fclose(fp);


    return 0;
}

