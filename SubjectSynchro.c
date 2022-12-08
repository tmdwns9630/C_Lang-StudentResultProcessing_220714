#include "FusionDestiny.h"

/*
과목별 성적처리 시스템
(미완성)

포인터 배열을 만들어서 피드라군의 배열값을 전부 꽃드라군에 참조시킨다.
...였는대 과목수가 너무 많아서 감당이 안되었고, 마감시간이 다가와서
그냥 기초프로젝트 과목 하나에 대해 30명의 컴공과 학생과 점수와 표준편차를 출력한다.
과목만 35개인데 그거 데이터를 어떻게 다 만들고 다 관리할지 어설픈 설계가 전부였다..
*/

void SubjectSynchro(TheStu* pDrgn) //char Subject[10]
{
   // TheStu* Tuner[SIZE] = { NULL };
    register int i;
    int sum = 0;
    double average=0, variance = 0;


    char SubjectName[20] = "기초프로젝트";
    int SubjectScore[30];
  //TheFlrDrgn FDrgn[100];

  
    FILE* fpSubjScore = NULL;

    
    fpSubjScore = fopen("SubjectData\\Subject_Score00.txt", "a+");
    for (i = 0;i < SUBJECT_SIZE;i++) {
        fscanf(fpSubjScore, "%d", &SubjectScore[i]);

    }
    fclose(fpSubjScore);
    
   
    printf("프린트 꽃드라군\n\n");
    printf("%-10s %4s %5s %14s %10s %8s",
        "학번", "학년", "이름", "전공학과", "과목명", "점수");

    printf("\n");
    quicksort(pDrgn, TheMajor_cmp);
    for (i = 0;i < SUBJECT_SIZE;i++) {

        printf("%-10d ", pDrgn[i].TheNum);//학번
        printf("%4d ", pDrgn[i].TheGrade);//학년
        printf("%5s ", pDrgn[i].TheName);//이름
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
            printf("%10d ", pDrgn[i].TheMajor);
            break;
        } //학과명
       
        printf("%10s ", SubjectName);
        printf("%3c", SubjectScore[i]);
        printf("\n");
    }

    //표준편차 구하기
    for (int i = 0; i < SUBJECT_SIZE; i++)
        sum += SubjectScore[i];
    
    average = (double)sum / SUBJECT_SIZE;

    for (int i = 0; i < SUBJECT_SIZE; i++) {
        variance = variance + (SubjectScore[i] - average) * (SubjectScore[i] - average);
    }

    variance = variance / SUBJECT_SIZE;

    printf("평균: %.3lf, 분산: %.3lf, 표준편차 : %.3lf\n", average, variance, sqrt(variance));
    //return ;
}

