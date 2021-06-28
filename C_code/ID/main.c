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
        printf("(1)驗證身份證字號\n(2)產生身分證字號\n(3)搜尋英文首字\n(4)結束\n請輸入選項：");
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
                puts("請重新輸入\n");
        }
    }while(choose!=4);
    return 0;
}

void verification(){
    char id[SIZE+1];
    int correct = 0;
    do{
        correct = 1;
        printf("請輸入驗證用身分證字號：");
        scanf("%10s", id);
        puts("  ");
        while(getchar()!='\n');
            continue;
        if(strlen(id) != 10){
            correct = 0;
            puts("長度不正確");
        }
        id[0] = toupper(id[0]);
        if(!isalpha(id[0])){
            correct = 0;
            puts("第一個字不是英文字母");
        }
        for(int  i = 1; i <= (strlen(id)-1); i++){
            if(!isdigit(id[i])){
                correct = 0;
                printf("第%d個字不是數字\n",i+1);
            }
        }
        if(!correct){
            puts("重新輸入");
        }
    }while(!correct);

    if(countvalue(id)%10 ){
        printf("%s 身分證字號錯誤\n\n", id);
    }
    else{
        printf("%s   身分證字號正確\n\n", id);
    }
}

void generation(){
    srand(time(NULL)%32767);
    char id[SIZE+1] ={'\0'};
    int correct = 0;
    puts("A  臺北市  B  臺中市  C  基隆市  D  臺南市  E  高雄市");
    puts("F  新北市  G  宜蘭縣  H  桃園市  I  嘉義市  J  新竹縣");
    puts("K  苗栗縣  M  南投縣  N  彰化縣  O  新竹市  P  雲林縣");
    puts("Q  嘉義縣  T  屏東縣  U  花蓮縣  V  臺東縣  W  金門縣");
    puts("X  澎湖縣  Z  連江縣");
    do{
        correct = 1;
        puts("請輸入身分證首碼：");
        scanf("%1s",id);
        id[0] = toupper(id[0]);
        if(!isalpha(id[0])){
            correct = 0;
            puts("第一個字不是英文字母");
        }
        else if(id[0] == 'L' || id[0] == 'R' || id[0] == 'S'){
            correct = 0;
            puts("此字首已停止賦號");
        }
        if(!correct){
            puts("請重新輸入");
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
    printf("產生的身分證字號為%s\n\n", id);
}

void findfirstletter(){
    char id[SIZE+1] = {'\0'};
    char icapital[SIZE] = {'\0'};
    int correct = 0;
    do{
        correct = 1;
        printf("請輸入分證字號後9碼：");
        scanf("%s", id);
        if(!strlen(id) == 9){
            correct = 0;
            puts("長度不正確");
        }
        for(int i = 0 ; i < 9 ; i++){
            if(!isdigit(id[i])){
                correct = 0;
                printf("第%d個字不是數字\n",i+1);
            }
        }
        if(!correct){
            puts("請重新輸入");
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
    printf("身分證字首可能為%s\n",icapital);
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
