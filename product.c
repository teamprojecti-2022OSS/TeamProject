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
        	fscanf(fp, " %[^\n]", p[i].name);
        	if(feof(fp)) break;
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
