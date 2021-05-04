//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Tlhelp32.h>
#include <mmsystem.h>
#pragma hdrstop


#include "ufmod.h"
#include "Credits.h"
#include "hl1.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int igOldMouseX, igOldMouseY;
int lab1 = 0;

HWND act = NULL;
DWORD prozessor;
DWORD puffer = 0;
int getwi = 1;
HANDLE handleact;
DWORD Baser;
DWORD AddressPistole;
DWORD AddressShotgun;
DWORD AddressShotgunSec;
DWORD AddressGra;
DWORD AddressMP;
DWORD AddressMag;
DWORD AdressMPg;
DWORD AdressLas;
DWORD AdressC4;
DWORD AdressGauss;
DWORD AdressGauss2;
DWORD AdressGauss3;
DWORD AdressGaussV;
DWORD AdressRPG;
DWORD AdressHive;
DWORD AdressHive2;
DWORD AdressCross;
DWORD AdressBugs;

DWORD AdressFlash;
DWORD AdressShild;

//int threadtimer = 1;
int Unlammo = 1;
int unlflash = 1;
int wasfounded = 0;
int unlshild = 1;
int eia = 1;

BYTE ammo[1] = {0x40};     //Pistol, ... ,crossbow
BYTE ammoshot[1] = {0x42};
BYTE ammonade[1] = {0x47};
BYTE shotam[3] = {0x83,0xea,0xfe};
BYTE lasermid[1] = {0x41};
BYTE cc4[2] = {0xff, 0x00};
BYTE Gauss[3] = {0x83 ,0xe9 ,0xfe};
BYTE Gauss2[1] = {0x41};    //gauss2 und 3 , Hive2 , Bugs
BYTE RPG[1]={0x40};
BYTE Hive[1]={0x42};
BYTE GaussV[2] = {0x01,0xd0};

BYTE Shilder[2] =  {0xd8,0xc1};


BYTE ammopist[1] = {0x48};   //Pistol, ... ,
BYTE ammoshotback[1] = {0x4A};
BYTE ammogra[1] = {0x4f};
BYTE backshotam[3] = {0x83, 0xc2, 0xfe};
BYTE lasermidback[1] = {0x49};
BYTE cc4back[2] = {0xff, 0x08};
BYTE Gaussback[3] = {0x83 ,0xc1 ,0xfe};
BYTE Gauss2back[1] = {0x49};   //Gauss2, Hive2 , Bugs
BYTE RPGback[1]={0x48};   //Cross
BYTE Hiveback[1]={0x4a};
BYTE GaussVback[2] = {0x29,0xd0};

BYTE  Shilderback[2]={0xd8,0xe1};

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
   Form1->WindowState=wsMinimized;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
 if (Button == mbLeft)
  {
	igOldMouseX = X;
    igOldMouseY = Y;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
 int iDeltaX, iDeltaY;
  if (Shift.Contains(ssLeft))
  {
    iDeltaX = X - igOldMouseX;
	iDeltaY = Y - igOldMouseY;
	Top = Top + iDeltaY;
    Left = Left + iDeltaX;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
  uFMOD_StopSong();
  //exit(1);
  Form1->Close();
}
//---------------------------------------------------------------------------
	  DWORD GetModuleBase(LPSTR lpModuleName, DWORD dwProcessId)
		 {
	  MODULEENTRY32 lpModuleEntry = {0};

      HANDLE hSnapShot = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, dwProcessId );

      if(!hSnapShot)

      return NULL;

      lpModuleEntry.dwSize = sizeof(lpModuleEntry);

      BOOL bModule = Module32First( hSnapShot, &lpModuleEntry );

	  while(bModule)
	  {
	  if(!strcmp( lpModuleEntry.szModule, lpModuleName ) )
	  {
      CloseHandle( hSnapShot );

	  return (DWORD)lpModuleEntry.modBaseAddr;
	  }
	  bModule = Module32Next( hSnapShot, &lpModuleEntry );
	  }
	  CloseHandle( hSnapShot );

      return NULL;
	  }
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 if(lab1==0)
  {
  Label1->Caption="Igromanru © 2010";
  lab1=1;
  }
  else if(lab1==1)
  {
   Label1->Caption="Half-Life 1 Unlimited Trainer v1 - Trainer +3";
   lab1=0;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::finderTimer(TObject *Sender)
{
 act = FindWindow(NULL, "Half-Life");
 TPngImage *png2 = new TPngImage();
  if(act!=NULL)
   {
   GetWindowThreadProcessId(act, &prozessor);
   Baser = GetModuleBase("hl.dll", prozessor);
	if(Baser!=NULL)
	{
   if(getwi==1)
   {
	 handleact = OpenProcess(PROCESS_ALL_ACCESS, FALSE, prozessor);

	 Image2Click(0);
	 png2->LoadFromResourceName( (int)GetModuleHandle(0),"found");
	Image3->Picture->Assign(png2);

	 AddressPistole = Baser + 0x3A155;
	 AddressShotgun = Baser + 0x75BA6;
	 AddressShotgunSec  = Baser + 0x75DE9;
	 AddressGra  = Baser + 0x34E06;
	 AddressMP  = Baser + 0x4B3D0;
	 AddressMag = Baser + 0x6CF13;
	 AdressMPg = Baser + 0x4B622;
	 AdressLas = Baser + 0x85C81;
	 AdressC4 = Baser + 0x6FEE8;
	 AdressGauss =  Baser + 0x2FB10;
	 AdressGauss =  Baser + 0x2FC44;
	 AdressGauss2  = Baser + 0x2FD93;
	 AdressGaussV  = Baser + 0x2595A;
	 AdressRPG = Baser + 0x6F09A;
	 AdressHive = Baser + 0x3B873;
	 AdressHive2 = Baser + 0x3C17C;
	 AdressCross = Baser + 0x1DBEA;
	 AdressBugs = Baser + 0x7B90E;
	 AdressFlash = Baser + 0x65429;
	 AdressShild = Baser + 0x5FB85;


	 getwi = 0;
	 wasfounded = 1;

	 featured->Enabled=true;

	 AmmoLab->Enabled=true;
	 FlashLab->Enabled=true;
	 ShildLab->Enabled=true;
   }
    }
   }
   else
   {
   if(wasfounded==1)
   {
	Image2Click(0);
	png2->LoadFromResourceName( (int)GetModuleHandle(0),"waiting");
	Image3->Picture->Assign(png2);
	getwi = 1;

	 wasfounded=0;
   }

      featured->Enabled=false;

	AmmoLab->Enabled=false;
	FlashLab->Enabled=false;
	ShildLab->Enabled=false;
   }
   delete png2;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   uFMOD_PlaySong((void *)"igro",(void *)GetModuleHandle(0),XM_RESOURCE);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::featuredTimer(TObject *Sender)
{
  if(GetAsyncKeyState(VK_NUMPAD1)&1!=0)
   {

	if(Unlammo == 1)
	{
	 PlaySound(TEXT("activ"), GetModuleHandle(NULL) ,SND_RESOURCE | SND_ASYNC);
	  WriteProcessMemory(handleact,(void*)(AddressPistole),&ammo,sizeof(ammo),&puffer);
	  WriteProcessMemory(handleact,(void*)(AddressShotgun),&ammoshot,sizeof(ammoshot),&puffer);
	  WriteProcessMemory(handleact,(void*)(AddressShotgunSec),&shotam,sizeof(shotam),&puffer);
	  WriteProcessMemory(handleact,(void*)(AddressGra),&ammonade,sizeof(ammonade),&puffer);
	  WriteProcessMemory(handleact,(void*)(AddressMP),&ammoshot,sizeof(ammoshot),&puffer);
	  WriteProcessMemory(handleact,(void*)(AddressMag),&ammoshot,sizeof(ammoshot),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressMPg),&ammonade,sizeof(ammonade),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressLas),&lasermid,sizeof(lasermid),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressC4),&cc4,sizeof(cc4),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressGauss),&Gauss,sizeof(Gauss),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressGauss2),&Gauss2,sizeof(Gauss2),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressGauss3),&Gauss2,sizeof(Gauss2),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressRPG),&RPG,sizeof(RPG),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressHive),&Hive,sizeof(Hive),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressHive2),&Gauss2,sizeof(Gauss2),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressCross),&RPG,sizeof(RPG),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressBugs),&Gauss2,sizeof(Gauss2),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressGaussV),&GaussV,sizeof(GaussV),&puffer);


	  Unlammo = 0;
	  AmmoLab->Font->Color=clLime;
	}
	else if(Unlammo == 0)
	{
	 PlaySound(TEXT("deactiv"), GetModuleHandle(NULL) ,SND_RESOURCE | SND_ASYNC);
	  WriteProcessMemory(handleact,(void*)(AddressPistole),&ammopist,sizeof(ammopist),&puffer);
	  WriteProcessMemory(handleact,(void*)(AddressShotgun),&ammoshot,sizeof(ammoshot),&puffer);
	  WriteProcessMemory(handleact,(void*)(AddressShotgunSec),&backshotam,sizeof(backshotam),&puffer);
	  WriteProcessMemory(handleact,(void*)(AddressGra),&ammogra,sizeof(ammogra),&puffer);
	  WriteProcessMemory(handleact,(void*)(AddressMP),&ammoshotback,sizeof(ammoshotback),&puffer);
	  WriteProcessMemory(handleact,(void*)(AddressMag),&ammoshotback,sizeof(ammoshotback),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressMPg),&ammogra,sizeof(ammogra),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressLas),&lasermidback,sizeof(lasermidback),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressC4),&cc4back,sizeof(cc4back),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressGauss),&Gaussback,sizeof(Gaussback),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressGauss2),&Gauss2back,sizeof(Gauss2back),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressGauss3),&Gauss2back,sizeof(Gauss2back),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressRPG),&RPGback,sizeof(RPGback),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressHive),&Hiveback,sizeof(Hiveback),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressHive2),&Gauss2back,sizeof(Gauss2back),&puffer);
	  WriteProcessMemory(handleact,(void*)(AdressCross),&RPGback,sizeof(RPGback),&puffer);
	   WriteProcessMemory(handleact,(void*)(AdressBugs),&Gauss2back,sizeof(Gauss2back),&puffer);
	   WriteProcessMemory(handleact,(void*)(AdressGaussV),&GaussVback,sizeof(GaussVback),&puffer);

	Unlammo = 1;
	AmmoLab->Font->Color=clYellow;
	}
   }

   if(GetAsyncKeyState(VK_NUMPAD3)&1!=0)
   {

	if(unlflash == 1)
	{
	 PlaySound(TEXT("activ"), GetModuleHandle(NULL) ,SND_RESOURCE | SND_ASYNC);
	  WriteProcessMemory(handleact,(void*)(AdressFlash),&ammo,sizeof(ammo),&puffer);

	  unlflash = 0;
	  FlashLab->Font->Color=clLime;
	}
	else if(unlflash == 0)
	{
	 PlaySound(TEXT("deactiv"), GetModuleHandle(NULL) ,SND_RESOURCE | SND_ASYNC);
	  WriteProcessMemory(handleact,(void*)(AdressFlash),&ammopist,sizeof(ammopist),&puffer);

	unlflash = 1;
	FlashLab->Font->Color=clYellow;
	}
   }

   if(GetAsyncKeyState(VK_NUMPAD2)&1!=0)
   {

	if(unlshild == 1)
	{
	PlaySound(TEXT("activ"), GetModuleHandle(NULL) ,SND_RESOURCE | SND_ASYNC);
	  WriteProcessMemory(handleact,(void*)(AdressShild),&Shilder,sizeof(Shilder),&puffer);

	  unlshild  = 0;
	  ShildLab->Font->Color=clLime;
	}
	else if(unlshild  == 0)
	{
	 PlaySound(TEXT("deactiv"), GetModuleHandle(NULL) ,SND_RESOURCE | SND_ASYNC);
	  WriteProcessMemory(handleact,(void*)(AdressShild),&Shilderback,sizeof(Shilder),&puffer);

	unlshild  = 1;
	ShildLab->Font->Color=clYellow;
	}
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image2Click(TObject *Sender)
{
 TPngImage *png = new TPngImage();
 if(eia==1)
  {
  png->LoadFromResourceName( (int)GetModuleHandle(0),"Idisabled");
  Image2->Picture->Assign(png);
  uFMOD_PlaySong(0,0,0);

  eia = 0;
  }
  else if(eia==0)
  {
   png->LoadFromResourceName( (int)GetModuleHandle(0),"Inambled");
  Image2->Picture->Assign(png);
   uFMOD_PlaySong((void *)"igro",(void *)GetModuleHandle(0),XM_RESOURCE);

  eia = 1;
  }
  delete png;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label2Click(TObject *Sender)
{
 Form2 = new TForm2(Application);
 Form2->ShowModal();
 delete Form2;
}
//---------------------------------------------------------------------------


