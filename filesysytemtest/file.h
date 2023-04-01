#pragma once
#include<iostream>
#include<filesystem>
#include<map>
#include<vector>
#include<cstdlib>

using std::string;
namespace fs = std::filesystem;
typedef string address;

class file
{
private:
	string id;//µØÖ·
	string name;//ÎÄ¼þÃû
public:
	file(string id,string name)
	{
		this->name = name;
		this->id = id;
	}
	file operator=(const file& f);
};

struct tag
{
	string name;
	string explain = "0";
	bool operator<(const tag& a)const {   
		return name == a.name ? explain < a.explain : name < a.name ;
	}
};

//�������ܺ���
void menu();
bool getout();
bool function_01(address filepath);
void function_02(std::map < tag, std::vector<file> >& FILE);
void function_08();


