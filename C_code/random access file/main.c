#include <stdio.h>
#include <conio.h>
#include <string.h>

const char*maintitle[] = { "顯示全部記錄","顯示一筆紀錄","新增一筆紀錄","刪除一筆紀錄","更改一筆紀錄","結束" };

struct clientData {
	char name[7];
	char position[11];
	char departmentno[4];
	char city[7];
	char address[33];
	char telephone[17];
	double payofhour;
	double salary;
	double seniority;
};

void showoption(const char* optionname[], unsigned int);
int choice(int);
void onerecord(struct clientData*);
void showrecord(struct clientData);

int main(void)
{
	FILE*cfPtr;

	if ((cfPtr = fopen("employee.dat", "rb")) == NULL) {
		puts("File could not be opened.");
	}
	else {
		struct clientData client[100];
		int mainchoice;
		unsigned int count = 0;

		int result = fread(client, sizeof(struct clientData), 100, cfPtr);
		fclose(cfPtr);

		printf("\nThere are %d records are read!!!!\n\n", result);
		while (result > 0) {
			if (strcmp("\n", client[result - 1].name)&&strcmp("", client[result - 1].name)) {
				count++;
			}
			result--;
		}
		printf("\nThere are %d data records!!!!!!\n\n", count);
		do {
			showoption(maintitle, 6);
			mainchoice = choice(6);
			switch (mainchoice)
			{
			case 1:
				printf("\n總共有%d筆記錄\n", count);
				if (count != 0) {
					int temp = 0,press;
					for (size_t i = 0; i <= 99; i++) {
						if (strcmp("", client[i].name)) {
							showrecord(client[i]);
							temp++;
							if ((temp % 20) == 0) {
								printf("%s", "按下任意鍵繼續!!!\n");
								press=_getche();
								press =_getch();
							}
						}
					}
				}
				break;
			case 2:
				printf("\n總共有%d筆記錄\n", count);
				if (count != 0) {
					char nameofinput[7];
					int found = 0;
					printf("請輸入要顯示的姓名:");
					scanf("%6s", nameofinput);
					for (size_t i = 0; i <= 99; i++) {
						if ((strcmp(nameofinput, client[i].name)) == 0) {
							showrecord(client[i]);
							found = 1;
						}
					}
					if (found == 0) {
						printf("\n%s!!!\n\n", "該人員沒找到");
					}
				}
				break;
			case 3:
				printf("\n總共有%d筆記錄\n", count);
				if (count < 100) {
					int found = -1;
					size_t i = 0;
					do {
						if (!strcmp("", client[i].name)) {
							found = i;
						}
						i++;
					} while ((i < 100) && (found == -1));
					if (found != -1) {
						onerecord(&client[found]);
						count++;
						if ((cfPtr = fopen("employee.dat", "rb+")) == NULL) {
							puts("File could not be opened.");
						}
						else {
							fseek(cfPtr, found * sizeof(struct clientData), SEEK_SET);
							fwrite(&client[found], sizeof(struct clientData), 1, cfPtr);
							fclose(cfPtr);
						}
					}
				}
				else
				{
					printf("\n%s!!!!!\n\n", "已經100人了");
				}
				break;
			case 4:
				printf("\n總共有%d筆記錄\n", count);
				if (count != 0) {
					char nameofinput[7];
					int found;
					printf("請輸入要刪除的姓名:");
					scanf("%6s", nameofinput);
					for (size_t i = 0; i <= 99; i++) {
						if ((strcmp(nameofinput, client[i].name)) == 0) {
							strcpy(client[i].name, "");
							strcpy(client[i].position, "");
							strcpy(client[i].departmentno, "");
							strcpy(client[i].city, "");
							strcpy(client[i].address, "");
							strcpy(client[i].telephone, "");
							client[i].payofhour = 0.0;
							client[i].salary = 0.0;
							client[i].seniority = 0.0;
							found = 1;
							count--;
							if ((cfPtr = fopen("employee.dat", "rb+")) == NULL) {
								puts("File could not be opened.");
							}
							else {
								fseek(cfPtr, i * sizeof(struct clientData), SEEK_SET);
								fwrite(&client[i], sizeof(struct clientData), 1, cfPtr);
								fclose(cfPtr);
							}
						}
					}
					if (found == 0) {
						printf("\n%s!!!!\n\n", "該人員沒找到");
					}
				}
				break;
            case 5:
                if (count != 0) {
					char nameofinput[7];
					int found = -1;
					printf("請輸入要更新的姓名:");
					scanf("%6s", nameofinput);
					for (size_t i = 0; i <= 99; i++) {
						if ((strcmp(nameofinput, client[i].name)) == 0) {
							showrecord(client[i]);
							found = i;
						}
					}
					if (found == -1) {
						printf("\n%s!!!\n\n", "該人員沒找到");
					}
					else{
                        onerecord(&client[found]);
                        if ((cfPtr = fopen("employee.dat", "rb+")) == NULL) {
                            puts("File could not be opened.");
                        }
                        else {
                            fseek(cfPtr, found * sizeof(struct clientData), SEEK_SET);
                            fwrite(&client[found], sizeof(struct clientData), 1, cfPtr);
                            fclose(cfPtr);
                        }
					}
				}
                break;
			}
		}while (mainchoice != 6);
	}
}

void showoption(const char* optiontype[], unsigned int typecount)
{
	printf("\n");
	for (size_t i = 0; i <= typecount - 1; i++)
		printf("(%d)%s\n", i + 1, optiontype[i]);
}

int choice(int count)
{
	int choose;
	do {
		printf("\n請輸入選項!:");
		scanf("%d", &choose);
	} while (choose<1 || choose>count);
	return choose;
}

void onerecord(struct clientData* oneclient)
{
	printf("\n");
	printf("請輸入姓名:");
	scanf("%6s", oneclient->name);
	printf("請輸入職稱：");
	scanf("%10s", oneclient->position);
	printf("請輸入單位編號:");
	scanf("%3s", oneclient->departmentno);
	printf("請輸入城市：");
	scanf("%6s", oneclient->city);
	printf("請輸入地址:");
	scanf("%32s", oneclient->address);
	printf("請輸入電話：");
	scanf("%16s", oneclient->telephone);
	printf("請輸入時薪:");
	scanf("%lf", &oneclient->payofhour);
	printf("請輸入月薪:");
	scanf("%lf", &oneclient->salary);
	printf("請輸入年資:");
	scanf("%lf", &oneclient->seniority);
}

void showrecord(struct clientData employee)
{
	printf("\n");
	printf("姓名:%s ", employee.name);
	printf("職稱:%s ", employee.position);
	printf("單位代碼:%s ", employee.departmentno);
	printf("城市:%s\n", employee.city);
	printf("地址:%s\n ", employee.address);
	printf("電話:%s ", employee.telephone);
	printf("時薪:%lf ", employee.payofhour);
	printf("月薪:%lf ", employee.salary);
	printf("年資:%lf\n ", employee.seniority);
}
