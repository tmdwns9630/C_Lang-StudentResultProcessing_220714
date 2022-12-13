#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/*
txt 파일 3개로부터 이름, 학년, 학번을 읽어내어 하나의 구조체로 만든다. 
*/
typedef struct Student {
    char TheName[4];
    int TheNum;
    int TheGrade;
}TheStu;
int main(void)
{
    
    TheStu DDrgn[1000] = { 0 };
    
    register int i;

    FILE* fpName = NULL;
    FILE* fpNum = NULL;
    FILE* fpGrade = NULL;


    fpName = fopen("Student_Name.txt", "a+");
    fpNum = fopen("Student_Number.txt", "a+");
    fpGrade = fopen("Student_Grade.txt", "a+");

    printf("준비된 사수로부터~~~~~~~\n 로딩 개시!\n\n");

    for (i = 0;i < 1000;i++) {
        fscanf(fpNum, "%d", &DDrgn[i].TheNum);
      
        fscanf(fpGrade, "%d", &DDrgn[i].TheGrade);

        fscanf(fpName, "%s", &DDrgn[i].TheName);
       
    }

    for (i = 0;i < 1000;i++) {
        printf("%d %d %s\n", DDrgn[i].TheNum, DDrgn[i].TheGrade, DDrgn[i].TheName);
    }
    
   
    fclose(fpName);
    fclose(fpNum);
    fclose(fpGrade);

    printf("나와라요.\n\n");
  
    //printf("%sEND\n", allname);
    //printf("대충 이들은 1000명의 암살자 집단이라 다 알파벳 세글자로 불린다고 칩시다.\n");
    //printf("문자열 길이 : %d\n", strlen(allname));
    return 0;
}

