#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "CN2.h"
#include "CN3.h"
#include "CN4.h"
using namespace std;
string ItoS(int a)
{
	string s = to_string(a);
	return s;
}

typedef struct {
	string docgia;
	string ten;
	string songay;
}dlay;
typedef struct no
{
	dlay k;
	no* Next;
};

no* getdelay(dlay a)
{
	no* p = new no;
	if (p == NULL)
		return NULL;
	p->k = a;
	p->Next = NULL;
	return p;
}

void Adddelay(no* &H, no* &T, no* p)
{
	if (H == NULL)
		H = T = p;
	else {
		T->Next = p;
		T = p;
	}
}

void readdelay(no* &H, no* &T, dlay &x2, no* p2)
{
	ifstream fi;
	fi.open("Delay.txt");
	while (fi.eof() == false)
	{
		getline(fi, x2.docgia, ' ');
		getline(fi, x2.ten, ',');
		getline(fi, x2.songay);
		p2 = getdelay(x2);
		Adddelay(H, T, p2);
	}
	fi.ignore();
	fi.close();
}

void Addpaid(no* &H2, no* &T2, no* p)
{
	if (H2 == NULL)
		H2 = T2 = p;
	else {
		T2->Next = p;
		T2 = p;
	}
}

void readpaid(no* &H2, no* &T2, dlay &x3, no* p2)
{
	ifstream fi;
	fi.open("Paid.txt");
	while (fi.eof() == false)
	{
		getline(fi, x3.docgia, ' ');
		getline(fi, x3.ten);
		p2 = getdelay(x3);
		Addpaid(H2, T2, p2);
	}
	fi.ignore();
	fi.close();
}

void showpay(NODE* &HEAD, NODE* &TAIL, NODE* p)
{
	bcard a;
	ifstream fi;
	fi.open("Paid.txt");
	//cin.ignore();
	for (p = HEAD; p != NULL; p = p->NEXT)
	{
		cout << "Ma doc gia: ";
		cout << p->key.madocgia << endl;
		cout << "Ten doc gia: ";
		cout << p->key.tendocgia << endl;
	}
	fi.ignore();
	fi.close();
}

void showborr(NODE* &HEAD, NODE* &TAIL, string x)
{
	NODE* p;
	bcard a;
	ifstream fi;
	fi.open("Borrow.txt");
	//cin.ignore();
	for (p = HEAD; p != NULL; p = p->NEXT)
	{
		if (p->key.madocgia == x)
		{
			cout << "Ma doc gia: ";
			cout << p->key.madocgia << endl;
			cout << "Ngay muon: ";
			cout << p->key.dmuon << "/" << p->key.mmuon << "/" << p->key.ymuon << endl;
			cout << "Ngay tra du kien: ";
			cout << p->key.dtradk << "/" << p->key.mtradk << "/" << p->key.ytradk << endl;
			cout << "Ngay tra thuc te: ";
			cout << p->key.dtt << "/" << p->key.mtt << "/" << p->key.ytt << endl;
			cout << "Tong so sach muon: ";
			cout << p->key.tongsach << endl;
			int n = StoI(p->key.tongsach);
			for (int i = 0; i < n; i++)
			{
				cout << "Ma cac sach muon: ";
				cout << p->key.masach[i] << endl;
				cout << "So luong moi loai: ";
				cout << p->key.sl[i] << endl;
			}
		}
		//cin.ignore();
	}
	fi.ignore();
	fi.close();
}

int giasach(note* &start, note* &end, string x)
{
	note* p;
	ifstream fi;
	fi.open("Book.txt");
	for (p = start; p != NULL; p = p->Next)
	{
		if (p->Data.ISBN == x)
		{
			int t = StoI(p->Data.value);
			return t;
		}
	}
}

int SDay(int year, int month, int day) {
	if (month < 3) {
		year--;
		month += 12;
	}
	return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
}

void IN1(no* H, no* T)
{
	no* p;
	ofstream fo;
	fo.open("Delay.txt");
	for (p = H; p != NULL; p = p->Next)
	{
		fo << p->k.docgia << " " << p->k.ten << "," << p->k.songay;
		if (p != T)
			fo << endl;
	}
}

void IN2(no* H2, no* T2)
{
	no* p;
	ofstream fo;
	fo.open("Paid.txt");
	for (p = H2; p != NULL; p = p->Next)
	{
		fo << p->k.docgia << " " << p->k.ten;
		if (p != T2)
			fo << endl;
	}
}

void addpay(NODE* &HEAD, NODE* &TAIL, note* &start, note* &end, no* &H, no* &T, no* &H2, no* &T2)
{
	NODE* p;
	bcard a;
	string ss;
	bool kt = false;
	ifstream fi;
	fi.open("Borrow.txt");
	cout << "Ma doc gia: ";
	cin >> a.madocgia;
	cin.ignore();
	cout << "Ten doc gia: ";
	getline(cin, a.tendocgia);
	for (NODE* q = HEAD; q != NULL; q = q->NEXT)
	{
		if (q->key.madocgia == a.madocgia)
			kt = true;
	}
	if (kt = true)
	{
		dlay j;
		showborr(HEAD, TAIL, a.madocgia);
		cout << endl;
		cout << "Nhap thong tin tra sach: " << endl;
		//cin.ignore();
		cout << "Ngay muon sach: ";
		getline(cin, a.dmuon);
		cout << "Thang muon sach: ";
		getline(cin, a.mmuon);
		cout << "Nam muon sach: ";
		getline(cin, a.ymuon);
		cout << "Ngay tra du kien: ";
		getline(cin, a.dtradk);
		cout << "Thang tra du kien: ";
		getline(cin, a.mtradk);
		cout << "Nam tra du kien: ";
		getline(cin, a.ytradk);
		cout << "Ngay tra thuc te: ";
		getline(cin, a.dtt);
		cout << "Thang tra thuc te ";
		getline(cin, a.mtt);
		cout << "Nam tra thuc te: ";
		getline(cin, a.ytt);
		cin.ignore();
		int x1, x2, x3, y1, y2, y3;
		x1 = StoI(a.dmuon);
		x2 = StoI(a.mmuon);
		x3 = StoI(a.ymuon);
		y1 = StoI(a.dtt);
		y2 = StoI(a.mtt);
		y3 = StoI(a.ytt);
		int num = SDay(y3, y2, y1) - SDay(x3, x2, x1);
		if (num > 7)
		{
			cout << "Ban da tre han " << num - 7 << " ngay" << endl;
			cout << "Ban bi phat " << (num - 7) * 5000 << " dong" << endl;
			ss = ItoS(num - 7);
			j.docgia = a.madocgia;
			j.ten = a.tendocgia;
			j.songay = ss;
			no* q = getdelay(j);
			Adddelay(H, T, q);
			IN1(H, T);
		}
		else
			if (num <= 7)
			{
				j.docgia = a.madocgia;
				j.ten = a.tendocgia;
				no* q = getdelay(j);
				Addpaid(H2, T2, q);
				IN2(H2, T2);
			}
		cout << "Nhap so sach muon: ";
		cin >> a.tongsach;
		int n = StoI(a.tongsach);
		cin.ignore();
		for (int i = 0; i < n; i++)
		{
			cout << "Ma cac sach muon: ";
			getline(cin, a.masach[i]);
			cout << "So luong moi loai sach muon o tren: ";
			getline(cin, a.sl[i]);
			for (NODE* q = HEAD; q != NULL; q = q->NEXT)
			{
				if ((q->key.madocgia == a.madocgia) && (q->key.masach[i] == a.masach[i]))
				{
					int S = 0;
					int t1 = StoI(q->key.sl[i]);
					int t2 = StoI(a.sl[i]);
					if (t1 > t2)
					{
						int S = t1 - t2;
						cout << "Ban da lam mat " << S << " sach " << " co ma " << a.masach[i] << endl;
						int tien = giasach(start, end, a.masach[i]);
						cout << "So tien boi thuong la " << tien*S*2 << " dong" << endl;
						break;
					}
				}
			}
		}
	}
	system("pause");
	system("cls");
}