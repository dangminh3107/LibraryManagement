#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
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
NODE* getcard(bcard a);
void AddLast(NODE* &HEAD, NODE* &TAIL, NODE* p);
void readborrow(NODE* &HEAD, NODE* &TAIL, bcard &x, NODE* p, ifstream &fi, ofstream &fo);
void addmuonsach(NODE* &HEAD, NODE* &TAIL);
void showborrow(NODE* &HEAD, NODE* &TAIL, NODE* p);
