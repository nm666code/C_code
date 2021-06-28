#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#define SIZE 18

void verification(void);
void generation(void);
int aIphatoint(char);
int countvalue(const char*);
void findfirstletter(char*);

int main(void)
{
 int choose, temp;
 do {
  printf("%s", "(1)����������(2)�����Ҳ���(3)����-->�п�J��ܡG");
  choose = _getch();
  printf("%c", choose);

  puts(" ");
  temp = _getch();
  if (choose == '1')
   verification();
  if (choose == '2')
   generation();
 } while (choose != '3');
}



void verification(void)
{
 char id[SIZE + 1];
 int correct;
 do {
  correct = 1;
  printf("%s", "�п�J���ҥΪ������Ҧr���G");
  scanf("%18s", id);
  puts(" ");
  while (getchar() != '\n')
   continue;
  if (strlen(id) != 18) {
   correct = 0;
   puts("���פ����T!!!!!");
  }
  for (size_t i = 0; i <= (strlen(id) - 1); i++)
  {
   if (!isdigit(id[i])) {
    correct = 0;
    printf("��%d�Ӧr�����O�Ʀr!!!!\n", i + 1);
   }
  }
  if (id[6] > '2' || (id[6] > '1' && id[7] > '0') || (id[6] > '1' && id[8] > '0') || id[10] > '1' || (id[10] > '0' && id[11] > '2') || id[12] > '3') {
      correct = 0;
   printf("��J���ͤ������s�b!!!!\n�Э��s��J!!!!\n");
  }
 } while (correct == 0);

 switch (countvalue(id) % 11) {
 case 0: if (id[17] == '1') puts("�����Ҧr�����T"); break;
 case 1: if (id[17] == '0')puts("�����Ҧr�����T"); break;
 case 2: if (id[17] == 'X' || id[17] == 'x') puts("�����Ҧr�����T"); break;
 case 3: if (id[17] == '9') puts("�����Ҧr�����T"); break;
 case 4: if (id[17] == '8') puts("�����Ҧr�����T"); break;
 case 5: if (id[17] == '7') puts("�����Ҧr�����T"); break;
 case 6: if (id[17] == '6') puts("�����Ҧr�����T"); break;
 case 7: if (id[17] == '5') puts("�����Ҧr�����T"); break;
 case 8: if (id[17] == '4') puts("�����Ҧr�����T"); break;
 case 9: if (id[17] == '3') puts("�����Ҧr�����T"); break;
 case 10: if (id[17] == '2') puts("�����Ҧr�����T"); break;
 default: puts("�����Ҧr�����~"); break;
 }
}
void generation(void)
{
 char array[SIZE + 1];
 srand(time(NULL) % 32767);
 for (size_t i = 0; i < 17; i++) {
  array[i] = (rand() % 10)+'0';
 }
 //for (size_t i = 1; i <= (SIZE - 2); i++)
  //array[i] = (rand() % 10) + 48;
 if ((12 - (countvalue(array) % 11)) )% 11 ) == 10)
    {
      array[17] = 'x';
 }
 else
  array[17] = (12 - (countvalue(array) % 11)) % 11 + '0';
 array[SIZE] = '\0';
 printf("%s\n", array);
}



int aIphatoint(char zone)
{
 if (zone >= 65 && zone <= 72)
  return (zone - 55);
 if (zone == 73)
  return (zone - 39);
 if (zone >= 74 && zone <= 78)
  return (zone - 56);
 if (zone == 79)
  return (zone - 44);
 if (zone >= 80 && zone <= 86)
  return (zone - 57);
 if (zone == 87)
  return (zone - 55);
 if (zone >= 88 && zone <= 89)
  return (zone - 58);
 if (zone == 90)
  return (zone - 57);
 return 0;
}


int countvalue(const char* iarray)
{
 int result = iarray[0] * 7 + iarray[1] * 9 + iarray[2] * 10 + iarray[3] * 5 + iarray[4] * 8 + iarray[5] * 4 + iarray[6] * 2
  + iarray[7] * 1 + iarray[8] * 6 + iarray[9] * 3 + iarray[10] * 7 + iarray[11] * 9 + iarray[12] * 10 + iarray[13] * 5
  + iarray[14] * 8 + iarray[15] * 4 + iarray[16] * 2;
 return result;
}

void findfirstletter(char* icapital)
{
 char id[SIZE + 1];
 do {
  printf("%s", "�п�J�����Ҧr����E�X�G");
  scanf("%9s", id);
  puts(" ");
 } while (strlen(id) != 9);
 for (int i = 9; i >= 0; i--) {
  id[i + 1] = id[i];
 }
 int j = 0;
 for (int i = 65; i <= 90; i++) {
  id[0] = i;
  if ((((id[9] - 48) + countvalue(id)) % 10) == 0) {
   icapital[j] = i;
   j++;
  }
 }
 icapital[j] = '\0';
}
