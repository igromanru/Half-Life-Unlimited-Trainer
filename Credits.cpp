//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Credits.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label1Click(TObject *Sender)
{
 ShellExecute(NULL, "open", "http://www.oldschoolhack.de/",
	NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label2Click(TObject *Sender)
{
 ShellExecute(NULL, "open", "http://homeofgamehacking.de",
	NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label3Click(TObject *Sender)
{
ShellExecute(NULL, "open", "http://.c-plusplus.de/forum/",
	NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------
