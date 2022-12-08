
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main(void)
{
    //char fname[10] = { '김','최','이','니','미','비','시','기','히','피' };
    //char mname[10] = { '승','가','나','다','바','사','아','자','타','카' };
    //char lname[10] = { '준','우','주','무','부','수','구','누','추','푸' };

    const char fname[21] = "김최이니미비시기히피";
    const char mname[21] = "승가나다바사아자타카";
    const char lname[21] = "준우주무부수구누추푸";


    char allname[10000] = { 0 };
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
    
    for (i = 0;i < (sizeof(fname)/2)-2;i++) {
        for (j = 0; j < (sizeof(mname)/2)-2; j++) {
            for (k = 0; k < (sizeof(lname)/2)-2;k++) {
                allname[count] = fname[i];
                count++;
                allname[count] = fname[i + 1];
                count++;
                //allname[count] = fname[i + 2];
                //count++;

                allname[count] = mname[j];
                count++;
                allname[count] = mname[j + 1];
                count++;
                //allname[count] = mname[j + 2];
                //count++;

                allname[count] = lname[k];
                count++;
                allname[count] = lname[k + 1];
                count++;
               //allname[count] = lname[k + 2];
                //count++;
                allname[count] = ' ';
                count++;
            }
            
        }
        
        


    }
    
    
    

    printf("좋다, 언제든 준비만전!\n");
  
    printf("%s\n", allname);

    return 0;
}

