#include <stdio.h>
#include <string.h>
#include "list.h"

#define DEBUG
int main(void){
    #ifdef DEBUG
        printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
    #endif

    List Llist[100];
    int index = 0;
    int count = 0;
    int snum; // selected number in Menu

    count = loadData(Llist);
    index = count;

    while(1){
        snum = selectMenu();
        if(snum == 0) break;
        if(snum == 1 || snum ==3 || snum == 4)
            if(count == 0) continue;
        if(snum == 1) {listList(Llist,count);}
        else if(snum == 2){
            count += createList(&Llist[index++]);
        }
        else if(snum == 3){
            int no = selectDataNo(Llist, index);
            if(no == 0){
                printf("취소됨!\n");
                continue;
            }
            int isupd = updateList(&Llist[no-1]);
            if(isupd == 1) printf("=> 수정성공!\n");
        }
        else if(snum == 4){
            int no = selectDataNo(Llist, count);
            if (no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1) ");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteList(&Llist[no-1])) {
                    printf("=> 삭제됨!\n");
                }
            }
        }
        else if(snum == 5){
            saveData(Llist,count);
        }
    }
    printf("종료됨!\n");

    return 0;
}