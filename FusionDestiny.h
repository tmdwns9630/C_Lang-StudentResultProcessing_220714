#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000
#define MONEYSIZE 50
#define SUBJECT_SIZE 30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct Student {
    char TheName[4];
    int TheNum;
    int TheGrade;
    int TheMajor;
    float TheScore;
    float TheMj_Score;
}TheStu;

typedef struct FlowerDragoon {
    char TheName[4];
    int TheNum;
    int TheGrade;
    int TheMajor;
    char TheSubject[20];
    char TheSubScore;
}TheFlrDrgn;

//꽃드라군 구조체는 결국 쓰지도 못했네.
//애초에 쓸 필요가 없긴 했지만

TheStu* StudentFusion(void);
//파일 입출력으로 txt파일에서 데이터를 구조체에 저장한다.

void ScholarshipLink(TheStu* pDrgn);
//학과별 장학금 및 어쩌구.

void PrintDDragoon(TheStu* pDrgn, const char* printMode, int printsize, int MajorNum);
//printMode에 따라 구조체의 데이터를 출력.

void quicksort(TheStu* pDrgn, int (*fp)(const void*, const void*));
//퀵 정렬 함수

//-----퀵 정렬에 쓸 내림차순 비교 함수--------
int TheGrade_cmp(const void* a, const void* b);
//학년 비교용

int TheScore_cmp(const void* a, const void* b);
//전체학점 비교용

int TheMj_Score_cmp(const void* a, const void* b);
//전공학점 비교

int TheMajor_cmp(const void* a, const void* b);
//전공학과 비교

int id_cmp(const void* a, const void* b);


//--------------------------------------------

void SubjectSynchro(TheStu* pDrgn);
//void SubjectSynchro(TheStu* pDrgn, char Subject[10]);