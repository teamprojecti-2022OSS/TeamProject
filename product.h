typedef struct {
	char name[50];
	char detail[50];
	int price;
} Product;

int createProduct(Product *p); //메뉴를 추가
void readProduct(Product p); //메뉴 조회
int updateProduct(Product *p); //메뉴 수정
int deletProduct(Product *p); //메뉴 삭제
void saveData(Product *p, int count); //FILE 저장 
int loadData(Prodcut *p); //FILE 로드
void searchProductName(Product *p, int count); //제품명으로 검색

