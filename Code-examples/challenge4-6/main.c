// main.c
#include <stdio.h>
#include <string.h>
#include "Dialog.h"

int main()
{

	int num; 
	Pbook pb[BLEN];
	int pbidx = 0; 
	int del; 
	int ser; 

	while (1)
	{
		Menu(&pbidx); 

		do {
			printf("Choose the menu: "); scanf_s("%d", &num);
		} while (num < 1 || num>5);

		switch (num)
		{
		case Insert:
			if (Menu_Insert(pb, &pbidx) == -1) {
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
			Menu_Print_All(pb, &pbidx);
			break;
		case Exit:
			return 0;
		}
	}

	return 0;
}
