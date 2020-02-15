#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;
int QSBook(note* &start, note* &end);
int QSBookbykind(note* &start, note* &end, string x);
int QSReader(nod* &head, nod* &tail);
int QSReaderbysex(nod* &head, nod* &tail, string x);
int QSBorrow(NODE* &HEAD, NODE* &TAIL);
void QSDelay(no* &H, no* &T);
void Menu_six(note* &start, note* &end, nod* &head, nod* &tail, NODE* &HEAD, NODE* &TAIL, no* &H, no* &T);