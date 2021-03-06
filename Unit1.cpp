//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
vector<int> mass1(10);
vector<int> mass2(10);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void iomass(vector<int>&A, int x, int y) {
	for (auto &ar : A) {
        ar = x + rand() % (y - x);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	srand(time(0));
	iomass(mass1, 20, 50);
	iomass(mass2, 20, 50);

	Memo1->Lines->Add("?????? ?1");
	for (auto &ar : mass1) {
		Memo1->Lines->Add(IntToStr(ar));
	}
	Memo1->Lines->Add("?????? ?2");
	for (auto &ar : mass2) {
		Memo1->Lines->Add(IntToStr(ar));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    vector<int> temp;
	temp.reserve(20);

	for (auto &ar : mass1) {
        temp.push_back(ar);
	}

	sort(temp.begin(), temp.end());

    Memo1->Lines->Clear();
	for (auto &ar : temp) {
		Memo1->Lines->Add(IntToStr(ar));
	}

	temp.~vector();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Memo1->Lines->Clear();
	int find_elem = StrToInt(Edit1->Text);
	auto first = mass1.begin();
	first = find(mass1.begin(), mass1.end(), find_elem);
	if (first != mass1.end()) {
		int temp = *first;
        Memo1->Lines->Add(IntToStr(temp));
	}
	else
        Memo1->Lines->Add("??????? ??????? ?? ??????!");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender){
	Memo1->Lines->Clear();
	vector<int> temp;
	temp.reserve(30);
	merge(mass1.cbegin(), mass1.cend(),
		   mass2.cbegin(), mass2.cend(), back_inserter(temp));

    for (auto &ar : temp) {
		Memo1->Lines->Add(IntToStr(ar));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Memo1->Lines->Clear();

	sort(mass1.begin(), mass1.end());
	sort(mass2.begin(), mass2.end());

	vector<int> intersection;
	int idA = 0, idB = 0;

	while(idA < mass1.size() && idB < mass2.size()) {
		if (mass1[idA] < mass2[idB]) idA++;
		else if (mass2[idB] < mass1[idA]) idB++;
		else {
			intersection.push_back(mass1[idA]);
			idA++;
			idB++;
		}
	}

    for (auto &ar : intersection) {
		Memo1->Lines->Add(IntToStr(ar));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    Memo1->Lines->Clear();
	vector<int> temp;
	temp.reserve(30);

	set_difference(begin(mass1), end(mass1), begin(mass2), end(mass2), back_inserter(temp));

	for (auto &ar : temp) {
		Memo1->Lines->Add(IntToStr(ar));
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
    Memo1->Lines->Clear();
	vector<int> temp, temp1, temp2;
	temp.reserve(60);
	temp1.reserve(30);
	temp2.reserve(30);

    set_difference(mass1.begin(), mass1.end(), mass2.begin(), mass2.end(), inserter(temp1, temp1.begin()));
	set_difference(mass2.begin(), mass2.end(), mass1.begin(), mass1.end(), inserter(temp2, temp2.begin()));
	merge(temp1.cbegin(), temp1.cend(), temp2.cbegin(), temp2.cend(), back_inserter(temp));

    for (auto &ar : temp) {
		Memo1->Lines->Add(IntToStr(ar));
	}
}
//---------------------------------------------------------------------------

