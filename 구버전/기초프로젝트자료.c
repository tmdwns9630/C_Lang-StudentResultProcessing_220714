#include "note.h"
#include "remember.h"

void login();
void editcode();
void gotoxy(int x, int y);
void addMemo();
void printMemo();
void printNote();
void AddDiary();
void printdiary();

int* year;
int* month;
int inputCalen(int* year, int* month);
void increase_month(int* month, int* year);
void decrease_month(int* month, int* year);
int y;
int m;
int mi, ya;
int yy, mm, dd;

int main()
{
	int menu;
	system("tiTle 다이어리");
	system("mode con:cols=100 lines=30");
	system("color 02");


	gotoxy(30, 5);
	printf("■■■■■■■■■■■■■■■■■\n");
	gotoxy(30, 6);
	printf("■                              ■\n");
	gotoxy(30, 7);
	printf("■                              ■\n");
	gotoxy(30, 8);
	printf("■                              ■\n");
	gotoxy(30, 9);
	printf("■       다이어리 프로그램      ■\n");
	gotoxy(30, 10);
	printf("■                              ■\n");
	gotoxy(30, 11);
	printf("■                              ■\n");
	gotoxy(30, 12);
	printf("■                              ■\n");
	gotoxy(30, 13);
	printf("■■■■■■■■■■■■■■■■■\n\n");
	gotoxy(30, 14);
	printf("*         PRESS ANY BUTTON       *\n");
	getch();

	system("cls");


	login();


mygoto:
	while (1)
	{
		gotoxy(8, 1);
		printf("다이어리 프로그램\n");
		gotoxy(4, 3);
		printf("번호를 눌러 원하는 기능을 실행하시오.\n");
		gotoxy(12, 5);
		printf("1.달력보기\n");
		gotoxy(12, 6);
		printf("2.일정 쓰기\n");
		gotoxy(12, 7);
		printf("3.일정 확인\n");
		gotoxy(12, 8);
		printf("4.다이어리 쓰기\n");
		gotoxy(12, 9);
		printf("5.다이어리 읽기\n");
		gotoxy(12, 10);
		printf("6.비밀번호 변경\n");
		gotoxy(12, 11);
		printf("7.종료\n");
		gotoxy(8, 13);
		printf("입력 : ");
		scanf_s("%d", &menu);

		system("cls");

		switch (menu)
		{
		case 1:


			//printf("보고싶은 년도의 달을 입력하시오.(YYYY MM)");
			while (1)
			{
				gotoxy(0, 3);
				char ans = 'a';
				printf("보고싶은 년도와 달을 입력해주세요 (YYYY MM) : ");
				scanf_s("%d %d", &y, &m);
				year = &y;
				month = &m;
				if (*year < 1 || *month>12 || *month < 1) {
					printf("잘못된 값을 입력하셨습니다.\n");
					system("pause");
					system("cls");
					continue;//잘못 입력했을 경우
				}

				while (ans != 'q') {

					inputCalen(year, month);
					//printf("\nq : 메뉴로 돌아가기고 싶은경우 q,저번달을 보고싶으면 n,다음 달을 보고싶으시면 p:");
					printf("\n\n	q : 메뉴로 돌아가기\n");
					printf("	n : 지난 달 보기\n");
					printf("	p : 다음 달 보기\n");
					ans = _getch();
					system("cls");
					//scanf("%c", &ans);

					if /*(strcmp*/ (ans == 'q')/* == 0)*/
					{
						printf("종료합니다.");
						goto mygoto;
						system("pause");

						system("cls");
						break;//메뉴함수로 돌아가는 부분 추가하기
					}

					if (ans == 'p') {//전달
						increase_month(month, year);
						system("cls");
						printf("%d %d", year, month);
						inputCalen(year, month);//원래는 &month, &year로하고 밑에 함수는 *month,*year 로 받았었습니다. 둘다시도해봐도 잘안되네요.
					}
					else if (ans == 'n') {//다음달
						decrease_month(month, year);
						system("cls");
						printf("%d %d", year, month);
						inputCalen(year, month);
					}
				}
				break;
				//system("pause");
				//system("cls");
			}
			//break;

		case 2:
			gotoxy(0, 2);
			addMemo();

			break;

		case 3:
			gotoxy(0, 3);




			do {
				system("cls");
				printf("\n■□■□■□■□■□■□■□■□■□■□■□■□\n");
				printf("▷일정을 알고싶은 달을 입력하세요(YYYY MM)\n▶");
				scanf("%d %d", &ya, &mi);
			} while (mi > 12 || mi < 1);


			printNote(ya, mi);
			break;

		case 4:
			gotoxy(0, 3);
			//inputdiary();
			printf(" \n");

			AddDiary();
			break;

		case 5:
		{
			gotoxy(0, 3);
			do {
				system("cls");
				printf("\n■□■□■□■□■□■□■□■□■□■□■□■□\n");

				printf(" 다이어리를 읽고싶은 날짜를 입력하세요(YYYY MM DD)\n▶");
				scanf("%d %d %d", &yy, &mm, &dd);
				Sleep(500);
				system("cls");
				printf("\nWaiting .");

				Sleep(500);

				system("cls");
				printf("\nWaiting . .");
				Sleep(500);
				system("cls");
				printf("\nWaiting . . .");
				Sleep(500);

			} while (mm > 12 || mm < 1);

			printdiary(yy, mm, dd);
			break;
		}
		/*
			printf("보고싶은 년도와 달을 입력(yyyy mm)");
			scanf("%d %d", &yy, &mm);
			printdiary(yy, mm);
			break;
			*/

		case 6:
			gotoxy(0, 3);
			editcode();

			break;

		case 7:
			gotoxy(0, 3);
			printf("프로그램을 종료합니다.\n");
			goto myexit;
			break;

		default:
			printf("잘못 입력하셨습니다.\n");
			while (getchar() != '\n');
			goto mygoto;
			system("cls");
		}
	}
myexit: EXIT:

	return 0;
}

// 로그인 함수

void login()
{

	char first[5] = "1234";		// 최초 비밀번호
	char code[5] = "\0", check[5];  //파일에서 읽어온 pw를 저장하고 비교용 문자열=선언시 null문자로 초기화 , scanf로 입력받을 문자열

	int i = 0;

	FILE* fp;
	fp = fopen("hello.txt", "rb");

	if (fp == NULL)			//txt파일이 없으면 하나 만들고
	{
		fp = fopen("hello.txt", "wb");
		for (i = 0; first[i] != '\0'; i++)
		{
			putc(first[i] + 5, fp);//최초 pw를 암호화해서 파일에 저장
			code[i] = first[i];//code에서는 최초pw 암호화없이 저장
		}

		fclose(fp);
	}

	else		//txt파일이 있다면?
	{
		fscanf(fp, "%s", code);	//code 문자열에 pw 저장
		fclose(fp);

		for (i = 0; code[i] != '\0'; i++)//pw 암호화 해제
		{
			code[i] = code[i] - 5;
		}

	}

	i = 0;	//밑의 반복문을 위한 i 초기화


	gotoxy(45, 8);
	printf("LOGIN");
	gotoxy(37, 10);
	printf("PRESS YOUR PASSWORD");
	gotoxy(45, 12);
	fflush(stdin);//입력 버퍼 초기화
	scanf("%s", check);

	while (1)
	{
		system("cls");//화면 한번 비우고
		i++;
		if (i == 5) {
			gotoxy(35, 8);
			printf("5회 실패로 자동종료됩니다\n\n\n");//제곧내
			exit(1);
		}

		if (strcmp(code, check) == 0)//입력받은거랑 code가 일치하면 성공하고 루프 넘어로 넘긴다
		{
			gotoxy(40, 8);
			printf("LOGIN SUCCESS!\n");
			gotoxy(39, 11);
			printf("PRESS ANY BUTTON\n");
			getch();
			break;
		}
		else//아니면 5회 틀릴때까지 입력받는다
		{

			gotoxy(45, 8);
			printf("LOGIN\n\n");
			gotoxy(24, 10);
			printf("※%d회 패스워드가 틀렸습니다. 5회 실패 시 자동종료 됩니다\n", i);
			gotoxy(39, 11);
			printf("(최초비밀번호=1234)");
			gotoxy(46, 13);
			fflush(stdin);//입력 버퍼 초기화
			scanf("%s", check);
		}
	}

	system("cls");
}

//보기 1번 달력보기

int inputCalen(int* year, int* month) {
	int monthday[] = { 0,31,28,31,30,31,31,30,31,30,31,30,31 };

	//int year = 0; 이게 함수로 안나왔을경우 들어가있어야했음.
	//int month = 0; 위와 같은 내용
	int startday = 1;
	int allday = 1;
	int i;
	char ch;
	startday = 1;
	allday = 1;
	if (((*year % 4 == 0) && (*year % 100 != 0)) || (*year % 400 == 0)) {
		monthday[2] = 29;//윤년에 29일 넣는 부분

	}
	allday += (*year - 1) * 365 + (*year - 1) / 4 - (*year - 1) / 100 + (*year - 1) / 400;//지금까지 년도가 얼만큼의 날짜가 지났는지 계산용


	for (i = 1; i < *month; i++) {
		allday += (monthday[i]);//그년도의 1월 1일부터 시작해서 해당 달만큼 더하는 것
	}
	startday = allday % 7;//7로 나눠서 남는 날이 첫째주임.

	system("cls");
	gotoxy(0, 4);
	printf("%14d년 %d월\n\n", *year, *month);
	printf("  일  월  화  수  목  금  토\n");
	for (i = 0; i < startday; i++) {
		printf("    ");//시작 요일 나올때까지 띄어쓰기, 여기서 띄어쓰기 한칸이라도 달라지면 이상하게 출력됨
	}
	for (i = 1; i <= monthday[*month]; i++) {
		printf("%4d", i);//요일 프린트하기
		if ((i + startday) % 7 == 0) {
			printf("\n");//토요일에 가면 다음주로 미루는것
		}
	}
}



void increase_month(int* month, int* year) { //increase the month by one
	++(*month);
	if (*month > 12) {
		++(*year);
		*month = *month - 12;

		//   return (*month, *year);
	}
}

void decrease_month(int* month, int* year) { //decrease the month by one// !n 누르면 문제가 생김
	--(*month);
	if (*month < 1) {
		--(*year);
		if (*year < 1600) {
			printf("No record available");
			return;
		}
		*month = *month + 12;

		//   return(*month, *year);
	}
}

// 보기 2번 일정 쓰기

void addMemo() {//다른 조건 입력시 계속 뜨게 만드는 //실패

	FILE* fp = fopen("file2.txt", "ab+");
	do {
		system("cls");
		printf("\n■□■□■□■□■□■□■□■□■□■□■□■□■\n");

		printf(" 일정을 저장하고 싶은 날짜를 입력하세요(YYYY MM DD)\n▶");

		fflush(stdin);
		scanf("%d %d %d", &R.yy, &R.mm, &R.dd);
		fflush(stdin);

	} while (R.mm < 1 || R.mm>12 || R.dd < 1);


	system("cls");
	printf("\n\n저장하고 싶은 일정을 입력하세요\n\n▶ ");
	fflush(stdin);
	scanf(" %[^\n]", R.note);




	if (fwrite(&R, sizeof(R), 1, fp)) {
		fclose(fp);
		system("cls");
		Sleep(500);
		system("cls");
		printf("\nWaiting .");

		Sleep(500);

		system("cls");
		printf("\nWaiting . .");
		Sleep(500);
		system("cls");
		printf("\nWaiting . . .");
		Sleep(500);
		system("cls");

		puts("일정이 저장되었습니다.\n");

		printf("아무 버튼이나 누르면 메뉴로 돌아갑니다.\n");
		_getch();
	}
	else {

		puts("저장에 실패하였습니다.");
		printf("아무 버튼이나 누르면 메뉴로 돌아갑니다.\n");
		_getch();
	}
	system("cls");
}

// 보기 3번 일정 확인
void printMemo() {//여기서부터 읽기용 시험
	FILE* fpr;
	fpr = fopen("file2.txt", "rb");
	if (fpr == NULL) {
		printf("열기 실패");
		printf("아무 버튼이나 누르면 메뉴로 돌아갑니다.\n");
		_getch();
		return;
	}

	if (!fread(&R, sizeof(R), 1, fpr)) {


		printf("▷%c %c %c : %s", R.yy, R.mm, R.dd, R.note);

	}

	if (fpr != NULL)fclose(fpr);
	while (1);
}



void printNote(int yy, int mm) {
	FILE* fp;
	int i = 0, isFound = 0;
	system("cls");
	fp = fopen("file2.txt", "rb");

	if (fp == NULL) {
		printf("오류");
	}
	system("cls");
	printf("\nWaiting .");

	Sleep(500);

	system("cls");
	printf("\nWaiting . .");
	Sleep(500);
	system("cls");
	printf("\nWaiting . . .");
	Sleep(500);
	system("cls");

	while (fread(&R, sizeof(R), 1, fp) == 1) {
		if (R.yy == yy) {
			if (R.mm == mm) {


				printf("▶%d번째 일정:%d년 %d월 %d일  %s \n", i + 1, R.yy, R.mm, R.dd, R.note);
				isFound = 1;
				i++;
			}
		}
	}
	if (isFound == 0) {

		printf("데이터가 없거나 잘못된 날짜를 입력하셨습니다\n");
	}
	printf("아무 버튼이나 누르면 메뉴로 돌아갑니다.\n");
	_getch();
	system("cls");
}


// 보기 4번 다이어리 쓰기
void AddDiary()
{
	char ch = '\0';
	char asd[500] = "\0";
	FILE* fp;
	fp = fopen("diary.txt", "ab+");

	printf("다이어리 작성을 시작합니다.\n");
	while (1) {

		printf("▷다이어리 날짜 입력(ex:2020 05 08)◁ ");
		fflush(stdin);
		printf("\n▶ ");
		scanf("%d %d %d", &D.yy, &D.mm, &D.dd);

		if (D.mm < 1 || D.mm>12 || D.dd < 1)
		{
			printf("잘못된 날짜를 입력하셨습니다\n");
		}
		else
			break;

	}
	printf("%d년 %d월 %d일의 일기를 작성합니다\n", D.yy, D.mm, D.dd);

	printf("작성을 종료하려면 tab키를 누른 후 엔터키를 눌러주세요 \n");
	printf("\n■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n");

	fflush(stdin);
	scanf(" %[^\t]", D.note);



Save:
	printf("\n일기을 저장하시겠습니까? Y / N : ");
	fflush(stdin);
	scanf(" %c", &ch);

	if (ch == 'Y' || ch == 'y')
	{
		fwrite(&D, sizeof(D), 1, fp);

		fclose(fp);

		system("cls");
		Sleep(500);
		system("cls");
		printf("\nWaiting .");

		Sleep(500);

		system("cls");
		printf("\nWaiting . .");
		Sleep(500);
		system("cls");
		printf("\nWaiting . . .");
		Sleep(500);
		system("cls");

		printf("일기가 저장되었습니다\n");

		printf("아무키나 누르면 메인메뉴로 돌아갑니다\n");
		getch();
	}

	else if (ch == 'N' || ch == 'n')
	{
		printf("현재까지 작성된 일기가 삭제됩니다 괜찮으시겠습니까? (Y / N) : ");
		scanf(" %c", &ch);
		if (ch == 'Y' || ch == 'y')
		{
			printf("저장된 내용이 삭제되었습니다. 메인메뉴로 돌아갑니다\n");
			getch();
		}

		else if (ch == 'N' || ch == 'n')
		{
			goto Save;
		}

		else
		{
			printf("\n다시 입력해주세요\n\n");
			getch();
		}
	}

	else
	{
		printf("다시 입력해주세요\n\n");
		//getch();
		goto Save;
	}
	Sleep(500);
	printf("일기 작성을 종료합니다");
	Sleep(500);
	system("cls");
}


//보기 5번 다이어리 읽기


void printdiary(int yy, int mm, int dd)
{
	FILE* fp;
	int i = 0, isFound = 0;
	int j = 0;
	system("cls");
	fp = fopen("diary.txt", "rb");


	if (fp == NULL) {
		printf("오류");
	}
	while (fread(&D, sizeof(D), 1, fp) == 1) {
		if (D.yy == yy) {
			if (D.mm == mm) {
				if (D.dd == dd)
				{

					printf("%d년 %d월 %d일의 일기\n■□■□■□■□■□■□■□■□■□■□■□■□\n ", D.yy, D.mm, D.dd);
					printf("%s\n\n", D.note);


					isFound = 1;

				}

			}
		}
	}
	if (isFound == 0) {

		printf("데이터가 없거나 잘못된 날짜를 입력하셨습니다\n");
	}
	printf("아무 버튼이나 누르면 메뉴로 돌아갑니다.");
	_getch();
	system("cls");
}


//보기 6번 비밀번호 변경

void editcode()
{
	FILE* fp;

	char origin[5], check[5], confirm[5] = "\0";
	//저장된 pw, 본인확인pw->초기화 후 변경할 pw , 다시한번pw

	int i = 0;

	fp = fopen("hello.txt", "rb");//기존 pw를 불러와서 origin에 저장

	fscanf(fp, "%s", origin);

	for (i = 0; origin[i] != '\0'; i++)//pw 암호화 해제
	{
		origin[i] = origin[i] - 5;
	}

	fclose(fp);

	system("cls");
	gotoxy(5, 1);
	printf("비밀번호를 수정합니다\n");
	gotoxy(0, 4);

	while (1) // 본인확인
	{
		printf("현재 패스워드를 입력하여 주십시오 : ");
		fflush(stdin);//입력 버퍼 초기화
		scanf("%s", check);


		//printf("%s", origin); //암호화 확인용

		if (strcmp(origin, check) == 0)
		{
			printf("\n\n패스워드가 일치합니다 변경을 시작합니다\n");
			break;
		}
		else
		{
			printf("비밀번호가 틀렸습니다 다시 입력하여 주십시오\n");
		}

	}
	for (i = 0; i < 4; i++)//check문자열 재사용을 위해 null로 초기화 
	{
		check[i] = '\0';
	}

	//보기 3번



	while (1) // 패스워드 변경
	{
		printf("새로운 패스워드 4자리를 입력하세요: ");
		fflush(stdin);
		scanf("%s", check);

		printf("패스워드를 한번 더 입력하세요 : ");
		fflush(stdin);
		scanf("%s", confirm);

		if (strcmp(check, confirm) == 0)
		{

			fp = fopen("hello.txt", "wb");

			for (i = 0; check[i] != '\0'; i++)//pw 암호화
			{
				check[i] = check[i] + 5;
			}
			fputs(check, fp);
			fclose(fp);


			printf("\n%s로 패스워드가 변경되었습니다.\n\n", confirm);
			printf("아무키를 누르면 메인메뉴로 돌아갑니다.\n");
			getch();
			system("cls");
			break;

		}
		else
		{
			printf("\n패스워드 불일치! 다시 입력해주세요\n");
		}

	}
	return;

}
//커서이동 함수
void gotoxy(int x, int y)

{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
