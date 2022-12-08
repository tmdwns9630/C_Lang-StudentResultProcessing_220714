#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "FusionDestiny.h"

#define SIZE 1000

/*
txt 파일 3개로부터 이름, 학년, 학번을 읽어내어 하나의 구조체로 만든다. 
*/

TheStu* StudentFusion(void)
{
    
    TheStu Drgn[SIZE] = { 0 };
    TheStu* pDrgn = &Drgn;
    
    register int i;

    FILE* fpName = NULL;
    FILE* fpNum = NULL;
    FILE* fpGrade = NULL;


    fpName = fopen("Student_Name.txt", "a+");
    fpNum = fopen("Student_Number.txt", "a+");
    fpGrade = fopen("Student_Grade.txt", "a+");

    
    for (i = 0;i < SIZE;i++) {
        fscanf(fpNum, "%d", &Drgn[i].TheNum);
      
        fscanf(fpGrade, "%d", &Drgn[i].TheGrade);

        fscanf(fpName, "%s", &Drgn[i].TheName);
       
    }

    for (i = 0;i < SIZE;i++) {
        //printf("%d %d %s\n", Drgn[i].TheNum, Drgn[i].TheGrade, Drgn[i].TheName);
    }

    return pDrgn;
    
   
    fclose(fpName);
    fclose(fpNum);
    fclose(fpGrade);

    //printf("나와라요.\n\n");
  
    //return 0;
}

