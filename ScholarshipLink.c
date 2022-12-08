#include "FusionDestiny.h"

/*
2. 장학금 지급을 위한 학과별 성적처리 시스템
배열포인터와 학과 번호를 매개변수로 퀵소트와 프린트를 한다.
기능마다 비교 함수를 다르게 하여 어떤 기준으로 퀵 정렬을 할지 고르고
구조체 배열을 프린트한다.
*/
void ScholarshipLink(TheStu *pDrgn, int mode) {
    int i;
    char* printMode = "1111110";
    
    printf("학과별로 전체 리스트를 정렬합니다.\n");
    system("pause");

    quicksort(pDrgn, TheMajor_cmp);
    PrintDDragoon(pDrgn, printMode, SIZE,mode);
    
    
    printf("-----------------------------------------\n");
    printf("1.전체학점 기준으로 내림차순 출력\n");
    printf("2.전공학점 기준으로 내림차순 출력\n");
    printf("3.학과->전체학점->전공학점 기준으로 장학금을 지급하여 내림차순 출력\n");
    printf("번호 입력 : ");
    scanf_s("%d", &i);
    printf("\n\n");

    switch (i) {
    case 1://전체 학점으로 내림차순 정렬
        printf("전체학점 기준으로 내림차순 출력\n");
        quicksort(pDrgn, TheScore_cmp);
        PrintDDragoon(pDrgn, printMode, SIZE, mode);
        break;

    case 2: // 전공 학점으로 내림차순 정렬
        printf("전공학점 기준으로 내림차순 출력\n");
        quicksort(pDrgn, TheMj_Score_cmp);
        PrintDDragoon(pDrgn, printMode, SIZE, mode);
        break;


    case 3:// 장학금 지급자 출력, 일단 50명, 전체 학점 기준.
        //학과 비교 -> 전체학점 비교 -> 전공학점 비교
        printMode = "11111111";
        quicksort(pDrgn, TheMajor_cmp);
        PrintDDragoon(pDrgn, printMode, SIZE, mode);
        break;


    default:
        printf("잘못 입력하셨습니다.\n");
        system("cls");
        break;
         
    }
}
