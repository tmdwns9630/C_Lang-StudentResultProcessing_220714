#include "FusionDestiny.h"

/*
2022 - 07 -11
선문대학교 컴퓨터공학부 2016244084 최승준
하계 계절학기 몰입형 교육 - 블록체인
C언어 개별 프로젝트.

주제 : 선문대학교 전체학과 전체학생을 위한 성적처리 프로그램 작성
*/

int main(void)
{
    TheStu* pDrgn;
    int menu;
   // char subject[10];
    pDrgn = StudentFusion();
    const char* printMode = "1111110";
    

    
     printf("번호를 눌러 원하는 기능을 실행하시오.\n");
     printf("1.학생 전체 기록 조회 시스템\n");
     printf("2.장학금 지급을 위한 학과별 성적처리 시스템\n");
     printf("3.교수님을 위한 과목별 성적처리 시스템\n");

     printf("입력 : ");
     scanf_s("%d", &menu);
     printf("\n\n");
     switch (menu) {
     case 1://학생 전체 기록 조회 시스템, 학년별로 정렬
         printf("학년, 학번별로 1000명의 리스트를 정렬합니다.\n");
         system("pause");
         quicksort(pDrgn, TheGrade_cmp);
         PrintDDragoon(pDrgn, printMode, SIZE,-1);
         printf("\n\n");
         break;
     case 2: // 학과별 성적처리 시스템
         printf("번호를 눌러 학과를 선택하세요.\n");
         printf("1.컴퓨터공학과\n");
         printf("2.신소재공학과\n");
         printf("3.데이터공학과\n");
         printf("4.영어학과\n");
         printf("5.국어학과\n");
         printf("6.연금술학과\n");
         printf("7.듀얼학과\n");
         printf("8.말딸학과\n");
         printf("9.에이펙스학과\n");
         printf("10.그루트학과\n\n");
         printf("입력 : ");
         scanf_s("%d", &menu);
         printf("\n\n");
         menu--;
         ScholarshipLink(pDrgn, menu);
   
         break;
     case 3:// 과목별 성적처리 시스템
         //printf("확인할 과목명을 입력하세요 : \n");
         //scanf_s("%s", subject);
         //printf("\n\n");
         printf("이 기능은 미완성된 기능입니다.\n");
         printf("현재는 과목 하나에 대해 30명의 컴공과 학생과 점수와 표준편차를 출력합니다.\n");
         system("pause");
         SubjectSynchro(pDrgn);
         break;

     default:
         printf("잘못 입력하셨습니다.\n");
         system("cls");
         break;

     }
 
    return 0;
}
