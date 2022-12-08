#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SN1 2000000000
/*
랜덤 생성기 - 학과
일단 0~9까지의 번호를 주고 그걸 나중에 매칭시킨다.

*/
int main(void)
{
    int major[30] = { 0 };
    //int sn2 = 0, sn3 = 0;
    int random = 0;
    int i,count=0;

    FILE* fp = NULL;
    fp = fopen("Subject_Score00.txt", "a+");

    srand(time(NULL));
    
    while (1) {
        for (i = 0;i < sizeof(major) / 4;i++) {

            major[i] = rand() % 5;
            switch (major[i])
            {
            case 0:
                major[i] = 65;
                count++;
                break;
            case 1:
                major[i] = 66;
                break;
            case 2:
                major[i] = 67;
                break;
            case 3:
                major[i] = 68;
                break;
            case 4:
                major[i] = 70;
                break;
            default:
                printf("error!\n");
                break;
            }

        }
        if (count > sizeof(major) / 8) {
            continue;
        }
        else
            break;
    }


    for (i = 0;i < sizeof(major) / 4;i++) {
        fprintf(fp, "%d\n", major[i]);
       printf("%d\n", major[i]);
    }


    
 
   
    fclose(fp);


    return 0;
}

