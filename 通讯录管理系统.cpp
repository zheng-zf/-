#include<iostream>
using namespace std;
#define Max 1000

struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Address;
};

struct Addressbooks
{
	struct Person personArray[Max];
	int m_Size;
};

void showMenu()
{
	string menu[7] = { "1、添加联系人","2、显示联系人","3、删除联系人","4、查找联系人","5、修改联系人","6、清空联系人","0、退出通讯录" };
	for (int i = 0; i < 7; i++)
	{
		cout << menu[i] << endl;
	}
}

void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == Max)
	{
		cout << "满了" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		cout << "请输入性别" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
		}
		int age = 0;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

void showAddressbooks(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << abs->personArray[i].m_Name << abs->personArray[i].m_Age << abs->personArray[i].m_Sex << abs->personArray[i].m_Phone << abs->personArray[i].m_Address << endl;
		}
	}
	system("pause");
	system("cls");
}

int selectPerson(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs, string name)
{
	int exist = selectPerson(abs, name);
	if (exist == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = exist; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
}

void modifyPerson(Addressbooks* abs, string name) {
	int exist = selectPerson(abs, name);
	if (exist == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "修改年龄" << endl;
		int age;
		cin >> age;
		abs->personArray[exist].m_Age = age;
	}
}
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ok" << endl;
}



int main() 
{
	Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showAddressbooks(&abs);
			break;
		case 3:
		{
			string name;
			cout << "请输入名字" << endl;
			cin >> name;
			deletePerson(&abs, name);
		}
			break;
		case 4:
		{
			string name;
			cout << "请输入名字" << endl;
			cin >> name;
			int res = selectPerson(&abs, name);
			if (res == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << abs.personArray[res].m_Name << abs.personArray[res].m_Age << abs.personArray[res].m_Sex << abs.personArray[res].m_Phone << abs.personArray[res].m_Address << endl;
			}
		}
			break;
		case 5:
		{
			string name;
			cout << "请输入名字" << endl;
			cin >> name;
			modifyPerson(&abs, name);
		}
			break;
		case 6:
			cleanPerson(&abs);
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}




