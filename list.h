#include <stdio.h>
#include <string.h>

typedef struct{
    char date[20];
    char name[60]; //이름으로
    char attendance;
} List;

int createList(List *l);
void readList(List l); //parameter 수정함
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
