#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;
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
string ItoS(int a);
no* getdelay(dlay a);
void Adddelay(no* &H, no* &T, no* p);
void readdelay(no* &H, no* &T, dlay &x2, no* p2);
void Addpaid(no* &H2, no* &T2, no* p);
void readpaid(no* &H2, no* &T2, dlay &x3, no* p2);
void showpay(NODE* &HEAD, NODE* &TAIL, NODE* p);
void showborr(NODE* &HEAD, NODE* &TAIL, string x);
int giasach(note* &start, note* &end, string x);
int SDay(int year, int month, int day);
void IN1(no* H, no* T);
void IN2(no* H2, no* T2);
void addpay(NODE* &HEAD, NODE* &TAIL, note* &start, note* &end, no* &H, no* &T, no* &H2, no* &T2);