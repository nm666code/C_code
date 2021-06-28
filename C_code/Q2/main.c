#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

//只有加乘且只求四位數所以千位以上忽略
int sting_to_four_digits_int(char* chars){
    int len = strlen(chars);
    int num = 0;

    if(len > 4){
        for(int i = 4; i > 0; i--){
            num *= 10;
            num += chars[len-i]-48;
        }
    }

    else{
        for(int i = len; i > 0; i--){
            num *= 10;
            num += chars[len-i]-48;
        }
    }

    return num;
}

int main()
{
    do{
        char input[1500] = {0},buf[1500] = {0};
        char notations[max];
        char *record = NULL;
        int i = 0, counter1 = 0, counter2 = 0;
        int nums[max];


        printf("請輸入運算式: (輸入 @ 結束)\n");
        scanf("%s",input);

        if(input[0]=='@')
            break;

        printf("你輸入的數學運算式為: \n");
        printf("%s\n",input);

        //用不會用到的值填滿陣列當sentinel
        strcpy(buf,input);
        memset(notations,'_',max);
        memset(nums,-1,max);

        //用陣列儲存運算子
        for(int j = 0, k = 0; j < strlen(buf); j++){
            if(buf[j]=='+'||buf[j]=='*'){
                notations[k] = buf[j];
                k++;
            }
        }

        //用字串分割存數字在陣列
        record = strtok(buf, "*+");
        do {
            nums[i] = sting_to_four_digits_int(record);
            record = strtok(NULL, "*+");
            i++;
        } while (record);

        //用while迴圈作先乘後加
        while(notations[counter1]!='_'){
            while(notations[counter2]!='_'){
                if(notations[counter2]=='*'){
                    nums[counter2]=(nums[counter2]*nums[counter2+1])%10000;
                    notations[counter2]='+';//其實這行沒用到可以刪掉，因為我乘完後剩加法，剩下的就直接視為加法，所以可以不用改變運算子
                    nums[counter2+1]=0;
                }
                counter2++;
            }
            nums[0]=(nums[0]+nums[counter1+1])%10000;
            counter1++;
        }

        //輸出結果
        printf("運算結果 = %d \n",nums[0]);

    }while(1);

    return 0;
}
