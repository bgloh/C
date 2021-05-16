#ifndef __DIALOG_H__
# define __DIALOG_H__

#define LEN 30 
#define BLEN 100 


enum {
	Insert = 1,
	Delete,
	Search,
	Printall,
	Exit
};


typedef struct
{
	char name[LEN];
	char phone[LEN];
} Pbook;

void Menu(int* idx); 

int Menu_Insert(Pbook pb[], int* idx); 

int Menu_Delete(Pbook pb[], int* idx); 

int Menu_Search(Pbook pb[], int* idx); 

void Menu_Print_All(Pbook pb[], int* idx); 

#endif
