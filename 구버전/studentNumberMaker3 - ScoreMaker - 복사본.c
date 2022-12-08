#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SN1 2000000000
/*
랜덤 생성기 - 평점
여긴 전공학점
*/
int main(void)
{
    float grade[1000] = { 0 };
    //int sn2 = 0, sn3 = 0;
    int random = 0;
    int i;

    FILE* fp = NULL;
    //fp = fopen("Student_Score.txt", "a+");
    fp = fopen("Student_Score2.txt", "a+");

    srand(time(NULL));
    

    for (i = 0;i < sizeof(grade)/4;i++) {
        
        grade[i] = ((float)(rand() % 21 + 30)) / 10;
       
    }


    for (i = 0;i < sizeof(grade) / 4;i++) {
        fprintf(fp, "%.1f\n", grade[i]);
        //printf("%.1f\n", grade[i]);
    }


    
 
   
    fclose(fp);


    return 0;
}

