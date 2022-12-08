#include "FusionDestiny.h"

/*
퀵정렬과 비교함수들.
퀵정렬은 맨 밑에 있고.
몇몇 비교함수는 같은 값일 경우, 다른 비교함수를 호출하여 재비교한다.

*/
int TheGrade_cmp(const void* a, const void* b)//학년별 비교
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
        //같을 경우 학번 순으로 정렬
        return id_cmp(m, n);
    }
    else
    {
        return (1);
    }
}

int TheScore_cmp(const void* a, const void* b)//전체학점 비교, 내림차순
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
        //같을 시 전공학점 비교
        return TheMj_Score_cmp(m,n);
    }
    else
    {
        return (-1);
    }
}

int TheMj_Score_cmp(const void* a, const void* b)//전공학점 비교, 내림차순
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

int TheMajor_cmp(const void* a, const void* b)//전공학과 비교
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
int id_cmp(const void* a, const void* b)//학번 정렬
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
    정렬할 배열, 요소 개수, 요소 크기, 비교 함수를 넣어줌
    qsort((pDrgn), sizeof(*pDrgn) / sizeof(TheStu), sizeof(TheStu), fp);
    */

    qsort((pDrgn), SIZE, sizeof(TheStu), fp);
    //요소를 식으로 쓰니까 정렬이 안됨->배열 포인터의 4바이트만 잡는듯.



}