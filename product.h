typedef struct {
	char name[50];
	char detail[50];
	int price;
} Product;

int selectMenu();//선택지 제공
int createProduct(Product *p); //메뉴를 추가
void readProduct(Product p); //메뉴 조회
int updateProduct(Product *p); //메뉴 수정
int deletProduct(Product *p); //메뉴 삭제
void saveData(Product *p, int count); //FILE 저장 
int loadData(Produt *p); //FILE 로드
void searchProductName(Product *p, int count); //제품명으로 검색
int changePassword(int oldPassword);//비밀번호 변경
