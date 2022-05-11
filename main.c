#include <stdio.h>
#include <string.h>
#include "product.h"


int main (void) {
	Product plist[50];
	int index = 0;
	int count =0, menu;
	int count2 =0, index2=0;//이용한 손님 수를 체크하는 변수
	int mode;//mode를 선택하도록 한다.
	int password=1111,inputPassword;//password 초기값과 입력값
	count = loadData(plist);
	index = count;
	index2 = count2;
    password=loadPassword();//비밀번호값 불러오기

	printf("점장이신가요? 손님이신가요? (점장: 1, 손님:2) ");
	scanf("%d",&mode);
if(mode==1){
    do{
	printf("\n비밀번호를 입력하시오. (초기값은 1111입니다.) ");
    scanf("%d",&inputPassword);
    if(inputPassword!=password) printf("잘못 입력하였습니다!\n");
    }while(inputPassword!=password);
        while (1){
            menu = selectMenu();
            if (menu == 0) break;
            if (menu == 1){
                count += createProduct(&plist[index++]);
            }
            else if (menu == 2){
                listProduct(plist, index);
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
                int changeOk;
                printf("비밀번호를 변경하시겠습니까? (변경시 1 입력)");
                scanf("%d",&changeOk);
                if(changeOk==1)
                password=changePassword(password);
                else{
                printf("=> 취소됨!\n");
                continue;
                }
            }
            }
            printf("종료됨!\n");
            return 0;
    }
if(mode==2){
    while (1){
            menu = selectMenu2();
            if (menu == 0) break;
            if (menu == 1){
               int check;//주문이 끝났는지 확인하는 변수
                int i=0;
                do {
                clist[index2].menuNum[i] = selectProductNo(plist, index);
                printf("더 주문하시겠습니까?(예:1, 아니요:2)");
                scanf("%d",&check);
                i++;
                } while(check==1);
                checkTakeout(&clist[index2++]);
            }
            else if (menu == 2){
		int check;//주차여부 확인
                printf("주차를 하셨나요?(하셨으면 1, 하지 않으셨으면 2) ");
                scanf("%d",&check);
                if(check==1)
                checkCarnum(&clist[index2]);
                
            }
            else if (menu == 3){
               int check;//주차요금 출력여부 확인
                int order;//검색한 차량번호가 있는 고객님의 순서
                int cometime;//고객님의 들어온 시간값을 받는 변수
                int parkingfee;
                printf("주차요금을 출력하시겠나요?(예 1, 아니요 2) ");
                scanf("%d",&check);
                if(check==1)
                order=printParkingfee(clist,index2);
                if(order==-1){
                    printf("검색하신 차량이 없습니다.");
                }
                else {
                    cometime=printCometime(clist,order);
                    parkingfee=calParkingfee(cometime);
                    printf("주차요금은 %d원입니다.",parkingfee*500);
                }
            }
            else if (menu == 4){
               
            }
            else if (menu == 5){
                
            }
            
            }
            printf("종료됨!\n");
            return 0;
    }
}   
