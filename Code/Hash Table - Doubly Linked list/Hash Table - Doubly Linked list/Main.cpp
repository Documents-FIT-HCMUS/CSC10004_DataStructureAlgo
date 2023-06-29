#include "Hash Table.h"
#include "Doubly Linked List.h"

int main()
{
	//TEST
	/*Company test1;
	string s;
	s = "CONG TY TNHH BEE VIET NAM|0108927262|So 8 - K8, Khu nha o lien ke trung tam 75, Tong cuc II, Bo Quoc Phong, thon Lai Xa, Xa Kim Chung, Huyen Hoai Duc, Thanh pho Ha Noi";
	test1 = readCompanyInfo(s);
	printCompanyInfo(test1);*/

	//HASH TABLE
	vector<Company> companyList = readCompanyList("MST.txt");
	Company* hashTable = createHashTable(companyList);

	Company* searchResult = search(hashTable, "CONG TY TNHH BEE VIET NAM");
	if (searchResult == NULL) cout << "KHONG TON TAI!\n\n";
	else printCompanyInfo(searchResult);

	searchResult = search(hashTable, "CONG TY TNHH MTV KIM LONG");
	if (searchResult == NULL) cout << "KHONG TON TAI!\n\n";
	else printCompanyInfo(searchResult);

	searchResult = search(hashTable, "CONG TY TNHH ABC");
	if (searchResult == NULL) cout << "KHONG TON TAI!\n\n";
	else printCompanyInfo(searchResult);

	//DOUBLY LINKED LIST
	DList* list = new DList;
	createDList(list, 60);
	addDNodeHead(list, 40);
	addDNodeHead(list, 30);
	addDNodeHead(list, 20);
	addDNodeHead(list, 10);
	addDNodeHead(list, 0);
	addDNodeTail(list, 70);
	addDNodeTail(list, 90);
	addDNodeTail(list, 110);
	printDList(list);

	addBeforeDNode(list, -1, 200);
	addBeforeDNode(list, 50, 60);
	addAfterDNode(list, 80, 70);
	addAfterDNode(list, 100, 90);
	printDList(list);

	removeHead(list);
	removeHead(list);
	removeTail(list);
	removeTail(list);
	printDList(list);

	removeDNode(list, 10);
	removeDNode(list, 50);
	removeDNode(list, 90);
	printDList(list);
	return 0;
}