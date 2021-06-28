#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void duplicatevowel(char *);
void pigLatin(const char *);

int main() {
    srand(time(NULL)%32767);
    const char *words[4][5] = {
        {"the", "a", "one", "some", "any"},
        {"boy", "girl", "dog", "town", "car"},
        {"drove", "jumped", "ran", "walked", "skipped"},
        {"to", "from", "over", "under", "on"}
    };
    char sentence[20][45] = {'\0'};
    srand(time(0));
    for(int i = 0 ; i < 20 ; i++) {
        for(int j = 0 ; j <= 5 ; j++) {
            strcat(sentence[i], words[j % 4][rand() % 5]);
            if(j != 5) {
                strcat(sentence[i], " ");
            }
        }
        strcat(sentence[i], ".");
        sentence[i][0] = toupper(sentence[i][0]);
        printf("%s ", sentence[i]);
    }

    puts("");
    getchar();

    for(int i = 0 ; i < 20 ; i++) {
        duplicatevowel(sentence[i]);
        printf("%s ", sentence[i]);
    }

    puts("");
    getchar();

    for(int i = 0 ; i < 20 ; i++) {
        pigLatin(sentence[i]);
    }

    puts("");
    getchar();



    return 0;
}

void duplicatevowel(char *sentence){

    char outString[45] = {'\0'};
    static char tempString[45] ={'\0'};
    strcpy(outString,sentence);
    char *tokenPtr = strtok(outString," ");

    for(int i = 0; i < 45; i++){
        tempString[i] ='\0';
    }

    while(tokenPtr != NULL){
        char *vowelptr = strpbrk(tokenPtr,"aeiouAEIOU");
        if(vowelptr != NULL){
            strncat(tempString,tokenPtr,vowelptr+1-tokenPtr);
            strcat(tempString,vowelptr);
            strcat(tempString," ");
        }
        tokenPtr = strtok(NULL," ");
    }
    strcpy(sentence,tempString);
}

void pigLatin(const char *sentence) {

    char outString[45];
    strcpy(outString,sentence);
    outString[0] = tolower(outString[0]);
    outString[strlen(outString)-1] = '\0';
    char *tokenPtr = strtok(outString," ");
    static int c = 0;

    while(tokenPtr != NULL){
        if(strlen(tokenPtr) != 1){
            char temp = tokenPtr[0];
            for(int i = 0; i <= strlen(tokenPtr)-2; i++){
                tokenPtr[i] = tokenPtr[i+1];
            }
            tokenPtr[strlen(tokenPtr)-1] = temp;
        }
        if(0 == c){
            printf("%say",tokenPtr);
            c++;
        }
        else{
            printf(" %say",tokenPtr);
        }
        tokenPtr = strtok(NULL," ");
    }
    printf(".");
}

