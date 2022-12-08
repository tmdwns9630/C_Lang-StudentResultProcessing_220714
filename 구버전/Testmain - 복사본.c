#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "FusionDestiny.h"

#define SIZE 1000
#define FIRST "��ǻ�Ͱ��а�"
#define Second  "�ż�����а�"
#define Third "�����Ͱ��а�"
/*
���� �������� ����� ���� �ϴ� �ҽ� �ϳ��� �����ھƺ���.
����1
*/

int main(void)
{
   TheStu* pDrgn;
   int menu;
   pDrgn = StudentFusion();
   const char* printMode = "111111";


   PrintDDragoon(pDrgn,printMode);


   /*
    printf("��ȣ�� ���� ���ϴ� ����� �����Ͻÿ�.\n");
    printf("1.�л� ��ü ��� ��ȸ �ý���\n");
    printf("2.���б� ������ ���� �а��� ����ó�� �ý���\n");
    printf("3.�������� ���� ���� ����ó�� �ý���\n");
    
    printf("�Է� : ");
    scanf_s("%d", &menu);
    switch (menu) { 
    case 1://�л� ��ü ��� ��ȸ �ý���
        pDrgn = StudentFusion();
        printf("p����� �ּ� : %p\n", pDrgn);
        break;
    case 2: // �а��� ����ó�� �ý���
        printf("��ȣ�� ���� �а��� �����ϼ���.\n");
        printf("1.��ǻ�Ͱ��а�\n");
        printf("2.�ż�����а�\n");
        printf("3.�����Ͱ��а�\n");
        printf("4.�����а�\n");
        break;
    case 3:// ���� ����ó�� �ý���
        break;
    default:
        printf("�߸� �Է��ϼ̽��ϴ�.\n");
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
    printf("����Ʈ ����\n\n");
    printf("%-10s %4s %5s %10s %8s %8s\n", "�й�", "�г�", "�̸�", "�����а�", "��ü����","��������");
    for (i = 0; i < SIZE; i++) {
       // printf("%-10d %4d %5s %%5.1f %5.1f\n", pDrgn[i].TheNum, pDrgn[i].TheGrade, pDrgn[i].TheName, pDrgn[i].TheScore, pDrgn[i].TheMj_Score);

        //���ڿ� printMode�� �� ���� 1�̸� ����Ѵ�.
        if(printMode[0]==49)
        printf("%-10d ", pDrgn[i].TheNum);//�й�

        if (printMode[1] == 49)
        printf("%4d ", pDrgn[i].TheGrade);//�г�

        if (printMode[2] == 49)
        printf("%5s ", pDrgn[i].TheName);//�̸�

        
        if (printMode[3] == 49){
        switch (pDrgn[i].TheMajor) {
        case 0:
            printf("%-10s ", "��ǻ�Ͱ��а�");
            break;
        
        case 1:
            printf("%-10s ", "�ż�����а�");
            break;
        case 2:
            printf("%-10s ", "�����Ͱ��а�");
            break;

        case 3:
            printf("%-10s ", "�����а�");
            break;

        case 4:
            printf("%-10s ", "�����а�");
            break;

        case 5:
            printf("%-10s ", "���ݼ��а�");
            break;

        case 6:
            printf("%-10s ", "����а�");
            break;

        case 7:
            printf("%-10s ", "�����а�");
            break;

        case 8:
            printf("%-10s ", "�����彺�а�");
            break;

        case 9:
            printf("%-10s ", "�׷�Ʈ�а�");
            break;

        default:
            printf("%-10d ", pDrgn[i].TheMajor);//�����а�
            break;
        }
        }
        
        if (printMode[4] == 49)
        printf("%8.1f ", pDrgn[i].TheScore);//��ü����

        if (printMode[5] == 49)
        printf("%8.1f ", pDrgn[i].TheMj_Score);//��������

        printf("\n");
        
        
        //�� pDrgn[i]=>TheNum �̰ɷδ� �ȵǴ����� �𸣰����� �ƹ�ư �����ϱ� �ƴ�ġ��.
        // printf("%d %d %s\n", pDrgn[i]->TheNum, pDrgn[i]->TheGrade, pDrgn[i]->TheName);
    }
}

void SubjectSynchro(void) {

}

void ScholarshipLink(TheStu *pDrgn) {
    int i;
    const char* printMode = "011111";
    printf("");
    printf("1.�� ���� ��\n2.�������� ��\n3.���б� ������ Ȯ��\n");
    printf("��ȣ �Է� : ");
    scanf("%d", &i);

    switch (i) {
    case 1://�л� ��ü ���������� ���.
        pDrgn = StudentFusion();
        printf("�ϴ� ��ü �������� ��� : %p\n", pDrgn);
        printf("%-10s %4s %5s %5s %5s\n", "�й�", "�г�", "�̸�", "��ü����", "��������");
        //PrintDDragoon(pDrgn);
        break;

    case 2: // �а��� ����ó�� �ý���
        ;
        break;


    case 3:// ���� ����ó�� �ý���
        break;


    default:
        printf("�߸� �Է��ϼ̽��ϴ�.\n");
        system("cls");
        break;
         
    }
}
