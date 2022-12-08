#include "FusionDestiny.h"

//printMode의 문자열을 비교해서 각 값이 1이면 출력한다.
//현재 범위는 7, 0~6
/*
모든 요소를 종합하여 디드라군을 프린트한다
매개변수1 : 구조체 배열 포인터
매개변수2 : 학번, 학년 등의 어떤 요소를 출력할지 고르는 요소.
매개변수3 : 출력할 전체 범위
ㄴ 참고로 이건 그냥 1000으로 고정하고 장학금 출력에 쓸 size로 쓰려고 하니까 장학금 출력 방식으로 인해 수정 실패
매개변수4 : 학과를 입력받아서 그 학과만 출력할 때 쓴다.
ㄴ 이게 출력방식이 그 학과가 아니면 continue로 무시하고 다음 루프 도는 방식이라
    장학금의 50명만 출력하는 기능을 구현 못함
*/
void PrintDDragoon(TheStu* pDrgn, const char* printMode, int printsize, int MajorNum) {
    register int i,count=0;
    printf("Print Destroyer Phoenix Guy\n\n");
    printf("%-10s %4s %5s %14s %10s %8s",
        "학번", "학년", "이름", "전공학과", "전체학점","전공학점");
    if (printMode[6] == 49)
        printf(" %8s", "장학금(만원)");
    
    printf("\n");
    for (i = 0; i < printsize; i++) {
       // printf("%-10d %4d %5s %%5.1f %5.1f\n", pDrgn[i].TheNum, pDrgn[i].TheGrade, pDrgn[i].TheName, pDrgn[i].TheScore, pDrgn[i].TheMj_Score);
        if (MajorNum > 0) {
            if (pDrgn[i].TheMajor != MajorNum)
                continue;
        }
        
        
        if (printMode[0] == 49)
            printf("%-10d ", pDrgn[i].TheNum);//학번
        else
            printf("%-10s", " ");

        if (printMode[1] == 49)
        printf("%4d ", pDrgn[i].TheGrade);//학년
        else
            printf("%4s", " ");

        if (printMode[2] == 49)
        printf("%5s ", pDrgn[i].TheName);//이름
        else
            printf("%5s", " ");
        
        if (printMode[3] == 49){
        switch (pDrgn[i].TheMajor) {
        case 0:
            printf("%15s ", "컴퓨터공학과");
            break;
        
        case 1:
            printf("%15s ", "신소재공학과");
            break;
        case 2:
            printf("%15s ", "데이터공학과");
            break;

        case 3:
            printf("%15s ", "영어학과");
            break;

        case 4:
            printf("%15s ", "국어학과");
            break;

        case 5:
            printf("%15s ", "연금술학과");
            break;

        case 6:
            printf("%15s ", "듀얼학과");
            break;

        case 7:
            printf("%15s ", "말딸학과");
            break;

        case 8:
            printf("%15s ", "에이펙스학과");
            break;

        case 9:
            printf("%15s ", "그루트학과");
            break;

        default:
            printf("%10d ", pDrgn[i].TheMajor);//전공학과
            break;
        }
        }
        else
            printf("%15s", " ");
        
        if (printMode[4] == 49)
        printf("%8.1f ", pDrgn[i].TheScore);//전체학점
        else
            printf("%8s", " ");

        if (printMode[5] == 49)
        printf("%8.1f ", pDrgn[i].TheMj_Score);//전공학점
        else
            printf("%8s", " ");
       
        //장학금
        if (printMode[6] == 49) {
            if (count == 0)
                printf("%5d", 1000);
            else if (count < 5)
                printf("%5d", 500);
            else if (count < 10)
                printf("%5d", 200);
            else if (count < 20)
                printf("%5d", 100);
            else if (count < 40)
                printf("%5d", 50);
            else
                printf("%5d", 0);
      
        }


        count++;
        printf("\n");
        
        
        //왜 pDrgn[i]=>TheNum 이걸로는 안되는지는 모르겠지만 아무튼 됐으니까 됐다치자.
        // printf("%d %d %s\n", pDrgn[i]->TheNum, pDrgn[i]->TheGrade, pDrgn[i]->TheName);
    }
}
