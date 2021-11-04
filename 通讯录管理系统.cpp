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
	string menu[7] = { "1�������ϵ��","2����ʾ��ϵ��","3��ɾ����ϵ��","4��������ϵ��","5���޸���ϵ��","6�������ϵ��","0���˳�ͨѶ¼" };
	for (int i = 0; i < 7; i++)
	{
		cout << menu[i] << endl;
	}
}

void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == Max)
	{
		cout << "����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		cout << "�������Ա�" << endl;
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
		cout << "����������" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

void showAddressbooks(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��¼Ϊ��" << endl;
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
		cout << "���޴���" << endl;
	}
	else
	{
		for (int i = exist; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
}

void modifyPerson(Addressbooks* abs, string name) {
	int exist = selectPerson(abs, name);
	if (exist == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "�޸�����" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
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
			cout << "����������" << endl;
			cin >> name;
			deletePerson(&abs, name);
		}
			break;
		case 4:
		{
			string name;
			cout << "����������" << endl;
			cin >> name;
			int res = selectPerson(&abs, name);
			if (res == -1)
			{
				cout << "���޴���" << endl;
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
			cout << "����������" << endl;
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




