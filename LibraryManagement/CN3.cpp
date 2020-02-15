#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;
typedef struct {
	string ISBN;
	string bname;
	string author;
	string nxb;
	string year;
	string kind;
	string value;
	string num;
}book;
typedef struct note
{
	book Data;
	struct note* Next;
};

note* getnote(book a)
{
	note* p = new note;
	if (p == NULL)
		return NULL;
	p->Data = a;
	p->Next = NULL;
	return p;
}

void Addtail(note* &start, note* &end, note* p)
{
	if (start == NULL)
		start = end = p;
	else {
		end->Next = p;
		end = p;
	}
}

void readbook(note* &start, note* &end, book &x, note* p, ifstream &fi, ofstream &fo)
{
	fi.open("Book.txt");
	while (fi.eof() == false)
	{
		getline(fi, x.ISBN, ' ');
		if (x.ISBN == "")
			break;
		getline(fi, x.bname, ',');
		getline(fi, x.nxb, ',');
		getline(fi, x.author, ',');
		getline(fi, x.year, ',');
		getline(fi, x.kind, ',');
		getline(fi, x.value, ',');
		getline(fi, x.num);
		p = getnote(x);
		Addtail(start, end, p);
	}
	fi.ignore();
	fi.close();
}

void showbook(note* &start, note* &end, note* p)
{
	book a;
	ifstream fi;
	fi.open("Book.txt");
	//cin.ignore();
	for (p = start;p != NULL;p = p->Next)
	{
		cout << "Ma sach: ";
		cout << p->Data.ISBN << endl;
		cout << "Ten sach: ";
		cout << p->Data.bname << endl;
		cout << "Nha xuat ban: ";
		cout << p->Data.nxb << endl;
		cout << "Tac gia: ";
		cout << p->Data.author << endl;
		cout << "Nam xuat ban: ";
		cout << p->Data.year << endl;
		cout << "Loai sach: ";
		cout << p->Data.kind << endl;
		cout << "Gia sach: ";
		cout << p->Data.value << endl;
		cout << "So sach: ";
		cout << p->Data.num << endl;
		cout << endl;
		//cin.ignore();
	}
	fi.ignore();
	fi.close();
}

void showabook(note* &start, note* &end, string isbn)
{
	note* p = new note;
	ifstream fi;
	fi.open("Book.txt");
	//cin.ignore();
	for (p = start;p != NULL;p = p->Next)
	{
		if (p->Data.ISBN == isbn)
		{
			cout << "Sach ban da chon: " << endl;
			cout << "Ma sach: ";
			cout << p->Data.ISBN << endl;
			cout << "Ten sach: ";
			cout << p->Data.bname << endl;
			cout << "Nha xuat ban: ";
			cout << p->Data.nxb << endl;
			cout << "Tac gia: ";
			cout << p->Data.author << endl;
			cout << "Nam xuat ban: ";
			cout << p->Data.year << endl;
			cout << "Loai sach: ";
			cout << p->Data.kind << endl;
			cout << "Gia sach: ";
			cout << p->Data.value << endl;
			cout << "So sach: ";
			cout << p->Data.num << endl;
			cout << endl;
		}
		//cin.ignore();
	}
	fi.ignore();
	fi.close();
}

bool checkbook(note* &start, string x)
{
	bool bl = false;
	for (note* q = start; q != NULL; q = q->Next)
		if (q->Data.ISBN == x)
		{
			bl = true;
			break;
		}
	return bl;
}
void addbook(note* &start, note* &end, book &x, note* p)
{
	bool bl = false;
	note* q;
	ifstream fi;
	fi.open("Book.txt");
	cin.ignore();
	cout << "Nhap ma sach: ";
	getline(cin, x.ISBN);
	bl = checkbook(start, x.ISBN);
	while (bl != false)
	{
		cout << "Ma sach da duoc dung. Hay thu lai!!!" << endl;
		cout << "Nhap ma sach: ";
		cin.ignore();
		getline(cin, x.ISBN);
		bl = checkbook(start, x.ISBN);
	}
	cout << "Ten sach: ";
	getline(cin, x.bname);
	cout << "Nha xuat ban: ";
	getline(cin, x.nxb);
	cout << "Tac gia: ";
	getline(cin, x.author);
	cout << "Nam xuat ban: ";
	getline(cin, x.year);
	cout << "Loai sach: ";
	getline(cin, x.kind);
	cout << "Gia sach: ";
	getline(cin, x.value);
	cout << "So sach: ";
	getline(cin, x.num);
	p = getnote(x);
	Addtail(start, end, p);
	cin.ignore();
	ofstream fo;
	fo.open("Book.txt");
	for (q = start; q; q = q->Next)
	{
		fo << q->Data.ISBN << " " << q->Data.bname << "," << q->Data.nxb << "," << q->Data.author << "," << q->Data.year << "," << q->Data.kind << "," << q->Data.value << "," << q->Data.num;
		if (q != end)
			fo << endl;
	}
	fi.ignore();
	fo.close();
	cout << "Them Thanh Cong!!!" << endl;
}

void Editbook(note* &start, note* &end, book c, string isbn, ifstream &fi, ofstream &fo)
{
	bool bl = false;
	string t;
	note* i;
	note* j;
	note* n = new note;
	int k;
	fi.open("Book.txt");
	cin.ignore();
	cout << "Nhap ma sach can chinh sua: ";
	getline(cin, isbn);
	//cin.ignore();
	for (note* i = start; i != NULL; i = i->Next)
	{
		if (isbn == i->Data.ISBN)
		{
			bl = true;
			break;
		}
	}
	if (bl == true)
	{
		note* p = new note;
		showabook(start, end, isbn);
		cout << "Ban muon chinh sua thong tin nao?" << endl;
		cout << "1. Ma sach" << endl << "2. Ten sach" << endl << "3. Nha xuat ban" << endl << "4. Ten tac gia" << endl << "5. Nam xuat ban" << endl << "6. Loai sach" << endl << "7. Gia sach" << endl << "8. So luong sach" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> k;
		cin.ignore();
		cout << "Nhap thong tin: ";
		getline(cin, t);
		for (i = start;i;i = i->Next)
		{
			if (isbn == i->Data.ISBN)
			{
				c.ISBN = i->Data.ISBN;
				c.bname = i->Data.bname;
				c.nxb = i->Data.nxb;
				c.author = i->Data.author;
				c.year = i->Data.year;
				c.kind = i->Data.kind;
				c.value = i->Data.value;
				c.num = i->Data.num;
				if (k == 1)
					c.ISBN = t;
				if (k == 2)
					c.bname = t;
				if (k == 3)
					c.nxb = t;
				if (k == 4)
					c.author = t;
				if (k == 5)
					c.year = t;
				if (k == 6)
					c.kind = t;
				if (k == 7)
					c.value = t;
				if (k == 8)
					c.num = t;
				n = getnote(c);
			}
			fo.open("Book.txt");
			for (j = start; j; j = j->Next)
			{
				if ((j->Data.ISBN) != isbn)
					fo << j->Data.ISBN << " " << j->Data.bname << "," << j->Data.nxb << "," << j->Data.author << "," << j->Data.year << "," << j->Data.kind << "," << j->Data.value << "," << j->Data.num;
				else
					fo << n->Data.ISBN << " " << n->Data.bname << "," << n->Data.nxb << "," << n->Data.author << "," << n->Data.year << "," << n->Data.kind << "," << n->Data.value << "," << n->Data.num;
				if (j != end)
					fo << endl;
			}
			fi.ignore();
			fo.close();
		}
		cout << "Thay Doi Thanh Cong!!!" << endl;
	}
	else
		cout << "Du Lieu Ban Nhap Khong Dung!!!" << endl;
}

void delbook(note* &start, note* &end, note* &p, ifstream &fi, ofstream &fo)
{
	bool bl = false;
	note* i;
	string t;
	fi.open("Book.txt");
	cin.ignore();
	cout << "Nhap ma sach can xoa: ";
	getline(cin, t);
	for (note* j = start; j != NULL; j = j->Next)
		if (j->Data.ISBN == t)
		{
			bl = true;
			break;
		}
	if (bl == true)
	{
		fo.open("Book.txt");
		for (note* q = start; q; q = q->Next)
		{
			if (q->Data.ISBN != t)
			{
				fo << q->Data.ISBN << " " << q->Data.bname << "," << q->Data.nxb << "," << q->Data.author << "," << q->Data.year << "," << q->Data.kind << "," << q->Data.value << "," << q->Data.num;
				if (q != end)
					fo << endl;
			}
		}
		fi.ignore();
		fo.close();
		cout << "Xoa Thanh Cong!!!" << endl;
	}
	else
		cout << "Du Lieu Ban Nhap Khong Dung!!!" << endl;
}

void SeekbookbyISBN(note* &start, note* &end, ifstream &fi, ofstream &fo)
{
	bool bl = false;
	string t;
	cin.ignore();
	cout << "Nhap ma sach: ";
	getline(cin, t);
	for (note* i = start;i != NULL;i = i->Next)
	{
		if (i->Data.ISBN == t)
		{
			bl = true;
			break;
		}
	}
	if (bl == true)
	{
		for (note* p = start; p != NULL; p = p->Next)
		{
			if (p->Data.ISBN == t)
			{
				cout << "Ma sach: ";
				cout << p->Data.ISBN << endl;
				cout << "Ten sach: ";
				cout << p->Data.bname << endl;
				cout << "Nha xuat ban: ";
				cout << p->Data.nxb << endl;
				cout << "Tac gia: ";
				cout << p->Data.author << endl;
				cout << "Nam xuat ban: ";
				cout << p->Data.year << endl;
				cout << "Loai sach: ";
				cout << p->Data.kind << endl;
				cout << "Gia sach: ";
				cout << p->Data.value << endl;
				cout << "So sach: ";
				cout << p->Data.num << endl;
				cout << endl;
				cin.ignore();
			}
		}
		fi.ignore();
		fi.close();
	}
	else
		cout << "Ma sach ban nhap khong trung khop!" << endl;
}

void Seekbookbyname(note* &start, note* &end, ifstream &fi, ofstream &fo)
{
	bool bl = false;
	string t;
	cin.ignore();
	cout << "Nhap ten sach: ";
	getline(cin, t);
	for (note* i = start;i != NULL;i = i->Next)
	{
		if (i->Data.bname == t)
		{
			bl = true;
			break;
		}
	}
	if (bl == true)
	{
		for (note* p = start; p != NULL; p = p->Next)
		{
			if (p->Data.bname == t)
			{
				cout << "Ma sach: ";
				cout << p->Data.ISBN << endl;
				cout << "Ten sach: ";
				cout << p->Data.bname << endl;
				cout << "Nha xuat ban: ";
				cout << p->Data.nxb << endl;
				cout << "Tac gia: ";
				cout << p->Data.author << endl;
				cout << "Nam xuat ban: ";
				cout << p->Data.year << endl;
				cout << "Loai sach: ";
				cout << p->Data.kind << endl;
				cout << "Gia sach: ";
				cout << p->Data.value << endl;
				cout << "So sach: ";
				cout << p->Data.num << endl;
				cout << endl;
				cin.ignore();
			}
		}
		fi.ignore();
		fi.close();
	}
	else
		cout << "Ten sach ban nhap khong trung khop!" << endl;
}

void Menu_three(note* &start, note* &end, note* &p, ifstream &fi, ofstream &fo)
{
	book a;
	string isbn;
	int k;
	cin.ignore();
	cout << "Menu" << endl;
	cout << "1. Xem danh sach cac sach" << endl << "2. Them sach" << endl << "3. Chinh sua thong tin sach" << endl << "4. Xoa thong tin mot quyen sach" << endl << "5. Tim kiem sach theo ma sach (ISBN)" << endl << "6. Tim kiem sach theo ten" << endl << "Nhan 0 de thoat!" << endl;
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
		showbook(start, end, p);
		system("pause");
		break;
	}
	case 2:
	{
		addbook(start, end, a, p);
		system("pause");
		break;
	}
	case 3:
	{
		Editbook(start, end, a, isbn, fi, fo);
		system("pause");
		break;
	}
	case 4:
	{
		delbook(start, end, p, fi, fo);
		system("pause");
		break;
	}
	case 5:
	{
		SeekbookbyISBN(start, end, fi, fo);
		system("pause");
		break;
	}
	case 6:
	{
		Seekbookbyname(start, end, fi, fo);
		system("pause");
		break;
	}
	default:
		break;
	}
	system("cls");
	//Menu_three(start, end, p, fi, fo);
}



