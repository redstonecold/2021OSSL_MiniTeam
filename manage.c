#include <stdio.h>
#include <string.h>
#include "list.h"

int selectMenu(){
    int snum;
    printf("\n*** MiniProject <출석 명단>  ***\n1.출석 데이타 조회 \n2. 출석 데이타 추가\n3. 출석 데이타 수정\n4. 출석 데이타 삭제\n");
    //printf("5. 파일저장\n");
    // printf("6. 이름으로 출석부 검색\n");
    // printf("7. 출석부 검색\n");
    //printf("8. 무게검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d",&snum);
    return snum;
}

int createList(List *l){
    printf("출석 날짜는 ? : ");
    scanf(" %[^\n]",l->date);
    printf("학생 이름은 ? : ");
    scanf(" %[^\n]",l->name);
    printf("출석 여부는 (O,X)? : ");
    scanf("%c",&l->attendance);
    return 1;
}

void readList(List l){
    printf("%s %s %c\n",l.date,l.name,l.attendance);
}

void listList(List* l, int count){
    lrintf("\nNo Date Name Attendance\n");
    printf("*****************\n");
    for(int i=0; i<count; i++){
        if(strcmp(l[i].attendance, '-')==0) continue;
        printf("%d ",i+1);
        readProduct(l[i]);
    }
    printf("\n");
}


int selectDataNo(List* l, int count){
    int no;
    listProduct(l, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);
    return no;
}

int updateList(List *l){
     printf("새로운 출석 날짜는 ? : ");
    scanf(" %[^\n]",l->date);
    printf("새로운 학생 이름은 ? : ");
    scanf(" %[^\n]",l->name);
    printf("출석 여부는 (O,X)? : ");
    scanf("%c",&l->attendance);
    return 1;
}

int deleteList(List *l){
    l->attendance= '-';
    return 1;
}
