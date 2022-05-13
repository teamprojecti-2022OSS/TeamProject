#include <stdio.h>
#include <string.h>
#include "product.h"

int selectMenu(){
    int menu;
    printf("\n*** 주헌&예준 cafe ***\n");
    printf("1. 메뉴추가\n");
    printf("2. 메뉴조회\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("5. 메뉴저장\n");
    printf("6. 비밀번호변경\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    getchar();
    return menu;
}

int createProduct(Product *p) {

	printf("메뉴명을 입력해주세요 : ");
	scanf(" %[^\n]s", p->name);
    getchar();
	printf("메뉴를 설명해주세요 : ");
    scanf(" %[^\n]s", p->detail);
    getchar();
	printf("메뉴의 가격을 입력해주세요 : ");
    scanf(" %d", &p->price);

}

void readProduct(Product p){
    printf("%-15s %-20s %-10d",p.name,p.detail,&p.price);
}

void listProduct(Product *p, int count) {
	printf("======================================================================\n");
    printf("||   메뉴             || 세부사항                      || 가격       ||\n");
    printf("||====================||===============================||============||\n");
	for(int i=0; i<count; i++) {
		if (p[i].price == -1) continue;
		printf("||%d. ", i+1);
		printf("%-16s || %-30s|| %-10d ||\n",p[i].name,p[i].detail,p[i].price);
	}
    printf("======================================================================\n");
}

int updateProduct(Product *p){
    getchar();
    printf("새 메뉴명은? ");
    scanf("%[^\n]s",p->name);
    getchar();
    printf("새 메뉴를 설명해주세요 : ");
    scanf(" %[^\n]s", p->detail);
    getchar();
    printf("새 메뉴의 가격을 입력해주세요 : ");
    scanf(" %d", &p->price);
    return 1;
}
	   
int deletProduct(Product *p){
    p->price=-1;
    return 1;
}
	   
void saveData(Product *p, int count) {

	FILE *fp;
	fp = fopen("menulist.txt", "wt");

	for(int i=0; i<count; i++) {
		if(p[i].price == -1) continue;
		fprintf(fp, "%s\n", p[i].name);
    		fprintf(fp, "%s\n", p[i].detail);
    		fprintf(fp, "%d\n",p[i].price);
	}
	fclose(fp);
	printf("=>저장됨!");
}	

int loadData(Product *p) {

	int i;
    	FILE *fp;
        if(fp = fopen("menulist.txt","rt")) {
        for(i=0; i<100; i++) {
        if(feof(fp)!=0) break;
	fscanf(fp, " %[^\n]", p[i].name);
        fscanf(fp, " %[^\n]", p[i].detail);
        fscanf(fp, " %d", &p[i].price);
        }

        fclose(fp);
        printf("\n=> 로딩 성공!\n");
        return i;
        }
        else {
        printf("\n=> 파일 없음\n");
        return 0;
    }


}
int changePassword(int oldPassword){
    int newPassword,check;
    do{
    printf("현재 비밀번호를 입력하시오.");
    scanf("%d",&check);
    if(check!=oldPassword) printf("비밀번호가 잘못되었습니다.\n");
    }while(check!=oldPassword);
    printf("바꾸실 비밀번호를 입력하시오. (1부터 9번호로만 설정가능)");
    scanf("%d",&newPassword);
    FILE *fp;
	fp = fopen("password.txt", "wt");
	fprintf(fp, "%d\n", newPassword);
    fclose(fp);
    return newPassword;
}
int selectProductNo(Product *p, int count) {

	int num;
	listProduct(p,count);

	printf("\n원하시는 번호는(취소: 0)? : ");
	scanf("%d", &num);
	return num;

}

int loadPassword(){
    int loadPassword;
    FILE *fp;
        if(fp = fopen("password.txt","rt")) {
        fscanf(fp, " %d", &loadPassword);
        return loadPassword;
        }
        else return 1111;
}
//손님모드 함수
int selectMenu2(){
    int menu;
    printf("\n*** 주헌&예준 cafe ***\n");
    printf("1. 메뉴선택\n");
    printf("2. 차량번호 입력\n");
    printf("3. 주차요금 출력\n");
    printf("4. 영수증 출력\n");
    printf("5. 본인순서 출력\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    getchar();
    return menu;
}

void checkTakeout(Custom *c){
    printf("매장을 이용하시나요? 포장 주문을 하시나요? (매장이용: C, 포장: T)");
    scanf("%s",c->placeEat);
}
void checkCarnum(Custom *c){
    printf("차번호를 입력하시오. ");
    scanf("%d",&c->carNum);
    printf("들어온 시간을 입력하시오.");
    scanf("%d",&c->cometime);
}

int printParkingorder(Custom *c,int count){
    int inputcarNum;//입력받는 주차번호를 받는 변수
    printf("주차번호는?");
    scanf("%d",&inputcarNum);
    for(int i=0; i<count;i++){
        if(c[i].carNum==inputcarNum) return i;
    }
    return -1;
}

int printCometime(Custom *c,int CarNum){
    return(c[CarNum].cometime);
}

int calParkingfee(int cometime){
    int outtime;//고객님의 나가는 시간값을 받는 변수
    int runtime=0;//고객님이 있었던 시간
    printf("지금 나가는 시간은?");
    scanf("%d",&outtime);
    runtime=outime-cometime;
    if(runtime<90) return 0;
    else {
        if((runtime-90)%10==0) return ((runtime-90)/10);
        else return ((runtime-90)/10+1);
    }
}

void printReceipt(Custom *c, Product *p,int num){
    int total=0;//주문한 것들의 총합
    printf("%d",c[num].menuNum[0]);
    for(int i=0; i<20; i++){
        if(c[num].menuNum[i]==0) break;
        total+=p[c[num].menuNum[i]-1].price;
    }
    if(c[num].placeEat=="T") printf("총 %d입니다. 포장입니다",total);
    else printf("총 %d입니다. 매장이용입니다",total);
}

