#include <stdio.h>
#include <string.h>

int selectMenu() {

	int menu;
	printf("\n*** 주문 ***\n");
    	printf("1. 메뉴 조회\n");
    	printf("2. 메뉴 검색\n");
    	printf("3. 주문하기\n");
    	printf("4. 주차 요금 결제\n");
    	//printf("5. \n");
    	//printf("6. \n");
    	//printf("7. \n");
    	//printf("8. \n");
    	//printf("0. 종료\n\n");
    	printf("=> 원하는 메뉴는? ");
    	scanf("%d", &menu);
    	return menu;
}

int main (void) {
	product plist[50];
	int index = 0;
	int count =0; menu;

	count = loadData(plist);
	index = count;

while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            count += createProduct(&plist[index++]);
        }
        else if (menu == 2){
            int no = selectProductNo(plist, index);
            if(no==0) {
                printf("=> 취소됨!\n");
                continue;
            }
            readProduct(plist[no-1]);
        }
        else if (menu == 3){
            int no = selectProductNo(plist, index);
            if(no==0) {
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(&plist[no-1]);
        }
        else if (menu == 4){
            int no = selectProductNo(plist, index);
            if(no==0) {
                printf("=> 취소됨!\n");
                continue;
            }
            int deletok;
            printf("정말로 삭제하시겠습니까? (삭제 :1)");
            scanf("%d", &deletok);
            if (deletok ==1) {
                if(deletProduct(&plist[no-1])) count--;
            }
                printf("=>삭제됨!\n");
        }
        else if (menu == 5){
            saveData(plist, index);
        }
        else if (menu == 6){
            searchProductName(plist, index);
        }
        else if (menu == 7){
            searchProductPrice(plist, index);
        }
        else if (menu == 8){
            searchProductWeight(plist, index);
        }
    }
    printf("종료됨!\n");
    return 0;
}

