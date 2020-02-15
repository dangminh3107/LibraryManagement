#include "stdafx.h"
#include "string"
#include "fstream"
#include "iostream"
#include "stdlib.h"
#include "CN1.h"
#include "CN2.h"
#include "CN3.h"
#include "CN4.h"
#include "CN5.h"
#include "CN6.h"
using namespace std;

void MENU(node* &pHead, node* &pTail, nod* &head, nod* &tail, note* &start, note* &end, NODE* &HEAD, NODE* &TAIL, node* &headstaff, node* &tailstaff, node* &headmag, node* &tailmag, no* &H, no* &T, no* &H2, no* &T2, ifstream &fi, ofstream &fo, note* p)
{
	string ID;
	int n;
	cout << "\tBan la Admin" << endl;
	cout << "\tCAC CHUC NANG" << endl;
	cout << "\t1.Quan ly nguoi dung" << endl;
	cout << "\t2.Quan ly doc gia" << endl;
	cout << "\t3.Quan ly sach" << endl;
	cout << "\t4.Lap phieu muon sach" << endl;
	cout << "\t5.Lap phieu tra sach" << endl;
	cout << "\t6.Cac thong ke co ban" << endl;
	cout << "\t0.Thoat" << endl;
	cout << "Nhap ma chuc nang: ";
	cin >> n;
	switch (n)
	{
	case 0:
		exit(0);
	case 1:
	{
		Menu_one(pHead, pTail, headstaff, tailstaff, headmag, tailmag);
		MENU(pHead, pTail, head, tail, start, end, HEAD, TAIL, headstaff, tailstaff, headmag, tailmag, H, T, H2, T2, fi, fo, p);
	}
	case 2:
	{
		Menu_two(head, tail, fi, fo, ID);
		MENU(pHead, pTail, head, tail, start, end, HEAD, TAIL, headstaff, tailstaff, headmag, tailmag, H, T, H2, T2, fi, fo, p);
	}
	case 3:
	{
		Menu_three(start, end, p, fi, fo);
		MENU(pHead, pTail, head, tail, start, end, HEAD, TAIL, headstaff, tailstaff, headmag, tailmag, H, T, H2, T2, fi, fo, p);
	}
	case 4:
	{
		int k;
		NODE* pk = new NODE;
		cout << "Nhap 0 de xem danh sach muon sach" << endl;
		cout << "Nhap 1 de lap phieu muon sach" << endl;
		cin >> k;
		if (k == 0)
			showborrow(HEAD, TAIL, pk);
		else
			if (k == 1)
				addmuonsach(HEAD, TAIL);
		MENU(pHead, pTail, head, tail, start, end, HEAD, TAIL, headstaff, tailstaff, headmag, tailmag, H, T, H2, T2, fi, fo, p);
	}
	case 5:
	{
		addpay(HEAD, TAIL, start, end, H, T, H2, T2);
		MENU(pHead, pTail, head, tail, start, end, HEAD, TAIL, headstaff, tailstaff, headmag, tailmag, H, T, H2, T2, fi, fo, p);
	}
	case 6:
	{
		Menu_six(start, end, head, tail, HEAD, TAIL, H, T);
		MENU(pHead, pTail, head, tail, start, end, HEAD, TAIL, headstaff, tailstaff, headmag, tailmag, H, T, H2, T2, fi, fo, p);
	}
	default:
		break;
	}
	system("cls");
}

void Menu_Staff(node* &headstaff, node* &tailstaff, nod* &head, nod* &tail, note* &start, note* &end, NODE* &HEAD, NODE* &TAIL, no* &H, no* &T, no* &H2, no* &T2, ifstream &fi, ofstream &fo)
{
	int n;
	cout << "\tBan la Chuyen Vien" << endl;
	cout << "\tMENU STAFF" << endl;
	cout << "\t1.Dang xuat" << endl;
	cout << "\t2.Doi mat khau" << endl;
	cout << "\t3.Cap nhat thong tin ca nhan Staff" << endl;
	cout << "\t4.Xem danh sach doc gia trong thu vien" << endl;
	cout << "\t5.Them doc gia" << endl;
	cout << "\t6.Chinh sua thong tin doc gia" << endl;
	cout << "\t7.Tim kiem doc gia theo CMND" << endl;
	cout << "\t8.Tim kiem doc gia theo ten" << endl;
	cout << "\t9.Tim kiem sach theo ISBN" << endl;
	cout << "\t10.Tim kiem sach theo ten sach" << endl;
	cout << "\t11.Lap phieu muon sach" << endl;
	cout << "\t12.Lap phieu tra sach" << endl;
	cout << "Nhap ma lua chon: ";
	cin >> n;
	switch (n)
	{
	case 1:
	{
		Logout();
		break;
	}
	case 2:
	{
		ChangePassStaff(headstaff, tailstaff);
		system("pause");
		break;
	}
	case 3:
	{
		EditStaff(headstaff, tailstaff);
		system("pause");
		break;
	}
	case 4:
	{
		nod* p = new nod;
		showreader(head, tail, p);
		system("pause");
		break;
	}
	case 5:
	{
		re a;
		nod* p = new nod;
		addreader(head, tail, a, p);
		system("pause");
		break;
	}
	case 6:
	{
		re a;
		string ID;
		Editreader(head, tail, a, ID, fi, fo);
		system("pause");
		break;
	}
	case 7:
	{
		Seekreaderbycmnd(head, tail, fi, fo);
		break;
	}
	case 8:
	{
		Seekreaderbyname(head, tail, fi, fo);
		break;
	}
	case 9:
	{
		SeekbookbyISBN(start, end, fi, fo);
		break;
	}
	case 10:
	{
		Seekbookbyname(start, end, fi, fo);
		break;
	}
	case 11:
	{
		addmuonsach(HEAD, TAIL);
		break;
	}
	case 12:
	{
		addpay(HEAD, TAIL, start, end, H, T, H2, T2);
		break;
	}
	default:
		break;
	}
	system("cls");
	Menu_Staff(headstaff, tailstaff, head, tail, start, end, HEAD, TAIL, H, T, H2, T2, fi, fo);
}

void Menu_Manager(node* &headmag, node* &tailmag, nod* &head, nod* &tail, note* &start, note* &end, NODE* &HEAD, NODE* &TAIL, no* &H, no* &T, no* &H2, no* &T2, ifstream &fi, ofstream &fo, note *p)
{
	int n;
	cout << "\tBan la Quan Ly" << endl;
	cout << "\tMENU MANAGER" << endl;
	cout << "\t1.Dang xuat" << endl;
	cout << "\t2.Doi mat khau" << endl;
	cout << "\t3.Cap nhat thong tin ca nhan Manager" << endl;
	cout << "\t4.Quan ly doc gia" << endl;
	cout << "\t5.Quan ly sach" << endl;
	cout << "\t6.Lap phieu muon sach" << endl;
	cout << "\t7.Lap phieu tra sach" << endl;
	cout << "\t8.Cac thong ke co ban" << endl;
	cout << "Nhap ma lua chon: ";
	cin >> n;
	switch (n)
	{
	case 1:
	{
		Logout();
		break;
	}
	case 2:
	{
		ChangePassManage(headmag, tailmag);
		system("pause");
		break;
	}
	case 3:
	{
		EditManage(headmag, tailmag);
		system("pause");
		break;
	}
	case 4:
	{
		string ID;
		Menu_two(head, tail, fi, fo, ID);
		system("pause");
		break;
	}
	case 5:
	{
		Menu_three(start, end, p, fi, fo);
		system("pause");
		break;
	}
	case 6:
	{
		addmuonsach(HEAD, TAIL);
		system("pause");
		break;
	}
	case 7:
	{
		addpay(HEAD, TAIL, start, end, H, T, H2, T2);
		system("pause");
		break;
	}
	case 8:
	{
		Menu_six(start, end, head, tail, HEAD, TAIL, H, T);
		break;
	}
	default:
		break;
	}
	system("cls");
	Menu_Manager(headmag, tailmag, head, tail, start, end, HEAD, TAIL, H, T, H2, T2, fi, fo, p);
}

void LOG(NODE* &HEAD, NODE* &TAIL, node* &pHead, node* &pTail, node* &headstaff, node* &tailstaff, node* &headmag, node* &tailmag, note* &start, note* &end, nod* &head, nod* &tail, no* &H, no* &T, no* &H2, no* &T2, ifstream &fi, ofstream &fo, note* p3)
{
	int kt;
	kt = Login(pHead, headstaff, headmag);
	if (kt == 0)
	{
		cout << "\tDang nhap thanh cong!!!" << endl;
		MENU(pHead, pTail, head, tail, start, end, HEAD, TAIL, headstaff, tailstaff, headmag, tailmag, H, T, H2, T2, fi, fo, p3);
	}
	else
	{
		if (kt == 1)
		{
			cout << "\tDang nhap thanh cong!!!" << endl;
			Menu_Staff(headstaff, tailstaff, head, tail, start, end, HEAD, TAIL, H, T, H2, T2, fi, fo);
		}
		else
		{
			if (kt == 2)
			{
				cout << "\tDang nhap thanh cong!!!" << endl;
				Menu_Manager(headmag, tailmag, head, tail, start, end, HEAD, TAIL, H, T, H2, T2, fi, fo, p3);
			}
			else
				if ((kt == -1) || (kt == -2) || (kt == -3))
				{
					cout << "\tSai ten tai khoan hoac mat khau!!!" << endl;
					LOG(HEAD, TAIL, pHead, pTail, headstaff, tailstaff, headmag, tailmag, start, end, head, tail, H, T, H2, T2, fi, fo, p3);
				}
		}
	}
}

void LOG_cmd(NODE* &HEAD, NODE* &TAIL, node* &pHead, node* &pTail, node* &headstaff, node* &tailstaff, node* &headmag, node* &tailmag, note* &start, note* &end, nod* &head, nod* &tail, no* &H, no* &T, no* &H2, no* &T2, ifstream &fi, ofstream &fo, note* p3, string user, string pass)
{
	int kt;
	kt = Login_cmd(pHead, headstaff, headmag, user, pass);
	if (kt == 0)
	{
		cout << "\tDang nhap thanh cong!!!" << endl;
		MENU(pHead, pTail, head, tail, start, end, HEAD, TAIL, headstaff, tailstaff, headmag, tailmag, H, T, H2, T2, fi, fo, p3);
	}
	else
	{
		if (kt == 1)
		{
			cout << "\tDang nhap thanh cong!!!" << endl;
			Menu_Staff(headstaff, tailstaff, head, tail, start, end, HEAD, TAIL, H, T, H2, T2, fi, fo);
		}
		else
		{
			if (kt == 2)
			{
				cout << "\tDang nhap thanh cong!!!" << endl;
				Menu_Manager(headmag, tailmag, head, tail, start, end, HEAD, TAIL, H, T, H2, T2, fi, fo, p3);
			}
			else
				if ((kt == -1) || (kt == -2) || (kt == -3))
				{
					cout << "\tSai ten tai khoan hoac mat khau!!!" << endl;
					LOG(HEAD, TAIL, pHead, pTail, headstaff, tailstaff, headmag, tailmag, start, end, head, tail, H, T, H2, T2, fi, fo, p3);
				}
		}
	}
}


char * wchar_to_string(_TCHAR* widechar)
{
	int size = 0;
	while ((char)widechar[size] != '\0') {
		size++;
	}
	size++; char * charpointer = new char[size];
	wcstombs(charpointer, widechar, size);
	return charpointer;
}

int _tmain(int argc, TCHAR* argv[])
{
	no* H = NULL;
	no* T = NULL;
	no* H2 = NULL;
	no* T2 = NULL;
	no* p5 = new no;
	no* p6 = new no;
	NODE* HEAD = NULL;
	NODE* TAIL = NULL;
	NODE* p4 = new NODE;
	note* start = NULL;
	note* end = NULL;
	note* p3 = new note;
	nod* head = NULL;
	nod* tail = NULL;
	nod* p2 = new nod;
	node* pHead = NULL;
	node* pTail = NULL;
	node* headstaff = NULL;
	node* tailstaff = NULL;
	node* headmag = NULL;
	node* tailmag = NULL;
	node* pp1 = new node;
	node* pp2 = new node;
	node* pp3 = new node;
	ifstream fi;
	ofstream fo;
	re a1, c;
	bcard a2;
	book x;
	dlay x2, x3;

	//Lay du lieu
	scan(pHead, pTail, pp1);
	scanstaff(headstaff, tailstaff, pp2);
	scanmanage(headmag, tailmag, pp3);
	Reader(head, tail, a1, p2, fi, fo);
	readbook(start, end, x, p3, fi, fo);
	readborrow(HEAD, TAIL, a2, p4, fi, fo);
	readpaid(H2, T2, x3, p6);
	readdelay(H, T, x2, p5);

	//Xu li tham so dong lenh
	if (argc == 3)
	{
		//Xu li chuong trinh co tham so dau vao
		string username = wchar_to_string(argv[1]);
		string password = wchar_to_string(argv[2]);

		LOG_cmd(HEAD, TAIL, pHead, pTail, headstaff, tailstaff, headmag, tailmag, start, end, head, tail, H, T, H2, T2, fi, fo, p3, username, password);
	}
	else
	{
		//Xu li chuong trinh khong tham so dau vao
		LOG(HEAD, TAIL, pHead, pTail, headstaff, tailstaff, headmag, tailmag, start, end, head, tail, H, T, H2, T2, fi, fo, p3);
	}


	return 0;
}