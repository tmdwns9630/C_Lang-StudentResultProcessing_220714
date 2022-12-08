#include "FusionDestiny.h"

/*
�����İ� ���Լ���.
�������� �� �ؿ� �ְ�.
��� ���Լ��� ���� ���� ���, �ٸ� ���Լ��� ȣ���Ͽ� ����Ѵ�.

*/
int TheGrade_cmp(const void* a, const void* b)//�г⺰ ��
{
    const TheStu* m, * n;
    m = (const TheStu*)a;
    n = (const TheStu*)b;

    if (m->TheGrade < n->TheGrade)
    {
        return (-1);
    }
    else if (m->TheGrade == n->TheGrade)
    {
        //return (0);
        //���� ��� �й� ������ ����
        return id_cmp(m, n);
    }
    else
    {
        return (1);
    }
}

int TheScore_cmp(const void* a, const void* b)//��ü���� ��, ��������
{
    const TheStu* m, * n;
    m = (const TheStu*)a;
    n = (const TheStu*)b;

    if (m->TheScore < n->TheScore)
    {
        return (1);
    }
    else if (m->TheScore == n->TheScore)
    {
        //return (0);
        //���� �� �������� ��
        return TheMj_Score_cmp(m,n);
    }
    else
    {
        return (-1);
    }
}

int TheMj_Score_cmp(const void* a, const void* b)//�������� ��, ��������
{
    const TheStu* m, * n;
    m = (const TheStu*)a;
    n = (const TheStu*)b;

    if (m->TheMj_Score < n->TheMj_Score)
    {
        return (1);
    }
    else if (m->TheMj_Score == n->TheMj_Score)
    {
        return (0);
    }
    else
    {
        return (-1);
    }
}

int TheMajor_cmp(const void* a, const void* b)//�����а� ��
{
    const TheStu* m, * n;
    m = (const TheStu*)a;
    n = (const TheStu*)b;

    if (m->TheMajor < n->TheMajor)
    {
        return (-1);
    }
    else if (m->TheMajor == n->TheMajor)
    {
        //return (0);
        return TheScore_cmp(m,n);
    }
    else
    {
        return (1);
    }
}
int id_cmp(const void* a, const void* b)//�й� ����
{
    const TheStu* m, * n;
    m = (const struct student*)a;
    n = (const struct student*)b;

    if (m->TheNum < n->TheNum)
    {
        return (-1);
    }
    else if (m->TheNum == n->TheNum)
    {
        return (0);
    }
    else
    {
        return (1);
    }
}



void quicksort(TheStu* pDrgn, int (*fp)(const void*, const void*)) {
  
    
    /* 
    ������ �迭, ��� ����, ��� ũ��, �� �Լ��� �־���
    qsort((pDrgn), sizeof(*pDrgn) / sizeof(TheStu), sizeof(TheStu), fp);
    */

    qsort((pDrgn), SIZE, sizeof(TheStu), fp);
    //��Ҹ� ������ ���ϱ� ������ �ȵ�->�迭 �������� 4����Ʈ�� ��µ�.



}