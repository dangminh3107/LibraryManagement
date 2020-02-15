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
note* getnote(book a);
void Addtail(note* &start, note* &end, note* p);
void readbook(note* &start, note* &end, book &x, note* p, ifstream &fi, ofstream &fo);
void showbook(note* &start, note* &end, note* p);
void showabook(note* &start, note* &end, string isbn);
bool checkbook(note* &start, string x);
void addbook(note* &start, note* &end, book &x, note* p);
void Editbook(note* &start, note* &end, book c, string isbn, ifstream &fi, ofstream &fo);
void delbook(note* &start, note* &end, note* &p, ifstream &fi, ofstream &fo);
void SeekbookbyISBN(note* &start, note* &end, ifstream &fi, ofstream &fo);
void Seekbookbyname(note* &start, note* &end, ifstream &fi, ofstream &fo);
void Menu_three(note* &start, note* &end, note* &p, ifstream &fi, ofstream &fo);


