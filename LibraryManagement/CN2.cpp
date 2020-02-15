#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;
typedef struct {
	string id;
	string hoten;
	string cmnd;
	string d;
	string gt;
	string email;
	string diachi;
	string dlap, mlap, ylap;
	int  dhet, mhet, yhet;
}re;
typedef struct nod
{
	re dta;
	struct nod* next;
};

nod* get(re a)
{
	nod* p = new nod;
	if (p == NULL)
		return NULL;
	p->dta = a;
	p->next = NULL;
	return p;
}

int StoI(string a)
{
	int b = atoi(a.c_str());
	return b;
}

void addlas(nod* &head, nod* &tail, nod* p)
{
	if (head == NULL)
		head = tail = p;
	else {
		tail->next = p;
		tail = p;
	}
}

void adddayhet(nod* &head, nod* &tail)
{
	nod* p;
	int a, b, c;
	ifstream fi;
	fi.open("Reader.txt");
	for (p = head;p != NULL;p = p->next)
	{
		a = StoI(p->dta.dlap);
		b = StoI(p->dta.mlap);
		c = StoI(p->dta.ylap);
		c = c + 4;
		p->dta.dhet = a;
		p->dta.mhet = b;
		p->dta.yhet = c;
	}
}

void Reader(nod* &head, nod* &tail, re &a, nod* p, ifstream &fi, ofstream &fo)
{
	fi.open("Reader.txt");
	while (fi.eof() == false)
	{
		getline(fi, a.id, ' ');
		if (a.id == "")
			break;
		getline(fi, a.hoten, ',');
		getline(fi, a.cmnd, ',');
		getline(fi, a.d, ',');
		getline(fi, a.gt, ',');
		getline(fi, a.email, ',');
		getline(fi, a.diachi, ',');
		getline(fi, a.dlap, '/');
		getline(fi, a.mlap, '/');
		getline(fi, a.ylap);
		//getline(fi, a.dhet);
		//fi.ignore();
		p = get(a);
		addlas(head, tail, p);
	}
	//fi.ignore();
	fi.close();
}

void Readagain(nod* &head, nod* &tail, re a)
{
	nod* p;
	ifstream fi;
	fi.open("Reader.txt");
	while (fi.eof() == false)
	{
		getline(fi, a.id, ' ');
		if (a.id == "")
			break;
		getline(fi, a.hoten, ',');
		getline(fi, a.cmnd, ',');
		getline(fi, a.d, ',');
		getline(fi, a.gt, ',');
		getline(fi, a.email, ',');
		getline(fi, a.diachi, ',');
		getline(fi, a.dlap, '/');
		getline(fi, a.mlap, '/');
		getline(fi, a.ylap);
		//getline(fi, a.dhet);
		//fi.ignore();
		p = get(a);
		addlas(head, tail, p);
	}
	//fi.ignore();
	fi.close();
}

void adddayhetcmnd(nod* &head, nod* &tail, string x)
{
	nod* p;
	int a, b, c;
	ifstream fi;
	fi.open("Reader.txt");
	for (p = head;p != NULL; p = p->next)
	{
		if (p->dta.cmnd == x)
		{
			a = StoI(p->dta.dlap);
			b = StoI(p->dta.mlap);
			c = StoI(p->dta.ylap);
			c = c + 4;
			p->dta.dhet = a;
			p->dta.mhet = b;
			p->dta.yhet = c;
		}
	}
}

void adddayhethoten(nod* &head, nod* &tail, string x)
{
	nod* p;
	int a, b, c;
	ifstream fi;
	fi.open("Reader.txt");
	for (p = head;p != NULL; p = p->next)
	{
		if (p->dta.hoten == x)
		{
			a = StoI(p->dta.dlap);
			b = StoI(p->dta.mlap);
			c = StoI(p->dta.ylap);
			c = c + 4;
			p->dta.dhet = a;
			p->dta.mhet = b;
			p->dta.yhet = c;
		}
	}
}

void adddayhetonereader(nod* &head, nod* &tail, string ID)
{
	nod* p;
	int a, b, c;
	ifstream fi;
	fi.open("Reader.txt");
	for (p = head;p != NULL; p = p->next)
	{
		if (p->dta.id == ID)
		{
			a = StoI(p->dta.dlap);
			b = StoI(p->dta.mlap);
			c = StoI(p->dta.ylap);
			c = c + 4;
			p->dta.dhet = a;
			p->dta.mhet = b;
			p->dta.yhet = c;
		}
	}
}

void showreader(nod* &head, nod* &tail, nod* p)
{
	re a;
	ifstream fi;
	fi.open("Reader.txt");
	cin.ignore();
	adddayhet(head, tail);
	for (p = head;p != NULL;p = p->next)
	{
		cout << "Ma doc gia: ";
		cout << p->dta.id << endl;
		cout << "Ho ten: ";
		cout << p->dta.hoten << endl;
		cout << "CMND: ";
		cout << p->dta.cmnd << endl;
		cout << "Gioi tinh: ";
		cout << p->dta.gt << endl;
		cout << "Email: ";
		cout << p->dta.email << endl;
		cout << "Dia chi: ";
		cout << p->dta.diachi << endl;
		cout << "Ngay lap the: ";
		cout << p->dta.dlap << "/" << p->dta.mlap << "/" << p->dta.ylap << endl;
		cout << "Ngay het han: ";
		cout << p->dta.dhet << "/" << p->dta.mhet << "/" << p->dta.yhet << endl;
		cin.ignore();
	}
	fi.ignore();
	fi.close();
}

void showareader(nod* &head, nod* &tail, string x)
{
	nod* p = new nod;
	ifstream fi;
	fi.open("Reader.txt");
	cin.ignore();
	for (p = head;p != NULL;p = p->next)
	{
		if (p->dta.id == x)
		{
			cout << "Doc gia ban da chon: " << endl;
			cout << "Ma doc gia: ";
			cout << p->dta.id << endl;
			cout << "Ho ten: ";
			cout << p->dta.hoten << endl;
			cout << "CMND: ";
			cout << p->dta.cmnd << endl;
			cout << "Gioi tinh: ";
			cout << p->dta.gt << endl;
			cout << "Email: ";
			cout << p->dta.email << endl;
			cout << "Dia chi: ";
			cout << p->dta.diachi << endl;
			cout << "Ngay lap the: ";
			cout << p->dta.dlap << "/" << p->dta.mlap << "/" << p->dta.ylap << endl;
			cout << "Ngay het han: ";
			cout << p->dta.dhet << "/" << p->dta.mhet << "/" << p->dta.yhet << endl;
			cin.ignore();
		}
		//cin.ignore();
	}
	fi.ignore();
	fi.close();
}

bool checkreader(nod* &head, string x)
{
	bool bl = false;
	for (nod* q = head; q != NULL; q = q->next)
		if (q->dta.id == x)
		{
			bl = true;
			break;
		}
	return bl;
}

void addreader(nod* &head, nod* &tail, re &a, nod* p)
{
	bool bl = false;
	nod* q;
	ifstream fi;
	fi.open("Reader.txt");
	cin.ignore();
	cout << "Nhap ma doc gia: ";
	getline(cin, a.id);
	bl = checkreader(head, a.id);
	while (bl != false)
	{
		cout << "Ma doc gia da duoc dung. Hay thu lai!!!" << endl;
		cout << "Nhap ma doc gia: ";
		cin.ignore();
		getline(cin, a.id);
		bl = checkreader(head, a.id);
	}
	cout << "Ho ten: ";
	getline(cin, a.hoten);
	cout << "CMND: ";
	getline(cin, a.cmnd);
	cout << "Ngay sinh: ";
	getline(cin, a.d);
	cout << "Gioi tinh: ";
	getline(cin, a.gt);
	cout << "Email: ";
	getline(cin, a.email);
	cout << "Dia chi: ";
	getline(cin, a.diachi);
	cout << "Ngay lap the: ";
	getline(cin, a.dlap);
	cout << "Thang lap the: ";
	getline(cin, a.mlap);
	cout << "Nam lap the: ";
	getline(cin, a.ylap);
	p = get(a);
	addlas(head, tail, p);
	//adddayhetonereader(head, tail, p);
	cin.ignore();
	ofstream fo;
	fo.open("Reader.txt");
	for (q = head; q; q = q->next)
	{
		fo << q->dta.id << " " << q->dta.hoten << "," << q->dta.cmnd << "," << q->dta.d << "," << q->dta.gt << "," << q->dta.email << "," << q->dta.diachi << "," << q->dta.dlap << "/" << q->dta.mlap << "/" << q->dta.ylap; //"," << q->dta.dhet << "/" << q->dta.mhet << "/" << q->dta.yhet;
		if (q != tail)
			fo << endl;
	}
	cout << "Them doc gia thanh cong!!!" << endl;
	fi.ignore();
	fo.close();
}

void Editreader(nod* &head, nod* &tail, re c, string ID, ifstream &fi, ofstream &fo)
{
	bool bl = false;
	string t;
	nod* i;
	nod* j;
	nod* n = new nod;
	int k;
	fi.open("Reader.txt");
	fi.ignore();
	cin.ignore();
	//adddayhet(head, tail);
	cout << "Nhap ma doc gia can chinh sua: ";
	getline(cin, ID);
	for (nod* i = head; i != NULL; i = i->next)
	{
		if (ID == i->dta.id)
		{
			bl = true;
			break;
		}
	}
	if (bl == true)
	{
		adddayhetonereader(head, tail, ID);
		for (nod* p = head;p != NULL;p = p->next)
		{
			if (ID == p->dta.id)
			{
				cout << "Doc gia ban da chon: " << endl;
				cout << "Ma doc gia: ";
				cout << p->dta.id << endl;
				cout << "Ho ten: ";
				cout << p->dta.hoten << endl;
				cout << "CMND: ";
				cout << p->dta.cmnd << endl;
				cout << "Gioi tinh: ";
				cout << p->dta.gt << endl;
				cout << "Email: ";
				cout << p->dta.email << endl;
				cout << "Dia chi: ";
				cout << p->dta.diachi << endl;
				cout << "Ngay lap the: ";
				cout << p->dta.dlap << "/" << p->dta.mlap << "/" << p->dta.ylap << endl;
				cout << "Ngay het han: ";
				cout << p->dta.dhet << "/" << p->dta.mhet << "/" << p->dta.yhet << endl;
			}
		}
		//showareader(head, tail, ID);
		cout << "Ban muon chinh sua thong tin nao?" << endl;
		cout << "1. Ma doc gia" << endl << "2. Ho ten" << endl << "3. CMND" << endl << "4. Ngay sinh" << endl << "5. Gioi tinh" << endl << "6. Email" << endl << "7. Dia chi" << endl << "8. Ngay lap the" << endl << "9. Ngay het han" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> k;
		cin.ignore();
		for (i = head;i;i = i->next)
		{
			if (ID == i->dta.id)
			{
				c.id = i->dta.id;
				c.hoten = i->dta.hoten;
				c.cmnd = i->dta.cmnd;
				c.d = i->dta.d;
				c.gt = i->dta.gt;
				c.email = i->dta.email;
				c.diachi = i->dta.diachi;
				c.dlap = i->dta.dlap;
				c.mlap = i->dta.mlap;
				c.ylap = i->dta.ylap;
				c.dhet = i->dta.dhet;
				c.mhet = i->dta.mhet;
				c.yhet = i->dta.yhet;
				if (k == 1)
				{
					cout << "Nhap thong tin: ";
					getline(cin, t);
					c.id = t;
				}
				if (k == 2)
				{
					cout << "Nhap thong tin: ";
					getline(cin, t);
					c.hoten = t;
				}
				if (k == 3)
				{
					cout << "Nhap thong tin: ";
					getline(cin, t);
					c.cmnd = t;
				}
				if (k == 4)
				{
					cout << "Nhap thong tin: ";
					getline(cin, t);
					c.d = t;
				}
				if (k == 5)
				{
					cout << "Nhap thong tin: ";
					getline(cin, t);
					c.gt = t;
				}
				if (k == 6)
				{
					cout << "Nhap thong tin: ";
					getline(cin, t);
					c.email = t;
				}
				if (k == 7)
				{
					cout << "Nhap thong tin: ";
					getline(cin, t);
					c.diachi = t;
				}
				if (k == 8)
				{
					string aa, bb, cc;
					cout << "Nhap ngay lap: :";
					getline(cin, aa);
					cout << "Nhap thang lap:";
					getline(cin, bb);
					cout << "Nhap nam lap:";
					getline(cin, cc);
					c.dlap = aa;
					c.mlap = bb;
					c.ylap = cc;
				}
				if (k == 9)
				{
					int x, y, z;
					cout << "Nhap ngay het: :";
					cin >> x;
					cout << "Nhap thang het:";
					cin >> y;
					cout << "Nhap nam het:";
					cin >> z;
					c.dhet = x;
					c.mhet = y;
					c.yhet = z;
				}
				n = get(c);
			}
			fo.open("Reader.txt");
			for (j = head; j != NULL; j = j->next)
			{
				if ((j->dta.id) != ID)
					fo << j->dta.id << " " << j->dta.hoten << "," << j->dta.cmnd << "," << j->dta.d << "," << j->dta.gt << "," << j->dta.email << "," << j->dta.diachi << "," << j->dta.dlap << "/" << j->dta.mlap << "/" << j->dta.ylap;// << "," << j->dta.dhet << "/" << j->dta.mhet << "/" << j->dta.yhet;
				else
					fo << n->dta.id << " " << n->dta.hoten << "," << n->dta.cmnd << "," << n->dta.d << "," << n->dta.gt << "," << n->dta.email << "," << n->dta.diachi << "," << n->dta.dlap << "/" << n->dta.mlap << "/" << n->dta.ylap;// << "," << n->dta.dhet << "/" << n->dta.mhet << "/" << n->dta.yhet;
				if (j != tail)
					fo << endl;
			}
			fi.ignore();
			fo.close();
		}
		cout << "Thay doi thanh cong!!!" << endl;
	}
	else
		cout << "Ma doc gia ban nhap khong dung!!!" << endl;
}


void Delreader(nod* &head, nod* &tail, ifstream &fi, ofstream &fo)
{
	bool bl = false;
	nod* i;
	string t;
	fi.open("Reader.txt");
	cin.ignore();
	cout << "Nhap ma doc gia can xoa: ";
	getline(cin, t);
	for (nod* j = head; j != NULL; j = j->next)
		if (j->dta.id == t)
		{
			bl = true;
			break;
		}
	if (bl == true)
	{
		fo.open("Reader.txt");
		for (nod* q = head; q; q = q->next)
		{
			if (q->dta.id != t)
			{
				fo << q->dta.id << " " << q->dta.hoten << "," << q->dta.cmnd << "," << q->dta.d << "," << q->dta.gt << "," << q->dta.email << "," << q->dta.diachi << "," << q->dta.dlap << "/" << q->dta.mlap << "/" << q->dta.ylap;
				if (q != tail)
					fo << endl;
			}
		}
		fo.close();
		cout << "Xoa doc gia thanh cong!!!" << endl;
	}
	else
		cout << "Ma doc gia ban nhap khong dung!!!" << endl;
}

void Seekreaderbycmnd(nod* &head, nod* &tail, ifstream &fi, ofstream &fo)
{
	bool bl = false;
	string t;
	cin.ignore();
	cout << "Nhap CMND: ";
	getline(cin, t);
	for (nod* i = head;i != NULL;i = i->next)
	{
		if (i->dta.cmnd == t)
		{
			bl = true;
			break;
		}
	}
	if (bl == true)
	{
		for (nod* p = head; p != NULL; p = p->next)
		{
			if (p->dta.cmnd == t)
			{
				adddayhetcmnd(head, tail, p->dta.cmnd);
				cout << "Ma doc gia: ";
				cout << p->dta.id << endl;
				cout << "Ho ten: ";
				cout << p->dta.hoten << endl;
				cout << "CMND: ";
				cout << p->dta.cmnd << endl;
				cout << "Gioi tinh: ";
				cout << p->dta.gt << endl;
				cout << "Email: ";
				cout << p->dta.email << endl;
				cout << "Dia chi: ";
				cout << p->dta.diachi << endl;
				cout << "Ngay lap the: ";
				cout << p->dta.dlap << "/" << p->dta.mlap << "/" << p->dta.ylap << endl;
				cout << "Ngay het han: ";
				cout << p->dta.dhet << "/" << p->dta.mhet << "/" << p->dta.yhet << endl;
				cin.ignore();
			}
		}
		fi.ignore();
		fi.close();
	}
	else
		cout << "CMND ban nhap khong trung khop!" << endl;
}

void Seekreaderbyname(nod* &head, nod* &tail, ifstream &fi, ofstream &fo)
{
	bool bl = false;
	string t;
	cin.ignore();
	cout << "Nhap ho ten doc gia: ";
	getline(cin, t);
	for (nod* i = head;i != NULL;i = i->next)
	{
		if (i->dta.hoten == t)
		{
			bl = true;
			break;
		}
	}
	if (bl == true)
	{
		for (nod* p = head; p != NULL; p = p->next)
		{
			if (p->dta.hoten == t)
			{
				adddayhethoten(head, tail, p->dta.hoten);
				cout << "Ma doc gia: ";
				cout << p->dta.id << endl;
				cout << "Ho ten: ";
				cout << p->dta.hoten << endl;
				cout << "CMND: ";
				cout << p->dta.cmnd << endl;
				cout << "Gioi tinh: ";
				cout << p->dta.gt << endl;
				cout << "Email: ";
				cout << p->dta.email << endl;
				cout << "Dia chi: ";
				cout << p->dta.diachi << endl;
				cout << "Ngay lap the: ";
				cout << p->dta.dlap << "/" << p->dta.mlap << "/" << p->dta.ylap << endl;
				cout << "Ngay het han: ";
				cout << p->dta.dhet << "/" << p->dta.mhet << "/" << p->dta.yhet << endl;
				cin.ignore();
			}
		}
		fi.ignore();
		fi.close();
	}
	else
		cout << "Ten doc gia ban nhap khong ton tai!" << endl;
}


void Menu_two(nod* &head, nod* &tail, ifstream &fi, ofstream &fo, string &ID)
{
	re a;
	nod* u = new nod;
	int k;
	cout << "Menu" << endl;
	cout << "1. Xem danh sach doc gia" << endl << "2. Them doc gia" << endl << "3. Chinh sua thong tin doc gia" << endl << "4. Xoa thong tin mot doc gia" << endl << "5. Tim kiem doc gia theo CMND" << endl << "6. Tim kiem doc gia theo ten" << endl << "Nhan 0 de thoat!" << endl;
	cout << "Nhap lua chon cua ban: ";
	cin >> k;
	switch (k)
	{
	case 0:
	{
		exit(0);
		break;
	}
	case 1:
	{
		showreader(head, tail, u);
		system("pause");
		break;
	}
	case 2:
	{
		addreader(head, tail, a, u);
		system("pause");
		break;
	}
	case 3:
	{
		Editreader(head, tail, a, ID, fi, fo);
		system("pause");
		break;
	}
	case 4:
	{
		Delreader(head, tail, fi, fo);
		system("pause");
		break;
	}
	case 5:
	{
		Seekreaderbycmnd(head, tail, fi, fo);
		break;
	}
	case 6:
	{
		Seekreaderbyname(head, tail, fi, fo);
		system("pause");
		break;
	}
	default:
		break;
	}
	system("cls");
	//Menu_two(head, tail, fi, fo, ID);
}
