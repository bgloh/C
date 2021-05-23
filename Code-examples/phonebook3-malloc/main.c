
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Dialog.h"

int main()
{

	int num;
	Pbook pb[BLEN];
	Pbook* pb_ptr;
	int pbidx = 0;
	int del;
	int ser;

	/**************************************************************************/
	FILE* fpr;
	fpr = fopen("Dialog.txt", "rt");
	if (fpr != NULL) {
		fscanf(fpr, "%d", &pbidx);
		pb_ptr = (Pbook*)malloc(sizeof(Pbook)*(pbidx + 50));
		if (pb_ptr == NULL)
            printf("dynamic memory error !!!! ***********************");
		for (int i = 0; i < pbidx; i++) {
			//fscanf(fpr, "%s %s", pb[i].name, pb[i].phone);
			fscanf(fpr, "%s %s", (pb_ptr+i)->name, (pb_ptr+i)->phone);

		}

		/*
        int i=0;
		while(fscanf(fpr, "%s %s", pb[i].name, pb[i].phone) != EOF)
        i++;
        */

		fclose(fpr);
	}
	/***************************************************************************/

	while (1)
	{
		Menu(&pbidx);

		do {
			printf("Choose the menu: "); scanf("%d", &num);
		} while (num < 1 || num>5);

		switch (num)
		{
		case Insert:
			if (Menu_Insert2(pb_ptr, &pbidx) == -1) {
				puts("전화번호부가 꽉 찼습니다.\n");
			}
			else
				puts("\t\t Data Inserted \n");
			break;
		case Delete:
			del = Menu_Delete(pb, &pbidx);
			if (del == -1) {
				puts("전화번호부가 비어있습니다.\n");
			}
			else if (del == 1)
				puts("\t\t Data Deleted \n");
			else {
				puts("일치하는 데이터가 없습니다. \n");
			}
			break;
		case Search:
			ser = Menu_Search(pb, &pbidx);
			if (ser == -1) {
				puts("찾으시는 데이터가 없습니다. \n");
			}
			else {
				printf("Name : %s \t Tel : %s \n\n", pb[ser].name, pb[ser].phone);
			}
			break;
		case Printall:
			//Menu_Print_All(pb, &pbidx);
			Menu_Print_All2(pb_ptr, &pbidx);
			break;
		case Exit:
		    fpr = fopen("Dialog.txt", "wt");
			fprintf(fpr, "%d\n", pbidx);
			for (int i = 0; i < pbidx; i++) {
				//fprintf(fpr, "%s %s \n", pb[i].name, pb[i].phone);
				fprintf(fpr, "%s %s \n", (pb_ptr+i)->name, (pb_ptr+i)->phone);
			}
			free(pb_ptr);
			fclose(fpr);
			return 0;
		}
	}

	return 0;
}
