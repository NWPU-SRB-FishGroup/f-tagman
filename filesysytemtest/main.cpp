#include"file.h"



using std::cin;
using std::cout;

int main()
{
	std::map<tag, std::vector<file> >FILE;
	address filepath;
	while (1)
	{
<<<<<<< HEAD
		menu();
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "����Ҫ�����Ŀ¼��: ";
			cin >> filepath;
			function_01(filepath);
			break;
		case 2:
			function_02(FILE);
			break;
		case 3:break;
		case 4:break;
		case 5:break;
		case 6:break;
		case 7:break;
		case 8:break;
		default:
			cout<<"������Ҳ��ǰɣ�";
			system("pause");
			break;
		}
=======
>>>>>>> 1272317dcc92fa3ff20c5423518860a473cb8ce8

	case 1:
		cout << "����Ҫ�����Ŀ¼��: ";
		cin >> filepath;
		read(filepath);
		break;
	case 2:break;
	case 3:break;
	case 4:break;
	case 5:break;
	case 6:break;
	case 7:break;
	case 8:
		function_08();
		break;
	default:
    cout<<"������Ҳ��ǰɣ�";
		system("pause");
		break;
	}

}