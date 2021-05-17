
#include <stdio.h>
#include <string.h>
#include "Dialog.h"

void Menu(int* idx)
{

	puts("***** MENU *****");
	printf("\t\t[%d/%d]\n", (*idx), BLEN);
	puts("1. Insert");
	puts("2. Delete");
	puts("3. Search");
	puts("4. Print All");
	puts("5. Exit");
}

int Menu_Insert(Pbook pb[], int* idx)
{

	if (*idx >= BLEN)
		return -1;

	puts("[INSERT]");
	printf("Input Name : "); scanf("%s", pb[*idx].name);
	printf("Input Tel Number : "); scanf("%s", pb[*idx].phone);
	(*idx)++;
	return 0;
}

int Menu_Delete(Pbook pb[], int* idx)
{

	char dname[LEN];

	if (*idx <= 0)
		return -1;

	puts("[DELETE]");
	printf("Deleted Name : "); scanf("%s", dname);
	for (int i = 0; i < *idx; i++) {
		if (strcmp(pb[i].name, dname) == 0) {
			for (int k = i; k < *idx - 1; k++) {
				strcpy(pb[k].name,  pb[k + 1].name);
				strcpy(pb[k].phone,  pb[k + 1].phone);
			}
			//strcpy(pb[*idx - 1].name,  "\0");
			//strcpy(pb[*idx - 1].phone,  "\0");
			(*idx)--;
			return 1;
		}
	}


	return 0;
}

int Menu_Search(Pbook pb[], int* idx)
{

	char fname[LEN];

	puts("[SEARCH]");
	printf("Searched Name : "); scanf("%s", fname);
	for (int i = 0; i < *idx; i++) {
		if (strcmp(pb[i].name, fname) == 0) {
			return i;
		}
	}

	return -1;
}

void Menu_Print_All(Pbook pb[], int* idx)
{

	for (int a = 0; a < *idx; a++)
	{
		printf("Name : %s \t Tel : %s \n", pb[a].name, pb[a].phone);
	}
	printf("\n");
}
