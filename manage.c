#include <stdio.h>
#include <string.h>
#include "list.h"

int selectMenu(){
    int snum;
    printf("\n*** MiniProject <출석 명단>  ***\n1.출석 데이타 조회 \n2. 출석 데이타 추가\n3. 출석 데이타 수정\n4. 출석 데이타 삭제\n");
    //printf("5. 파일저장\n");
    printf("6. 이름으로 출석부 검색\n");
    printf("7. 출석부 검색\n");
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
/*
void readList(List *l){
    printf("%s %d %d %d %d\n",p.name,p.weight,p.price,p.star,p.numOfStar);
}

void listProduct(Product* p, int count){
    printf("\nNo Name Weight Price Star NumOfStar\n");
    printf("*****************\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        printf("%d ",i+1);
        readProduct(p[i]);
    }
    printf("\n");
}
*/
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


/*
int loadData(Product *p){
    FILE *fp;
    fp = fopen("manager.txt","rt");
    int i = 0;

    if(fp == NULL){
        printf("=>파일 없음\n");
    }
    else {
        for(; i<100; i++){
            fscanf(fp," %[^,], %d %d %d %d",p[i].name, &p[i].weight, &p[i].price, &p[i].star, &p[i].numOfStar);
            if (feof(fp)) break;
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");
    }
    return i;
}

void saveData(Product *p, int count){
    FILE *fp;
    fp = fopen("manager.txt","wt");

    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        fprintf(fp,"%s, %d %d %d %d\n",p[i].name,p[i].weight,p[i].price,p[i].star,p[i].numOfStar);
    }
    fclose(fp);
    printf("저장됨!\n");
}

void searchName(List *p, int count){
    char searchn[20];
    int scnt = 0;

    printf("검색할 제품 이름? ");
    scanf(" %s",searchn);

    printf("\nNo Name Weight Price Star NumOfStar\n");
    printf("================================\n");
    for(int i = 0; i<count; i++){
        if(p[i].price == -1) continue;
        if(strstr(p[i].name, searchn)){
            printf("%2d ",i+1);
            readProduct(p[i]);
            scnt ++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void searchPrice(Product *p, int count){
    int searchp;
    int scnt = 0;

    printf("검색할 제품 가격? ");
    scanf("%d", &searchp);

    printf("\nNo Name Weight Price Star NumOfStar\n");
    printf("================================\n");
    for(int i = 0; i<count; i++){
        if(p[i].price == -1) continue;
        if(p[i].price == searchp){
            printf("%2d ",i+1);
            readProduct(p[i]);
            scnt ++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
};
void searchWeight(Product *p, int count){
    int searchw;
    int scnt = 0;

    printf("검색할 제품 무게? ");
    scanf("%d",&searchw);

    printf("\nNo Name Weight Price Star NumOfStar\n");
    printf("================================\n");
    for(int i = 0; i<count; i++){
        if(p[i].weight == -1) continue;
        if(p[i].weight == searchw){
            printf("%2d ",i+1);
            readProduct(p[i]);
            scnt ++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
};
*/