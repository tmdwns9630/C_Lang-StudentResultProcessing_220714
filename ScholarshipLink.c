#include "FusionDestiny.h"

/*
2. ���б� ������ ���� �а��� ����ó�� �ý���
�迭�����Ϳ� �а� ��ȣ�� �Ű������� ����Ʈ�� ����Ʈ�� �Ѵ�.
��ɸ��� �� �Լ��� �ٸ��� �Ͽ� � �������� �� ������ ���� ����
����ü �迭�� ����Ʈ�Ѵ�.
*/
void ScholarshipLink(TheStu *pDrgn, int mode) {
    int i;
    char* printMode = "1111110";
    
    printf("�а����� ��ü ����Ʈ�� �����մϴ�.\n");
    system("pause");

    quicksort(pDrgn, TheMajor_cmp);
    PrintDDragoon(pDrgn, printMode, SIZE,mode);
    
    
    printf("-----------------------------------------\n");
    printf("1.��ü���� �������� �������� ���\n");
    printf("2.�������� �������� �������� ���\n");
    printf("3.�а�->��ü����->�������� �������� ���б��� �����Ͽ� �������� ���\n");
    printf("��ȣ �Է� : ");
    scanf_s("%d", &i);
    printf("\n\n");

    switch (i) {
    case 1://��ü �������� �������� ����
        printf("��ü���� �������� �������� ���\n");
        quicksort(pDrgn, TheScore_cmp);
        PrintDDragoon(pDrgn, printMode, SIZE, mode);
        break;

    case 2: // ���� �������� �������� ����
        printf("�������� �������� �������� ���\n");
        quicksort(pDrgn, TheMj_Score_cmp);
        PrintDDragoon(pDrgn, printMode, SIZE, mode);
        break;


    case 3:// ���б� ������ ���, �ϴ� 50��, ��ü ���� ����.
        //�а� �� -> ��ü���� �� -> �������� ��
        printMode = "11111111";
        quicksort(pDrgn, TheMajor_cmp);
        PrintDDragoon(pDrgn, printMode, SIZE, mode);
        break;


    default:
        printf("�߸� �Է��ϼ̽��ϴ�.\n");
        system("cls");
        break;
         
    }
}
