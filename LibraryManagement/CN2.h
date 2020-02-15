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

nod* get(re a);
int StoI(string a);
void addlas(nod* &head, nod* &tail, nod* p);
void adddayhet(nod* &head, nod* &tail);
void Reader(nod* &head, nod* &tail, re &a, nod* p, ifstream &fi, ofstream &fo);
void Readagain(nod* &head, nod* &tail, re a);
void adddayhetcmnd(nod* &head, nod* &tail, string x);
void adddayhethoten(nod* &head, nod* &tail, string x);
void adddayhetonereader(nod* &head, nod* &tail, string ID);
void showreader(nod* &head, nod* &tail, nod* p);
void showareader(nod* &head, nod* &tail, string x);
void addreader(nod* &head, nod* &tail, re &a, nod* p);
void Editreader(nod* &head, nod* &tail, re c, string ID, ifstream &fi, ofstream &fo);
void Delreader(nod* &head, nod* &tail, ifstream &fi, ofstream &fo);
void Seekreaderbycmnd(nod* &head, nod* &tail, ifstream &fi, ofstream &fo);
void Seekreaderbyname(nod* &head, nod* &tail, ifstream &fi, ofstream &fo);
void Menu_two(nod* &head, nod* &tail, ifstream &fi, ofstream &fo, string &ID);
