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
		cout << "�ֱ������ļ����ͱ�ǩ�����ÿո����" << endl;
		cin >> filename;
		cin >> tipname;
		tip.name = tipname;
		file newfile(filename, fileaddress + "//" + filename);
		if (FILE.find(tip) == FILE.end())  //��ǩ�������ڣ���ӱ�ǩ�����Ϸ��������map��
		{
			std::vector<file> document;    //�µ�vector<file>�������ļ�
			document.push_back(newfile);
			FILE.insert(make_pair(tip, document));
			cout << "��ӳɹ�" << endl;
		}
		else			//�����ǩ�Ѵ��ڣ����û�ѡ��ʹ��������ǩ�����Ǹ���ǩ���˵��
		{
			cout << "�Ѵ��� " << tip.name << " ��ǩ" << endl;
			cout << "����Ҫʹ��������ǩ������1������Ҫ���ñ�ǩ���˵��������2����ֱ����Ӹñ�ǩ������3" << endl;
			tag old_tip;
			old_tip.name = tip.name;			//����û���Ҫ�޸ı�ǩ˵����ɾ���ɱ�ǩ����ԭvalue�����˱�ǩ��Ӧ��
			std::vector<file>*tempfile;							 //����û���Ҫ�޸ı�ǩ˵������ʱ����valueֵ
			std::vector<file> document;							//����û���Ҫ�޸ı�ǩ˵���������µ�vector<file>�������ļ�
			int select;
			cin >> select;
			switch (select)
			{
			case 1: continue;
			case 2:
					tempfile = &FILE[tip];
					FILE.erase(FILE.find(tip));
					cout << "�������ԭ��ǩ��˵��" << endl;
					cin >> old_tip.explain;
					cout << "��������±�ǩ��˵��" << endl;
					cin >> tip.explain;
					document.push_back(newfile);
					FILE.insert(make_pair(old_tip, *tempfile));
					FILE.insert(make_pair(tip, document));
					continue;
			case 3:
				FILE[tip].push_back(newfile);
				continue;
			default:
				cout << "û�����ѡ�����" << endl;
				continue;
			}
		}
	}
}