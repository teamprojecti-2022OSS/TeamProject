typedef struct {
	char name[50];
	char detail[50];
	int price;
} Product;

typedef struct {
	int menuNum[20];//주문받는 메뉴번호
	char placeEat[5];//포장 or 매장
	int carNum;//주차번호
	int cometime[2];//입장시간(시간과 분을 구분)
} Custom;

int selectMenu();//선택지 제공(점장님모드)
int selectMenu2();//선택지 제공(손님모드)
int createProduct(Product *p); //메뉴를 추가
void readProduct(Product p); //메뉴 조회
int updateProduct(Product *p); //메뉴 수정
int deletProduct(Product *p); //메뉴 삭제
void listProduct(Product *p, int count); //메뉴 리스트 조회
void saveData(Product *p, int count); // 메뉴에 대한 FILE 저장 
int loadData(Product *p); //메뉴에 대한 FILE 로드
void searchProductName(Product *p, int count); //제품명으로 검색
int changePassword(int oldPassword);//비밀번호 변경
int selectProductNo(Product *p, int count); //원하는 메뉴 선택
int loadPassword();//비밀번호 불러오기
void checkTakeout(Custom *c);//포장인지 주문인지 파악
void checkCarnum(Custom *c);//차번호와 들어온 시간을 저장
int printParkingorder(Custom *c,int count);//고객님의 차번호가 있는 순서를 반환해주는 함수
int printComehour(Custom *c,int CarNum);//고객님의 들어온 시간만을 반환
int printComeminute(Custom *c,int CarNum);//고객님의 들어온 분을 반환
int calParkingfee(int cometime, int comeminute);//고객님의 들어온 시간을 가지고, 요금을 반환해주는 함수
void printReceipt(Custom *c, Product *p,int num);//영수증 출력해주는 함수0
void saveData2(Custom *c, int count); //손님에 대한 FILE 저장
int loadData2(Custom *c); //손님에 대한 FILE 로드
