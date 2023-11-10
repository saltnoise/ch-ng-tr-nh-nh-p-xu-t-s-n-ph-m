#include<iostream>
#include<string>
#include<math.h>

using namespace std;
struct Product{
	string name;
	int price;
	int numbers;
	friend istream& operator >>(istream &is,Product &product){
	cout <<"Nhap ten san pham:" << endl;
	is.ignore();
	getline(is, product.name);
	cout <<"Nhap gia san pham:" << endl;
	is >> product.price;
	cout <<"Nhap so luong san pham:" << endl;
	is >> product.numbers;
	return is;
    }
    friend ostream& operator <<(ostream &os,Product product){
    cout <<"Ten san pham:";
	os << product.name;
	cout <<" "<<"Gia san pham:";
	os <<product.price;
	cout <<" "<<"So luong san pham:";
	os <<product.numbers;
	return os;	
	}
	
};
int show_menu(){
	int choose;
	system("cls");
	cout <<"______________Menu______________" << endl;
	cout <<"Chon chuc nang can su dung" << endl;
	cout <<"1.Xem danh sach san pham" << endl;
	cout <<"2.Them vao mot san pham" << endl;
	cout <<"3.Xoa bot mot san pham" << endl;
	cin >> choose;
	return choose;
}
void show_list(Product *products,int size){
	if(size == 0){
		cout << "Hien khong co san pham nao" << endl;
	}
	for(int i = 0;i < size;i ++){
		cout << products[i] << endl;
	}
}
void add_product(Product* &products,int &size){
	Product new_product;
	cout << "Nhap san pham can them:" << endl;
	cin >> new_product;
	int new_size = size + 1;
	Product* new_products = new Product [new_size];
	for(int i = 0;i < size;i++){
		new_products[i] = products[i];
	}
	new_products[new_size - 1] = new_product;
	delete[] products;
	products = new_products;
	size = new_size;
}
void remove_product(Product* &products,int &size)
{
	int x;
	cout <<"Nhap vi tri cua san pham can xoa" << endl;
	cin >> x;
	for(int i = x;i < size - 1;i++){
		products[i] = products[i + 1];
	}
	int new_size = size - 1;
	Product* new_products = new Product[new_size];
	for(int i = 0;i < new_size;i++){
		new_products[i] = products[i];
	}
	delete[] products;
	products = new_products;
	size = new_size;
	
}

int main(){
	int size = 0;
	Product *products = new Product[size];
	while(true)
	{
		int choose = show_menu();
		system("cls");
		switch(choose){
			
			case 1 :
				show_list(products,size);
				break;
			case 2:
			    add_product(products,size);
			    break;
			case 3:
			    remove_product(products,size);
				break;
			default:
			    cout <<"Lua chon khong hop le";
			}
	cout <<"Ban co muon tiep tuc khong?"<< endl;
	bool want_countinue;
	cin >> want_countinue;
	if(!want_countinue){
		break;
	}
}	
	return 0;
}

