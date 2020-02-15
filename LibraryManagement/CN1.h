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

node* getnode(Us a);
void addlast(node* &pHead, node* &pTail, node* p);
void addlaststaff(node* &headstaff, node* &tailstaff, node* p);
void addlastmanage(node* &headmag, node* &tailmag, node* p);
void scan(node* &pHead, node* &pTail, node* p);
void scanstaff(node* &headstaff, node* &tailstaff, node* p);
void scanmanage(node* &headmag, node* &tailmag, node* p);
bool checkstaff(node* &headstaff, string a, string b);
bool checkadmin(node* &pHead, string a, string b);
bool checkmanage(node* &headmag, string a, string b);
int Login(node* &pHead, node* &headstaff, node* &headmag);
void ChangePass(node* &pHead, node* &pTail);
void ChangePassStaff(node* &headstaff, node* &tailstaff);
void ChangePassManage(node* &headmag, node* &tailmag);
void Logout(void);
bool check(node* pHead, string x);
void Edituser(node* &pHead, node* &pTail);
void EditStaff(node* &headstaff, node* &tailstaff);
void EditManage(node* &headmag, node* &tailmag);
void createuser(node* &pHead, node* &pTail);
void creatstaff(node* &headstaff, node* &tailstaff);
void creatmanage(node* &headmag, node* &tailmag);
void Menu_one(node* &pHead, node* &pTail, node* &headstaff, node* &tailstaff, node* &headmag, node* &tailmag);
int Login_cmd(node* &pHead, node* &headstaff, node* &headmag, string user, string pass);