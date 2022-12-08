#include "FusionDestiny.h"

/*
퓨전 데스티니로 드라군을 융합한다
파일 입출력으로 txt의 데이터를 출력하여 구조체 배열에 저장하고
배열 포인터를 리턴한다.
*/

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
