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
	system("tiTle ���̾");
	system("mode con:cols=100 lines=30");
	system("color 02");


	gotoxy(30, 5);
	printf("������������������\n");
	gotoxy(30, 6);
	printf("��                              ��\n");
	gotoxy(30, 7);
	printf("��                              ��\n");
	gotoxy(30, 8);
	printf("��                              ��\n");
	gotoxy(30, 9);
	printf("��       ���̾ ���α׷�      ��\n");
	gotoxy(30, 10);
	printf("��                              ��\n");
	gotoxy(30, 11);
	printf("��                              ��\n");
	gotoxy(30, 12);
	printf("��                              ��\n");
	gotoxy(30, 13);
	printf("������������������\n\n");
	gotoxy(30, 14);
	printf("*         PRESS ANY BUTTON       *\n");
	getch();

	system("cls");


	login();


mygoto:
	while (1)
	{
		gotoxy(8, 1);
		printf("���̾ ���α׷�\n");
		gotoxy(4, 3);
		printf("��ȣ�� ���� ���ϴ� ����� �����Ͻÿ�.\n");
		gotoxy(12, 5);
		printf("1.�޷º���\n");
		gotoxy(12, 6);
		printf("2.���� ����\n");
		gotoxy(12, 7);
		printf("3.���� Ȯ��\n");
		gotoxy(12, 8);
		printf("4.���̾ ����\n");
		gotoxy(12, 9);
		printf("5.���̾ �б�\n");
		gotoxy(12, 10);
		printf("6.��й�ȣ ����\n");
		gotoxy(12, 11);
		printf("7.����\n");
		gotoxy(8, 13);
		printf("�Է� : ");
		scanf_s("%d", &menu);

		system("cls");

		switch (menu)
		{
		case 1:


			//printf("������� �⵵�� ���� �Է��Ͻÿ�.(YYYY MM)");
			while (1)
			{
				gotoxy(0, 3);
				char ans = 'a';
				printf("������� �⵵�� ���� �Է����ּ��� (YYYY MM) : ");
				scanf_s("%d %d", &y, &m);
				year = &y;
				month = &m;
				if (*year < 1 || *month>12 || *month < 1) {
					printf("�߸��� ���� �Է��ϼ̽��ϴ�.\n");
					system("pause");
					system("cls");
					continue;//�߸� �Է����� ���
				}

				while (ans != 'q') {

					inputCalen(year, month);
					//printf("\nq : �޴��� ���ư���� ������� q,�������� ��������� n,���� ���� ��������ø� p:");
					printf("\n\n	q : �޴��� ���ư���\n");
					printf("	n : ���� �� ����\n");
					printf("	p : ���� �� ����\n");
					ans = _getch();
					system("cls");
					//scanf("%c", &ans);

					if /*(strcmp*/ (ans == 'q')/* == 0)*/
					{
						printf("�����մϴ�.");
						goto mygoto;
						system("pause");

						system("cls");
						break;//�޴��Լ��� ���ư��� �κ� �߰��ϱ�
					}

					if (ans == 'p') {//����
						increase_month(month, year);
						system("cls");
						printf("%d %d", year, month);
						inputCalen(year, month);//������ &month, &year���ϰ� �ؿ� �Լ��� *month,*year �� �޾Ҿ����ϴ�. �Ѵٽõ��غ��� �߾ȵǳ׿�.
					}
					else if (ans == 'n') {//������
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
				printf("\n�������������������������\n");
				printf("�������� �˰���� ���� �Է��ϼ���(YYYY MM)\n��");
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
				printf("\n�������������������������\n");

				printf(" ���̾�� �а���� ��¥�� �Է��ϼ���(YYYY MM DD)\n��");
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
			printf("������� �⵵�� ���� �Է�(yyyy mm)");
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
			printf("���α׷��� �����մϴ�.\n");
			goto myexit;
			break;

		default:
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			while (getchar() != '\n');
			goto mygoto;
			system("cls");
		}
	}
myexit: EXIT:

	return 0;
}

// �α��� �Լ�

void login()
{

	char first[5] = "1234";		// ���� ��й�ȣ
	char code[5] = "\0", check[5];  //���Ͽ��� �о�� pw�� �����ϰ� �񱳿� ���ڿ�=����� null���ڷ� �ʱ�ȭ , scanf�� �Է¹��� ���ڿ�

	int i = 0;

	FILE* fp;
	fp = fopen("hello.txt", "rb");

	if (fp == NULL)			//txt������ ������ �ϳ� �����
	{
		fp = fopen("hello.txt", "wb");
		for (i = 0; first[i] != '\0'; i++)
		{
			putc(first[i] + 5, fp);//���� pw�� ��ȣȭ�ؼ� ���Ͽ� ����
			code[i] = first[i];//code������ ����pw ��ȣȭ���� ����
		}

		fclose(fp);
	}

	else		//txt������ �ִٸ�?
	{
		fscanf(fp, "%s", code);	//code ���ڿ��� pw ����
		fclose(fp);

		for (i = 0; code[i] != '\0'; i++)//pw ��ȣȭ ����
		{
			code[i] = code[i] - 5;
		}

	}

	i = 0;	//���� �ݺ����� ���� i �ʱ�ȭ


	gotoxy(45, 8);
	printf("LOGIN");
	gotoxy(37, 10);
	printf("PRESS YOUR PASSWORD");
	gotoxy(45, 12);
	fflush(stdin);//�Է� ���� �ʱ�ȭ
	scanf("%s", check);

	while (1)
	{
		system("cls");//ȭ�� �ѹ� ����
		i++;
		if (i == 5) {
			gotoxy(35, 8);
			printf("5ȸ ���з� �ڵ�����˴ϴ�\n\n\n");//����
			exit(1);
		}

		if (strcmp(code, check) == 0)//�Է¹����Ŷ� code�� ��ġ�ϸ� �����ϰ� ���� �Ѿ�� �ѱ��
		{
			gotoxy(40, 8);
			printf("LOGIN SUCCESS!\n");
			gotoxy(39, 11);
			printf("PRESS ANY BUTTON\n");
			getch();
			break;
		}
		else//�ƴϸ� 5ȸ Ʋ�������� �Է¹޴´�
		{

			gotoxy(45, 8);
			printf("LOGIN\n\n");
			gotoxy(24, 10);
			printf("��%dȸ �н����尡 Ʋ�Ƚ��ϴ�. 5ȸ ���� �� �ڵ����� �˴ϴ�\n", i);
			gotoxy(39, 11);
			printf("(���ʺ�й�ȣ=1234)");
			gotoxy(46, 13);
			fflush(stdin);//�Է� ���� �ʱ�ȭ
			scanf("%s", check);
		}
	}

	system("cls");
}

//���� 1�� �޷º���

int inputCalen(int* year, int* month) {
	int monthday[] = { 0,31,28,31,30,31,31,30,31,30,31,30,31 };

	//int year = 0; �̰� �Լ��� �ȳ�������� ���־������.
	//int month = 0; ���� ���� ����
	int startday = 1;
	int allday = 1;
	int i;
	char ch;
	startday = 1;
	allday = 1;
	if (((*year % 4 == 0) && (*year % 100 != 0)) || (*year % 400 == 0)) {
		monthday[2] = 29;//���⿡ 29�� �ִ� �κ�

	}
	allday += (*year - 1) * 365 + (*year - 1) / 4 - (*year - 1) / 100 + (*year - 1) / 400;//���ݱ��� �⵵�� ��ŭ�� ��¥�� �������� ����


	for (i = 1; i < *month; i++) {
		allday += (monthday[i]);//�׳⵵�� 1�� 1�Ϻ��� �����ؼ� �ش� �޸�ŭ ���ϴ� ��
	}
	startday = allday % 7;//7�� ������ ���� ���� ù°����.

	system("cls");
	gotoxy(0, 4);
	printf("%14d�� %d��\n\n", *year, *month);
	printf("  ��  ��  ȭ  ��  ��  ��  ��\n");
	for (i = 0; i < startday; i++) {
		printf("    ");//���� ���� ���ö����� ����, ���⼭ ���� ��ĭ�̶� �޶����� �̻��ϰ� ��µ�
	}
	for (i = 1; i <= monthday[*month]; i++) {
		printf("%4d", i);//���� ����Ʈ�ϱ�
		if ((i + startday) % 7 == 0) {
			printf("\n");//����Ͽ� ���� �����ַ� �̷�°�
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

void decrease_month(int* month, int* year) { //decrease the month by one// !n ������ ������ ����
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

// ���� 2�� ���� ����

void addMemo() {//�ٸ� ���� �Է½� ��� �߰� ����� //����

	FILE* fp = fopen("file2.txt", "ab+");
	do {
		system("cls");
		printf("\n��������������������������\n");

		printf(" ������ �����ϰ� ���� ��¥�� �Է��ϼ���(YYYY MM DD)\n��");

		fflush(stdin);
		scanf("%d %d %d", &R.yy, &R.mm, &R.dd);
		fflush(stdin);

	} while (R.mm < 1 || R.mm>12 || R.dd < 1);


	system("cls");
	printf("\n\n�����ϰ� ���� ������ �Է��ϼ���\n\n�� ");
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

		puts("������ ����Ǿ����ϴ�.\n");

		printf("�ƹ� ��ư�̳� ������ �޴��� ���ư��ϴ�.\n");
		_getch();
	}
	else {

		puts("���忡 �����Ͽ����ϴ�.");
		printf("�ƹ� ��ư�̳� ������ �޴��� ���ư��ϴ�.\n");
		_getch();
	}
	system("cls");
}

// ���� 3�� ���� Ȯ��
void printMemo() {//���⼭���� �б�� ����
	FILE* fpr;
	fpr = fopen("file2.txt", "rb");
	if (fpr == NULL) {
		printf("���� ����");
		printf("�ƹ� ��ư�̳� ������ �޴��� ���ư��ϴ�.\n");
		_getch();
		return;
	}

	if (!fread(&R, sizeof(R), 1, fpr)) {


		printf("��%c %c %c : %s", R.yy, R.mm, R.dd, R.note);

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
		printf("����");
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


				printf("��%d��° ����:%d�� %d�� %d��  %s \n", i + 1, R.yy, R.mm, R.dd, R.note);
				isFound = 1;
				i++;
			}
		}
	}
	if (isFound == 0) {

		printf("�����Ͱ� ���ų� �߸��� ��¥�� �Է��ϼ̽��ϴ�\n");
	}
	printf("�ƹ� ��ư�̳� ������ �޴��� ���ư��ϴ�.\n");
	_getch();
	system("cls");
}


// ���� 4�� ���̾ ����
void AddDiary()
{
	char ch = '\0';
	char asd[500] = "\0";
	FILE* fp;
	fp = fopen("diary.txt", "ab+");

	printf("���̾ �ۼ��� �����մϴ�.\n");
	while (1) {

		printf("�����̾ ��¥ �Է�(ex:2020 05 08)�� ");
		fflush(stdin);
		printf("\n�� ");
		scanf("%d %d %d", &D.yy, &D.mm, &D.dd);

		if (D.mm < 1 || D.mm>12 || D.dd < 1)
		{
			printf("�߸��� ��¥�� �Է��ϼ̽��ϴ�\n");
		}
		else
			break;

	}
	printf("%d�� %d�� %d���� �ϱ⸦ �ۼ��մϴ�\n", D.yy, D.mm, D.dd);

	printf("�ۼ��� �����Ϸ��� tabŰ�� ���� �� ����Ű�� �����ּ��� \n");
	printf("\n��������������������������������������\n");

	fflush(stdin);
	scanf(" %[^\t]", D.note);



Save:
	printf("\n�ϱ��� �����Ͻðڽ��ϱ�? Y / N : ");
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

		printf("�ϱⰡ ����Ǿ����ϴ�\n");

		printf("�ƹ�Ű�� ������ ���θ޴��� ���ư��ϴ�\n");
		getch();
	}

	else if (ch == 'N' || ch == 'n')
	{
		printf("������� �ۼ��� �ϱⰡ �����˴ϴ� �������ðڽ��ϱ�? (Y / N) : ");
		scanf(" %c", &ch);
		if (ch == 'Y' || ch == 'y')
		{
			printf("����� ������ �����Ǿ����ϴ�. ���θ޴��� ���ư��ϴ�\n");
			getch();
		}

		else if (ch == 'N' || ch == 'n')
		{
			goto Save;
		}

		else
		{
			printf("\n�ٽ� �Է����ּ���\n\n");
			getch();
		}
	}

	else
	{
		printf("�ٽ� �Է����ּ���\n\n");
		//getch();
		goto Save;
	}
	Sleep(500);
	printf("�ϱ� �ۼ��� �����մϴ�");
	Sleep(500);
	system("cls");
}


//���� 5�� ���̾ �б�


void printdiary(int yy, int mm, int dd)
{
	FILE* fp;
	int i = 0, isFound = 0;
	int j = 0;
	system("cls");
	fp = fopen("diary.txt", "rb");


	if (fp == NULL) {
		printf("����");
	}
	while (fread(&D, sizeof(D), 1, fp) == 1) {
		if (D.yy == yy) {
			if (D.mm == mm) {
				if (D.dd == dd)
				{

					printf("%d�� %d�� %d���� �ϱ�\n�������������������������\n ", D.yy, D.mm, D.dd);
					printf("%s\n\n", D.note);


					isFound = 1;

				}

			}
		}
	}
	if (isFound == 0) {

		printf("�����Ͱ� ���ų� �߸��� ��¥�� �Է��ϼ̽��ϴ�\n");
	}
	printf("�ƹ� ��ư�̳� ������ �޴��� ���ư��ϴ�.");
	_getch();
	system("cls");
}


//���� 6�� ��й�ȣ ����

void editcode()
{
	FILE* fp;

	char origin[5], check[5], confirm[5] = "\0";
	//����� pw, ����Ȯ��pw->�ʱ�ȭ �� ������ pw , �ٽ��ѹ�pw

	int i = 0;

	fp = fopen("hello.txt", "rb");//���� pw�� �ҷ��ͼ� origin�� ����

	fscanf(fp, "%s", origin);

	for (i = 0; origin[i] != '\0'; i++)//pw ��ȣȭ ����
	{
		origin[i] = origin[i] - 5;
	}

	fclose(fp);

	system("cls");
	gotoxy(5, 1);
	printf("��й�ȣ�� �����մϴ�\n");
	gotoxy(0, 4);

	while (1) // ����Ȯ��
	{
		printf("���� �н����带 �Է��Ͽ� �ֽʽÿ� : ");
		fflush(stdin);//�Է� ���� �ʱ�ȭ
		scanf("%s", check);


		//printf("%s", origin); //��ȣȭ Ȯ�ο�

		if (strcmp(origin, check) == 0)
		{
			printf("\n\n�н����尡 ��ġ�մϴ� ������ �����մϴ�\n");
			break;
		}
		else
		{
			printf("��й�ȣ�� Ʋ�Ƚ��ϴ� �ٽ� �Է��Ͽ� �ֽʽÿ�\n");
		}

	}
	for (i = 0; i < 4; i++)//check���ڿ� ������ ���� null�� �ʱ�ȭ 
	{
		check[i] = '\0';
	}

	//���� 3��



	while (1) // �н����� ����
	{
		printf("���ο� �н����� 4�ڸ��� �Է��ϼ���: ");
		fflush(stdin);
		scanf("%s", check);

		printf("�н����带 �ѹ� �� �Է��ϼ��� : ");
		fflush(stdin);
		scanf("%s", confirm);

		if (strcmp(check, confirm) == 0)
		{

			fp = fopen("hello.txt", "wb");

			for (i = 0; check[i] != '\0'; i++)//pw ��ȣȭ
			{
				check[i] = check[i] + 5;
			}
			fputs(check, fp);
			fclose(fp);


			printf("\n%s�� �н����尡 ����Ǿ����ϴ�.\n\n", confirm);
			printf("�ƹ�Ű�� ������ ���θ޴��� ���ư��ϴ�.\n");
			getch();
			system("cls");
			break;

		}
		else
		{
			printf("\n�н����� ����ġ! �ٽ� �Է����ּ���\n");
		}

	}
	return;

}
//Ŀ���̵� �Լ�
void gotoxy(int x, int y)

{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
