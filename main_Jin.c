#include "FusionDestiny.h"

/*
2022 - 07 -11
�������б� ��ǻ�Ͱ��к� 2016244084 �ֽ���
�ϰ� �����б� ������ ���� - ���ü��
C��� ���� ������Ʈ.

���� : �������б� ��ü�а� ��ü�л��� ���� ����ó�� ���α׷� �ۼ�
*/

int main(void)
{
    TheStu* pDrgn;
    int menu;
   // char subject[10];
    pDrgn = StudentFusion();
    const char* printMode = "1111110";
    

    
     printf("��ȣ�� ���� ���ϴ� ����� �����Ͻÿ�.\n");
     printf("1.�л� ��ü ��� ��ȸ �ý���\n");
     printf("2.���б� ������ ���� �а��� ����ó�� �ý���\n");
     printf("3.�������� ���� ���� ����ó�� �ý���\n");

     printf("�Է� : ");
     scanf_s("%d", &menu);
     printf("\n\n");
     switch (menu) {
     case 1://�л� ��ü ��� ��ȸ �ý���, �г⺰�� ����
         printf("�г�, �й����� 1000���� ����Ʈ�� �����մϴ�.\n");
         system("pause");
         quicksort(pDrgn, TheGrade_cmp);
         PrintDDragoon(pDrgn, printMode, SIZE,-1);
         printf("\n\n");
         break;
     case 2: // �а��� ����ó�� �ý���
         printf("��ȣ�� ���� �а��� �����ϼ���.\n");
         printf("1.��ǻ�Ͱ��а�\n");
         printf("2.�ż�����а�\n");
         printf("3.�����Ͱ��а�\n");
         printf("4.�����а�\n");
         printf("5.�����а�\n");
         printf("6.���ݼ��а�\n");
         printf("7.����а�\n");
         printf("8.�����а�\n");
         printf("9.�����彺�а�\n");
         printf("10.�׷�Ʈ�а�\n\n");
         printf("�Է� : ");
         scanf_s("%d", &menu);
         printf("\n\n");
         menu--;
         ScholarshipLink(pDrgn, menu);
   
         break;
     case 3:// ���� ����ó�� �ý���
         //printf("Ȯ���� ������� �Է��ϼ��� : \n");
         //scanf_s("%s", subject);
         //printf("\n\n");
         printf("�� ����� �̿ϼ��� ����Դϴ�.\n");
         printf("����� ���� �ϳ��� ���� 30���� �İ��� �л��� ������ ǥ�������� ����մϴ�.\n");
         system("pause");
         SubjectSynchro(pDrgn);
         break;

     default:
         printf("�߸� �Է��ϼ̽��ϴ�.\n");
         system("cls");
         break;

     }
 
    return 0;
}
