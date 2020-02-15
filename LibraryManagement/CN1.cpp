#include "stdafx.h"
#include "string"
#include "fstream"
#include "iostream"
#include "stdlib.h"
using namespace std;

typedef struct {
	string Name;
	string UName;
	string pass;
	string dd;
	string ic;
	string addr;
	string sex;
	string status;
}Us;

typedef struct node
{
	Us data;
	struct node* pnext;
};

node* getnode(Us a)
{
	node* p = new node;
	if (p == NULL)
		return NULL;
	p->data = a;
	p->pnext = NULL;
	return p;
}
void addlast(node* &pHead, node* &pTail, node* p)
{
	if (pHead == NULL)
		pHead = pTail = p;
	else {
		pTail->pnext = p;
		pTail = p;
	}
}
void scan(node* &pHead, node* &pTail, node* p)
{
	Us man;
	ifstream fi;
	fi.open("Admin.txt", ios::in);
	while (!fi.eof())
	{
		getline(fi, man.UName, ' ');
		if (man.UName == "")
			break;
		getline(fi, man.pass, ',');
		getline(fi, man.Name, ',');
		getline(fi, man.dd, ',');
		getline(fi, man.ic, ',');
		getline(fi, man.addr, ',');
		getline(fi, man.sex, ',');
		getline(fi, man.status);
		p = getnode(man);
		addlast(pHead, pTail, p);
	}
	fi.ignore();
	fi.close();
}
void addlaststaff(node* &headstaff, node* &tailstaff, node* p)
{
	if (headstaff == NULL)
		headstaff = tailstaff = p;
	else {
		tailstaff->pnext = p;
		tailstaff = p;
	}
}

void scanstaff(node* &headstaff, node* &tailstaff, node* p)
{
	Us man;
	ifstream fi;
	fi.open("Staff.txt", ios::in);
	while (!fi.eof())
	{
		getline(fi, man.UName, ' ');
		if (man.UName == "")
			break;
		getline(fi, man.pass, ',');
		getline(fi, man.Name, ',');
		getline(fi, man.dd, ',');
		getline(fi, man.ic, ',');
		getline(fi, man.addr, ',');
		getline(fi, man.sex, ',');
		getline(fi, man.status);
		p = getnode(man);
		addlaststaff(headstaff, tailstaff, p);
	}
	fi.ignore();
	fi.close();
}

void addlastmanage(node* &headmag, node* &tailmag, node* p)
{
	if (headmag == NULL)
		headmag = tailmag = p;
	else {
		tailmag->pnext = p;
		tailmag = p;
	}
}

void scanmanage(node* &headmag, node* &tailmag, node* p)
{
	Us man;
	ifstream fi;
	fi.open("Manager.txt", ios::in);
	while (!fi.eof())
	{
		getline(fi, man.UName, ' ');
		if (man.UName == "")
			break;
		getline(fi, man.pass, ',');
		getline(fi, man.Name, ',');
		getline(fi, man.dd, ',');
		getline(fi, man.ic, ',');
		getline(fi, man.addr, ',');
		getline(fi, man.sex, ',');
		getline(fi, man.status);
		p = getnode(man);
		addlastmanage(headmag, tailmag, p);
	}
	fi.ignore();
	fi.close();
}

bool checkstaff(node* &headstaff, string a, string b)
{
	bool kt = false;
	node* p;
	ifstream fi;
	fi.open("Staff.txt");
	for (p = headstaff;p != NULL;p = p->pnext)
	{
		if (p->data.UName == a)
		{
			if (p->data.pass == b)
			{
				return true;
				break;
			}
		}
	}
	return kt;
}

bool checkadmin(node* &pHead, string a, string b)
{
	bool kt = false;
	node* p;
	ifstream fi;
	fi.open("Admin.txt");
	for (p = pHead;p != NULL;p = p->pnext)
	{
		if (p->data.UName == a)
		{
			if (p->data.pass == b)
			{
				return true;
				break;
			}
		}
	}
	return kt;
}

bool checkmanage(node* &headmag, string a, string b)
{
	bool kt = false;
	node* p;
	ifstream fi;
	fi.open("Manager.txt");
	for (p = headmag;p != NULL;p = p->pnext)
	{
		if (p->data.UName == a)
		{
			if (p->data.pass == b)
			{
				return true;
				break;
			}
		}
	}
	return kt;
}

int Login(node* &pHead, node* &headstaff, node* &headmag)
{
	bool kt;
	int d;
	node* p = pHead;
	string t1, t2;
	cout << "Tai khoan: ";
	getline(cin, t1);
	cout << "Mat khau: ";
	getline(cin, t2);
	cin.ignore();
	if (checkadmin(pHead, t1, t2) == true)
		d = 0;
	else
	{
		if (checkadmin(pHead, t1, t2) == false)
		{
			if (checkstaff(headstaff, t1, t2) == true)
				d = 1;
			else
			{
				if (checkstaff(headstaff, t1, t2) == false)
				{
					if (checkmanage(headmag, t1, t2) == true)
						d = 2;
					else
						if (checkmanage(headmag, t1, t2) == false)
						{
							d = -1;
						}
				}
			}
		}
	}

	return d; // Tra ve vai tro nguoi dung
}

int Login_cmd(node* &pHead, node* &headstaff, node* &headmag, string user, string pass)
{
	bool kt;
	int d;
	node* p = pHead;
	string t1 = user;
	string t2 = pass;
	if (checkadmin(pHead, t1, t2) == true)
		d = 0;
	else
	{
		if (checkadmin(pHead, t1, t2) == false)
		{
			if (checkstaff(headstaff, t1, t2) == true)
				d = 1;
			else
			{
				if (checkstaff(headstaff, t1, t2) == false)
				{
					if (checkmanage(headmag, t1, t2) == true)
						d = 2;
					else
						if (checkmanage(headmag, t1, t2) == false)
						{
							d = -1;
						}
				}
			}
		}
	}

	return d; // Tra ve vai tro nguoi dung
}

void ChangePass(node* &pHead, node* &pTail)
{
	string t1, t2;
	node* p;
	node* q;
	printf("Mat khau cu: ");
	cin >> t1;
	printf("Mat khau moi: ");
	cin >> t2;
	ifstream fi;
	fi.open("Admin.txt");
	for (p = pHead;p != NULL;p = p->pnext)
	{
		if (t1 == p->data.pass)
		{
			p->data.pass = t2;
			break;
		}
	}
	fi.close();
	ofstream fo;
	fo.open("Admin.txt");
	for (q = pHead;q != NULL;q = q->pnext)
	{
		fo << q->data.UName << " " << q->data.pass << "," << q->data.Name << "," << q->data.dd << "," << q->data.ic << "," << q->data.addr << "," << q->data.sex << "," << q->data.status;
		if (q != pTail)
			fo << endl;
	}
	fi.ignore();
	cout << "Doi mat khau thanh cong!" << endl;
	fo.close();
}

void ChangePassStaff(node* &headstaff, node* &tailstaff)
{
	string t1, t2;
	node* p;
	node* q;
	printf("Mat khau cu: ");
	cin >> t1;
	printf("Mat khau moi: ");
	cin >> t2;
	ifstream fi;
	fi.open("Staff.txt");
	for (p = headstaff;p != NULL;p = p->pnext)
	{
		if (t1 == p->data.pass)
		{
			p->data.pass = t2;
			break;
		}
	}
	fi.close();
	ofstream fo;
	fo.open("Staff.txt");
	for (q = headstaff;q != NULL;q = q->pnext)
	{
		fo << q->data.UName << " " << q->data.pass << "," << q->data.Name << "," << q->data.dd << "," << q->data.ic << "," << q->data.addr << "," << q->data.sex << "," << q->data.status;
		if (q != tailstaff)
			fo << endl;
	}
	fi.ignore();
	cout << "Doi mat khau thanh cong!" << endl;
	fo.close();
}

void ChangePassManage(node* &headmag, node* &tailmag)
{
	string t1, t2;
	node* p;
	node* q;
	printf("Mat khau cu: ");
	cin >> t1;
	printf("Mat khau moi: ");
	cin >> t2;
	ifstream fi;
	fi.open("Manager.txt");
	for (p = headmag;p != NULL;p = p->pnext)
	{
		if (t1 == p->data.pass)
		{
			p->data.pass = t2;
			break;
		}
	}
	fi.close();
	ofstream fo;
	fo.open("Manager.txt");
	for (q = headmag;q != NULL;q = q->pnext)
	{
		fo << q->data.UName << " " << q->data.pass << "," << q->data.Name << "," << q->data.dd << "," << q->data.ic << "," << q->data.addr << "," << q->data.sex << "," << q->data.status;
		if (q != tailmag)
			fo << endl;
	}
	fi.ignore();
	cout << "Doi mat khau thanh cong!" << endl;
	fo.close();
}

void Logout(void)
{
	exit(0);
}

bool check(node* pHead, string x)
{
	bool bl = false;
	for (node* q = pHead; q != NULL; q = q->pnext)
		if (q->data.UName == x)
		{
			bl = true;
			break;
		}
	return bl;
}

void Edituser(node* &pHead, node* &pTail)
{
	bool bl = false;
	Us x;
	string t, ten;
	node* i;
	node* j;
	node* n = new node;
	int k;
	ifstream fi;
	fi.open("Admin.txt");
	cin.ignore();
	cout << "Nhap ten tai khoan can cap nhat: ";
	//cin.ignore();
	getline(cin, ten);
	for (node* i = pHead; i != NULL; i = i->pnext)
	{
		if (ten == i->data.UName)
		{
			bl = true;
			break;
		}
	}
	if (bl == true)
	{
		cout << "Thong tin nao can cap nhat?" << endl;
		cout << "1. Tai khoan" << endl << "2. Mat khau" << endl << "3. Ho ten" << endl << "4. Ngay sinh" << endl << "5. CMND" << endl << "6. Dia chi" << endl << "7. Gioi tinh" << endl << "8. Tinh trang tai khoan" << endl;
		cout << "Nhap ma lua chon: ";
		cin >> k;
		cin.ignore();
		cout << "Nhap thong tin dieu chinh: ";
		getline(cin, t);
		for (i = pHead;i;i = i->pnext)
		{
			if (i->data.UName == ten)
			{
				x.UName = i->data.UName;
				x.pass = i->data.pass;
				x.Name = i->data.Name;
				x.dd = i->data.dd;
				x.ic = i->data.ic;
				x.addr = i->data.addr;
				x.sex = i->data.sex;
				x.status = i->data.status;
				if (k == 1)
					x.UName = t;
				if (k == 2)
					x.pass = t;
				if (k == 3)
					x.Name = t;
				if (k == 4)
					x.dd = t;
				if (k == 5)
					x.ic = t;
				if (k == 6)
					x.addr = t;
				if (k == 7)
					x.sex = t;
				if (k == 8)
					x.status = t;
				n = getnode(x);
			}
			ofstream fo;
			fo.open("Admin.txt");
			for (j = pHead; j; j = j->pnext)
			{
				if ((j->data.UName) != ten)
					fo << j->data.UName << " " << j->data.pass << "," << j->data.Name << "," << j->data.dd << "," << j->data.ic << "," << j->data.addr << "," << j->data.sex << "," << j->data.status;
				else
					fo << n->data.UName << " " << n->data.pass << "," << n->data.Name << "," << n->data.dd << "," << n->data.ic << "," << n->data.addr << "," << n->data.sex << "," << n->data.status;
				if (j != pTail)
					fo << endl;
			}
			fi.ignore();
			fo.close();
		}
		cout << "Cap nhat thanh cong!!!" << endl;
	}
	else
		cout << "Tai khoan khong hop le!!!" << endl;
}

void EditStaff(node* &headstaff, node* &tailstaff)
{
	bool bl = false;
	Us x;
	string t, ten;
	node* i;
	node* j;
	node* n = new node;
	int k;
	ifstream fi;
	fi.open("Staff.txt");
	cin.ignore();
	cout << "Nhap ten tai khoan can cap nhat: ";
	//cin.ignore();
	getline(cin, ten);
	for (node* i = headstaff; i != NULL; i = i->pnext)
	{
		if (ten == i->data.UName)
		{
			bl = true;
			break;
		}
	}
	if (bl == true)
	{
		cout << "Thong tin nao can cap nhat?" << endl;
		cout << "1. Tai khoan" << endl << "2. Mat khau" << endl << "3. Ho ten" << endl << "4. Ngay sinh" << endl << "5. CMND" << endl << "6. Dia chi" << endl << "7. Gioi tinh" << endl << "8. Tinh trang tai khoan" << endl;
		cout << "Nhap ma lua chon: ";
		cin >> k;
		cin.ignore();
		cout << "Nhap thong tin dieu chinh: ";
		getline(cin, t);
		for (i = headstaff;i;i = i->pnext)
		{
			if (i->data.UName == ten)
			{
				x.UName = i->data.UName;
				x.pass = i->data.pass;
				x.Name = i->data.Name;
				x.dd = i->data.dd;
				x.ic = i->data.ic;
				x.addr = i->data.addr;
				x.sex = i->data.sex;
				x.status = i->data.status;
				if (k == 1)
					x.UName = t;
				if (k == 2)
					x.pass = t;
				if (k == 3)
					x.Name = t;
				if (k == 4)
					x.dd = t;
				if (k == 5)
					x.ic = t;
				if (k == 6)
					x.addr = t;
				if (k == 7)
					x.sex = t;
				if (k == 8)
					x.status = t;
				n = getnode(x);
			}
			ofstream fo;
			fo.open("Staff.txt");
			for (j = headstaff; j; j = j->pnext)
			{
				if ((j->data.UName) != ten)
					fo << j->data.UName << " " << j->data.pass << "," << j->data.Name << "," << j->data.dd << "," << j->data.ic << "," << j->data.addr << "," << j->data.sex << "," << j->data.status;
				else
					fo << n->data.UName << " " << n->data.pass << "," << n->data.Name << "," << n->data.dd << "," << n->data.ic << "," << n->data.addr << "," << n->data.sex << "," << n->data.status;
				if (j != tailstaff)
					fo << endl;
			}
			fi.ignore();
			fo.close();
		}
		cout << "Cap nhat thanh cong!!!" << endl;
	}
	else
		cout << "Tai khoan khong hop le!!!" << endl;
}

void EditManage(node* &headmag, node* &tailmag)
{
	bool bl = false;
	Us x;
	string t, ten;
	node* i;
	node* j;
	node* n = new node;
	int k;
	ifstream fi;
	fi.open("Manager.txt");
	cin.ignore();
	cout << "Nhap ten tai khoan can cap nhat: ";
	//cin.ignore();
	getline(cin, ten);
	for (node* i = headmag; i != NULL; i = i->pnext)
	{
		if (ten == i->data.UName)
		{
			bl = true;
			break;
		}
	}
	if (bl == true)
	{
		cout << "Thong tin nao can cap nhat?" << endl;
		cout << "1. Tai khoan" << endl << "2. Mat khau" << endl << "3. Ho ten" << endl << "4. Ngay sinh" << endl << "5. CMND" << endl << "6. Dia chi" << endl << "7. Gioi tinh" << endl << "8. Tinh trang tai khoan" << endl;
		cout << "Nhap ma lua chon: ";
		cin >> k;
		cin.ignore();
		cout << "Nhap thong tin dieu chinh: ";
		getline(cin, t);
		for (i = headmag;i;i = i->pnext)
		{
			if (i->data.UName == ten)
			{
				x.UName = i->data.UName;
				x.pass = i->data.pass;
				x.Name = i->data.Name;
				x.dd = i->data.dd;
				x.ic = i->data.ic;
				x.addr = i->data.addr;
				x.sex = i->data.sex;
				x.status = i->data.status;
				if (k == 1)
					x.UName = t;
				if (k == 2)
					x.pass = t;
				if (k == 3)
					x.Name = t;
				if (k == 4)
					x.dd = t;
				if (k == 5)
					x.ic = t;
				if (k == 6)
					x.addr = t;
				if (k == 7)
					x.sex = t;
				if (k == 8)
					x.status = t;
				n = getnode(x);
			}
			ofstream fo;
			fo.open("Manager.txt");
			for (j = headmag; j; j = j->pnext)
			{
				if ((j->data.UName) != ten)
					fo << j->data.UName << " " << j->data.pass << "," << j->data.Name << "," << j->data.dd << "," << j->data.ic << "," << j->data.addr << "," << j->data.sex << "," << j->data.status;
				else
					fo << n->data.UName << " " << n->data.pass << "," << n->data.Name << "," << n->data.dd << "," << n->data.ic << "," << n->data.addr << "," << n->data.sex << "," << n->data.status;
				if (j != tailmag)
					fo << endl;
			}
			fi.ignore();
			fo.close();
		}
		cout << "Cap nhat thanh cong!!!" << endl;
	}
	else
		cout << "Tai khoan khong hop le!!!" << endl;
}

void createuser(node* &pHead, node* &pTail)
{
	Us a;
	bool bl = false;
	node* p;
	node* q = pHead;
	ifstream fi;
	fi.open("Admin.txt");
	//fi.ignore();
	cin.ignore();
	cout << "Nhap tai khoan cua ban: ";
	getline(cin, a.UName);
	bl = check(pHead, a.UName);
	while (bl != false)
	{
		cout << "Tai khoan da duoc dung. Hay thu lai!!!" << endl;
		cout << "Nhap tai khoan cua ban: ";
		getline(cin, a.UName);
		bl = check(pHead, a.UName);
	}
	cout << "Mat khau: ";
	getline(cin, a.pass);
	cout << "Ho ten: ";
	getline(cin, a.Name);
	cout << "Ngay sinh: ";
	getline(cin, a.dd);
	cout << "CMND: ";
	getline(cin, a.ic);
	cout << "Dia chi: ";
	getline(cin, a.addr);
	cout << "Gioi tinh: ";
	getline(cin, a.sex);
	a.status = "activated";
	p = getnode(a);
	addlast(pHead, pTail, p);
	ofstream fo;
	fo.open("Admin.txt");
	for (q = pHead; q != NULL; q = q->pnext)
	{
		fo << q->data.UName << " " << q->data.pass << "," << q->data.Name << "," << q->data.dd << "," << q->data.ic << "," << q->data.addr << "," << q->data.sex << "," << q->data.status;
		if (q != pTail)
			fo << endl;
	}
	fi.ignore();
	fi.close();
	fo.close();
}

void creatstaff(node* &headstaff, node* &tailstaff)
{
	Us a;
	bool bl = false;
	node* p;
	node* q = headstaff;
	ifstream fi;
	fi.open("Staff.txt");
	//fi.ignore();
	cout << "Nhap tai khoan cua ban: ";
	cin.ignore();
	getline(cin, a.UName);
	bl = check(headstaff, a.UName);
	while (bl != false)
	{
		cout << "Tai khoan da duoc dung. Hay thu lai!!!" << endl;
		cout << "Nhap tai khoan cua ban: ";
		getline(cin, a.UName);
		bl = check(headstaff, a.UName);
	}
	cout << "Mat khau: ";
	getline(cin, a.pass);
	cout << "Ho ten: ";
	getline(cin, a.Name);
	cout << "Ngay sinh: ";
	getline(cin, a.dd);
	cout << "CMND: ";
	getline(cin, a.ic);
	cout << "Dia chi: ";
	getline(cin, a.addr);
	cout << "Gioi tinh: ";
	getline(cin, a.sex);
	a.status = "activated";
	p = getnode(a);
	addlaststaff(headstaff, tailstaff, p);
	ofstream fo;
	fo.open("Staff.txt");
	for (q = headstaff; q != NULL; q = q->pnext)
	{
		fo << q->data.UName << " " << q->data.pass << "," << q->data.Name << "," << q->data.dd << "," << q->data.ic << "," << q->data.addr << "," << q->data.sex << "," << q->data.status;
		if (q != tailstaff)
			fo << endl;
	}
	fi.ignore();
	fi.close();
	fo.close();
}

void creatmanage(node* &headmag, node* &tailmag)
{
	Us a;
	bool bl = false;
	node* p;
	node* q = headmag;
	ifstream fi;
	fi.open("Manager.txt");
	//fi.ignore();
	cout << "Nhap tai khoan cua ban: ";
	cin.ignore();
	getline(cin, a.UName);
	bl = check(headmag, a.UName);
	while (bl != false)
	{
		cout << "Tai khoan da duoc dung. Hay thu lai!!!" << endl;
		cout << "Nhap tai khoan cua ban: ";
		getline(cin, a.UName);
		bl = check(headmag, a.UName);
	}
	cout << "Mat khau: ";
	getline(cin, a.pass);
	cout << "Ho ten: ";
	getline(cin, a.Name);
	cout << "Ngay sinh: ";
	getline(cin, a.dd);
	cout << "CMND: ";
	getline(cin, a.ic);
	cout << "Dia chi: ";
	getline(cin, a.addr);
	cout << "Gioi tinh: ";
	getline(cin, a.sex);
	a.status = "activated";
	p = getnode(a);
	addlastmanage(headmag, tailmag, p);
	ofstream fo;
	fo.open("Manager.txt");
	for (q = headmag; q != NULL; q = q->pnext)
	{
		fo << q->data.UName << " " << q->data.pass << "," << q->data.Name << "," << q->data.dd << "," << q->data.ic << "," << q->data.addr << "," << q->data.sex << "," << q->data.status;
		if (q != tailmag)
			fo << endl;
	}
	fi.ignore();
	fi.close();
	fo.close();
}
void Menu_one(node* &pHead, node* &pTail, node* &headstaff, node* &tailstaff, node* &headmag, node* &tailmag)
{
	int k, d = 0;
	string ten;
	cout << "Menu" << endl;
	cout << "1.Dang xuat" << endl;
	cout << "2.Doi mat khau" << endl;
	cout << "3.Cap nhat thong tin ca nhan" << endl;
	cout << "4.Tao nguoi dung" << endl;
	cout << "Nhap ma lua chon: " << endl;
	cin >> k;
	switch (k)
	{
	case 1:
	{
		Logout();
		system("pause");
		break;
	}
	case 2:
	{
		ChangePass(pHead, pTail);
		system("pause");
		break;
	}
	case 3:
	{
		int n;
		cout << "1.Cap nhat thong tin tai khoan Admin" << endl;
		cout << "2.Cap nhat thong tin tai khoan Quan ly" << endl;
		cout << "3.Cap nhat thong tin tai khoan Chuyen vien" << endl;
		cout << "Nhap ma lua chon: ";
		cin >> n;
		if (n == 1)
			Edituser(pHead, pTail);
		if (n == 2)
			EditManage(headmag, tailmag);
		if (n == 3)
			EditStaff(headstaff, tailstaff);
		system("pause");
		break;
	}
	case 4:
	{
		int n;
		cout << "1.Tai khoan Quan ly" << endl;
		cout << "2.Tai khoai Chuyen vien" << endl;
		cout << "Nhap ma lua chon: ";
		cin >> n;
		if (n == 1)
			creatmanage(headmag, tailmag);
		if (n == 2)
			creatstaff(headstaff, tailstaff);
		//createuser(pHead, pTail);
		system("pause");
		break;
	}

	default:
		break;
	}
	system("cls");
}