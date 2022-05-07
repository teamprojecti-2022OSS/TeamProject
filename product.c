#include <stdio.h>
#include <string.h>
#include "product.h>

int selectMenu(){
    int menu;
    printf("\n*** 주헌&예준 cafe ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
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
	scanf(" %[^\n]", p->name);
	printf("메뉴를 설명해주세요 : ");
        scanf(" %[^\n]", p->detail);
	printf("메뉴의 가격을 입력해주세요 : ");
        scanf(" %d", &p->price);

}

void readProduct(Product p){
    printf("%-15s %-20s %-10d원,p->name,p->detail,&p->price);
}
	   
int updateProduct(Product *p){
    printf("새 메뉴명은? ");
    scanf("%[^\n]s",p->name);
    getchar();
    printf("새 메뉴를 설명해주세요 : ");
    scanf(" %[^\n]", p->detail);
    printf("새 메뉴의 가격을 입력해주세요 : ");
    scanf(" %d", &p->price);
    return 1;
}
	   
int deletProduct(Product *p){
    p->price=-1;
    return 1;
}
	   
void saveData(Product *p, int count);
int loadData(Product *p);
void searchProductName();

