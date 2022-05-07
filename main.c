#include <stdio.h>
#include <string.h>
#include "product.h"


int main (void) {
	Product plist[50];
	int index = 0;
	int count =0, menu;
	int mode;//mode를 선택하도록 한다.
	int password=0000,inputPassword;//password와 입력값
	count = loadData(plist);
	index = count;

	pritnf("점장이신가요? 손님이신가요?(점장: 1, 손님:2)");
	scanf("%d",&mode);
if(mode==1){
	printf("비밀번호를 입력하시오."(초기값은 0000입니다.));
    sncaf("%d",inputPassword);
    if(inputPassword==password){
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
    }   
}   
