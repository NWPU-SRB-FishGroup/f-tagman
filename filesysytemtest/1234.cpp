#pragma once
#include"file.h"

using std::cout;
using std::cin;
using std::endl;



void function_02(std::map < tag, std::vector<file> >&FILE)
{
	
	address fileaddress;
	cout << "�������ļ�·��: ";
	cin >> fileaddress;
	function_01(fileaddress);
	while (1) {
		if (getout())break;
		string tipname;
		string filename;
		tag tip;
		std::vector<file> document;
		cout << "�ֱ������ļ����ͱ�ǩ�����ÿո����" << endl;
		cin >> filename;
		cin >> tipname;
		tip.name = tipname;
		file newfile(filename, fileaddress + "//" + filename);
		if (FILE.find(tip) == FILE.end())  //��ǩ�������ڣ���ӱ�ǩ�����Ϸ��������map��
		{
			document.push_back(newfile);
			FILE.insert(make_pair(tip, document));
			cout << "��ӳɹ�" << endl;
		}
		else			//�����ǩ�Ѵ��ڣ����û�ѡ��ʹ��������ǩ�����Ǹ���ǩ���˵��
		{
			cout << "�Ѵ��� " << tip.name << " ��ǩ" << endl;
			cout << "����Ҫʹ��������ǩ������1������Ҫ����ǩ���˵��������2" << endl;
			int select;
			cin >> select;
			if (select == 1)continue;
			else if (select == 2)//�ȸ��Ѵ��ڵı�ǩ�޸�˵�����ٸ������ӵı�ǩ�޸�˵��
			{
				std::vector<file>newfile;
				newfile = FILE[tip];
				FILE.erase(FILE.find(tip));

			}
			else
			{
				cout << "û�����ѡ�����";
				continue;
			}
		}
	}
}