#include <stdio.h>
#include <string.h>
#include "product.h>

int createProduct(Product *p) {

	printf("메뉴명을 입력해주세요 : ");
	scanf(" %[^\n]", p->name);
	printf("메뉴를 설명해주세요 : ");
        scanf(" %[^\n]", p->detail);
	printf("메뉴의 가격을 입력해주세요 : ");
        scanf(" %d", &p->price);

}

void readProduct(Product p);
int updateProduct(Product *p);
int deletProduct(Product *p);
void saveData(Product *p, int count);
int loadData(Product *p);
void searchProductName);

