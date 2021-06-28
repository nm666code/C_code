#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

char check(char id[]);
void genID2(char id[],char date[],char stuID[]);

void genID2(char id[],char date[],char stuID[]){
    int index;
    strcpy(id,stuID);
    for (index = 6; index < 17; index++){
        id[index] = '0' + rand()%10;
        if(index >= 6 && index < 14)
            id[index] = date[index-6];
    }
    id[17] = check(id);
}

char check(char id[]) {
	int index, sum, num;
	for (sum = index = 0; index < 17; index++)
		sum += ((int)pow(2, 17 - index) % 11) * (id[index] - '0');
	num = (12 - (sum % 11)) % 11;
	if (num < 10)
		return (num + '0');
	else
		return 'X';
}

int main()
{
    srand(time(NULL));
    char id[20] = {'\0'};
    char date[10] = {'\0'};
    int choice;
    int mingguo;

    printf("(1)���������һP��(2)�S�w�ͤ餧�����Ҳ���(3)����\n");
    printf("�п��:");
    scanf("%d",&choice);

    do{
        switch(choice){
            case 1:
                printf("�п�J���ˬd�����ꨭ���Ҧr��:");
                scanf("%s",id);
                char c = check(id);

                if(id[17] == c)
                    puts("���T");
                else
                    printf("���~,���T���̫�@�X����%c\n",c);
                break;

            case 2:
                printf("�п�J����X�ͦ~���:");
                scanf("%d/n",&mingguo);
                mingguo+=19110000;
                for(int i = 0; i < 8; i++){
                    date[7-i] = mingguo % 10 + '0';
                    mingguo/=10;
                }
                genID2(id,date,"916025");
                printf("%s\n",id);
                break;
        }

        printf("(1)���������һP��(2)�S�w�ͤ餧�����Ҳ���(3)����\n");
        printf("�п��:");
        scanf("%d",&choice);
    }while(choice!=3);

    return 0;
}
