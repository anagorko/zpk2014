//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#pragma hdrstop

#include "wisielec_pchojnowski.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


#include <conio.h>
#include <string.h>

#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <mmsystem.h>

#include <iostream.h>
#include <string>

using namespace std;


TForm1 *Form1;

void poczatek(){

                 Form1 -> Button4 -> Visible  = false;
                 Form1 -> Button5 -> Visible  = false;

                Form1 -> Wisielec -> Caption = "Z";
                Application -> ProcessMessages(); Sleep(70);
                Form1 -> Wisielec -> Caption = "Za";
                Application -> ProcessMessages(); Sleep(70);
                Form1 -> Wisielec -> Caption = "Zacz";
                Application -> ProcessMessages(); Sleep(70);
                Form1 -> Wisielec -> Caption = "Zaczy";
                Application -> ProcessMessages(); Sleep(70);
                Form1 -> Wisielec -> Caption = "Zaczyn";
                Application -> ProcessMessages(); Sleep(70);
                Form1 -> Wisielec -> Caption = "Zaczyna";
                Application -> ProcessMessages(); Sleep(70);
                Form1 -> Wisielec -> Caption = "Zaczynam";
                Application -> ProcessMessages(); Sleep(70);
                Form1 -> Wisielec -> Caption = "Zaczynamy!";
                Application -> ProcessMessages(); Sleep(1700);
                Form1 -> Wisielec -> Caption = "G";
                Application -> ProcessMessages(); Sleep(100);
                Form1 -> Wisielec -> Caption = "Gr";
                Application -> ProcessMessages(); Sleep(100);
                Form1 -> Wisielec -> Caption = "Gre";
                Application -> ProcessMessages(); Sleep(100);
                Form1 -> Wisielec -> Caption = "Gre w";
                Application -> ProcessMessages(); Sleep(100);

                Form1 -> Wisielec -> Caption = "Gre w w";
                Application -> ProcessMessages(); Sleep(60);
                Form1 -> Wisielec -> Caption = "Gre w wi";
                Application -> ProcessMessages(); Sleep(60);
                Form1 -> Wisielec -> Caption = "Gre w wis";
                Application -> ProcessMessages(); Sleep(60);
                Form1 -> Wisielec -> Caption = "Gre w wisi";
                Application -> ProcessMessages(); Sleep(60);
                Form1 -> Wisielec -> Caption = "Gre w wisie";
                Application -> ProcessMessages(); Sleep(60);
                Form1 -> Wisielec -> Caption = "Gre w wisiel";
                Application -> ProcessMessages(); Sleep(60);
                Form1 -> Wisielec -> Caption = "Gre w wisiele";
                Application -> ProcessMessages(); Sleep(60);
                Form1 -> Wisielec -> Caption = "Gre w wisielec";
                Application -> ProcessMessages(); Sleep(60);
                Form1 -> Wisielec -> Caption = "Gre w wisieleca";
                Application -> ProcessMessages(); Sleep(60);
                Form1 -> Wisielec -> Caption = "Gre w wisieleca!";
                Application -> ProcessMessages(); Sleep(60);
                Form1 -> Wisielec -> Caption = "Gre w wisieleca! :";
                Application -> ProcessMessages(); Sleep(60);
                Form1 -> Wisielec -> Caption = "Gre w wisieleca! :)";
                Application -> ProcessMessages(); Sleep(60);
                Form1 -> Wisielec -> Caption = "Gre w wisieleca! :) .";
                Application -> ProcessMessages(); Sleep(1000);
                Form1 -> Wisielec -> Caption = "Gre w wisieleca! :) ..";
                Application -> ProcessMessages(); Sleep(1000);
                Form1 -> Wisielec -> Caption = "Gre w wisieleca! :) ...";
                 Application -> ProcessMessages(); Sleep(1000);


}


int BledneOdpowiedzi = 0;
int dlugosc;
bool NextPlayer = 1;
string tabwyr[15]; //tworze tablice wyrazow o ilosci takiej samej co slow w pliku txt

char p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12;
                                // p1 ... p12 - poszczegolne litery wyrazu
                                //( jezeli pole jest poste: p1 = '?'; )


string slowo = "????????????";
AnsiString slowoB;

fstream plik;









char ih1, ih2, ih3, ih4, ih5, ih6, ih7, ih8, ih9, ih10, ih11, ih12;
char ktora;
int IloscPol = 0, IloscPopr = 0;

bool byloA = false, byloB = false, byloC = false, byloD = false, byloE = false,
     byloF = false, byloG = false, byloH = false, byloI = false, byloJ = false,
     byloK = false, byloL = false, byloM = false, byloN = false, byloO = false,
     byloP = false, byloR = false, byloS = false, byloT = false, byloU = false,
     byloW = false, byloY = false, byloZ = false;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{



    p1 = '?';          p7 = '?';
    p2 = '?';          p8 = '?';
    p3 = '?';          p9 = '?';
    p4 = '?';          p10 = '?';
    p5 = '?';          p11 = '?';
    p6 = '?';          p12 = '?';


    ktora = '?';
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button3Click(TObject *Sender)
{
sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
if( Label1 -> Visible == false){
   Label1 -> Visible = true;
   Button3 -> Caption = "Ukryj zasady gry";
   } else {
   Label1 -> Visible = false;
   Button3 -> Caption = "Zasady gry";
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
Button1 -> Visible = false;
Button2 -> Visible = false;
Button3 -> Visible = false;
//Button8 ->Caption = "Jeden Gracz";
Button4 -> Visible = true;
Button5 -> Visible = true;


Label3 -> Visible = false;


}
//---------------------------------------------------------------------------



void __fastcall TForm1::Zakocz1Click(TObject *Sender)
{
Application -> Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
Application -> Terminate();
}
//---------------------------------------------------------------------------



  bool graczjeden=true, jeszczeraz=true;








void __fastcall TForm1::FormCreate(TObject *Sender)
{

Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");



Image1 -> Visible = false;

Image23 -> Picture -> LoadFromFile("zdjecia/a.bmp");
Image24 -> Picture -> LoadFromFile("zdjecia/b.bmp");
Image25 -> Picture -> LoadFromFile("zdjecia/c.bmp");
Image26 -> Picture -> LoadFromFile("zdjecia/d.bmp");
Image27 -> Picture -> LoadFromFile("zdjecia/e.bmp");
Image28 -> Picture -> LoadFromFile("zdjecia/f.bmp");
Image29 -> Picture -> LoadFromFile("zdjecia/g.bmp");
Image30 -> Picture -> LoadFromFile("zdjecia/h.bmp");
Image31 -> Picture -> LoadFromFile("zdjecia/i.bmp");
Image32 -> Picture -> LoadFromFile("zdjecia/j.bmp");
Image33 -> Picture -> LoadFromFile("zdjecia/k.bmp");
Image34 -> Picture -> LoadFromFile("zdjecia/l.bmp");
Image35 -> Picture -> LoadFromFile("zdjecia/m.bmp");
Image36 -> Picture -> LoadFromFile("zdjecia/n.bmp");
Image37 -> Picture -> LoadFromFile("zdjecia/o.bmp");
Image38 -> Picture -> LoadFromFile("zdjecia/p.bmp");
Image39 -> Picture -> LoadFromFile("zdjecia/r.bmp");
Image40 -> Picture -> LoadFromFile("zdjecia/s.bmp");
Image41 -> Picture -> LoadFromFile("zdjecia/t.bmp");
Image42 -> Picture -> LoadFromFile("zdjecia/u.bmp");
Image43 -> Picture -> LoadFromFile("zdjecia/w.bmp");
Image44 -> Picture -> LoadFromFile("zdjecia/y.bmp");
Image45 -> Picture -> LoadFromFile("zdjecia/z.bmp");

Image11 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image12 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image13 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image14 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image15 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image16 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image17 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image18 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image19 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image20 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image21 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image22 -> Picture -> LoadFromFile("zdjecia/puste.bmp");

/*
Image58 -> Picture -> LoadFromFile("zdjecia/a.bmp");
Image59 -> Picture -> LoadFromFile("zdjecia/b.bmp");
Image60 -> Picture -> LoadFromFile("zdjecia/c.bmp");
Image61 -> Picture -> LoadFromFile("zdjecia/d.bmp");
Image62 -> Picture -> LoadFromFile("zdjecia/e.bmp");
Image63 -> Picture -> LoadFromFile("zdjecia/f.bmp");
Image64 -> Picture -> LoadFromFile("zdjecia/g.bmp");
Image65 -> Picture -> LoadFromFile("zdjecia/h.bmp");
Image66 -> Picture -> LoadFromFile("zdjecia/i.bmp");
Image67 -> Picture -> LoadFromFile("zdjecia/j.bmp");
Image68 -> Picture -> LoadFromFile("zdjecia/k.bmp");
Image69 -> Picture -> LoadFromFile("zdjecia/l.bmp");
Image70 -> Picture -> LoadFromFile("zdjecia/m.bmp");
Image71 -> Picture -> LoadFromFile("zdjecia/n.bmp");
Image72 -> Picture -> LoadFromFile("zdjecia/o.bmp");
Image73 -> Picture -> LoadFromFile("zdjecia/p.bmp");
Image74 -> Picture -> LoadFromFile("zdjecia/r.bmp");
Image75 -> Picture -> LoadFromFile("zdjecia/s.bmp");
Image76 -> Picture -> LoadFromFile("zdjecia/t.bmp");
Image77 -> Picture -> LoadFromFile("zdjecia/u.bmp");
Image78 -> Picture -> LoadFromFile("zdjecia/w.bmp");
Image79 -> Picture -> LoadFromFile("zdjecia/y.bmp");
Image80 -> Picture -> LoadFromFile("zdjecia/z.bmp");

Image46 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image47 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image48 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image49 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image50 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image51 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image52 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image53 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image54 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image55 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image56 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image57 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
*/

}
//---------------------------------------------------------------------------


// dwoch graczy
void __fastcall TForm1::Button5Click(TObject *Sender)
{
sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
poczatek();
Wisielec -> Visible = false;
Button4 ->   Visible = false;
Button5 ->   Visible = false;
Button6 ->   Visible = true;

Image11 -> Visible = true;
Image12 -> Visible = true;
Image13 -> Visible = true;
Image14 -> Visible = true;
Image15 -> Visible = true;
Image16 -> Visible = true;
Image17 -> Visible = true;
Image18 -> Visible = true;
Image19 -> Visible = true;
Image20 -> Visible = true;
Image21 -> Visible = true;
Image22 -> Visible = true;
Image23 -> Visible = true;
Image24 -> Visible = true;
Image25 -> Visible = true;
Image26 -> Visible = true;
Image27 -> Visible = true;
Image28 -> Visible = true;
Image29 -> Visible = true;
Image30 -> Visible = true;
Image31 -> Visible = true;
Image32 -> Visible = true;
Image33 -> Visible = true;
Image34 -> Visible = true;
Image35 -> Visible = true;
Image36 -> Visible = true;
Image37 -> Visible = true;
Image38 -> Visible = true;
Image39 -> Visible = true;
Image40 -> Visible = true;
Image41 -> Visible = true;
Image42 -> Visible = true;
Image43 -> Visible = true;
Image44 -> Visible = true;
Image45 -> Visible = true;

pytanieI -> Visible = true;





}

//---------------------------------------------------------------------------

void __fastcall TForm1::Image23Click(TObject *Sender)
{
   sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image23 -> Picture -> LoadFromFile("zdjecia/na.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/a.bmp");
    p1 = 'a';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/a.bmp");
    p2 = 'a';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/a.bmp");
       p3 = 'a';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/a.bmp");
       p4 = 'a';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/a.bmp");
       p5 = 'a';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/a.bmp");
       p6 = 'a';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/a.bmp");
       p7 = 'a';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/a.bmp");
       p8 = 'a';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/a.bmp");
       p9 = 'a';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/a.bmp");
       p10 = 'a';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/a.bmp");
       p11 = 'a';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/a.bmp");
       p12 = 'a'; }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image24Click(TObject *Sender)
{
    sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image24 -> Picture -> LoadFromFile("zdjecia/nb.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/b.bmp");
    p1 = 'b';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/b.bmp");
    p2 = 'b';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/b.bmp");
       p3 = 'b';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/b.bmp");
       p4 = 'b';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/b.bmp");
       p5 = 'b';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/b.bmp");
       p6 = 'b';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/b.bmp");
       p7 = 'b';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/b.bmp");
       p8 = 'b';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/b.bmp");
       p9 = 'b';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/b.bmp");
       p10 = 'b';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/b.bmp");
       p11 = 'b';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/b.bmp");
       p12 = 'b'; }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image25Click(TObject *Sender)
{
     sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image25 -> Picture -> LoadFromFile("zdjecia/nc.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/c.bmp");
    p1 = 'c';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/c.bmp");
    p2 = 'c';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/c.bmp");
       p3 = 'c';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/c.bmp");
       p4 = 'c';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/c.bmp");
       p5 = 'c';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/c.bmp");
       p6 = 'c';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/c.bmp");
       p7 = 'c';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/c.bmp");
       p8 = 'c';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/c.bmp");
       p9 = 'c';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/c.bmp");
       p10 = 'c';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/c.bmp");
       p11 = 'c';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/c.bmp");
       p12 = 'c'; }


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image26Click(TObject *Sender)
{
        sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image26 -> Picture -> LoadFromFile("zdjecia/nd.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/d.bmp");
    p1 = 'd';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/d.bmp");
    p2 = 'd';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/d.bmp");
       p3 = 'd';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/d.bmp");
       p4 = 'd';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/d.bmp");
       p5 = 'd';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/d.bmp");
       p6 = 'd';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/d.bmp");
       p7 = 'd';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/d.bmp");
       p8 = 'd';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/d.bmp");
       p9 = 'd';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/d.bmp");
       p10 = 'd';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/d.bmp");
       p11 = 'd';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/d.bmp");
       p12 = 'd'; }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image27Click(TObject *Sender)
{
          sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image27 -> Picture -> LoadFromFile("zdjecia/ne.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/e.bmp");
    p1 = 'e';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/e.bmp");
    p2 = 'e';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/e.bmp");
       p3 = 'e';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/e.bmp");
       p4 = 'e';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/e.bmp");
       p5 = 'e';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/e.bmp");
       p6 = 'e';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/e.bmp");
       p7 = 'e';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/e.bmp");
       p8 = 'e';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/e.bmp");
       p9 = 'e';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/e.bmp");
       p10 = 'e';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/e.bmp");
       p11 = 'e';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/e.bmp");
       p12 = 'e'; }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image28Click(TObject *Sender)
{
            sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image28 -> Picture -> LoadFromFile("zdjecia/nf.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/f.bmp");
    p1 = 'f';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/f.bmp");
    p2 = 'f';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/f.bmp");
       p3 = 'f';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/f.bmp");
       p4 = 'f';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/f.bmp");
       p5 = 'f';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/f.bmp");
       p6 = 'f';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/f.bmp");
       p7 = 'f';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/f.bmp");
       p8 = 'f';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/f.bmp");
       p9 = 'f';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/f.bmp");
       p10 = 'f';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/f.bmp");
       p11 = 'f';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/f.bmp");
       p12 = 'f'; }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image29Click(TObject *Sender)
{
           sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image29 -> Picture -> LoadFromFile("zdjecia/ng.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/g.bmp");
    p1 = 'g';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/g.bmp");
    p2 = 'g';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/g.bmp");
       p3 = 'g';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/g.bmp");
       p4 = 'g';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/g.bmp");
       p5 = 'g';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/g.bmp");
       p6 = 'g';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/g.bmp");
       p7 = 'g';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/g.bmp");
       p8 = 'g';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/g.bmp");
       p9 = 'g';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/g.bmp");
       p10 = 'g';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/g.bmp");
       p11 = 'g';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/g.bmp");
       p12 = 'g'; }



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image30Click(TObject *Sender)
{
            sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image30 -> Picture -> LoadFromFile("zdjecia/nh.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/h.bmp");
    p1 = 'h';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/h.bmp");
    p2 = 'h';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/h.bmp");
       p3 = 'h';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/h.bmp");
       p4 = 'h';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/h.bmp");
       p5 = 'h';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/h.bmp");
       p6 = 'h';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/h.bmp");
       p7 = 'h';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/h.bmp");
       p8 = 'h';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/h.bmp");
       p9 = 'h';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/h.bmp");
       p10 = 'h';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/h.bmp");
       p11 = 'h';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/h.bmp");
       p12 = 'h'; }



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image31Click(TObject *Sender)
{
            sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); // Image31 -> Picture -> LoadFromFile("zdjecia/ni.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/i.bmp");
    p1 = 'i';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/i.bmp");
    p2 = 'i';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/i.bmp");
       p3 = 'i';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/i.bmp");
       p4 = 'i';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/i.bmp");
       p5 = 'i';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/i.bmp");
       p6 = 'i';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/i.bmp");
       p7 = 'i';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/i.bmp");
       p8 = 'i';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/i.bmp");
       p9 = 'i';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/i.bmp");
       p10 = 'i';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/i.bmp");
       p11 = 'i';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/i.bmp");
       p12 = 'i'; }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image32Click(TObject *Sender)
{
             sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image32 -> Picture -> LoadFromFile("zdjecia/nj.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/j.bmp");
    p1 = 'j';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/j.bmp");
    p2 = 'j';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/j.bmp");
       p3 = 'j';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/j.bmp");
       p4 = 'j';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/j.bmp");
       p5 = 'j';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/j.bmp");
       p6 = 'j';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/j.bmp");
       p7 = 'j';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/j.bmp");
       p8 = 'j';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/j.bmp");
       p9 = 'j';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/j.bmp");
       p10 = 'j';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/j.bmp");
       p11 = 'j';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/j.bmp");
       p12 = 'j'; }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image33Click(TObject *Sender)
{
             sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image33 -> Picture -> LoadFromFile("zdjecia/nk.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/k.bmp");
    p1 = 'k';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/k.bmp");
    p2 = 'k';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/k.bmp");
       p3 = 'k';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/k.bmp");
       p4 = 'k';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/k.bmp");
       p5 = 'k';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/k.bmp");
       p6 = 'k';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/k.bmp");
       p7 = 'k';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/k.bmp");
       p8 = 'k';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/k.bmp");
       p9 = 'k';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/k.bmp");
       p10 = 'k';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/k.bmp");
       p11 = 'k';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/k.bmp");
       p12 = 'k'; }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image34Click(TObject *Sender)
{
               sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image34 -> Picture -> LoadFromFile("zdjecia/nl.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/l.bmp");
    p1 = 'l';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/l.bmp");
    p2 = 'l';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/l.bmp");
       p3 = 'l';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/l.bmp");
       p4 = 'l';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/l.bmp");
       p5 = 'l';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/l.bmp");
       p6 = 'l';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/l.bmp");
       p7 = 'l';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/l.bmp");
       p8 = 'l';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/l.bmp");
       p9 = 'l';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/l.bmp");
       p10 = 'l';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/l.bmp");
       p11 = 'l';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/l.bmp");
       p12 = 'l'; }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image35Click(TObject *Sender)
{
             sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image35 -> Picture -> LoadFromFile("zdjecia/nm.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/m.bmp");
    p1 = 'm';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/m.bmp");
    p2 = 'm';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/m.bmp");
       p3 = 'm';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/m.bmp");
       p4 = 'm';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/m.bmp");
       p5 = 'm';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/m.bmp");
       p6 = 'm';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/m.bmp");
       p7 = 'm';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/m.bmp");
       p8 = 'm';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/m.bmp");
       p9 = 'm';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/m.bmp");
       p10 = 'm';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/m.bmp");
       p11 = 'm';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/m.bmp");
       p12 = 'm'; }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Imag36Click(TObject *Sender)
{
                sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image36 -> Picture -> LoadFromFile("zdjecia/nn.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/n.bmp");
    p1 = 'n';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/n.bmp");
    p2 = 'n';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/n.bmp");
       p3 = 'n';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/n.bmp");
       p4 = 'n';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/n.bmp");
       p5 = 'n';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/n.bmp");
       p6 = 'n';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/n.bmp");
       p7 = 'n';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/n.bmp");
       p8 = 'n';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/n.bmp");
       p9 = 'n';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/n.bmp");
       p10 = 'n';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/n.bmp");
       p11 = 'n';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/n.bmp");
       p12 = 'n'; }



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image37Click(TObject *Sender)
{
              sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image37 -> Picture -> LoadFromFile("zdjecia/no.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/o.bmp");
    p1 = 'o';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/o.bmp");
    p2 = 'o';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/o.bmp");
       p3 = 'o';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/o.bmp");
       p4 = 'o';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/o.bmp");
       p5 = 'o';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/o.bmp");
       p6 = 'o';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/o.bmp");
       p7 = 'o';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/o.bmp");
       p8 = 'o';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/o.bmp");
       p9 = 'o';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/o.bmp");
       p10 = 'o';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/o.bmp");
       p11 = 'o';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/o.bmp");
       p12 = 'o'; }



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image38Click(TObject *Sender)
{
                      sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image38 -> Picture -> LoadFromFile("zdjecia/np.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/p.bmp");
    p1 = 'p';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/p.bmp");
    p2 = 'p';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/p.bmp");
       p3 = 'p';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/p.bmp");
       p4 = 'p';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/p.bmp");
       p5 = 'p';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/p.bmp");
       p6 = 'p';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/p.bmp");
       p7 = 'p';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/p.bmp");
       p8 = 'p';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/p.bmp");
       p9 = 'p';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/p.bmp");
       p10 = 'p';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/p.bmp");
       p11 = 'p';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/p.bmp");
       p12 = 'p'; }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image39Click(TObject *Sender)
{
                     sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); // Image39 -> Picture -> LoadFromFile("zdjecia/nr.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/r.bmp");
    p1 = 'r';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/r.bmp");
    p2 = 'r';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/r.bmp");
       p3 = 'r';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/r.bmp");
       p4 = 'r';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/r.bmp");
       p5 = 'r';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/r.bmp");
       p6 = 'r';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/r.bmp");
       p7 = 'r';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/r.bmp");
       p8 = 'r';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/r.bmp");
       p9 = 'r';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/r.bmp");
       p10 = 'r';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/r.bmp");
       p11 = 'r';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/r.bmp");
       p12 = 'r'; }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image40Click(TObject *Sender)
{
                    sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); // Image40 -> Picture -> LoadFromFile("zdjecia/ns.bmp");


    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/s.bmp");
    p1 = 's';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/s.bmp");
    p2 = 's';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/s.bmp");
       p3 = 's';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/s.bmp");
       p4 = 's';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/s.bmp");
       p5 = 's';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/s.bmp");
       p6 = 's';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/s.bmp");
       p7 = 's';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/s.bmp");
       p8 = 's';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/s.bmp");
       p9 = 's';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/s.bmp");
       p10 = 's';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/s.bmp");
       p11 = 's';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/s.bmp");
       p12 = 's'; }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image41Click(TObject *Sender)
{
                   sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); // Image41 -> Picture -> LoadFromFile("zdjecia/nt.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/t.bmp");
    p1 = 't';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/t.bmp");
    p2 = 't';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/t.bmp");
       p3 = 't';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/t.bmp");
       p4 = 't';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/t.bmp");
       p5 = 't';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/t.bmp");
       p6 = 't';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/t.bmp");
       p7 = 't';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/t.bmp");
       p8 = 't';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/t.bmp");
       p9 = 't';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/t.bmp");
       p10 = 't';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/t.bmp");
       p11 = 't';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/t.bmp");
       p12 = 't'; }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image42Click(TObject *Sender)
{
                     sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //  Image42 -> Picture -> LoadFromFile("zdjecia/nu.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/u.bmp");
    p1 = 'u';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/u.bmp");
    p2 = 'u';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/u.bmp");
       p3 = 'u';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/u.bmp");
       p4 = 'u';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/u.bmp");
       p5 = 'u';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/u.bmp");
       p6 = 'u';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/u.bmp");
       p7 = 'u';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/u.bmp");
       p8 = 'u';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/u.bmp");
       p9 = 'u';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/u.bmp");
       p10 = 'u';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/u.bmp");
       p11 = 'u';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/u.bmp");
       p12 = 'u'; }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image43Click(TObject *Sender)
{
                    sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image43 -> Picture -> LoadFromFile("zdjecia/nw.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/w.bmp");
    p1 = 'w';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/w.bmp");
    p2 = 'w';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/w.bmp");
       p3 = 'w';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/w.bmp");
       p4 = 'w';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/w.bmp");
       p5 = 'w';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/w.bmp");
       p6 = 'w';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/w.bmp");
       p7 = 'w';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/w.bmp");
       p8 = 'w';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/w.bmp");
       p9 = 'w';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/w.bmp");
       p10 = 'w';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/w.bmp");
       p11 = 'w';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/w.bmp");
       p12 = 'w'; }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image44Click(TObject *Sender)
{
                sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); // Image44 -> Picture -> LoadFromFile("zdjecia/ny.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/y.bmp");
    p1 = 'y';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/y.bmp");
    p2 = 'y';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/y.bmp");
       p3 = 'y';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/y.bmp");
       p4 = 'y';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/y.bmp");
       p5 = 'y';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/y.bmp");
       p6 = 'y';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/y.bmp");
       p7 = 'y';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/y.bmp");
       p8 = 'y';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/y.bmp");
       p9 = 'y';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/y.bmp");
       p10 = 'y';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/y.bmp");
       p11 = 'y';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/y.bmp");
       p12 = 'y'; }



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image45Click(TObject *Sender)
{
               sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC); //Image45 -> Picture -> LoadFromFile("zdjecia/nz.bmp");

    if( p1 == '?') {
    Image11 -> Picture -> LoadFromFile("zdjecia/z.bmp");
    p1 = 'z';} else
    if( p2 == '?') {
       Image12 -> Picture -> LoadFromFile("zdjecia/z.bmp");
    p2 = 'z';} else
    if( p3 == '?') {
       Image13 -> Picture -> LoadFromFile("zdjecia/z.bmp");
       p3 = 'z';} else
    if( p4 == '?') {
       Image14 -> Picture -> LoadFromFile("zdjecia/z.bmp");
       p4 = 'z';} else
    if( p5 == '?') {
       Image15 -> Picture -> LoadFromFile("zdjecia/z.bmp");
       p5 = 'z';} else
    if( p6 == '?') {
       Image16 -> Picture -> LoadFromFile("zdjecia/z.bmp");
       p6 = 'z';} else
    if( p7 == '?') {
       Image17 -> Picture -> LoadFromFile("zdjecia/z.bmp");
       p7 = 'z';} else
    if( p8 == '?') {
       Image18 -> Picture -> LoadFromFile("zdjecia/z.bmp");
       p8 = 'z';} else
    if( p9 == '?') {
       Image19 -> Picture -> LoadFromFile("zdjecia/z.bmp");
       p9 = 'z';} else
    if( p10 == '?') {
       Image20 -> Picture -> LoadFromFile("zdjecia/z.bmp");
       p10 = 'z';} else
    if( p11 == '?') {
       Image21 -> Picture -> LoadFromFile("zdjecia/z.bmp");
       p11 = 'z';} else
    if( p12 == '?') {
       Image22 -> Picture -> LoadFromFile("zdjecia/z.bmp");
       p12 = 'z'; }


}







//---------------------------------------------------------------------------






void __fastcall TForm1::Button6Click(TObject *Sender)
{
sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
Image11 -> Visible = false;
Image12 -> Visible = false;
Image13 -> Visible = false;
Image14 -> Visible = false;
Image15 -> Visible = false;
Image16 -> Visible = false;
Image17 -> Visible = false;
Image18 -> Visible = false;
Image19 -> Visible = false;
Image20 -> Visible = false;
Image21 -> Visible = false;
Image22 -> Visible = false;
Image23 -> Visible = false;
Image24 -> Visible = false;
Image25 -> Visible = false;
Image26 -> Visible = false;
Image27 -> Visible = false;
Image28 -> Visible = false;
Image29 -> Visible = false;
Image30 -> Visible = false;
Image31 -> Visible = false;
Image32 -> Visible = false;
Image33 -> Visible = false;
Image34 -> Visible = false;
Image35 -> Visible = false;
Image36 -> Visible = false;
Image37 -> Visible = false;
Image38 -> Visible = false;
Image39 -> Visible = false;
Image40 -> Visible = false;
Image41 -> Visible = false;
Image42 -> Visible = false;
Image43 -> Visible = false;
Image44 -> Visible = false;
Image45 -> Visible = false;

Image46 -> Visible = true;
Image47 -> Visible = true;
Image48 -> Visible = true;
Image49 -> Visible = true;
Image50 -> Visible = true;
Image51 -> Visible = true;
Image52 -> Visible = true;
Image53 -> Visible = true;
Image54 -> Visible = true;
Image55 -> Visible = true;
Image56 -> Visible = true;
Image57 -> Visible = true;
Image58 -> Visible = true;
Image59 -> Visible = true;
Image60 -> Visible = true;
Image61 -> Visible = true;
Image62 -> Visible = true;
Image63 -> Visible = true;
Image64 -> Visible = true;
Image65 -> Visible = true;
Image66 -> Visible = true;
Image67 -> Visible = true;
Image68 -> Visible = true;
Image69 -> Visible = true;
Image70 -> Visible = true;
Image71 -> Visible = true;
Image72 -> Visible = true;
Image73 -> Visible = true;
Image74 -> Visible = true;
Image75 -> Visible = true;
Image76 -> Visible = true;
Image77 -> Visible = true;
Image78 -> Visible = true;
Image79 -> Visible = true;
Image80 -> Visible = true;



      ih1 = p1;             ih7 = p7;
      ih2 = p2;             ih8 = p8;
      ih3 = p3;             ih9 = p9;
      ih4 = p4;             ih10 = p10;
      ih5 = p5;             ih11 = p11;
      ih6 = p6;             ih12 = p12;
      //zapamietywanie liter

Image23 -> Picture -> LoadFromFile("zdjecia/a.bmp");
Image24 -> Picture -> LoadFromFile("zdjecia/b.bmp");
Image25 -> Picture -> LoadFromFile("zdjecia/c.bmp");
Image26 -> Picture -> LoadFromFile("zdjecia/d.bmp");
Image27 -> Picture -> LoadFromFile("zdjecia/e.bmp");
Image28 -> Picture -> LoadFromFile("zdjecia/f.bmp");
Image29 -> Picture -> LoadFromFile("zdjecia/g.bmp");
Image30 -> Picture -> LoadFromFile("zdjecia/h.bmp");
Image31 -> Picture -> LoadFromFile("zdjecia/i.bmp");
Image32 -> Picture -> LoadFromFile("zdjecia/j.bmp");
Image33 -> Picture -> LoadFromFile("zdjecia/k.bmp");
Image34 -> Picture -> LoadFromFile("zdjecia/l.bmp");
Image35 -> Picture -> LoadFromFile("zdjecia/m.bmp");
Image36 -> Picture -> LoadFromFile("zdjecia/n.bmp");
Image37 -> Picture -> LoadFromFile("zdjecia/o.bmp");
Image38 -> Picture -> LoadFromFile("zdjecia/p.bmp");
Image39 -> Picture -> LoadFromFile("zdjecia/r.bmp");
Image40 -> Picture -> LoadFromFile("zdjecia/s.bmp");
Image41 -> Picture -> LoadFromFile("zdjecia/t.bmp");
Image42 -> Picture -> LoadFromFile("zdjecia/u.bmp");
Image43 -> Picture -> LoadFromFile("zdjecia/w.bmp");
Image44 -> Picture -> LoadFromFile("zdjecia/y.bmp");
Image45 -> Picture -> LoadFromFile("zdjecia/z.bmp");
// przywracanie nieskreslonych obrazow liter

Image11 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image12 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image13 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image14 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image15 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image16 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image17 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image18 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image19 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image20 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image21 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
Image22 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
// przywracanie pustych pol - '?'


Image58 -> Picture -> LoadFromFile("zdjecia/a.bmp");
Image59 -> Picture -> LoadFromFile("zdjecia/b.bmp");
Image60 -> Picture -> LoadFromFile("zdjecia/c.bmp");
Image61 -> Picture -> LoadFromFile("zdjecia/d.bmp");
Image62 -> Picture -> LoadFromFile("zdjecia/e.bmp");
Image63 -> Picture -> LoadFromFile("zdjecia/f.bmp");
Image64 -> Picture -> LoadFromFile("zdjecia/g.bmp");
Image65 -> Picture -> LoadFromFile("zdjecia/h.bmp");
Image66 -> Picture -> LoadFromFile("zdjecia/i.bmp");
Image67 -> Picture -> LoadFromFile("zdjecia/j.bmp");
Image68 -> Picture -> LoadFromFile("zdjecia/k.bmp");
Image69 -> Picture -> LoadFromFile("zdjecia/l.bmp");
Image70 -> Picture -> LoadFromFile("zdjecia/m.bmp");
Image71 -> Picture -> LoadFromFile("zdjecia/n.bmp");
Image72 -> Picture -> LoadFromFile("zdjecia/o.bmp");
Image73 -> Picture -> LoadFromFile("zdjecia/p.bmp");
Image74 -> Picture -> LoadFromFile("zdjecia/r.bmp");
Image75 -> Picture -> LoadFromFile("zdjecia/s.bmp");
Image76 -> Picture -> LoadFromFile("zdjecia/t.bmp");
Image77 -> Picture -> LoadFromFile("zdjecia/u.bmp");
Image78 -> Picture -> LoadFromFile("zdjecia/w.bmp");
Image79 -> Picture -> LoadFromFile("zdjecia/y.bmp");
Image80 -> Picture -> LoadFromFile("zdjecia/z.bmp");

if( p1 != '?') {Image46 -> Picture -> LoadFromFile("zdjecia/puste.bmp"); IloscPol++; }
if( p2 != '?') {Image47 -> Picture -> LoadFromFile("zdjecia/puste.bmp"); IloscPol++; }
if( p3 != '?') {Image48 -> Picture -> LoadFromFile("zdjecia/puste.bmp"); IloscPol++; }
if( p4 != '?') {Image49 -> Picture -> LoadFromFile("zdjecia/puste.bmp"); IloscPol++; }
if( p5 != '?') {Image50 -> Picture -> LoadFromFile("zdjecia/puste.bmp"); IloscPol++; }
if( p6 != '?') {Image51 -> Picture -> LoadFromFile("zdjecia/puste.bmp"); IloscPol++; }
if( p7 != '?') {Image52 -> Picture -> LoadFromFile("zdjecia/puste.bmp"); IloscPol++; }
if( p8 != '?') {Image53 -> Picture -> LoadFromFile("zdjecia/puste.bmp"); IloscPol++; }
if( p9 != '?') {Image54 -> Picture -> LoadFromFile("zdjecia/puste.bmp"); IloscPol++; }
if( p10 != '?') {Image55 -> Picture -> LoadFromFile("zdjecia/puste.bmp"); IloscPol++; }
if( p11 != '?') {Image56 -> Picture -> LoadFromFile("zdjecia/puste.bmp"); IloscPol++; }
if( p12 != '?') {Image57 -> Picture -> LoadFromFile("zdjecia/puste.bmp"); IloscPol++; }


pytanieI -> Visible = false;
pytanieII -> Visible = false;

if( NextPlayer )   {ZgadujDrugi -> Visible = true;
                    NextPlayer = false;
                    } else{
                    ZgadujPierwszy -> Visible = true;
                    NextPlayer = true;
                    }

Button6 -> Visible = false;
Image1 -> Visible = true;
}


 /************************************************************/
 /************************************************************/
  /************************************************************/
 /************************************************************/
  /************************************************************/
 /************************************************************/
  /************************************************************/
 /************************************************************/
  /************************************************************/
 /************************************************************/
  /************************************************************/
 /*****                                               ********/
  /*****                                               ********/
   /*****                                               ********/
    /*****                                               ********/
     /*****                                               ********/
      /*****                                               ********/
 /************************************************************/
 /************************************************************/
  /************************************************************/
 /************************************************************/
  /************************************************************/
 /************************************************************/
  /************************************************************/
 /************************************************************/
  /************************************************************/
 /************************************************************/
  /************************************************************/



void __fastcall TForm1::Image58Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

        if( !(p1 == 'a' || p2 == 'a' || p3 == 'a' || p4 == 'a' || p5 == 'a' ||  p6 == 'a'
         || p7 == 'a' || p8 == 'a' || p9 == 'a' || p10 == 'a' || p11 == 'a' ||  p12 == 'a')) {
BledneOdpowiedzi++;
                 Image58 -> Picture -> LoadFromFile("zdjecia/na.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'a'){ Image46 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( p2 == 'a'){ Image47 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( p3 == 'a'){ Image48 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( p4 == 'a'){ Image49 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( p5 == 'a'){ Image50 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( p6 == 'a'){ Image51 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( p7 == 'a'){ Image52 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( p8 == 'a'){ Image53 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( p9 == 'a'){ Image54 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( p10 == 'a'){ Image55 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( p11 == 'a'){ Image56 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( p12 == 'a'){ Image57 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;} byloA = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image59Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

         if( !(p1 == 'b' || p2 == 'b' || p3 == 'b' || p4 == 'b' || p5 == 'b' ||  p6 == 'b'
         || p7 == 'b' || p8 == 'b' || p9 == 'b' || p10 == 'b' || p11 == 'b' ||  p12 == 'b')) {
BledneOdpowiedzi++;
                 Image59 -> Picture -> LoadFromFile("zdjecia/nb.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'b'){ Image46 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( p2 == 'b'){ Image47 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( p3 == 'b'){ Image48 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( p4 == 'b'){ Image49 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( p5 == 'b'){ Image50 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( p6 == 'b'){ Image51 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( p7 == 'b'){ Image52 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( p8 == 'b'){ Image53 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( p9 == 'b'){ Image54 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( p10 == 'b'){ Image55 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( p11 == 'b'){ Image56 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( p12 == 'b'){ Image57 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;} byloB = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image60Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

           if( !(p1 == 'c' || p2 == 'c' || p3 == 'c' || p4 == 'c' || p5 == 'c' ||  p6 == 'c'
         || p7 == 'c' || p8 == 'c' || p9 == 'c' || p10 == 'c' || p11 == 'c' ||  p12 == 'c')) {
BledneOdpowiedzi++;
                 Image60 -> Picture -> LoadFromFile("zdjecia/nc.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'c'){ Image46 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( p2 == 'c'){ Image47 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( p3 == 'c'){ Image48 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( p4 == 'c'){ Image49 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( p5 == 'c'){ Image50 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( p6 == 'c'){ Image51 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( p7 == 'c'){ Image52 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( p8 == 'c'){ Image53 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( p9 == 'c'){ Image54 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( p10 == 'c'){ Image55 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( p11 == 'c'){ Image56 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( p12 == 'c'){ Image57 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;} byloC = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------




void __fastcall TForm1::Image61Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

          if( !(p1 == 'd' || p2 == 'd' || p3 == 'd' || p4 == 'd' || p5 == 'd' ||  p6 == 'd'
         || p7 == 'd' || p8 == 'd' || p9 == 'd' || p10 == 'd' || p11 == 'd' ||  p12 == 'd')) {
BledneOdpowiedzi++;
                 Image61 -> Picture -> LoadFromFile("zdjecia/nd.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'd'){ Image46 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( p2 == 'd'){ Image47 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( p3 == 'd'){ Image48 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( p4 == 'd'){ Image49 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( p5 == 'd'){ Image50 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( p6 == 'd'){ Image51 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( p7 == 'd'){ Image52 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( p8 == 'd'){ Image53 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( p9 == 'd'){ Image54 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( p10 == 'd'){ Image55 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( p11 == 'd'){ Image56 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( p12 == 'd'){ Image57 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;} byloD = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image62Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

           if( !(p1 == 'e' || p2 == 'e' || p3 == 'e' || p4 == 'e' || p5 == 'e' ||  p6 == 'e'
         || p7 == 'e' || p8 == 'e' || p9 == 'e' || p10 == 'e' || p11 == 'e' ||  p12 == 'e')) {
BledneOdpowiedzi++;
                 Image62 -> Picture -> LoadFromFile("zdjecia/ne.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'e'){ Image46 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( p2 == 'e'){ Image47 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( p3 == 'e'){ Image48 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( p4 == 'e'){ Image49 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( p5 == 'e'){ Image50 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( p6 == 'e'){ Image51 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( p7 == 'e'){ Image52 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( p8 == 'e'){ Image53 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( p9 == 'e'){ Image54 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( p10 == 'e'){ Image55 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( p11 == 'e'){ Image56 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( p12 == 'e'){ Image57 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;} byloE = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image63Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

        if( !(p1 == 'f' || p2 == 'f' || p3 == 'f' || p4 == 'f' || p5 == 'f' ||  p6 == 'f'
         || p7 == 'f' || p8 == 'f' || p9 == 'f' || p10 == 'f' || p11 == 'f' ||  p12 == 'f')) {
BledneOdpowiedzi++;
                 Image63 -> Picture -> LoadFromFile("zdjecia/nf.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'f'){ Image46 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( p2 == 'f'){ Image47 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( p3 == 'f'){ Image48 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( p4 == 'f'){ Image49 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( p5 == 'f'){ Image50 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( p6 == 'f'){ Image51 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( p7 == 'f'){ Image52 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( p8 == 'f'){ Image53 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( p9 == 'f'){ Image54 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( p10 == 'f'){ Image55 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( p11 == 'f'){ Image56 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( p12 == 'f'){ Image57 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;} byloF = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image64Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

         if( !(p1 == 'g' || p2 == 'g' || p3 == 'g' || p4 == 'g' || p5 == 'g' ||  p6 == 'g'
         || p7 == 'g' || p8 == 'g' || p9 == 'g' || p10 == 'g' || p11 == 'g' ||  p12 == 'g')) {
BledneOdpowiedzi++;
                 Image64 -> Picture -> LoadFromFile("zdjecia/ng.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'g'){ Image46 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( p2 == 'g'){ Image47 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( p3 == 'g'){ Image48 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( p4 == 'g'){ Image49 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( p5 == 'g'){ Image50 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( p6 == 'g'){ Image51 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( p7 == 'g'){ Image52 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( p8 == 'g'){ Image53 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( p9 == 'g'){ Image54 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( p10 == 'g'){ Image55 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( p11 == 'g'){ Image56 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( p12 == 'g'){ Image57 -> Picture -> LoadFromFile("zdjecia/G.bmp"); if( !(byloG) )IloscPopr++;} byloG = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image65Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

          if( !(p1 == 'h' || p2 == 'h' || p3 == 'h' || p4 == 'h' || p5 == 'h' ||  p6 == 'h'
         || p7 == 'h' || p8 == 'h' || p9 == 'h' || p10 == 'h' || p11 == 'h' ||  p12 == 'h')) {
BledneOdpowiedzi++;
                 Image65 -> Picture -> LoadFromFile("zdjecia/nh.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'h'){ Image46 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( p2 == 'h'){ Image47 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( p3 == 'h'){ Image48 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( p4 == 'h'){ Image49 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( p5 == 'h'){ Image50 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( p6 == 'h'){ Image51 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( p7 == 'h'){ Image52 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( p8 == 'h'){ Image53 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( p9 == 'h'){ Image54 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( p10 == 'h'){ Image55 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( p11 == 'h'){ Image56 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( p12 == 'h'){ Image57 -> Picture -> LoadFromFile("zdjecia/H.bmp"); if( !(byloH) )IloscPopr++;} byloH = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image66Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

          if( !(p1 == 'i' || p2 == 'i' || p3 == 'i' || p4 == 'i' || p5 == 'i' ||  p6 == 'i'
         || p7 == 'i' || p8 == 'i' || p9 == 'i' || p10 == 'i' || p11 == 'i' ||  p12 == 'i')) {
BledneOdpowiedzi++;
                 Image66 -> Picture -> LoadFromFile("zdjecia/ni.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'i'){ Image46 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( p2 == 'i'){ Image47 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( p3 == 'i'){ Image48 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( p4 == 'i'){ Image49 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( p5 == 'i'){ Image50 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( p6 == 'i'){ Image51 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( p7 == 'i'){ Image52 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( p8 == 'i'){ Image53 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( p9 == 'i'){ Image54 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( p10 == 'i'){ Image55 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( p11 == 'i'){ Image56 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( p12 == 'i'){ Image57 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;} byloI = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image67Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

         if( !(p1 == 'j' || p2 == 'j' || p3 == 'j' || p4 == 'j' || p5 == 'j' ||  p6 == 'j'
         || p7 == 'j' || p8 == 'j' || p9 == 'j' || p10 == 'j' || p11 == 'j' ||  p12 == 'j')) {
         BledneOdpowiedzi++;
                 Image67 -> Picture -> LoadFromFile("zdjecia/nj.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'j'){ Image46 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( p2 == 'j'){ Image47 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( p3 == 'j'){ Image48 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( p4 == 'j'){ Image49 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( p5 == 'j'){ Image50 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( p6 == 'j'){ Image51 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( p7 == 'j'){ Image52 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( p8 == 'j'){ Image53 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( p9 == 'j'){ Image54 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( p10 == 'j'){ Image55 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( p11 == 'j'){ Image56 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( p12 == 'j'){ Image57 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;} byloJ = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false;
}




}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image68Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

          if( !(p1 == 'k' || p2 == 'k' || p3 == 'k' || p4 == 'k' || p5 == 'k' ||  p6 == 'k'
         || p7 == 'k' || p8 == 'k' || p9 == 'k' || p10 == 'k' || p11 == 'k' ||  p12 == 'k')) {
BledneOdpowiedzi++;
                 Image68 -> Picture -> LoadFromFile("zdjecia/nk.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'k'){ Image46 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) ) IloscPopr++;}
if( p2 == 'k'){ Image47 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) ) IloscPopr++;}
if( p3 == 'k'){ Image48 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) ) IloscPopr++;}
if( p4 == 'k'){ Image49 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) ) IloscPopr++;}
if( p5 == 'k'){ Image50 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) ) IloscPopr++;}
if( p6 == 'k'){ Image51 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) ) IloscPopr++;}
if( p7 == 'k'){ Image52 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) ) IloscPopr++;}
if( p8 == 'k'){ Image53 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) ) IloscPopr++;}
if( p9 == 'k'){ Image54 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) ) IloscPopr++;}
if( p10 == 'k'){ Image55 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) ) IloscPopr++;}
if( p11 == 'k'){ Image56 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) ) IloscPopr++;}
if( p12 == 'k'){ Image57 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) ) IloscPopr++;} byloK = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image69Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

            if( !(p1 == 'l' || p2 == 'l' || p3 == 'l' || p4 == 'l' || p5 == 'l' ||  p6 == 'l'
         || p7 == 'l' || p8 == 'l' || p9 == 'l' || p10 == 'l' || p11 == 'l' ||  p12 == 'l')) {
BledneOdpowiedzi++;
                 Image69 -> Picture -> LoadFromFile("zdjecia/nl.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'l'){ Image46 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( p2 == 'l'){ Image47 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( p3 == 'l'){ Image48 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( p4 == 'l'){ Image49 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( p5 == 'l'){ Image50 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( p6 == 'l'){ Image51 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( p7 == 'l'){ Image52 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( p8 == 'l'){ Image53 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( p9 == 'l'){ Image54 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( p10 == 'l'){ Image55 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( p11 == 'l'){ Image56 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( p12 == 'l'){ Image57 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;} byloL = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image70Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

          if( !(p1 == 'm' || p2 == 'm' || p3 == 'm' || p4 == 'm' || p5 == 'm' ||  p6 == 'm'
         || p7 == 'm' || p8 == 'm' || p9 == 'm' || p10 == 'm' || p11 == 'm' ||  p12 == 'm')) {
BledneOdpowiedzi++;
                 Image70 -> Picture -> LoadFromFile("zdjecia/nm.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'm'){ Image46 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( p2 == 'm'){ Image47 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( p3 == 'm'){ Image48 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( p4 == 'm'){ Image49 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( p5 == 'm'){ Image50 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( p6 == 'm'){ Image51 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( p7 == 'm'){ Image52 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( p8 == 'm'){ Image53 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( p9 == 'm'){ Image54 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( p10 == 'm'){ Image55 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( p11 == 'm'){ Image56 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( p12 == 'm'){ Image57 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;} byloM = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image71Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

                      if( !(p1 == 'n' || p2 == 'n' || p3 == 'n' || p4 == 'n' || p5 == 'n' ||  p6 == 'n'
         || p7 == 'n' || p8 == 'n' || p9 == 'n' || p10 == 'n' || p11 == 'n' ||  p12 == 'n')) {
BledneOdpowiedzi++;
                 Image71 -> Picture -> LoadFromFile("zdjecia/nn.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'n'){ Image46 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( p2 == 'n'){ Image47 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( p3 == 'n'){ Image48 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( p4 == 'n'){ Image49 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( p5 == 'n'){ Image50 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( p6 == 'n'){ Image51 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( p7 == 'n'){ Image52 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( p8 == 'n'){ Image53 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( p9 == 'n'){ Image54 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( p10 == 'n'){ Image55 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( p11 == 'n'){ Image56 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( p12 == 'n'){ Image57 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;} byloN = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image72Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

          if( !(p1 == 'o' || p2 == 'o' || p3 == 'o' || p4 == 'o' || p5 == 'o' ||  p6 == 'o'
         || p7 == 'o' || p8 == 'o' || p9 == 'o' || p10 == 'o' || p11 == 'o' ||  p12 == 'o')) {
BledneOdpowiedzi++;
                 Image72 -> Picture -> LoadFromFile("zdjecia/no.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'o'){ Image46 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( p2 == 'o'){ Image47 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( p3 == 'o'){ Image48 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( p4 == 'o'){ Image49 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( p5 == 'o'){ Image50 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( p6 == 'o'){ Image51 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( p7 == 'o'){ Image52 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( p8 == 'o'){ Image53 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( p9 == 'o'){ Image54 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( p10 == 'o'){ Image55 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( p11 == 'o'){ Image56 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( p12 == 'o'){ Image57 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;} byloO = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image73Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

             if( !(p1 == 'p' || p2 == 'p' || p3 == 'p' || p4 == 'p' || p5 == 'p' ||  p6 == 'p'
         || p7 == 'p' || p8 == 'p' || p9 == 'p' || p10 == 'p' || p11 == 'p' ||  p12 == 'p')) {
BledneOdpowiedzi++;
                 Image73 -> Picture -> LoadFromFile("zdjecia/np.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'p'){ Image46 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( p2 == 'p'){ Image47 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( p3 == 'p'){ Image48 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( p4 == 'p'){ Image49 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( p5 == 'p'){ Image50 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( p6 == 'p'){ Image51 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( p7 == 'p'){ Image52 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( p8 == 'p'){ Image53 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( p9 == 'p'){ Image54 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( p10 == 'p'){ Image55 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( p11 == 'p'){ Image56 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( p12 == 'p'){ Image57 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;} byloP = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image74Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

        if( !(p1 == 'r' || p2 == 'r' || p3 == 'r' || p4 == 'r' || p5 == 'r' ||  p6 == 'r'
         || p7 == 'r' || p8 == 'r' || p9 == 'r' || p10 == 'r' || p11 == 'r' ||  p12 == 'r')) {
BledneOdpowiedzi++;
                 Image74 -> Picture -> LoadFromFile("zdjecia/nr.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'r'){ Image46 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( p2 == 'r'){ Image47 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( p3 == 'r'){ Image48 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( p4 == 'r'){ Image49 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( p5 == 'r'){ Image50 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( p6 == 'r'){ Image51 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( p7 == 'r'){ Image52 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( p8 == 'r'){ Image53 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( p9 == 'r'){ Image54 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( p10 == 'r'){ Image55 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( p11 == 'r'){ Image56 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( p12 == 'r'){ Image57 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;} byloR = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image75Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

            if( !(p1 == 's' || p2 == 's' || p3 == 's' || p4 == 's' || p5 == 's' ||  p6 == 's'
         || p7 == 's' || p8 == 's' || p9 == 's' || p10 == 's' || p11 == 's' ||  p12 == 's')) {
BledneOdpowiedzi++;
                 Image75 -> Picture -> LoadFromFile("zdjecia/ns.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 's'){ Image46 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( p2 == 's'){ Image47 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( p3 == 's'){ Image48 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( p4 == 's'){ Image49 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( p5 == 's'){ Image50 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( p6 == 's'){ Image51 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( p7 == 's'){ Image52 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( p8 == 's'){ Image53 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( p9 == 's'){ Image54 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( p10 == 's'){ Image55 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( p11 == 's'){ Image56 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( p12 == 's'){ Image57 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;} byloS = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image76Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

           if( !(p1 == 't' || p2 == 't' || p3 == 't' || p4 == 't' || p5 == 't' ||  p6 == 't'
         || p7 == 't' || p8 == 't' || p9 == 't' || p10 == 't' || p11 == 't' ||  p12 == 't')) {
BledneOdpowiedzi++;
                 Image76 -> Picture -> LoadFromFile("zdjecia/nt.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 't'){ Image46 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( p2 == 't'){ Image47 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( p3 == 't'){ Image48 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( p4 == 't'){ Image49 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( p5 == 't'){ Image50 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( p6 == 't'){ Image51 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( p7 == 't'){ Image52 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( p8 == 't'){ Image53 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( p9 == 't'){ Image54 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( p10 == 't'){ Image55 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( p11 == 't'){ Image56 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( p12 == 't'){ Image57 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;} byloT = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image77Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

            if( !(p1 == 'u' || p2 == 'u' || p3 == 'u' || p4 == 'u' || p5 == 'u' ||  p6 == 'u'
         || p7 == 'u' || p8 == 'u' || p9 == 'u' || p10 == 'u' || p11 == 'u' ||  p12 == 'u')) {
BledneOdpowiedzi++;
                 Image77 -> Picture -> LoadFromFile("zdjecia/nu.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'u'){ Image46 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( p2 == 'u'){ Image47 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( p3 == 'u'){ Image48 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( p4 == 'u'){ Image49 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( p5 == 'u'){ Image50 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( p6 == 'u'){ Image51 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( p7 == 'u'){ Image52 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( p8 == 'u'){ Image53 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( p9 == 'u'){ Image54 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( p10 == 'u'){ Image55 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( p11 == 'u'){ Image56 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( p12 == 'u'){ Image57 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;} byloU = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image78Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

            if( !(p1 == 'w' || p2 == 'w' || p3 == 'w' || p4 == 'w' || p5 == 'w' ||  p6 == 'w'
         || p7 == 'w' || p8 == 'w' || p9 == 'w' || p10 == 'w' || p11 == 'w' ||  p12 == 'w')) {
BledneOdpowiedzi++;
                 Image78 -> Picture -> LoadFromFile("zdjecia/nw.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'w'){ Image46 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( p2 == 'w'){ Image47 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( p3 == 'w'){ Image48 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( p4 == 'w'){ Image49 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( p5 == 'w'){ Image50 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( p6 == 'w'){ Image51 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( p7 == 'w'){ Image52 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( p8 == 'w'){ Image53 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( p9 == 'w'){ Image54 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( p10 == 'w'){ Image55 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( p11 == 'w'){ Image56 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( p12 == 'w'){ Image57 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;} byloW = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image79Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

          if( !(p1 == 'y' || p2 == 'y' || p3 == 'y' || p4 == 'y' || p5 == 'y' ||  p6 == 'y'
         || p7 == 'y' || p8 == 'y' || p9 == 'y' || p10 == 'y' || p11 == 'y' ||  p12 == 'y')) {
BledneOdpowiedzi++;
                 Image79 -> Picture -> LoadFromFile("zdjecia/ny.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'y'){ Image46 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( p2 == 'y'){ Image47 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( p3 == 'y'){ Image48 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( p4 == 'y'){ Image49 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( p5 == 'y'){ Image50 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( p6 == 'y'){ Image51 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( p7 == 'y'){ Image52 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( p8 == 'y'){ Image53 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( p9 == 'y'){ Image54 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( p10 == 'y'){ Image55 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( p11 == 'y'){ Image56 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( p12 == 'y'){ Image57 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;} byloY = true;

 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false; 
}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image80Click(TObject *Sender){ sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);

                 if( !(p1 == 'z' || p2 == 'z' || p3 == 'z' || p4 == 'z' || p5 == 'z' ||  p6 == 'z'
         || p7 == 'z' || p8 == 'z' || p9 == 'z' || p10 == 'z' || p11 == 'z' ||  p12 == 'z')) {
BledneOdpowiedzi++;
                 Image80 -> Picture -> LoadFromFile("zdjecia/nz.bmp");
                  if(BledneOdpowiedzi == 0)         Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                   else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                   else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                   else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                   else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                   else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                   else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                   else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                   else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                   else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

                   }
else { if( p1 == 'z'){ Image46 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( p2 == 'z'){ Image47 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( p3 == 'z'){ Image48 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( p4 == 'z'){ Image49 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( p5 == 'z'){ Image50 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( p6 == 'z'){ Image51 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( p7 == 'z'){ Image52 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( p8 == 'z'){ Image53 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( p9 == 'z'){ Image54 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( p10 == 'z'){ Image55 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( p11 == 'z'){ Image56 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( p12 == 'z'){ Image57 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;} byloZ = true;
 if( IloscPopr == IloscPol)Label4 -> Visible = true;  } if( BledneOdpowiedzi == 9 || IloscPopr == IloscPol) {
Image46 -> Visible = false;
Image47 -> Visible = false;
Image48 -> Visible = false;
Image49 -> Visible = false;
Image50 -> Visible = false;
Image51 -> Visible = false;
Image52 -> Visible = false;
Image53 -> Visible = false;
Image54 -> Visible = false;
Image55 -> Visible = false;
Image56 -> Visible = false;
Image57 -> Visible = false;
Image58 -> Visible = false;
Image59 -> Visible = false;
Image60 -> Visible = false;
Image61 -> Visible = false;
Image62 -> Visible = false;
Image63 -> Visible = false;
Image64 -> Visible = false;
Image65 -> Visible = false;
Image66 -> Visible = false;
Image67 -> Visible = false;
Image68 -> Visible = false;
Image69 -> Visible = false;
Image70 -> Visible = false;
Image71 -> Visible = false;
Image72 -> Visible = false;
Image73 -> Visible = false;
Image74 -> Visible = false;
Image75 -> Visible = false;
Image76 -> Visible = false;
Image77 -> Visible = false;
Image78 -> Visible = false;
Image79 -> Visible = false;
Image80 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC);} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true; sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button7 -> Visible = true; ZgadujDrugi -> Visible = false; ZgadujPierwszy -> Visible = false;
}



}









void __fastcall TForm1::Button7Click(TObject *Sender)
{
sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
BledneOdpowiedzi = 0;



IloscPol = 0;
IloscPopr = 0;

     byloA = false; byloB = false; byloC = false; byloD = false; byloE = false;
     byloF = false; byloG = false; byloH = false; byloI = false; byloJ = false;
     byloK = false; byloL = false; byloM = false; byloN = false; byloO = false;
     byloP = false; byloR = false; byloS = false; byloT = false; byloU = false;
     byloW = false; byloY = false; byloZ = false;

    // Image58 -> Picture -> LoadFromFile("zdjecia/a.bmp");
Image46 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
Image47 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
Image48 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
Image49 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
Image50 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
Image51 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
Image52 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
Image53 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
Image54 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
Image55 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
Image56 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
Image57 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");







    p1 = '?';          p7 = '?';
    p2 = '?';          p8 = '?';
    p3 = '?';          p9 = '?';
    p4 = '?';          p10 = '?';
    p5 = '?';          p11 = '?';
    p6 = '?';          p12 = '?';
    //usuwanie liter

Image2 -> Visible = false;
Label3 -> Visible = false; Label4 -> Visible = false;  Button7 -> Visible = false; ZgadujDrugi -> Visible = false;

Image11 -> Visible = true;
Image12 -> Visible = true;
Image13 -> Visible = true;
Image14 -> Visible = true;
Image15 -> Visible = true;
Image16 -> Visible = true;
Image17 -> Visible = true;
Image18 -> Visible = true;
Image19 -> Visible = true;
Image20 -> Visible = true;
Image21 -> Visible = true;
Image22 -> Visible = true;
Image23 -> Visible = true;
Image24 -> Visible = true;
Image25 -> Visible = true;
Image26 -> Visible = true;
Image27 -> Visible = true;
Image28 -> Visible = true;
Image29 -> Visible = true;
Image30 -> Visible = true;
Image31 -> Visible = true;
Image32 -> Visible = true;
Image33 -> Visible = true;
Image34 -> Visible = true;
Image35 -> Visible = true;
Image36 -> Visible = true;
Image37 -> Visible = true;
Image38 -> Visible = true;
Image39 -> Visible = true;
Image40 -> Visible = true;
Image41 -> Visible = true;
Image42 -> Visible = true;
Image43 -> Visible = true;
Image44 -> Visible = true;
Image45 -> Visible = true;

Button6 -> Visible = true;





if( NextPlayer )   {
                    pytanieI -> Visible = true;
                   }else{
                    pytanieII -> Visible = true;
                   }

}








//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
poczatek();
Label8 -> Visible = true;
Wisielec -> Visible = false;

plik.open("przykladowe_wyrazy.txt", ios::in); // plik z przykladowymi slowami.
if(plik.good() == false) Application -> Terminate();    // sprawdzam czy plik istnieje

srand(time(NULL)); // funkcja do generowania liczb losowych   srand -'start radomising'
int los =  (rand()%15)+1; // losowanie liczby z przedzialu(1; 15) , sama funkcja rand()%15 losuje liczby z przedzielu (0;14)
//char litera;

 string linia;
 int nr_linii = 1;


while(getline(plik, linia)){
      tabwyr[nr_linii - 1] = linia;
      nr_linii++;
      }


   /* {switch(los){
    case 1: plik >> slowo;
    case 2: plik >> slowo;
    case 3: plik >> slowo;
    case 4: plik >> slowo;
    case 5: plik >> slowo;
    case 6: plik >> slowo;
    case 7: plik >> slowo;
    case 8: plik >> slowo;
    case 9: plik >> slowo;
    case 10: plik >> slowo;
    case 11: plik >> slowo;
    case 12: plik >> slowo;
    case 13: plik >> slowo;
    case 14: plik >> slowo;
    case 15: plik >> slowo;}  */




plik.close();


    slowo = tabwyr[los-1] ;


    dlugosc = slowo.length();

    AnsiString slowoB;

for(int i=0; i < dlugosc; i++) slowoB = slowoB + slowo[i];



Label2  ->   Visible = true;
Button2 ->   Visible = true;
Button3 ->   Visible = true;
Button4 ->   Visible = false;
Button5 ->   Visible = false;



Image120 -> Picture -> LoadFromFile("zdjecia/a.bmp");
Image121 -> Picture -> LoadFromFile("zdjecia/b.bmp");
Image122 -> Picture -> LoadFromFile("zdjecia/c.bmp");
Image123 -> Picture -> LoadFromFile("zdjecia/d.bmp");
Image124 -> Picture -> LoadFromFile("zdjecia/e.bmp");
Image125 -> Picture -> LoadFromFile("zdjecia/f.bmp");
Image126 -> Picture -> LoadFromFile("zdjecia/g.bmp");
Image127 -> Picture -> LoadFromFile("zdjecia/h.bmp");
Image128 -> Picture -> LoadFromFile("zdjecia/i.bmp");
Image129 -> Picture -> LoadFromFile("zdjecia/j.bmp");
Image130 -> Picture -> LoadFromFile("zdjecia/k.bmp");
Image131 -> Picture -> LoadFromFile("zdjecia/l.bmp");
Image132 -> Picture -> LoadFromFile("zdjecia/m.bmp");
Image133 -> Picture -> LoadFromFile("zdjecia/n.bmp");
Image134 -> Picture -> LoadFromFile("zdjecia/o.bmp");
Image135 -> Picture -> LoadFromFile("zdjecia/p.bmp");
Image136 -> Picture -> LoadFromFile("zdjecia/r.bmp");
Image137 -> Picture -> LoadFromFile("zdjecia/s.bmp");
Image138 -> Picture -> LoadFromFile("zdjecia/t.bmp");
Image139 -> Picture -> LoadFromFile("zdjecia/u.bmp");
Image140 -> Picture -> LoadFromFile("zdjecia/w.bmp");
Image141 -> Picture -> LoadFromFile("zdjecia/y.bmp");
Image142 -> Picture -> LoadFromFile("zdjecia/z.bmp");

if( dlugosc >= 1 ) Image108 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
if( dlugosc >= 2 ) Image109 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
if( dlugosc >= 3 ) Image110 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
if( dlugosc >= 4 ) Image111 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
if( dlugosc >= 5 ) Image112 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
if( dlugosc >= 6 ) Image113 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
if( dlugosc >= 7 ) Image114 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
if( dlugosc >= 8 ) Image115 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
if( dlugosc >= 9 ) Image116 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
if( dlugosc >= 10) Image117 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
if( dlugosc >= 11) Image118 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
if( dlugosc >= 12) Image119 -> Picture -> LoadFromFile("zdjecia/puste.bmp");

Image108 -> Visible = true;
Image109 -> Visible = true;
Image110 -> Visible = true;
Image111 -> Visible = true;
Image112 -> Visible = true;
Image113 -> Visible = true;
Image114 -> Visible = true;
Image115 -> Visible = true;
Image116 -> Visible = true;
Image117 -> Visible = true;
Image118 -> Visible = true;
Image119 -> Visible = true;
Image120 -> Visible = true;
Image121 -> Visible = true;
Image122 -> Visible = true;
Image123 -> Visible = true;
Image124 -> Visible = true;
Image125 -> Visible = true;
Image126 -> Visible = true;
Image127 -> Visible = true;
Image128 -> Visible = true;
Image129 -> Visible = true;
Image130 -> Visible = true;
Image131 -> Visible = true;
Image132 -> Visible = true;
Image133 -> Visible = true;
Image134 -> Visible = true;
Image135 -> Visible = true;
Image136 -> Visible = true;
Image137 -> Visible = true;
Image138 -> Visible = true;
Image139 -> Visible = true;
Image140 -> Visible = true;
Image141 -> Visible = true;
Image142 -> Visible = true;

Image1 -> Visible = true;
Image2 -> Visible = true;

Label5 -> Caption = slowoB;
Label6 -> Caption = dlugosc;
Label7 -> Caption = los;
Label9 -> Caption = slowoB;
}
//---------------------------------------------------------------------------








//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
BledneOdpowiedzi = 0;
Visible = true; Label8-> Visible = false;
 
slowo = "????????????";

 int los = (rand()%15)+1; // losowanie liczby z przedzialu (1;15)
/*
plik.open("przykladowe_wyrazy.txt", ios::in); // plik z przykladowymi slowami.
if(plik.good() == false) Application -> Terminate();

    switch(los){
    case 1: plik >> slowo;
    case 2: plik >> slowo;
    case 3: plik >> slowo;
    case 4: plik >> slowo;
    case 5: plik >> slowo;
    case 6: plik >> slowo;
    case 7: plik >> slowo;
    case 8: plik >> slowo;
    case 9: plik >> slowo;
    case 10: plik >> slowo;
    case 11: plik >> slowo;
    case 12: plik >> slowo;
    case 13: plik >> slowo;
    case 14: plik >> slowo;
    case 15: plik >> slowo;
    }

plik.close();
*/
slowo = tabwyr[los-1];
    
    dlugosc = slowo.length();

    AnsiString slowoB;

for(int i=0; i < dlugosc; i++) slowoB = slowoB + slowo[i];    //tworze kopie slowo do slowoB



IloscPol = 0;
IloscPopr = 0;

     byloA = false; byloB = false; byloC = false; byloD = false; byloE = false;
     byloF = false; byloG = false; byloH = false; byloI = false; byloJ = false;
     byloK = false; byloL = false; byloM = false; byloN = false; byloO = false;
     byloP = false; byloR = false; byloS = false; byloT = false; byloU = false;
     byloW = false; byloY = false; byloZ = false;

     if( slowo[0] != '?' && slowo[0] != '\0') Image108 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
             else  Image108 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
     if( slowo[1] != '?' && slowo[1] != '\0') Image109 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
             else  Image109 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
     if( slowo[2] != '?' && slowo[2] != '\0')Image110 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
             else  Image110 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
     if( slowo[3] != '?' && slowo[3] != '\0')Image111 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
             else  Image111 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
     if( slowo[4] != '?' && slowo[4] != '\0')Image112 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
             else  Image112 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
     if( slowo[5] != '?' && slowo[5] != '\0')Image113 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
             else  Image113 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
     if( slowo[6] != '?' && slowo[6] != '\0')Image114 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
             else  Image114 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
     if( slowo[7] != '?' && slowo[7] != '\0')Image115 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
             else  Image115 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
     if( slowo[8] != '?' && slowo[8] != '\0')Image116 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
             else  Image116 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
     if( slowo[9] != '?' && slowo[9] != '\0')Image117 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
             else  Image117 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
     if( slowo[10] != '?' && slowo[10] != '\0')Image118 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
             else  Image118 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");
     if( slowo[11] != '?' && slowo[11] != '\0')Image119 -> Picture -> LoadFromFile("zdjecia/puste.bmp");
             else  Image119 -> Picture -> LoadFromFile("zdjecia/piksel.bmp");


Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
Image1 -> Visible = true;
Image2 -> Visible = false;
Label3 -> Visible = false; Label4 -> Visible = false;  Button8 -> Visible = false; Button8 ->Caption = "Jeszcze raz!";

Image120 -> Picture -> LoadFromFile("zdjecia/a.bmp");
Image121 -> Picture -> LoadFromFile("zdjecia/b.bmp");
Image122 -> Picture -> LoadFromFile("zdjecia/c.bmp");
Image123 -> Picture -> LoadFromFile("zdjecia/d.bmp");
Image124 -> Picture -> LoadFromFile("zdjecia/e.bmp");
Image125 -> Picture -> LoadFromFile("zdjecia/f.bmp");
Image126 -> Picture -> LoadFromFile("zdjecia/g.bmp");
Image127 -> Picture -> LoadFromFile("zdjecia/h.bmp");
Image128 -> Picture -> LoadFromFile("zdjecia/i.bmp");
Image129 -> Picture -> LoadFromFile("zdjecia/j.bmp");
Image130 -> Picture -> LoadFromFile("zdjecia/k.bmp");
Image131 -> Picture -> LoadFromFile("zdjecia/l.bmp");
Image132 -> Picture -> LoadFromFile("zdjecia/m.bmp");
Image133 -> Picture -> LoadFromFile("zdjecia/n.bmp");
Image134 -> Picture -> LoadFromFile("zdjecia/o.bmp");
Image135 -> Picture -> LoadFromFile("zdjecia/p.bmp");
Image136 -> Picture -> LoadFromFile("zdjecia/r.bmp");
Image137 -> Picture -> LoadFromFile("zdjecia/s.bmp");
Image138 -> Picture -> LoadFromFile("zdjecia/t.bmp");
Image139 -> Picture -> LoadFromFile("zdjecia/u.bmp");
Image140 -> Picture -> LoadFromFile("zdjecia/w.bmp");
Image141 -> Picture -> LoadFromFile("zdjecia/y.bmp");
Image142 -> Picture -> LoadFromFile("zdjecia/z.bmp");

Image108 -> Visible = true;
Image109 -> Visible = true;
Image110 -> Visible = true;
Image111 -> Visible = true;
Image112 -> Visible = true;
Image113 -> Visible = true;
Image114 -> Visible = true;
Image115 -> Visible = true;
Image116 -> Visible = true;
Image117 -> Visible = true;
Image118 -> Visible = true;
Image119 -> Visible = true;
Image120 -> Visible = true;
Image121 -> Visible = true;
Image122 -> Visible = true;
Image123 -> Visible = true;
Image124 -> Visible = true;
Image125 -> Visible = true;
Image126 -> Visible = true;
Image127 -> Visible = true;
Image128 -> Visible = true;
Image129 -> Visible = true;
Image130 -> Visible = true;
Image131 -> Visible = true;
Image132 -> Visible = true;
Image133 -> Visible = true;
Image134 -> Visible = true;
Image135 -> Visible = true;
Image136 -> Visible = true;
Image137 -> Visible = true;
Image138 -> Visible = true;
Image139 -> Visible = true;
Image140 -> Visible = true;
Image141 -> Visible = true;
Image142 -> Visible = true;







Label5 -> Caption = slowoB;
Label6 -> Caption = dlugosc;
Label7 -> Caption = los;
Label9 -> Visible = false;
Label10 -> Visible = false;
Label9 -> Caption = slowoB;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image120Click(TObject *Sender)
{        sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'a' || slowo[1] == 'a' || slowo[2] == 'a' || slowo[3] == 'a' ||
               slowo[4] == 'a' || slowo[5] == 'a' || slowo[6] == 'a' || slowo[7] == 'a' ||
                slowo[8] == 'a' || slowo[9] == 'a' || slowo[10] == 'a' || slowo[11] == 'a') ){


                BledneOdpowiedzi++;
                Image120 -> Picture -> LoadFromFile("zdjecia/na.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'a'){ Image108 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( slowo[1] == 'a'){ Image109 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( slowo[2] == 'a'){ Image110 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( slowo[3] == 'a'){ Image111 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( slowo[4] == 'a'){ Image112 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( slowo[5] == 'a'){ Image113 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( slowo[6] == 'a'){ Image114 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( slowo[7] == 'a'){ Image115 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( slowo[8] == 'a'){ Image116 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( slowo[9] == 'a'){ Image117 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( slowo[10] == 'a'){ Image118 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
if( slowo[11] == 'a'){ Image119 -> Picture -> LoadFromFile("zdjecia/a.bmp"); if( !(byloA) )IloscPopr++;}
byloA = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;  if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}




void __fastcall TForm1::Image121Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'b' || slowo[1] == 'b' || slowo[2] == 'b' || slowo[3] == 'b' ||
               slowo[4] == 'b' || slowo[5] == 'b' || slowo[6] == 'b' || slowo[7] == 'b' ||
                slowo[8] == 'b' || slowo[9] == 'b' || slowo[10] == 'b' || slowo[11] == 'b') ){


                BledneOdpowiedzi++;
                Image121 -> Picture -> LoadFromFile("zdjecia/nb.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'b'){ Image108 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( slowo[1] == 'b'){ Image109 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( slowo[2] == 'b'){ Image110 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( slowo[3] == 'b'){ Image111 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( slowo[4] == 'b'){ Image112 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( slowo[5] == 'b'){ Image113 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( slowo[6] == 'b'){ Image114 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( slowo[7] == 'b'){ Image115 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( slowo[8] == 'b'){ Image116 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( slowo[9] == 'b'){ Image117 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( slowo[10] == 'b'){ Image118 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
if( slowo[11] == 'b'){ Image119 -> Picture -> LoadFromFile("zdjecia/b.bmp"); if( !(byloB) )IloscPopr++;}
byloB = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;
if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image122Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'c' || slowo[1] == 'c' || slowo[2] == 'c' || slowo[3] == 'c' ||
               slowo[4] == 'c' || slowo[5] == 'c' || slowo[6] == 'c' || slowo[7] == 'c' ||
                slowo[8] == 'c' || slowo[9] == 'c' || slowo[10] == 'c' || slowo[11] == 'c') ){


                BledneOdpowiedzi++;
                Image122 -> Picture -> LoadFromFile("zdjecia/nc.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'c'){ Image108 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( slowo[1] == 'c'){ Image109 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( slowo[2] == 'c'){ Image110 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( slowo[3] == 'c'){ Image111 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( slowo[4] == 'c'){ Image112 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( slowo[5] == 'c'){ Image113 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( slowo[6] == 'c'){ Image114 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( slowo[7] == 'c'){ Image115 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( slowo[8] == 'c'){ Image116 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( slowo[9] == 'c'){ Image117 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( slowo[10] == 'c'){ Image118 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
if( slowo[11] == 'c'){ Image119 -> Picture -> LoadFromFile("zdjecia/c.bmp"); if( !(byloC) )IloscPopr++;}
byloC = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;  if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image123Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'd' || slowo[1] == 'd' || slowo[2] == 'd' || slowo[3] == 'd' ||
               slowo[4] == 'd' || slowo[5] == 'd' || slowo[6] == 'd' || slowo[7] == 'd' ||
                slowo[8] == 'd' || slowo[9] == 'd' || slowo[10] == 'd' || slowo[11] == 'd') ){


                BledneOdpowiedzi++;
                Image123 -> Picture -> LoadFromFile("zdjecia/nd.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'd'){ Image108 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( slowo[1] == 'd'){ Image109 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( slowo[2] == 'd'){ Image110 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( slowo[3] == 'd'){ Image111 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( slowo[4] == 'd'){ Image112 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( slowo[5] == 'd'){ Image113 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( slowo[6] == 'd'){ Image114 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( slowo[7] == 'd'){ Image115 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( slowo[8] == 'd'){ Image116 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( slowo[9] == 'd'){ Image117 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( slowo[10] == 'd'){ Image118 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
if( slowo[11] == 'd'){ Image119 -> Picture -> LoadFromFile("zdjecia/d.bmp"); if( !(byloD) )IloscPopr++;}
byloD = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                                                                    if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image124Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'e' || slowo[1] == 'e' || slowo[2] == 'e' || slowo[3] == 'e' ||
               slowo[4] == 'e' || slowo[5] == 'e' || slowo[6] == 'e' || slowo[7] == 'e' ||
                slowo[8] == 'e' || slowo[9] == 'e' || slowo[10] == 'e' || slowo[11] == 'e') ){


                BledneOdpowiedzi++;
                Image124 -> Picture -> LoadFromFile("zdjecia/ne.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'e'){ Image108 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( slowo[1] == 'e'){ Image109 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( slowo[2] == 'e'){ Image110 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( slowo[3] == 'e'){ Image111 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( slowo[4] == 'e'){ Image112 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( slowo[5] == 'e'){ Image113 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( slowo[6] == 'e'){ Image114 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( slowo[7] == 'e'){ Image115 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( slowo[8] == 'e'){ Image116 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( slowo[9] == 'e'){ Image117 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( slowo[10] == 'e'){ Image118 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
if( slowo[11] == 'e'){ Image119 -> Picture -> LoadFromFile("zdjecia/e.bmp"); if( !(byloE) )IloscPopr++;}
byloE = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                                                                                     if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image125Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'f' || slowo[1] == 'f' || slowo[2] == 'f' || slowo[3] == 'f' ||
               slowo[4] == 'f' || slowo[5] == 'f' || slowo[6] == 'f' || slowo[7] == 'f' ||
                slowo[8] == 'f' || slowo[9] == 'f' || slowo[10] == 'f' || slowo[11] == 'f') ){


                BledneOdpowiedzi++;
                Image125 -> Picture -> LoadFromFile("zdjecia/nf.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'f'){ Image108 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( slowo[1] == 'f'){ Image109 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( slowo[2] == 'f'){ Image110 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( slowo[3] == 'f'){ Image111 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( slowo[4] == 'f'){ Image112 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( slowo[5] == 'f'){ Image113 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( slowo[6] == 'f'){ Image114 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( slowo[7] == 'f'){ Image115 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( slowo[8] == 'f'){ Image116 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( slowo[9] == 'f'){ Image117 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( slowo[10] == 'f'){ Image118 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
if( slowo[11] == 'f'){ Image119 -> Picture -> LoadFromFile("zdjecia/f.bmp"); if( !(byloF) )IloscPopr++;}
byloF = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                                                                                                     if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image126Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'g' || slowo[1] == 'g' || slowo[2] == 'g' || slowo[3] == 'g' ||
               slowo[4] == 'g' || slowo[5] == 'g' || slowo[6] == 'g' || slowo[7] == 'g' ||
                slowo[8] == 'g' || slowo[9] == 'g' || slowo[10] == 'g' || slowo[11] == 'g') ){


                BledneOdpowiedzi++;
                Image126 -> Picture -> LoadFromFile("zdjecia/ng.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'g'){ Image108 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( slowo[1] == 'g'){ Image109 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( slowo[2] == 'g'){ Image110 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( slowo[3] == 'g'){ Image111 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( slowo[4] == 'g'){ Image112 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( slowo[5] == 'g'){ Image113 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( slowo[6] == 'g'){ Image114 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( slowo[7] == 'g'){ Image115 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( slowo[8] == 'g'){ Image116 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( slowo[9] == 'g'){ Image117 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( slowo[10] == 'g'){ Image118 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
if( slowo[11] == 'g'){ Image119 -> Picture -> LoadFromFile("zdjecia/g.bmp"); if( !(byloG) )IloscPopr++;}
byloG = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;   if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image127Click(TObject *Sender)
{      sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'h' || slowo[1] == 'h' || slowo[2] == 'h' || slowo[3] == 'h' ||
               slowo[4] == 'h' || slowo[5] == 'h' || slowo[6] == 'h' || slowo[7] == 'h' ||
                slowo[8] == 'h' || slowo[9] == 'h' || slowo[10] == 'h' || slowo[11] == 'h') ){


                BledneOdpowiedzi++;
                Image127 -> Picture -> LoadFromFile("zdjecia/nh.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'h'){ Image108 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( slowo[1] == 'h'){ Image109 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( slowo[2] == 'h'){ Image110 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( slowo[3] == 'h'){ Image111 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( slowo[4] == 'h'){ Image112 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( slowo[5] == 'h'){ Image113 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( slowo[6] == 'h'){ Image114 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( slowo[7] == 'h'){ Image115 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( slowo[8] == 'h'){ Image116 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( slowo[9] == 'h'){ Image117 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( slowo[10] == 'h'){ Image118 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
if( slowo[11] == 'h'){ Image119 -> Picture -> LoadFromFile("zdjecia/h.bmp"); if( !(byloH) )IloscPopr++;}
byloH = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                    if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image128Click(TObject *Sender)
{      sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'i' || slowo[1] == 'i' || slowo[2] == 'i' || slowo[3] == 'i' ||
               slowo[4] == 'i' || slowo[5] == 'i' || slowo[6] == 'i' || slowo[7] == 'i' ||
                slowo[8] == 'i' || slowo[9] == 'i' || slowo[10] == 'i' || slowo[11] == 'i') ){


                BledneOdpowiedzi++;
                Image128 -> Picture -> LoadFromFile("zdjecia/ni.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'i'){ Image108 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( slowo[1] == 'i'){ Image109 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( slowo[2] == 'i'){ Image110 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( slowo[3] == 'i'){ Image111 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( slowo[4] == 'i'){ Image112 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( slowo[5] == 'i'){ Image113 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( slowo[6] == 'i'){ Image114 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( slowo[7] == 'i'){ Image115 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( slowo[8] == 'i'){ Image116 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( slowo[9] == 'i'){ Image117 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( slowo[10] == 'i'){ Image118 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
if( slowo[11] == 'i'){ Image119 -> Picture -> LoadFromFile("zdjecia/i.bmp"); if( !(byloI) )IloscPopr++;}
byloI = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                                     if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image129Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'j' || slowo[1] == 'j' || slowo[2] == 'j' || slowo[3] == 'j' ||
               slowo[4] == 'j' || slowo[5] == 'j' || slowo[6] == 'j' || slowo[7] == 'j' ||
                slowo[8] == 'j' || slowo[9] == 'j' || slowo[10] == 'j' || slowo[11] == 'j') ){


                BledneOdpowiedzi++;
                Image129 -> Picture -> LoadFromFile("zdjecia/nj.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'j'){ Image108 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( slowo[1] == 'j'){ Image109 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( slowo[2] == 'j'){ Image110 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( slowo[3] == 'j'){ Image111 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( slowo[4] == 'j'){ Image112 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( slowo[5] == 'j'){ Image113 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( slowo[6] == 'j'){ Image114 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( slowo[7] == 'j'){ Image115 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( slowo[8] == 'j'){ Image116 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( slowo[9] == 'j'){ Image117 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( slowo[10] == 'j'){ Image118 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
if( slowo[11] == 'j'){ Image119 -> Picture -> LoadFromFile("zdjecia/j.bmp"); if( !(byloJ) )IloscPopr++;}
byloJ = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;  if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image130Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'k' || slowo[1] == 'k' || slowo[2] == 'k' || slowo[3] == 'k' ||
               slowo[4] == 'k' || slowo[5] == 'k' || slowo[6] == 'k' || slowo[7] == 'k' ||
                slowo[8] == 'k' || slowo[9] == 'k' || slowo[10] == 'k' || slowo[11] == 'k') ){


                BledneOdpowiedzi++;
                Image130 -> Picture -> LoadFromFile("zdjecia/nk.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'k'){ Image108 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) )IloscPopr++;}
if( slowo[1] == 'k'){ Image109 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) )IloscPopr++;}
if( slowo[2] == 'k'){ Image110 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) )IloscPopr++;}
if( slowo[3] == 'k'){ Image111 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) )IloscPopr++;}
if( slowo[4] == 'k'){ Image112 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) )IloscPopr++;}
if( slowo[5] == 'k'){ Image113 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) )IloscPopr++;}
if( slowo[6] == 'k'){ Image114 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) )IloscPopr++;}
if( slowo[7] == 'k'){ Image115 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) )IloscPopr++;}
if( slowo[8] == 'k'){ Image116 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) )IloscPopr++;}
if( slowo[9] == 'k'){ Image117 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) )IloscPopr++;}
if( slowo[10] == 'k'){ Image118 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) )IloscPopr++;}
if( slowo[11] == 'k'){ Image119 -> Picture -> LoadFromFile("zdjecia/k.bmp"); if( !(byloK) )IloscPopr++;}
byloK = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                   if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image131Click(TObject *Sender)
{      sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'l' || slowo[1] == 'l' || slowo[2] == 'l' || slowo[3] == 'l' ||
               slowo[4] == 'l' || slowo[5] == 'l' || slowo[6] == 'l' || slowo[7] == 'l' ||
                slowo[8] == 'l' || slowo[9] == 'l' || slowo[10] == 'l' || slowo[11] == 'l') ){


                BledneOdpowiedzi++;
                Image131 -> Picture -> LoadFromFile("zdjecia/nl.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'l'){ Image108 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( slowo[1] == 'l'){ Image109 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( slowo[2] == 'l'){ Image110 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( slowo[3] == 'l'){ Image111 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( slowo[4] == 'l'){ Image112 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( slowo[5] == 'l'){ Image113 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( slowo[6] == 'l'){ Image114 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( slowo[7] == 'l'){ Image115 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( slowo[8] == 'l'){ Image116 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( slowo[9] == 'l'){ Image117 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( slowo[10] == 'l'){ Image118 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
if( slowo[11] == 'l'){ Image119 -> Picture -> LoadFromFile("zdjecia/l.bmp"); if( !(byloL) )IloscPopr++;}
byloL = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                                    if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image132Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'm' || slowo[1] == 'm' || slowo[2] == 'm' || slowo[3] == 'm' ||
               slowo[4] == 'm' || slowo[5] == 'm' || slowo[6] == 'm' || slowo[7] == 'm' ||
                slowo[8] == 'm' || slowo[9] == 'm' || slowo[10] == 'm' || slowo[11] == 'm') ){


                BledneOdpowiedzi++;
                Image132 -> Picture -> LoadFromFile("zdjecia/nm.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'm'){ Image108 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( slowo[1] == 'm'){ Image109 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( slowo[2] == 'm'){ Image110 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( slowo[3] == 'm'){ Image111 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( slowo[4] == 'm'){ Image112 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( slowo[5] == 'm'){ Image113 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( slowo[6] == 'm'){ Image114 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( slowo[7] == 'm'){ Image115 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( slowo[8] == 'm'){ Image116 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( slowo[9] == 'm'){ Image117 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( slowo[10] == 'm'){ Image118 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
if( slowo[11] == 'm'){ Image119 -> Picture -> LoadFromFile("zdjecia/m.bmp"); if( !(byloM) )IloscPopr++;}
byloM = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;            if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image133Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'n' || slowo[1] == 'n' || slowo[2] == 'n' || slowo[3] == 'n' ||
               slowo[4] == 'n' || slowo[5] == 'n' || slowo[6] == 'n' || slowo[7] == 'n' ||
                slowo[8] == 'n' || slowo[9] == 'n' || slowo[10] == 'n' || slowo[11] == 'n') ){


                BledneOdpowiedzi++;
                Image133 -> Picture -> LoadFromFile("zdjecia/nn.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'n'){ Image108 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( slowo[1] == 'n'){ Image109 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( slowo[2] == 'n'){ Image110 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( slowo[3] == 'n'){ Image111 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( slowo[4] == 'n'){ Image112 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( slowo[5] == 'n'){ Image113 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( slowo[6] == 'n'){ Image114 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( slowo[7] == 'n'){ Image115 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( slowo[8] == 'n'){ Image116 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( slowo[9] == 'n'){ Image117 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( slowo[10] == 'n'){ Image118 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
if( slowo[11] == 'n'){ Image119 -> Picture -> LoadFromFile("zdjecia/n.bmp"); if( !(byloN) )IloscPopr++;}
byloN = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;   if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image134Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'o' || slowo[1] == 'o' || slowo[2] == 'o' || slowo[3] == 'o' ||
               slowo[4] == 'o' || slowo[5] == 'o' || slowo[6] == 'o' || slowo[7] == 'o' ||
                slowo[8] == 'o' || slowo[9] == 'o' || slowo[10] == 'o' || slowo[11] == 'o') ){


                BledneOdpowiedzi++;
                Image134 -> Picture -> LoadFromFile("zdjecia/no.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'o'){ Image108 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( slowo[1] == 'o'){ Image109 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( slowo[2] == 'o'){ Image110 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( slowo[3] == 'o'){ Image111 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( slowo[4] == 'o'){ Image112 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( slowo[5] == 'o'){ Image113 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( slowo[6] == 'o'){ Image114 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( slowo[7] == 'o'){ Image115 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( slowo[8] == 'o'){ Image116 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( slowo[9] == 'o'){ Image117 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( slowo[10] == 'o'){ Image118 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
if( slowo[11] == 'o'){ Image119 -> Picture -> LoadFromFile("zdjecia/o.bmp"); if( !(byloO) )IloscPopr++;}
byloO = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                     if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image135Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'p' || slowo[1] == 'p' || slowo[2] == 'p' || slowo[3] == 'p' ||
               slowo[4] == 'p' || slowo[5] == 'p' || slowo[6] == 'p' || slowo[7] == 'p' ||
                slowo[8] == 'p' || slowo[9] == 'p' || slowo[10] == 'p' || slowo[11] == 'p') ){


                BledneOdpowiedzi++;
                Image135 -> Picture -> LoadFromFile("zdjecia/np.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'p'){ Image108 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( slowo[1] == 'p'){ Image109 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( slowo[2] == 'p'){ Image110 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( slowo[3] == 'p'){ Image111 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( slowo[4] == 'p'){ Image112 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( slowo[5] == 'p'){ Image113 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( slowo[6] == 'p'){ Image114 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( slowo[7] == 'p'){ Image115 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( slowo[8] == 'p'){ Image116 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( slowo[9] == 'p'){ Image117 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( slowo[10] == 'p'){ Image118 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
if( slowo[11] == 'p'){ Image119 -> Picture -> LoadFromFile("zdjecia/p.bmp"); if( !(byloP) )IloscPopr++;}
byloP = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                                      if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image136Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'r' || slowo[1] == 'r' || slowo[2] == 'r' || slowo[3] == 'r' ||
               slowo[4] == 'r' || slowo[5] == 'r' || slowo[6] == 'r' || slowo[7] == 'r' ||
                slowo[8] == 'r' || slowo[9] == 'r' || slowo[10] == 'r' || slowo[11] == 'r') ){


                BledneOdpowiedzi++;
                Image136 -> Picture -> LoadFromFile("zdjecia/nr.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'r'){ Image108 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( slowo[1] == 'r'){ Image109 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( slowo[2] == 'r'){ Image110 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( slowo[3] == 'r'){ Image111 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( slowo[4] == 'r'){ Image112 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( slowo[5] == 'r'){ Image113 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( slowo[6] == 'r'){ Image114 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( slowo[7] == 'r'){ Image115 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( slowo[8] == 'r'){ Image116 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( slowo[9] == 'r'){ Image117 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( slowo[10] == 'r'){ Image118 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
if( slowo[11] == 'r'){ Image119 -> Picture -> LoadFromFile("zdjecia/r.bmp"); if( !(byloR) )IloscPopr++;}
byloR = true;
if( IloscPopr == dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                                                       if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image137Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 's' || slowo[1] == 's' || slowo[2] == 's' || slowo[3] == 's' ||
               slowo[4] == 's' || slowo[5] == 's' || slowo[6] == 's' || slowo[7] == 's' ||
                slowo[8] == 's' || slowo[9] == 's' || slowo[10] == 's' || slowo[11] == 's') ){


                BledneOdpowiedzi++;
                Image137 -> Picture -> LoadFromFile("zdjecia/ns.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 's'){ Image108 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( slowo[1] == 's'){ Image109 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( slowo[2] == 's'){ Image110 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( slowo[3] == 's'){ Image111 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( slowo[4] == 's'){ Image112 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( slowo[5] == 's'){ Image113 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( slowo[6] == 's'){ Image114 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( slowo[7] == 's'){ Image115 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( slowo[8] == 's'){ Image116 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( slowo[9] == 's'){ Image117 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( slowo[10] == 's'){ Image118 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
if( slowo[11] == 's'){ Image119 -> Picture -> LoadFromFile("zdjecia/s.bmp"); if( !(byloS) )IloscPopr++;}
byloS = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                                                                        if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image138Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 't' || slowo[1] == 't' || slowo[2] == 't' || slowo[3] == 't' ||
               slowo[4] == 't' || slowo[5] == 't' || slowo[6] == 't' || slowo[7] == 't' ||
                slowo[8] == 't' || slowo[9] == 't' || slowo[10] == 't' || slowo[11] == 't') ){


                BledneOdpowiedzi++;
                Image138 -> Picture -> LoadFromFile("zdjecia/nt.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 't'){ Image108 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( slowo[1] == 't'){ Image109 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( slowo[2] == 't'){ Image110 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( slowo[3] == 't'){ Image111 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( slowo[4] == 't'){ Image112 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( slowo[5] == 't'){ Image113 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( slowo[6] == 't'){ Image114 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( slowo[7] == 't'){ Image115 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( slowo[8] == 't'){ Image116 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( slowo[9] == 't'){ Image117 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( slowo[10] == 't'){ Image118 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
if( slowo[11] == 't'){ Image119 -> Picture -> LoadFromFile("zdjecia/t.bmp"); if( !(byloT) )IloscPopr++;}
byloT = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                                                                                        if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image139Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'u' || slowo[1] == 'u' || slowo[2] == 'u' || slowo[3] == 'u' ||
               slowo[4] == 'u' || slowo[5] == 'u' || slowo[6] == 'u' || slowo[7] == 'u' ||
                slowo[8] == 'u' || slowo[9] == 'u' || slowo[10] == 'u' || slowo[11] == 'u') ){


                BledneOdpowiedzi++;
                Image139 -> Picture -> LoadFromFile("zdjecia/nu.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'u'){ Image108 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( slowo[1] == 'u'){ Image109 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( slowo[2] == 'u'){ Image110 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( slowo[3] == 'u'){ Image111 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( slowo[4] == 'u'){ Image112 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( slowo[5] == 'u'){ Image113 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( slowo[6] == 'u'){ Image114 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( slowo[7] == 'u'){ Image115 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( slowo[8] == 'u'){ Image116 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( slowo[9] == 'u'){ Image117 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( slowo[10] == 'u'){ Image118 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
if( slowo[11] == 'u'){ Image119 -> Picture -> LoadFromFile("zdjecia/u.bmp"); if( !(byloU) )IloscPopr++;}
byloU = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true; if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image140Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'w' || slowo[1] == 'w' || slowo[2] == 'w' || slowo[3] == 'w' ||
               slowo[4] == 'w' || slowo[5] == 'w' || slowo[6] == 'w' || slowo[7] == 'w' ||
                slowo[8] == 'w' || slowo[9] == 'w' || slowo[10] == 'w' || slowo[11] == 'w') ){


                BledneOdpowiedzi++;
                Image140 -> Picture -> LoadFromFile("zdjecia/nw.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'w'){ Image108 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( slowo[1] == 'w'){ Image109 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( slowo[2] == 'w'){ Image110 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( slowo[3] == 'w'){ Image111 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( slowo[4] == 'w'){ Image112 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( slowo[5] == 'w'){ Image113 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( slowo[6] == 'w'){ Image114 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( slowo[7] == 'w'){ Image115 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( slowo[8] == 'w'){ Image116 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( slowo[9] == 'w'){ Image117 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( slowo[10] == 'w'){ Image118 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
if( slowo[11] == 'w'){ Image119 -> Picture -> LoadFromFile("zdjecia/w.bmp"); if( !(byloW) )IloscPopr++;}
byloW = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                                      if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image141Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'y' || slowo[1] == 'y' || slowo[2] == 'y' || slowo[3] == 'y' ||
               slowo[4] == 'y' || slowo[5] == 'y' || slowo[6] == 'y' || slowo[7] == 'y' ||
                slowo[8] == 'y' || slowo[9] == 'y' || slowo[10] == 'y' || slowo[11] == 'y') ){


                BledneOdpowiedzi++;
                Image141 -> Picture -> LoadFromFile("zdjecia/ny.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'y'){ Image108 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( slowo[1] == 'y'){ Image109 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( slowo[2] == 'y'){ Image110 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( slowo[3] == 'y'){ Image111 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( slowo[4] == 'y'){ Image112 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( slowo[5] == 'y'){ Image113 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( slowo[6] == 'y'){ Image114 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( slowo[7] == 'y'){ Image115 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( slowo[8] == 'y'){ Image116 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( slowo[9] == 'y'){ Image117 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( slowo[10] == 'y'){ Image118 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
if( slowo[11] == 'y'){ Image119 -> Picture -> LoadFromFile("zdjecia/y.bmp"); if( !(byloY) )IloscPopr++;}
byloY = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                                                        if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image142Click(TObject *Sender)
{       sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
        if( !(slowo[0] == 'z' || slowo[1] == 'z' || slowo[2] == 'z' || slowo[3] == 'z' ||
               slowo[4] == 'z' || slowo[5] == 'z' || slowo[6] == 'z' || slowo[7] == 'z' ||
                slowo[8] == 'z' || slowo[9] == 'z' || slowo[10] == 'z' || slowo[11] == 'z') ){


                BledneOdpowiedzi++;
                Image142 -> Picture -> LoadFromFile("zdjecia/nz.bmp");

                if(BledneOdpowiedzi == 0)   Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
                else if(BledneOdpowiedzi == 1)   Image1 -> Picture -> LoadFromFile("zdjecia/2.bmp");
                else if(BledneOdpowiedzi == 2)   Image1 -> Picture -> LoadFromFile("zdjecia/3.bmp");
                else if(BledneOdpowiedzi == 3)   Image1 -> Picture -> LoadFromFile("zdjecia/4.bmp");
                else if(BledneOdpowiedzi == 4)   Image1 -> Picture -> LoadFromFile("zdjecia/5.bmp");
                else if(BledneOdpowiedzi == 5)   Image1 -> Picture -> LoadFromFile("zdjecia/6.bmp");
                else if(BledneOdpowiedzi == 6)   Image1 -> Picture -> LoadFromFile("zdjecia/7.bmp");
                else if(BledneOdpowiedzi == 7)   Image1 -> Picture -> LoadFromFile("zdjecia/8.bmp");
                else if(BledneOdpowiedzi == 8)   Image1 -> Picture -> LoadFromFile("zdjecia/9.bmp");
                else if(BledneOdpowiedzi == 9)   Image1 -> Picture -> LoadFromFile("zdjecia/10.bmp");

        } else

{
if( slowo[0] == 'z'){ Image108 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( slowo[1] == 'z'){ Image109 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( slowo[2] == 'z'){ Image110 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( slowo[3] == 'z'){ Image111 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( slowo[4] == 'z'){ Image112 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( slowo[5] == 'z'){ Image113 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( slowo[6] == 'z'){ Image114 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( slowo[7] == 'z'){ Image115 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( slowo[8] == 'z'){ Image116 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( slowo[9] == 'z'){ Image117 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( slowo[10] == 'z'){ Image118 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
if( slowo[11] == 'z'){ Image119 -> Picture -> LoadFromFile("zdjecia/z.bmp"); if( !(byloZ) )IloscPopr++;}
byloZ = true;
if( IloscPopr ==  dlugosc)Label4 -> Visible = true;
}

if( BledneOdpowiedzi == 9 || IloscPopr == dlugosc) {
Image108 -> Visible = false;
Image109 -> Visible = false;
Image110 -> Visible = false;
Image111 -> Visible = false;
Image112 -> Visible = false;
Image113 -> Visible = false;
Image114 -> Visible = false;
Image115 -> Visible = false;
Image116 -> Visible = false;
Image117 -> Visible = false;
Image118 -> Visible = false;
Image119 -> Visible = false;
Image120 -> Visible = false;
Image121 -> Visible = false;
Image122 -> Visible = false;
Image123 -> Visible = false;
Image124 -> Visible = false;
Image125 -> Visible = false;
Image126 -> Visible = false;
Image127 -> Visible = false;
Image128 -> Visible = false;
Image129 -> Visible = false;
Image130 -> Visible = false;
Image131 -> Visible = false;
Image132 -> Visible = false;
Image133 -> Visible = false;
Image134 -> Visible = false;
Image135 -> Visible = false;
Image136 -> Visible = false;
Image137 -> Visible = false;
Image138 -> Visible = false;
Image139 -> Visible = false;
Image140 -> Visible = false;
Image141 -> Visible = false;
Image142 -> Visible = false;
if( BledneOdpowiedzi == 9) {Image2 -> Visible = true; Image2 -> Picture -> LoadFromFile("zdjecia/10.bmp");} else {Image2 -> Picture -> LoadFromFile("zdjecia/usmiech.bmp"); Image2 -> Visible = true;} Image1 -> Visible = false; Image1 -> Picture -> LoadFromFile("zdjecia/1.bmp");
 if( BledneOdpowiedzi == 9) Label3 -> Visible = true; Button2 -> Visible = true; Button8 -> Visible = true; Label8-> Visible = false; Label9-> Visible = true; Label10-> Visible = true;                                                                        if( BledneOdpowiedzi == 9) sndPlaySound("dzwiek/Sad_Trombone-Joe_Lamb-665429450.wav", SND_ASYNC); else sndPlaySound("dzwiek/Fireworks_Finale_SoundBible.wav", SND_ASYNC);
}




        
}



//---------------------------------------------------------------------------



void __fastcall TForm1::Button9Click(TObject *Sender)
{
sndPlaySound("dzwiek/Button-SoundBible.com-1420500901.wav", SND_ASYNC);
Button9  ->   Visible = false;
Label7  ->   Visible = false;
Label6  ->   Visible = false;
Label5  ->   Visible = false;
}
//---------------------------------------------------------------------------








