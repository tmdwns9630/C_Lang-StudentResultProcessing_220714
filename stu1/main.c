#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "FusionDestiny.h"

/*
메인 소스.
다른 소스파일의 코드를 쓸 수 있는지 테스트 중.
*/

int main(void)
{
    TheStu* DDrgn;
    int a;

    DDrgn = StudentFusion();

    printf("잘 됐다면 주소가 나올 것이다 : %p", DDrgn);
    a = *DDrgn[0]->TheNum;


    return 0;
}

