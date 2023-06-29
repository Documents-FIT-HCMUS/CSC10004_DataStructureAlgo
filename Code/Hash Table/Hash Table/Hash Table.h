#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#define M 1000000009
#define p 31
#define SIZE 2000
using namespace std;

struct Company
{
	string name, profitTax, address;
};

//HASH TABLE
string split(string, int&);
Company readCompanyInfo(string);
vector<Company> readCompanyList(string);
void printCompanyList(vector<Company>);
void printCompanyInfo(Company);
void printCompanyInfo(Company*);

long long unsigned int hashString(string);
Company* createHashTable(vector<Company>);
void insert(Company*, Company);
Company* search(Company*, string);
