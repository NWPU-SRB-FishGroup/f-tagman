#include"file.h"
//����ʵ��file���еķ���

file file::operator=(const file& f)
{
	file newfile();
	newfile().id = f.id;
	newfile().name = f.name;
	return newfile();
}