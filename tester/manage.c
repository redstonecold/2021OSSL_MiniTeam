#include <stdio.h>
#include <string.h>
#include "list.h"

int selectMenu(){
    int snum;
    printf("\n*** MiniProject <출석 명단>  ***\n1.출석 데이타 조회 \n2. 출석 데이타 추가\n3. 출석 데이타 수정\n4. 출석 데이타 삭제\n");
    printf("5. 파일저장\n");
    //printf("6. 이름으로 출석부 검색\n");
    //printf("7. 출석부 검색\n");
    //printf("8. 무게검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d",&snum);
    return snum;
}

int createList(List *l){
    while(1){
        printf("출석 날짜는 ? yyyy-mm-dd:");
        scanf(" %[^\n]",l->date);
        if(strlen(l->date)>11) printf(" yyyy-mm-dd 형식으로 입력해주세요\n");
        else break;
    }
    while(1){
    printf("학생 이름은 ? :");
    scanf(" %[^\n]",l->name);
    if(strlen(l->name)>60) printf("60자 이내로 입력해 주세요\n");
    else break;
    }
    
    while(1){
        printf("출석 여부는 (O,X)? :");
        getchar();
        scanf("%c",&l->attendance);
        if(l->attendance=='O'||l->attendance=='X'||l->attendance=='o'||l->attendance=='x') break;
        else printf("잘못 입력하셧습니다 (O,X) 로 입력해주세요\n");
    }
    
    return 1;
}   

void readList(List l){
    printf("%s %s %c\n",l.date,l.name,l.attendance);
}

void listList(List* l, int count){
    printf("\nNo Date Name Attendance\n");
    printf("*****************\n");
    for(int i=0; i<count; i++){
        if(l[i].attendance == '-') continue;
        printf("%d ",i+1);
        readList(l[i]);
    }
    printf("\n");
}

int selectDataNo(List* l, int count){
    int no;
    listList(l, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);
    return no;
}

int updateList(List *l){
    while(1){
        printf("새로운 출석 날짜는 ?yyyy-mm-dd :");
        scanf(" %[^\n]",l->date);
        if(strlen(l->date)>11) printf(" yyyy-mm-dd 형식으로 입력해주세요\n");
        else break;
    }
    while(1){
        printf("새로운 학생 이름은 ? :");
        scanf(" %[^\n]",l->name);
        if(strlen(l->name)>60) printf("60자 이내로 입력해 주세요\n");
        else break;
    }
    
    while(1){
        getchar();
        printf("출석 여부는 (O,X)? :");
        scanf("%c",&l->attendance);
        if(l->attendance=='O'||l->attendance=='X'||l->attendance=='o'||l->attendance=='x') break;
        else printf("잘못 입력하셧습니다 (O,X) 로 입력해주세요\n");
        
    }
    return 1;
}
int loadData(List *l){
    FILE *fp;
    fp = fopen("attendance.txt","rt");
    int i =0;
    if(fp == NULL){
        printf("=> 파일 없음\n");
    }
    else {
        for (;i+100;i++){
            fscanf(fp, " %[^,], %[^,], %c",l[i].date,l[i].name, &l[i].attendance);
            if(feof(fp)) break;
        }
        fclose(fp);
        printf("=> 로딩 성공\n");

    }return i;
    
    
}

void saveData(List *l, int count){
    FILE *fp;
    fp = fopen("attendance.txt","wt");
    for(int i =0;i<count;i++){
        if(l[i].attendance=='-') continue;
        fprintf(fp,"%s, %s, %c\n",l[i].date,l[i].name,l[i].attendance);
    }
        fclose(fp);
        printf("저장됨!\n");
    
}
int deleteList(List *l){
    l->attendance= '-';
    return 1;
}