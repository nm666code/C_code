#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void verification();
void generation();
void findfirstletter();
int alphatoint(char);
int countvalue(const char*);

int main(void) {
    int choose;
    do{
        printf("(1)���Ҩ����Ҧr��\n(2)���ͨ����Ҧr��\n(3)�j�M�^�孺�r\n(4)����\n�п�J�ﶵ�G");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                verification();
                break;
            case 2:
                generation();
                break;
            case 3:
                findfirstletter();
                break;
            case 4:
                break;
            default:
                puts("�Э��s��J\n");
        }
    }while(choose!=4);
    return 0;
}

void verification(){
    char id[SIZE+1];
    int correct = 0;
    do{
        correct = 1;
        printf("�п�J���ҥΨ����Ҧr���G");
        scanf("%10s", id);
        puts("  ");
        while(getchar()!='\n');
            continue;
        if(strlen(id) != 10){
            correct = 0;
            puts("���פ����T");
        }
        id[0] = toupper(id[0]);
        if(!isalpha(id[0])){
            correct = 0;
            puts("�Ĥ@�Ӧr���O�^��r��");
        }
        for(int  i = 1; i <= (strlen(id)-1); i++){
            if(!isdigit(id[i])){
                correct = 0;
                printf("��%d�Ӧr���O�Ʀr\n",i+1);
            }
        }
        if(!correct){
            puts("���s��J");
        }
    }while(!correct);

    if(countvalue(id)%10 ){
        printf("%s �����Ҧr�����~\n\n", id);
    }
    else{
        printf("%s   �����Ҧr�����T\n\n", id);
    }
}

void generation(){
    srand(time(NULL)%32767);
    char id[SIZE+1] ={'\0'};
    int correct = 0;
    puts("A  �O�_��  B  �O����  C  �򶩥�  D  �O�n��  E  ������");
    puts("F  �s�_��  G  �y����  H  ��饫  I  �Ÿq��  J  �s�˿�");
    puts("K  �]�߿�  M  �n�뿤  N  ���ƿ�  O  �s�˥�  P  ���L��");
    puts("Q  �Ÿq��  T  �̪F��  U  �Ὤ��  V  �O�F��  W  ������");
    puts("X  ���  Z  �s����");
    do{
        correct = 1;
        puts("�п�J�����ҭ��X�G");
        scanf("%1s",id);
        id[0] = toupper(id[0]);
        if(!isalpha(id[0])){
            correct = 0;
            puts("�Ĥ@�Ӧr���O�^��r��");
        }
        else if(id[0] == 'L' || id[0] == 'R' || id[0] == 'S'){
            correct = 0;
            puts("���r���w����ḹ");
        }
        if(!correct){
            puts("�Э��s��J");
        }
    }while(!correct);
    correct = 0;
    do{
        int sum = alphatoint(id[0]);
        int rn;
        for(int i = 8; i >=1; i--){
            rn = rand() % 10;
            sum += rn * i;
            id[9-i] = rn + '0';
        }
        id[SIZE-1] = (10-sum%10)%10+'0';
        id[SIZE] = '\0';

        if(countvalue(id) == 0){
            correct = 1;
        }
    }while(!correct);
    printf("���ͪ������Ҧr����%s\n\n", id);
}

void findfirstletter(){
    char id[SIZE+1] = {'\0'};
    char icapital[SIZE] = {'\0'};
    int correct = 0;
    do{
        correct = 1;
        printf("�п�J���Ҧr����9�X�G");
        scanf("%s", id);
        if(!strlen(id) == 9){
            correct = 0;
            puts("���פ����T");
        }
        for(int i = 0 ; i < 9 ; i++){
            if(!isdigit(id[i])){
                correct = 0;
                printf("��%d�Ӧr���O�Ʀr\n",i+1);
            }
        }
        if(!correct){
            puts("�Э��s��J");
        }
    }while(!correct);

    for(int i = 9; i>=0; i--){
        id[i+1] = id[i];
    }

    int j = 0;
    for(int i = 'A'; i<='Z'; i++){
        id[0] = i;
        if(countvalue(id)==0){
            icapital[j] = i;
            j++;
        }
    }
    printf("�����Ҧr���i�ର%s\n",icapital);
    puts("");
}

int alphatoint(char letter){
    char list[] = "10987654932210898765431320";
    return list[letter - 'A'] - '0';
}

int countvalue(const char* id){
    int sum = alphatoint(id[0]);
    for(int i = 8; i >= 1; i--){
        sum += (id[9 - i] - '0') * i;
    }
    sum += id[9] - '0';
    return sum%10;
}
