#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "FusionDestiny.h"

/*
���� �ҽ�.
�ٸ� �ҽ������� �ڵ带 �� �� �ִ��� �׽�Ʈ ��.
*/

int main(void)
{
    TheStu* DDrgn;
    int a;

    DDrgn = StudentFusion();

    printf("�� �ƴٸ� �ּҰ� ���� ���̴� : %p", DDrgn);
    a = *DDrgn[0]->TheNum;


    return 0;
}

