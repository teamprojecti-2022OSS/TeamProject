typedef struct {
	char name[50];
	char detail[50];
	int price;
} Product;

typedef struct {
	int menuNum[20];//주문하는 메뉴번호
	char placeEat[5];//포장 or 매장
	int carNum;//주차번호
	int cometime;//입장시간
} Custom;

int selectMenu();//선택지 제공(점장모드)
int selectMenu2();//선택지 제공(손님모드)
int createProduct(Product *p); //메뉴를 추가
void readProduct(Product p); //메뉴 조회
int updateProduct(Product *p); //메뉴 수정
int deletProduct(Product *p); //메뉴 삭제
void listProduct(Product *p, int count); //메뉴 리스트 조회
void saveData(Product *p, int count); //FILE 저장 
int loadData(Product *p); //FILE 로드
void searchProductName(Product *p, int count); //제품명으로 검색
int changePassword(int oldPassword);//비밀번호 변경
int selectProductNo(Product *p, int count); //원하는 메뉴 선택
int loadPassword();//비밀번호 불러오기
void checkTakeout(Custom *c);//포장인지 주문인지 파악
