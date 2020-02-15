#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "CN2.h"
using namespace std;
typedef struct {
	string madocgia;
	string tendocgia;
	string dmuon, mmuon, ymuon;
	string dtradk, mtradk, ytradk;
	string dtt, mtt, ytt;
	string tongsach;
	string masach[100];
	string sl[100];
}bcard;
typedef struct NODE
{
	bcard key;
	struct NODE* NEXT;
};

NODE* getcard(bcard a)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->key = a;
	p->NEXT = NULL;
	return p;
}

void AddLast(NODE* &HEAD, NODE* &TAIL, NODE* p)
{
	if (HEAD == NULL)
		HEAD = TAIL = p;
	else {
		TAIL->NEXT = p;
		TAIL = p;
	}
}

void readborrow(NODE* &HEAD, NODE* &TAIL, bcard &x, NODE* p, ifstream &fi, ofstream &fo)
{
	fi.open("Borrow.txt");
	while (fi.eof() == false)
	{
		getline(fi, x.madocgia, ' ');
		if (x.madocgia == "")
			break;
		getline(fi, x.dmuon, '/');
		getline(fi, x.mmuon, '/');
		getline(fi, x.ymuon, ',');
		getline(fi, x.dtradk, '/');
		getline(fi, x.mtradk, '/');
		getline(fi, x.ytradk, ',');
		getline(fi, x.dtt, '/');
		getline(fi, x.mtt, '/');
		getline(fi, x.ytt, ',');
		getline(fi, x.tongsach, ',');
		int n = StoI(x.tongsach);
		for (int i = 0;i < n;i++)
		{
			if (i == n - 1)
			{
				getline(fi, x.masach[i], '-');
				getline(fi, x.sl[i]);
				break;
			}
			getline(fi, x.masach[i], '-');
			getline(fi, x.sl[i], '/');
		}
		p = getcard(x);
		AddLast(HEAD, TAIL, p);
	}
	fi.ignore();
	fi.close();
}

void addmuonsach(NODE* &HEAD, NODE* &TAIL)
{
	NODE* p;
	bcard a;
	cin.ignore();
	cout << "Ma doc gia: ";
	cin >> a.madocgia;
	cout << "Ngay/thang/nam muon sach: ";
	cin >> a.dmuon >> a.mmuon >> a.ymuon;
	cout << "Ngay/thang/nam tra du kien: ";
	cin >> a.dtradk >> a.mtradk >> a.ytradk;
	cout << "Ngay/thang/nam tra thuc te: ";
	cin >> a.dtt >> a.mtt >> a.ytt;
	cout << "Nhap so sach muon: ";
	cin >> a.tongsach;
	int n = StoI(a.tongsach);
	cin.ignore();
	for (int i = 0;i<n;i++)
	{
		cout << "Ma sach muon: ";
		getline(cin, a.masach[i]);
		cout << "So luong: ";
		getline(cin, a.sl[i]);
	}
	p = getcard(a);
	AddLast(HEAD, TAIL, p);
	ofstream fo;
	fo.open("Borrow.txt");
	for (NODE* q = HEAD; q != NULL; q = q->NEXT)
	{
		fo << q->key.madocgia << " " << q->key.dmuon << "/" << q->key.mmuon << "/" << q->key.ymuon << "," << q->key.dtradk << "/" << q->key.mtradk << "/" << q->key.ytradk << "," << q->key.dtt << "/" << q->key.mtt << "/" << q->key.ytt << "," << q->key.tongsach << ",";
		int n = StoI(q->key.tongsach);
		for (int i = 0;i < n;i++)
		{
			if (i == n - 1)
			{
				fo << q->key.masach[i] << "-" << q->key.sl[i] << endl;
				break;
			}
			fo << q->key.masach[i] << "-" << q->key.sl[i] << "/";
		}
	}
	fo.close();
	system("pause");
	system("cls");
}

void showborrow(NODE* &HEAD, NODE* &TAIL, NODE* p)
{
	bcard a;
	ifstream fi;
	fi.open("Borrow.txt");
	//cin.ignore();
	for (p = HEAD;p != NULL;p = p->NEXT)
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
		for (int i = 0;i < n;i++)
		{
			cout << "Ma cac sach muon: ";
			cout << p->key.masach[i] << endl;
			cout << "So luong moi loai: ";
			cout << p->key.sl[i] << endl;
		}
		//cin.ignore();
	}
	fi.ignore();
	fi.close();
	system("pause");
	system("cls");
}