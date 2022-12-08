#include "FusionDestiny.h"

//printMode�� ���ڿ��� ���ؼ� �� ���� 1�̸� ����Ѵ�.
//���� ������ 7, 0~6
/*
��� ��Ҹ� �����Ͽ� ������ ����Ʈ�Ѵ�
�Ű�����1 : ����ü �迭 ������
�Ű�����2 : �й�, �г� ���� � ��Ҹ� ������� ���� ���.
�Ű�����3 : ����� ��ü ����
�� ����� �̰� �׳� 1000���� �����ϰ� ���б� ��¿� �� size�� ������ �ϴϱ� ���б� ��� ������� ���� ���� ����
�Ű�����4 : �а��� �Է¹޾Ƽ� �� �а��� ����� �� ����.
�� �̰� ��¹���� �� �а��� �ƴϸ� continue�� �����ϰ� ���� ���� ���� ����̶�
    ���б��� 50�� ����ϴ� ����� ���� ����
*/
void PrintDDragoon(TheStu* pDrgn, const char* printMode, int printsize, int MajorNum) {
    register int i,count=0;
    printf("Print Destroyer Phoenix Guy\n\n");
    printf("%-10s %4s %5s %14s %10s %8s",
        "�й�", "�г�", "�̸�", "�����а�", "��ü����","��������");
    if (printMode[6] == 49)
        printf(" %8s", "���б�(����)");
    
    printf("\n");
    for (i = 0; i < printsize; i++) {
       // printf("%-10d %4d %5s %%5.1f %5.1f\n", pDrgn[i].TheNum, pDrgn[i].TheGrade, pDrgn[i].TheName, pDrgn[i].TheScore, pDrgn[i].TheMj_Score);
        if (MajorNum > 0) {
            if (pDrgn[i].TheMajor != MajorNum)
                continue;
        }
        
        
        if (printMode[0] == 49)
            printf("%-10d ", pDrgn[i].TheNum);//�й�
        else
            printf("%-10s", " ");

        if (printMode[1] == 49)
        printf("%4d ", pDrgn[i].TheGrade);//�г�
        else
            printf("%4s", " ");

        if (printMode[2] == 49)
        printf("%5s ", pDrgn[i].TheName);//�̸�
        else
            printf("%5s", " ");
        
        if (printMode[3] == 49){
        switch (pDrgn[i].TheMajor) {
        case 0:
            printf("%15s ", "��ǻ�Ͱ��а�");
            break;
        
        case 1:
            printf("%15s ", "�ż�����а�");
            break;
        case 2:
            printf("%15s ", "�����Ͱ��а�");
            break;

        case 3:
            printf("%15s ", "�����а�");
            break;

        case 4:
            printf("%15s ", "�����а�");
            break;

        case 5:
            printf("%15s ", "���ݼ��а�");
            break;

        case 6:
            printf("%15s ", "����а�");
            break;

        case 7:
            printf("%15s ", "�����а�");
            break;

        case 8:
            printf("%15s ", "�����彺�а�");
            break;

        case 9:
            printf("%15s ", "�׷�Ʈ�а�");
            break;

        default:
            printf("%10d ", pDrgn[i].TheMajor);//�����а�
            break;
        }
        }
        else
            printf("%15s", " ");
        
        if (printMode[4] == 49)
        printf("%8.1f ", pDrgn[i].TheScore);//��ü����
        else
            printf("%8s", " ");

        if (printMode[5] == 49)
        printf("%8.1f ", pDrgn[i].TheMj_Score);//��������
        else
            printf("%8s", " ");
       
        //���б�
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
        
        
        //�� pDrgn[i]=>TheNum �̰ɷδ� �ȵǴ����� �𸣰����� �ƹ�ư �����ϱ� �ƴ�ġ��.
        // printf("%d %d %s\n", pDrgn[i]->TheNum, pDrgn[i]->TheGrade, pDrgn[i]->TheName);
    }
}
