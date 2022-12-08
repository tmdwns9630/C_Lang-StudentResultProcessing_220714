
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

    //자 현재 목적
    /*
    랜덤 이름을 뽑아낸다.
    이론상 10개의 성, 10개의 미들네임, 10개의 라스트네임으로 1000명의 이름을 중복되지 
    않고 만들 수 있다.
    저걸 뽑아내서 파일 입출력으로 저장하면 된다
    아님 말고
    아니지, 굳이 랜덤으로 할 필요 없이 그냥 1번부터 차르르 해도 이번 경우엔 문제가 없지
    */
    
    for (i = 0;i < (sizeof(fname));i++) {
        for (j = 0; j < (sizeof(mname)); j++) {
            for (k = 0; k < (sizeof(lname));k++) {
                allname[count] = fname[i];
                count++;
              
                allname[count] = mname[j];
                count++;
         
                allname[count] = lname[k];
                count++;

                allname[count] = ' ';
                count++;
            }          
        }
    }
    
   
    printf("좋다, 언제든 준비만전!\n\n");
  
    printf("%sEND\n", allname);
    printf("대충 이들은 1000명의 암살자 집단이라 다 알파벳 세글자로 불린다고 칩시다.\n");
    printf("문자열 길이 : %d\n", strlen(allname));
    return 0;
}

