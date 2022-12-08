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

//�ɵ�� ����ü�� �ᱹ ������ ���߳�.
//���ʿ� �� �ʿ䰡 ���� ������

TheStu* StudentFusion(void);
//���� ��������� txt���Ͽ��� �����͸� ����ü�� �����Ѵ�.

void ScholarshipLink(TheStu* pDrgn);
//�а��� ���б� �� ��¼��.

void PrintDDragoon(TheStu* pDrgn, const char* printMode, int printsize, int MajorNum);
//printMode�� ���� ����ü�� �����͸� ���.

void quicksort(TheStu* pDrgn, int (*fp)(const void*, const void*));
//�� ���� �Լ�

//-----�� ���Ŀ� �� �������� �� �Լ�--------
int TheGrade_cmp(const void* a, const void* b);
//�г� �񱳿�

int TheScore_cmp(const void* a, const void* b);
//��ü���� �񱳿�

int TheMj_Score_cmp(const void* a, const void* b);
//�������� ��

int TheMajor_cmp(const void* a, const void* b);
//�����а� ��

int id_cmp(const void* a, const void* b);


//--------------------------------------------

void SubjectSynchro(TheStu* pDrgn);
//void SubjectSynchro(TheStu* pDrgn, char Subject[10]);