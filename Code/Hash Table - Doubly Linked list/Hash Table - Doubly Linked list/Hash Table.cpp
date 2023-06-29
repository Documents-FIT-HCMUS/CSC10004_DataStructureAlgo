#include "Hash Table.h"


//HASH TABLE
string split(string s, int& pos)
{
	string buffer;
	while (s[pos] != '|' && (unsigned int)pos < s.length())
	{
		buffer.push_back(s[pos]);
		pos++;
	}
	pos++;
	return buffer;
}
Company readCompanyInfo(string info)
{
	int i = 0;
	Company result;
	result.name = split(info, i);
	result.profitTax = split(info, i);
	result.address = split(info, i);
	return result;
}
vector<Company> readCompanyList(string filename)
{
	fstream fi;
	vector<Company> companyList;
	fi.open(filename, ios::in);
	if (fi.fail())
	{
		cout << "CANNOT OPEN FILE!" << endl;
		return companyList;
	}
	string s;
	fi.ignore(1000, '\n');
	while (!fi.eof())
	{
		getline(fi, s);
		companyList.push_back(readCompanyInfo(s));
	}
	return companyList;
}
void printCompanyInfo(Company c)
{
	cout << "Name:    " << c.name << endl;
	cout << "Tax ID:  " << c.profitTax << endl;
	cout << "Address: " << c.address << endl << endl;
}
void printCompanyInfo(Company* c)
{
	cout << "Name:    " << c->name << endl;
	cout << "Tax ID:  " << c->profitTax << endl;
	cout << "Address: " << c->address << endl << endl;
}
void printCompanyList(vector<Company> list)
{
	for (unsigned int i = 0; i < list.size(); ++i)
		printCompanyInfo(list.at(i));
}

long long unsigned int hashString(string companyName)
{
	int start = 0;
	long long unsigned int s = 0;

	if (companyName.length() > 20)
		start = companyName.length() - 20;

	for (unsigned int i = start; i < companyName.length(); ++i)
		s += (long long unsigned int)companyName.at(i) * (long long unsigned int)pow(p, i);

	s = s % M;
	return s;
}
Company* createHashTable(vector<Company> companyList)
{
	Company* hashTable = new Company[SIZE];
	for (unsigned int i = 0; i < companyList.size(); ++i)
	{
		insert(hashTable, companyList.at(i));
	}
	return hashTable;
}
void insert(Company* hashTable, Company company)
{
	long long unsigned int hash = hashString(company.name);
	int location = hash % SIZE;
	int i = 0;

	while (hashTable[location].name != "")
	{
		location++;
		i++;
		if (location >= SIZE) 
			location = location % SIZE;
		if (i >= SIZE) 
			break;
	}

	hashTable[location] = company;
}
Company* search(Company* hashTable, string companyName)
{
	long long unsigned int hash = hashString(companyName);
	int location = hash % SIZE;
	int i = 0;

	while (hashTable[location].name != companyName)
	{
		location++;
		i++;
		if (location >= SIZE)
			location = location % SIZE;
		if (i >= SIZE)
			break;
	}

	if (i < SIZE) return &hashTable[location];
	else return NULL;
}
