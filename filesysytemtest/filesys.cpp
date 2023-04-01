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

void menu()
{
	cout << "********** ��ӭ�����ļ���ǩ����ϵͳ������**********" << endl;
	cout << "********** 1.չʾ��Ŀ¼ **********" << endl;
	cout << "********** 2.���ļ���ӱ�ǩ **********" << endl;
	cout << "********** 3.���ļ�ɾ����ǩ **********" << endl;
	cout << "********** 4.���ļ��޸ı�ǩ **********" << endl;
	cout << "********** 5.�Ƴ���ǩ **********" << endl;
	cout << "********** 6.���ı�ǩ���� **********" << endl;
	cout << "********** 7.��ѯ��ǩ�������ļ� **********" << endl;
	cout << "********** 8.�޸�ָ���ļ����ļ��� **********" << endl;
	cout << "********** ����������Ҫʹ�õĹ��ܣ�**********" << endl;
}

bool getout()
{
	int select;
	cout << "����������������� 1 ������������������";
	cin >> select;
	return select == 1;
}
