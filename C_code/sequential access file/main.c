#include <stdio.h>
#include <string.h>

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

int main(void)
{
	FILE* cfPtr;
	struct clientData Client[100];
	struct clientData newClient;
    char choiceOfname[7];

	if ((cfPtr = fopen("employee.txt", "r")) == NULL) {
		puts("File could not be opened");
	}
	else {
		int total = 0;
		while (!feof(cfPtr)) {
			fscanf(cfPtr, "%s %s %s %s %s %s %lf %lf %lf \n", Client[total].name, Client[total].position,
				Client[total].departmentno, Client[total].city, Client[total].address, Client[total].telephone,
				&Client[total].payofhour, &Client[total].salary, &Client[total].seniority);
			total++;
		}
		fclose(cfPtr);
		printf("Total %d records are read!\n", total);
		printf("%s", "Enter request\n"
			" 1 - List all\n"
			" 2 - Search city\n"
			" 3 - Search salary\n"
			" 4 - Append one record\n"
			" 5 - Delete one record\n"
			" 6 - Output random  access file\n"
			" 7 - Renew one record\n"
            " 8 - End of run\n");
		unsigned int request;
		scanf("%u", &request);
		int tempcount;

		while (request != 8) {
			tempcount = 0;
			switch (request) {
			case 1:
				for (int count = 0; count < total; count++) {
					printf("%s %s %s %s %s %s\n %lf %lf %lf\n", Client[count].name, Client[count].position,
						Client[count].departmentno, Client[count].city, Client[count].address, Client[count].telephone,
						Client[count].payofhour, Client[count].salary, Client[count].seniority);
					tempcount++;
				}
				break;
			case 2:
				printf("%s", "Which city do you want to search? ");
				char choiceOfcity[7];
				scanf("%6s", choiceOfcity);
				for (int count = 0; count < total; count++) {
					if (0 == strcmp(choiceOfcity, Client[count].city)) {
						printf("%s %s %s %s %s %s\n %lf %lf %lf\n", Client[count].name, Client[count].position,
							Client[count].departmentno, Client[count].city, Client[count].address, Client[count].telephone,
							Client[count].payofhour, Client[count].salary, Client[count].seniority);
						tempcount++;
					}
				}
				break;
			case 3:
				printf("%s", "What salary do you want to search?");
				double moneyquery;
				scanf("%lf", &moneyquery);
				for (int count = 0; count < total; count++) {
					if (Client[count].salary >= moneyquery) {
						printf("%s %s %s %s %s %s\n %lf %lf %lf\n", Client[count].name, Client[count].position,
							Client[count].departmentno, Client[count].city, Client[count].address, Client[count].telephone,
							Client[count].payofhour, Client[count].salary, Client[count].seniority);
						tempcount++;
					}
				}
				break;
			case 4:
				printf("%s", "Please  input name:");
				scanf("%6s", newClient.name);//一個中文字=兩個英文字
				strcpy(Client[total].name, newClient.name);
				printf("%s", "Please input position:");
				scanf("%10s", newClient.position);
				strcpy(Client[total].position, newClient.position);
				printf("%s", "Please input department number: ");
				scanf("%3s", newClient.departmentno);
				strcpy(Client[total].departmentno, newClient.departmentno);
				printf("%s", "Please input city: ");
				scanf("%6s", newClient.city);
				strcpy(Client[total].city, newClient.city);
				printf("%s", "Please input address: ");
				scanf("%32s", newClient.address);
				strcpy(Client[total].address, newClient.address);
				printf("%s", "Please input telephone: ");
				scanf("%16s", newClient.telephone);
				strcpy(Client[total].telephone, newClient.telephone);
				printf("%s", "Please input pay of hour: ");
				scanf("%lf",&newClient.payofhour);
				Client[total].payofhour = newClient.payofhour;
				printf("%s", "Please input pay salary: ");
				scanf("%lf",&newClient.salary);
				Client[total].salary = newClient.salary;
				printf("%s", "Please input seniority: ");
				scanf("%lf",&newClient.seniority);
				Client[total].seniority = newClient.seniority;
				total++;
				cfPtr = fopen("employee.txt", "a");
				fprintf(cfPtr, "%s %s %s %s %s %s %lf %lf %lf\n", newClient.name, newClient.position,
					newClient.departmentno, newClient.city, newClient.address, newClient.telephone,
					newClient.payofhour, newClient.salary, newClient.seniority);
				fclose(cfPtr);
				break;
			case 5:
				printf("%s", "Which name do you want to delete?");
				scanf("%6s", choiceOfname);
				int found = 0, recordno = 0;
				do {
					if (0 == strcmp(choiceOfname, Client[recordno].name)) {
						found++;
					}
					recordno++;
				} while ((!found) && (recordno < total));
				if (!found) {
					printf("\n%s\n\n", "Not found!!!!!");
				}
				else
				{
					cfPtr = fopen("employee.txt", "w");
					for (int count = 0; count < total; count++) {
						if (count != (recordno - 1)) {
							fprintf(cfPtr, "%s %s %s %s %s %s\n %lf %lf %lf\n", Client[count].name, Client[count].position,
								Client[count].departmentno, Client[count].city, Client[count].address, Client[count].telephone,
								Client[count].payofhour, Client[count].salary, Client[count].seniority);
						}
						if (count >= recordno) {
							strcpy(Client[count - 1].name, Client[count].name);
							strcpy(Client[count - 1].position, Client[count].position);
							strcpy(Client[count - 1].departmentno, Client[count].departmentno);
							strcpy(Client[count - 1].city, Client[count].city);
							strcpy(Client[count - 1].address, Client[count].address);
							strcpy(Client[count - 1].telephone, Client[count].telephone);
							Client[count - 1].payofhour = Client[count].payofhour;
							Client[count - 1].salary = Client[count].salary;
							Client[count - 1].seniority = Client[count].seniority;
						}
					}
					fclose(cfPtr);
					total--;
					printf("\n%s is deleted!!!\n\n", choiceOfname);
				}
				break;
			case 6:
				if ((cfPtr = fopen("employee.dat", "wb")) == NULL) {
					puts("File could not be opened.");
				}
				else {
					struct clientData blankClient = { "","","","", "","",0.0,0.0,0.0 };
					fwrite(Client, sizeof(struct clientData), total, cfPtr);
					for (int count = 1; count <= (100 - total); count++) {
						fwrite(&blankClient, sizeof(struct clientData), 1, cfPtr);
					}
					fclose(cfPtr);
					printf("\nOutput %d records to random access file!!!\n\n", total);
				}
				break;
            case 7:
                printf("%s", "Which name do you want to renew?");
				scanf("%6s", choiceOfname);
                found = 0, recordno = 0;
				do {
					if (0 == strcmp(choiceOfname, Client[recordno].name)) {
						found++;
					}
					recordno++;
				} while ((!found) && (recordno < total));
				if (!found) {
					printf("\n%s\n\n", "Not found!!!!!");
				}
				else {
                    cfPtr = fopen("employee.txt", "w");
					for (int count = 0; count < total; count++) {
						if (count != (recordno - 1)) {
							fprintf(cfPtr, "%s %s %s %s %s %s\n %lf %lf %lf\n", Client[count].name, Client[count].position,
								Client[count].departmentno, Client[count].city, Client[count].address, Client[count].telephone,
								Client[count].payofhour, Client[count].salary, Client[count].seniority);
						}
						else {
							printf("%s", "Please input position:");
                            scanf("%10s", newClient.position);
                            strcpy(Client[count].position, newClient.position);
                            printf("%s", "Please input department number: ");
                            scanf("%3s", newClient.departmentno);
                            strcpy(Client[count].departmentno, newClient.departmentno);
                            printf("%s", "Please input city: ");
                            scanf("%6s", newClient.city);
                            strcpy(Client[count].city, newClient.city);
                            printf("%s", "Please input address: ");
                            scanf("%32s", newClient.address);
                            strcpy(Client[count].address, newClient.address);
                            printf("%s", "Please input telephone: ");
                            scanf("%16s", newClient.telephone);
                            strcpy(Client[count].telephone, newClient.telephone);
                            printf("%s", "Please input pay of hour: ");
                            scanf("%lf",&newClient.payofhour);
                            Client[count].payofhour = newClient.payofhour;
                            printf("%s", "Please input pay salary: ");
                            scanf("%lf",&newClient.salary);
                            Client[count].salary = newClient.salary;
                            printf("%s", "Please input seniority: ");
                            scanf("%lf",&newClient.seniority);
                            Client[count].seniority = newClient.seniority;
                            fprintf(cfPtr, "%s %s %s %s %s %s\n %lf %lf %lf\n", Client[count].name, Client[count].position,
								Client[count].departmentno, Client[count].city, Client[count].address, Client[count].telephone,
								Client[count].payofhour, Client[count].salary, Client[count].seniority);
						}
                    }
                    fclose(cfPtr);
					printf("\n%s is renew!!!\n\n", choiceOfname);
				}
				break;
			}
			if (request <= 3) {
				printf("\nThere are %d records match your request!!!\n\n", tempcount);
			}
			printf("%s", "Enter request\n"
				" 1 - List all\n"
				" 2 - Search city\n"
				" 3 - Search salary\n"
				" 4 - Append one record\n"
				" 5 - Delete one record\n"
				" 6 - Output random access file\n"
				" 7 - Renew one record\n"
				" 8 - End of run\n");
			scanf("%d", &request);
		}
		puts("End of run.");
	}
}
