#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/*
10개짜리 문자열 3개로 1000개의 겹치지 않는 알파벳 이름을 만들어낸다. 
*/
int main(void)
{
    const char fname[10] = "ABCDEFGHIZ";
    const char mname[10] = "QWERTYUIOZ";
    const char lname[10] = "XCVBNMASDZ";


    char allname[4001] = { 0 };
    int i, j, k,m;
    int count = 0;

    FILE* fp = NULL;
    fp = fopen("Student_Name.txt", "a+");


    for (i = 0;i < (sizeof(fname));i++) {
        for (j = 0; j < (sizeof(mname)); j++) {
            for (k = 0; k < (sizeof(lname));k++) {
                allname[count] = fname[i];
                count++;
              
                allname[count] = mname[j];
                count++;
         
                allname[count] = lname[k];
                count++;

                allname[count] = '\n';
                count++;
            }          
        }
    }
    
   
    fputs(allname, fp);
    fclose(fp);


    printf("저장이 잘 됐기를 빈다.\n\n");
  
    //printf("%sEND\n", allname);
    //printf("대충 이들은 1000명의 암살자 집단이라 다 알파벳 세글자로 불린다고 칩시다.\n");
    //printf("문자열 길이 : %d\n", strlen(allname));
    return 0;
}

