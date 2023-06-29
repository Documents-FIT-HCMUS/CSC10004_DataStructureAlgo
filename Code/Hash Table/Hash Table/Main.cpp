#include "Hash Table.h"

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
	return 0;
}