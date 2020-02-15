#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "CN2.h"
#include "CN3.h"
#include "CN4.h"
#include "CN5.h"
using namespace std;
int QSBook(note* &start, note* &end)
{
	note* p;
	ifstream fi;
	fi.open("Book.txt");
	int S = 0;
	for (p = start;p != NULL;p = p->Next)
	{
		int k = StoI(p->Data.num);
		S = S + k;
	}
	return S;
}

int QSBookbykind(note* &start, note* &end, string x)
{
	note* p;
	ifstream fi;
	fi.open("Book.txt");
	int S = 0;
	for (p = start;p != NULL;p = p->Next)
	{
		if (p->Data.kind == x)
		{
			int k = StoI(p->Data.num);
			S = S + k;
		}
	}
	return S;
}

int QSReader(nod* &head, nod* &tail)
{
	nod* p;
	ifstream fi;
	fi.open("Reader.txt");
	int S = 0;
	for (p = head;p != NULL;p = p->next)
		S++;
	return S;
}

int QSReaderbysex(nod* &head, nod* &tail, string x)
{
	nod* p;
	ifstream fi;
	fi.open("Reader.txt");
	int S = 0;
	for (p = head;p != NULL;p = p->next)
	{
		if (p->dta.gt == x)
			S++;
	}
	return S;
}

int QSBorrow(NODE* &HEAD, NODE* &TAIL)
{
	NODE* p;
	ifstream fi;
	fi.open("Borrow.txt");
	int S = 0;
	for (p = HEAD;p != NULL;p = p->NEXT)
	{
		int k = 0;
		int n = StoI(p->key.tongsach);
		for (int i = 0;i < n;i++)
		{
			int t = StoI(p->key.sl[i]);
			k = k + t;
		}
		S = S + k;
	}
	return S;
}

void QSDelay(no* &H, no* &T)
{
	no* p;
	ifstream fi;
	fi.open("Delay.txt");
	for (p = H;p != NULL;p = p->Next)
	{
		cout << "\tMa doc gia: " << p->k.docgia << endl;
		cout << "\tHo ten: " << p->k.ten << ", So ngay tre: " << p->k.songay << endl;
		cout << endl;
	}
	fi.ignore();
	fi.close();
}

void Menu_six(note* &start, note* &end, nod* &head, nod* &tail, NODE* &HEAD, NODE* &TAIL, no* &H, no* &T)
{
	int n;
	cout << "\t\t\tCAC THONG KE CO BAN" << endl;
	cout << "\t\t1-Thong ke so luong sach trong thu vien" << endl << "\t\t2-Thong ke so luong sach theo the loai" << endl << "\t\t3-Thong ke so luong doc gia" << endl << "\t\t4-Thong ke so luong doc gia theo gioi tinh" << endl << "\t\t5-Thong ke so sach dang duoc muon" << endl << "\t\t6-Thong ke danh sach doc gia bi tre han" << endl;
	cout << "Nhap ma so thong ke (nhap 0 de thoat): ";
	cin >> n;
	switch (n)
	{
	case 0:
	{
		exit(0);
		break;
	}
	case 1:
	{
		int t1;
		t1 = QSBook(start, end);
		cout << "\tSo luong sach trong thu vien la: " << t1 << " quyen" << endl;
		system("pause");
		break;
	}
	case 2:
	{
		int t2;
		string x;
		cin.ignore();
		cout << "\tNhap the loai sach: ";
		getline(cin, x);
		t2 = QSBookbykind(start, end, x);
		cout << "\tSo luong sach theo the loai " << x << " la: " << t2 << " quyen" << endl;
		system("pause");
		break;
	}
	case 3:
	{
		int t3;
		t3 = QSReader(head, tail);
		cout << "\tSo luong doc gia la: " << t3 << " nguoi" << endl;
		system("pause");
		break;
	}
	case 4:
	{
		int t4;
		string x;
		cin.ignore();
		cout << "\tNhap gioi tinh: ";
		getline(cin, x);
		t4 = QSReaderbysex(head, tail, x);
		cout << "\tSo luong doc gia theo the gioi tinh " << x << " la: " << t4 << " nguoi" << endl;
		system("pause");
		break;
	}
	case 5:
	{
		int t5;
		t5 = QSBorrow(HEAD, TAIL);
		cout << "\tSo so sach dang duoc muon la: " << t5 << " quyen" << endl;
		system("pause");
		break;
	}
	case 6:
	{
		cout << "\tDanh sach doc gia bi tre han: " << endl;
		QSDelay(H, T);
		system("pause");
		break;
	}
	default:
		break;
	}
	system("cls");
	//Menu_six(H1, T1, H2, T2, H3, T3, H4, T4);
}
