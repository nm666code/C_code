#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
//改成兩個母音
void pigLatin(const char*);
void pigLatin2(const char*);

int main(void)
{
	srand(time(NULL) % 32767);
	const char* word[4][5] = { "the", "a", "one", "some", "any",
							"boy", "girl", "dog","town","car",
							"drove", "jumped", "ran", "walked", "skipped",
							"to", "from", "over", "under", "on" };

char sentence[20][35] = { '\0' };
for(size_t j = 0; j <= 19; j++) {
	for (size_t i = 0; i <= 5; i++) {
		strcat(sentence[j], word[i % 4][rand() % 5]);
		if (i != 5)
			strcat(sentence[j], " ");
		else
			strcat(sentence[j], ".");
	}
	sentence[j][0] = toupper(sentence[j][0]);
	printf("%s", sentence[j]);
}
printf("\n");
getchar();
for (size_t i = 0; i <= 19; i++)
	pigLatin(sentence[i]);
printf("\n");
printf("\n");
for (size_t i = 0; i <= 19; i++)
	pigLatin2(sentence[i]);
printf("\n");
getchar();
}
void pigLatin(const char* instring)
{
	char outstring[45];
	strcpy(outstring, instring);
	outstring[0] = tolower(outstring[0]);
	outstring[strlen(outstring) - 1] = '\0';
	char* tokenPtr = strtok(outstring, " ");
	static int c = 0;
	while (tokenPtr != NULL)
	{
		if (strlen(tokenPtr) != 1) {
			const char* s1 = { "aeiou" };
			int n = strcspn(tokenPtr, s1);
			char temp = tokenPtr[0];
			for (size_t i = 0; i <= strlen(tokenPtr) - 2; i++)
				tokenPtr[i] = tokenPtr[i+1];
			tokenPtr[strlen(tokenPtr) - 1] = temp;
		}
		if (0 == c) {
			printf("%say", tokenPtr);
			c++;
		}
		else {
			printf(" %say", tokenPtr);
		}
		tokenPtr = strtok(NULL, " ");
	}
	printf(".");
}
void pigLatin2(const char* instring)
{
	char outstring[45];
	strcpy(outstring, instring);
	outstring[0] = tolower(outstring[0]);
	outstring[strlen(outstring) - 1] = '\0';
	char* tokenPtr = strtok(outstring, " ");
	static int c = 0;
	while (tokenPtr != NULL)
	{
        char tempstring[45] = {'\0'};
		if(strlen(tokenPtr) != 1){
            char temp = tokenPtr[0];
            for(int i = 0; i <= strlen(tokenPtr)-2; i++){
                tokenPtr[i] = tokenPtr[i+1];
            }
            tokenPtr[strlen(tokenPtr)-1] = temp;
        }
		int n = strcspn(tokenPtr,"aeiouAEIOU")+1;
        strncpy(tempstring,tokenPtr,n);
        for (int i = n-1; i <= strlen(tokenPtr)-1; i++){
            tempstring[i+1] = tokenPtr[i];
        }
		if (0 == c) {
			printf("%say", tempstring);
			c++;
		}
		else {
			printf(" %say", tempstring);
		}
		tokenPtr = strtok(NULL, " ");

	}
	printf(".");
}

//for (int k = 0; k <= strlen(sentence)-n+1; k++) {
	/*if (sentence[i][j][k] == sentence[i][j][n - 1]) {
		sentence[i][j][k + 1] = sentence[i][j][k];
	}*/
	/*char sentence2[20][35] = { '\0' };

	for (int t = strlen(sentence2) - n + 1; t >= 0; t--)
		sentence2[j][n + 1] = sentence2[j][n + t]*/
		/*for (size_t i = 0; i <= 19; i++) {
			pigLatin2(sentence[i]);
		}*/
