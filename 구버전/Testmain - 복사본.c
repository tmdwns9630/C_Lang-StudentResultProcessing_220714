#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "FusionDestiny.h"

#define SIZE 1000
#define FIRST "컴퓨터공학과"
#define Second  "신소재공학과"
#define Third "데이터공학과"
/*
파일 여러개로 만들기 힘들어서 일단 소스 하나에 때려박아보자.
버전1
*/

int main(void)
{
   TheStu* pDrgn;
   int menu;
   pDrgn = StudentFusion();
   const char* printMode = "111111";


   PrintDDragoon(pDrgn,printMode);


   /*
    printf("번호를 눌러 원하는 기능을 실행하시오.\n");
    printf("1.학생 전체 기록 조회 시스템\n");
    printf("2.장학금 지급을 위한 학과별 성적처리 시스템\n");
    printf("3.교수님을 위한 과목별 성적처리 시스템\n");
    
    printf("입력 : ");
    scanf_s("%d", &menu);
    switch (menu) { 
    case 1://학생 전체 기록 조회 시스템
        pDrgn = StudentFusion();
        printf("p드라군의 주소 : %p\n", pDrgn);
        break;
    case 2: // 학과별 성적처리 시스템
        printf("번호를 눌러 학과를 선택하세요.\n");
        printf("1.컴퓨터공학과\n");
        printf("2.신소재공학과\n");
        printf("3.데이터공학과\n");
        printf("4.영어학과\n");
        break;
    case 3:// 과목별 성적처리 시스템
        break;
    default:
        printf("잘못 입력하셨습니다.\n");
        system("cls");
        break;
    
    }
*/
    return 0;
}

TheStu* StudentFusion(void)
{

    static TheStu Drgn[SIZE]={0};
    static TheStu* pDrgn = Drgn;

    register int i;

    FILE* fpName = NULL;
    FILE* fpNum = NULL;
    FILE* fpGrade = NULL;
    FILE* fpScore = NULL;
    FILE* fpScoreM = NULL;
    FILE* fpMajor = NULL;


    fpName = fopen("Student_Name.txt", "a+");
    fpNum = fopen("Student_Number.txt", "a+");
    fpGrade = fopen("Student_Grade.txt", "a+");
    fpMajor = fopen("Student_Major.txt", "a+");
    fpScore = fopen("Student_Score.txt", "a+");
    fpScoreM = fopen("Student_ScoreM.txt", "a+");
    

    for (i = 0; i < SIZE; i++) {
        fscanf(fpNum, "%d", &Drgn[i].TheNum);

        fscanf(fpGrade, "%d", &Drgn[i].TheGrade);
      
        fscanf(fpName, "%s", &Drgn[i].TheName);

        fscanf(fpMajor, "%d", &Drgn[i].TheMajor);

        fscanf(fpScore, "%f", &Drgn[i].TheScore);

        fscanf(fpScoreM, "%f", &Drgn[i].TheMj_Score);

    }
   



    fclose(fpName);
    fclose(fpNum);
    fclose(fpGrade);
    fclose(fpScore);
    fclose(fpScoreM);
    fclose(fpMajor);
    return pDrgn;

}

void PrintDDragoon(TheStu* pDrgn,const char* printMode) {
    int i;
    printf("프린트 디드라군\n\n");
    printf("%-10s %4s %5s %10s %8s %8s\n", "학번", "학년", "이름", "전공학과", "전체학점","전공학점");
    for (i = 0; i < SIZE; i++) {
       // printf("%-10d %4d %5s %%5.1f %5.1f\n", pDrgn[i].TheNum, pDrgn[i].TheGrade, pDrgn[i].TheName, pDrgn[i].TheScore, pDrgn[i].TheMj_Score);

        //문자열 printMode의 각 값이 1이면 출력한다.
        if(printMode[0]==49)
        printf("%-10d ", pDrgn[i].TheNum);//학번

        if (printMode[1] == 49)
        printf("%4d ", pDrgn[i].TheGrade);//학년

        if (printMode[2] == 49)
        printf("%5s ", pDrgn[i].TheName);//이름

        
        if (printMode[3] == 49){
        switch (pDrgn[i].TheMajor) {
        case 0:
            printf("%-10s ", "컴퓨터공학과");
            break;
        
        case 1:
            printf("%-10s ", "신소재공학과");
            break;
        case 2:
            printf("%-10s ", "데이터공학과");
            break;

        case 3:
            printf("%-10s ", "영어학과");
            break;

        case 4:
            printf("%-10s ", "국어학과");
            break;

        case 5:
            printf("%-10s ", "연금술학과");
            break;

        case 6:
            printf("%-10s ", "듀얼학과");
            break;

        case 7:
            printf("%-10s ", "말딸학과");
            break;

        case 8:
            printf("%-10s ", "에이펙스학과");
            break;

        case 9:
            printf("%-10s ", "그루트학과");
            break;

        default:
            printf("%-10d ", pDrgn[i].TheMajor);//전공학과
            break;
        }
        }
        
        if (printMode[4] == 49)
        printf("%8.1f ", pDrgn[i].TheScore);//전체학점

        if (printMode[5] == 49)
        printf("%8.1f ", pDrgn[i].TheMj_Score);//전공학점

        printf("\n");
        
        
        //왜 pDrgn[i]=>TheNum 이걸로는 안되는지는 모르겠지만 아무튼 됐으니까 됐다치자.
        // printf("%d %d %s\n", pDrgn[i]->TheNum, pDrgn[i]->TheGrade, pDrgn[i]->TheName);
    }
}

void SubjectSynchro(void) {

}

void ScholarshipLink(TheStu *pDrgn) {
    int i;
    const char* printMode = "011111";
    printf("");
    printf("1.총 학점 비교\n2.전공학점 비교\n3.장학금 지급자 확인\n");
    printf("번호 입력 : ");
    scanf("%d", &i);

    switch (i) {
    case 1://학생 전체 인적사항을 출력.
        pDrgn = StudentFusion();
        printf("일단 전체 인적사항 출력 : %p\n", pDrgn);
        printf("%-10s %4s %5s %5s %5s\n", "학번", "학년", "이름", "전체학점", "전공학점");
        //PrintDDragoon(pDrgn);
        break;

    case 2: // 학과별 성적처리 시스템
        ;
        break;


    case 3:// 과목별 성적처리 시스템
        break;


    default:
        printf("잘못 입력하셨습니다.\n");
        system("cls");
        break;
         
    }
}
