#include "FusionDestiny.h"

/*
디버그용 메인 소스파일.

ver1.파일 여러개로 만들기 힘들어서 일단 소스 하나에 때려박아보자.
ver2. 소스파일 분할했다.

*/

int main(void)
{
   TheStu* pDrgn;
   int menu;
   register int i;
   
   int start = 906;
   int end = 1000;

   pDrgn = StudentFusion();
   const char* printMode = "1111111";
   //PrintDDragoon(pDrgn, printMode, SIZE);
   
  

   
   SubjectSynchro(pDrgn);
   
   

   
    return 0;
}
