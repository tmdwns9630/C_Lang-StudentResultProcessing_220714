#include "FusionDestiny.h"

/*
ǻ�� ����Ƽ�Ϸ� ����� �����Ѵ�
���� ��������� txt�� �����͸� ����Ͽ� ����ü �迭�� �����ϰ�
�迭 �����͸� �����Ѵ�.
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
