//---------------------------------------------------------------------------

#ifndef hl1H
#define hl1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
#include "TeCanvas.hpp"
#include "IWBaseControl.hpp"
#include "IWBaseHTMLControl.hpp"
#include "IWCompButton.hpp"
#include "IWControl.hpp"
#include "IWVCLBaseControl.hpp"
#include <Buttons.hpp>
#include <ImgList.hpp>
#include <ComCtrls.hpp>
#include <pngimage.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-verwaltete Komponenten
	TImage *Image1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton1;
	TLabel *Label1;
	TTimer *Timer1;
	TTimer *finder;
	TLabel *AmmoLab;
	TLabel *FlashLab;
	TTimer *featured;
	TImage *Image2;
	TLabel *ShildLab;
	TImage *Image3;
	TLabel *Label2;
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall finderTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall featuredTimer(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Label2Click(TObject *Sender);


private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
/* class Igro : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall Igro(bool CreateSuspended);

}; */
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
