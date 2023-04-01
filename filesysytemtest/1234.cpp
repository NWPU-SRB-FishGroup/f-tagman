#pragma once
#include"file.h"

using std::cout;
using std::cin;
using std::endl;

bool function_01(address filepath)
{
	fs::path str(filepath);
	if (!fs::exists(str))		//�����ȼ��Ŀ¼�Ƿ���ڲ���ʹ���ļ����.
		return 1;
	fs::directory_entry entry(str);		//�ļ����
	if (entry.status().type() == fs::file_type::directory)	//��������C++11��ǿö������
		cout << "��·����һ��Ŀ¼" << endl;
	fs::directory_iterator list(str);	        //�ļ��������
	for (auto& it : list)
		cout << it.path().filename() << endl;	//ͨ���ļ���ڣ�it����ȡpath�����ٵõ�path������ļ�������֮���
	system("pause");
	return 0;
}


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