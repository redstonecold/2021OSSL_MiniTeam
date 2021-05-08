#include <stdio.h>
#include <string.h>

typedef struct{
    char date[10];
    char name[60];
    char attendance;
} List;

int createList(List *l);
void readList(List l); 
void listList(List* l, int count);
int updateList(List *l);   
int deleteList(List *l);      

int selectMenu();
int selectDataNo(List* l, int count);

int loadData(List *l);
void saveData(List *l, int count);

void searchDate(List *l, int count);
void searchName(List *l, int count);
void searchAttendance(List *l, int count);
