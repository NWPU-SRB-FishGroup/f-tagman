#include"file.h"
//����ʵ��file���еķ���

file file::operator=(const file& f)
{
	file newfile("0","0");
	newfile.id = f.id;
	newfile.name = f.name;
	return newfile;
}