#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <chrono>
#include <ctime>
#include <iostream>
#include <winbgim.h>
#include <thread>
#include <conio.h>
#include <stdlib.h>
using namespace std;
using namespace chrono;

void meniu();
void ceas_analog();
void ceas_analog_light();
bool exit();
void exit_stopwatch();
 void selectie_meniu();
void  ceas_digital();
 void stopwatch();
void  alarma();
void  timer();
void fus_orar();
void schimba_ora();
void schimba_data();
void schimba_timp();
int iaTimpul_anul();
int iaTimpul_luna();
int iaTimpul_zilele();
int iaTimpul_ora();
int iaTimpul_minutele();

bool anBisect(int an) {
    if ((an % 4 == 0 && an % 100 != 0) || (an % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}



int calculeaza_diferenta(int x,int y){
    int rest;
rest=y-x;
    return rest;
}

int verifica_ora(int x){
    if(x>=48)
        return 0;
    if(x>=24){
        return x-24;
    }
    else if(x<0)
        return -x;
    else return x;
}

int verifica_minutele(int x){
    if(x>=120){
            return 0;

    }

   else if(x>=60){
        return x-60;
    }
    else if(x<0)
        return -x;
    else return x;
}

int verifica_anul(int x){

    if(x<0)
        return -x;
    else return x;
}
int verifica_luna(int x){
    if(x>=26)
        return 1;
    if(x>=13){
        return x-12;
    }
    else if(x<0)
        return -x;
    else return x;
}

int verifica_zi(int x){
    if(x>=64)
        return 1;
    if(x>=32){
        return x-30;
    }
    else if(x<0)
        return -x;
    else return x;
}



//FONTURI SI PARTI GRAFICE
int zz=0,ll=0,aa=0,oo=0,mm=0,ss=0;

 int iaTimpul_zilele(){


    auto ora = std::chrono::system_clock::now();
    std::time_t ora_t = std::chrono::system_clock::to_time_t(ora);
    std::tm* localTime = std::localtime(&ora_t);

    localTime->tm_hour += oo;
    localTime->tm_year += aa;
    localTime->tm_mday += zz;
    localTime->tm_min += mm;
    localTime->tm_mon += ll;
    localTime->tm_sec += ss;

    // converteste inapoi dupa ce adauga
    std::chrono::system_clock::time_point modifiedTime = std::chrono::system_clock::from_time_t(std::mktime(localTime));

    std::time_t modifiedTime_t = std::chrono::system_clock::to_time_t(modifiedTime);
    std::tm* modifiedLocalTime = std::localtime(&modifiedTime_t);
    int zi_mod = modifiedLocalTime->tm_mday;

    // returnez zi
    return zi_mod;

    /*
int zi = localTime->tm_mday+zz;
verifica_zi(zi);
int ziAn,ziLuna;
ziAn=iaTimpul_anul();
ziLuna=iaTimpul_luna();
*/

/*
if(anBisect(ziAn)==1){
    if((ziLuna==2) && zi>29)
        zi=1;
}
else if(anBisect(ziAn)==0){
    if((ziLuna==2)&& zi>28)
        zi=1;
}
else if((ziLuna==4 || ziLuna==6 || ziLuna==9 || ziLuna==11)&& zi>30)
    zi=1;


     return zi;
     */
 }
        int iaTimpul_luna(){


               auto ora = system_clock::now();
    time_t ora_t = system_clock::to_time_t(ora);

    tm* localTime = localtime(&ora_t);

int luna = localTime->tm_mon+1+ll;
verifica_luna(luna);
           // return luna;
        }


        int iaTimpul_anul(){
            auto ora = std::chrono::system_clock::now();
    std::time_t ora_t = std::chrono::system_clock::to_time_t(ora);
    std::tm* localTime = std::localtime(&ora_t);

    localTime->tm_hour += oo;
    localTime->tm_year += aa;
    localTime->tm_mday += zz;
    localTime->tm_min += mm;
    localTime->tm_mon += ll;
    localTime->tm_sec += ss;

    // converteste inapoi dupa ce adauga
    std::chrono::system_clock::time_point modifiedTime = std::chrono::system_clock::from_time_t(std::mktime(localTime));

    std::time_t modifiedTime_t = std::chrono::system_clock::to_time_t(modifiedTime);
    std::tm* modifiedLocalTime = std::localtime(&modifiedTime_t);
    int an_mod = modifiedLocalTime->tm_year;

    // returnez ora
    return an_mod+1900;
           // return anul;
        }

int iaTimpul_ora(){
    auto ora = std::chrono::system_clock::now();
    std::time_t ora_t = std::chrono::system_clock::to_time_t(ora);
    std::tm* localTime = std::localtime(&ora_t);

    localTime->tm_hour += oo;
    localTime->tm_year += aa;
    localTime->tm_mday += zz;
    localTime->tm_min += mm;
    localTime->tm_mon += ll;
    localTime->tm_sec += ss;

    // converteste inapoi dupa ce adauga
    std::chrono::system_clock::time_point modifiedTime = std::chrono::system_clock::from_time_t(std::mktime(localTime));

    std::time_t modifiedTime_t = std::chrono::system_clock::to_time_t(modifiedTime);
    std::tm* modifiedLocalTime = std::localtime(&modifiedTime_t);
    int ora_mod = modifiedLocalTime->tm_hour;

    // returnez ora
    return ora_mod;

}

int iaTimpul_minutele(){
    auto ora = std::chrono::system_clock::now();
    std::time_t ora_t = std::chrono::system_clock::to_time_t(ora);
    std::tm* localTime = std::localtime(&ora_t);

    localTime->tm_hour += oo;
    localTime->tm_year += aa;
    localTime->tm_mday += zz;
    localTime->tm_min += mm;
    localTime->tm_mon += ll;
    localTime->tm_sec += ss;

    // converteste inapoi dupa ce adauga
    std::chrono::system_clock::time_point modifiedTime = std::chrono::system_clock::from_time_t(std::mktime(localTime));

    std::time_t modifiedTime_t = std::chrono::system_clock::to_time_t(modifiedTime);
    std::tm* modifiedLocalTime = std::localtime(&modifiedTime_t);
    int minute_mod = modifiedLocalTime->tm_min;

    // returnez minute
    return minute_mod;

}

int iaTimpul_secundele(){
    auto ora = system_clock::now();
        time_t ora_t = system_clock::to_time_t(ora);
        tm* localTime = localtime(&ora_t);

        int seconds = localTime->tm_sec+ss;
       return seconds;

}

void drawSmallText(int x, int y,  char* text) {
    setbkcolor(BLACK);
    settextstyle(SMALL_FONT, HORIZ_DIR, 7);
    outtextxy(x, y, text);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
}

void drawSmallText_L(int x, int y,  char* text) {
    setbkcolor(WHITE);
    settextstyle(SMALL_FONT, HORIZ_DIR, 7);
    outtextxy(x, y, text);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
}
void playTickTockSound() {
    Beep(10000, 100);
}

void playAlarmSound() {
    Beep(1000, 500);
    Beep(1500, 500);
    Beep(2000, 500);
    Beep(1000, 500);
    Beep(1500, 500);
    Beep(2000, 500);
       Beep(1000, 500);
    Beep(1500, 500);
    Beep(2000, 500);
    Beep(1000, 500);
    Beep(1500, 500);
    Beep(2000, 500);
    Beep(1000, 500);
    Beep(1500, 500);
    Beep(2000, 500);
    Beep(1000, 500);
    Beep(1500, 500);
    Beep(2000, 500);
       Beep(1000, 500);
    Beep(1500, 500);
    Beep(2000, 500);
    Beep(1000, 500);
    Beep(1500, 500);
    Beep(2000, 500);
    Beep(1000, 500);
    Beep(1500, 500);



}

void circles(int x,int y,int r,int a1,int a2,int a3,int b1,int b2,int b3){
    setcolor(RGB(b1, b2, b3));
    setlinestyle(SOLID_LINE, 0, 3);

    setfillstyle(SOLID_FILL,RGB(a1, a2, a3));


         circle(x,y,r);
         floodfill(x, y,RGB(b1, b2, b3));


}
void bg(int L,int l,int n){
if(n==0){
        //cercuri colt albastre
circles(0,0,160,64,123,255,255,255,254);
circles(L-1,0,160,64,123,255,255,255,254);
circles(L-1,l-1,160,64,123,255,255,255,254);
circles(0,l-1,160,64,123,255,255,255,254);
//cercuri colt portocalii
circles(30,30,50,248,156,19,255,255,254);
circles(L-1-30,30,50,248,156,19,255,255,254);
circles(30,l-1-30,50,248,156,19,255,255,254);


}
   if(n==1){
        //cercuri colt albastre
circles(0,0,160,64,123,255,0,0,1);
circles(L-1,0,160,64,123,255,0,0,1);
circles(L-1,l-1,160,64,123,255,0,0,1);
circles(0,l-1,160,64,123,255,0,0,1);
circles(L/2,0,125,248,156,19,0,0,1);
//cercuri colt portocalii
circles(30,30,50,248,156,19,0,0,1);
circles(L-1-30,30,50,248,156,19,0,0,1);
circles(30,l-1-30,50,248,156,19,0,0,1);
circles(L-1-30,l-1-30,50,248,156,19,0,0,1);

setcolor(BLACK);
setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

outtextxy(905,25,"X");

   }


}













//PARTE DE FUNCTIONALITATE PROIECT-meniu
      void introducere(){
       int l,L;
    l=600;
    L=950;

    initwindow(L,l,"Meniu");
       setbkcolor(WHITE);
cleardevice();
    circles(L/2,350,162,64,123,255,255,255,254);//cerc mare
circles(L/2,350,30,255,255,255,255,255,255);//cerc interior
circles(L/2,0,140,64,123,255,255,255,254);
circles(L/2,0,140,64,123,255,255,255,254);//HEADER
bg(L,l,0);
//cercuri decorative portocalii
circles(940,450,50,248,156,19,255,255,253);//buton next
circles(L/2-120,80,40,248,156,19,255,255,253);//buna
circles(L/2-120,460,30,248,156,19,255,255,253);//ceas analog si digital
circles(L/2-90,490,20,248,156,19,255,255,252);//ceas analog si digital
setcolor(BLACK);
//settextstyle(SIMPLEX_FONT, HORIZ_DIR, 4);
//settextstyle(BOLD_FONT, HORIZ_DIR, 4);
//settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
setcolor(WHITE);
setbkcolor(RGB(64,123,255));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

    outtextxy(L / 2 - textwidth("BUNA!") / 2, 50,"BUNA!");

outtextxy(850, 550,"NEXT");
outtextxy(L / 2 - textwidth("CEASUL ANALOG") / 2, 280,"CEASUL ANALOG");

outtextxy(L / 2 - textwidth("CEASUL DIGITAL") / 2, 400,"CEASUL DIGITAL");
setcolor(RGB(64,123,255));
setbkcolor(WHITE);

outtextxy(L / 2 - textwidth("SI") / 2, 340,"SI");

while (!kbhit()) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);

            if (mx > 780 && mx < L ) {
                if (my >500  && my < l) {

                    cleardevice();
                    break;

                }

            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
}
}

void selectie_meniu(){
       while (!kbhit()) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);

            if ((mx > 300 && mx < 550 ) && (my >310  && my < 410)) {

                    cleardevice();
                    setbkcolor(BLACK);
                    cleardevice();

                    ceas_analog();
                    break;


            }

              if ((mx > 600 && mx < 850 ) && (my >310  && my < 410)) {

                   cleardevice();
                    setbkcolor(BLACK);
                    cleardevice();
                   ceas_digital();
                    break;


            }

            if ((mx > 470 && mx < 700 ) && (my >410  && my < 510)) {

cleardevice();
                    setbkcolor(BLACK);
                    cleardevice();
                   stopwatch();
                    break;


            }

             if ((mx > 100 && mx < 230 ) && (my >310  && my < 410)) {

cleardevice();
                    setbkcolor(BLACK);
                    cleardevice();
                    alarma();
                    break;


            }

             if ((mx > 250 && mx < 400 ) && (my >410  && my < 510)) {

cleardevice();
                    setbkcolor(BLACK);
                    cleardevice();
                    timer();
                    break;


            }


                         if ((mx > 350 && mx < 550 ) && (my >490  && my < 540)) {

cleardevice();
                    setbkcolor(BLACK);
                    cleardevice();
                    fus_orar();
                    break;


            }
           // rectangle(340,550,570,598);

             if ((mx > 300 && mx < 610 ) && (my >550  && my < 598)) {

cleardevice();
                    setbkcolor(BLACK);
                    cleardevice();
                    schimba_ora();
                    break;


            }

            clearmouseclick(WM_LBUTTONDOWN);
        }
}
}
void meniu(){
int L=950;
int l=600;

bg(L,l,0);
circles(930,570,50,248,156,19,255,255,254);



circles(L/2,160,140,64,123,255,255,255,254);
circles(L/2,160,125,248,156,19,255,255,254);
setcolor(WHITE);
setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 1.5);

    outtextxy(L / 2 - textwidth("CE ITI DORESTI?") / 2, 160,"CE ITI DORESTI?");
setcolor(BLACK);
setbkcolor(WHITE);

settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);


    outtextxy(100, 360,"ALARMA");
    outtextxy(100+textwidth("ALARMA")+100, 360,"CEAS ANALOG");
    outtextxy(100+textwidth("ALARMA")+textwidth("CEAS ANALOG")+200, 360,"CEAS DIGITAL");
    outtextxy(300, 430,"TIMER");
    outtextxy(300+textwidth("TIMER")+100, 430,"STOPWATCH");
    outtextxy(L / 2 - textwidth("FUS ORAR") / 2-20, 500,"FUS ORAR");
    setcolor(WHITE);

setcolor(RGB(255,65,247));
setfillstyle(SOLID_FILL,RGB(255,65,247));
setcolor(RGB(64,123,255));



rectangle(300,550,610,598);
floodfill(347, 554,RGB(64,123,255));
setbkcolor(RGB(255,65,247));
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    outtextxy(L / 2 - textwidth("SCHIMBA ORA") / 2-20, 565,"SCHIMBA ORA");
    //ceas_analog();
selectie_meniu();
}

//PARTE DE FUNCTIONALITATE PROIECT-END



bool exit(){
     if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);

            if ((mx > 900 && mx < 950 ) && (my >0  && my < 50)) {

                    cleardevice();
                    setbkcolor(WHITE);

                    cleardevice();
                     meniu();
                    // return 1;



            }
             if ((mx > 800 && mx < 900 ) && (my >270  && my < 330)) {

                    cleardevice();
                                        setbkcolor(WHITE);

                    cleardevice();
                     ceas_analog_light();



            }

     }

 //return 0;


}

bool exit_L(){
     if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);

            if ((mx > 900 && mx < 950 ) && (my >0  && my < 50)) {

                    cleardevice();
                    setbkcolor(WHITE);

                    cleardevice();
                     meniu();
                    // return 1;



            }
             if ((mx > 800 && mx < 900 ) && (my >270  && my < 330)) {

                    cleardevice();
                                        setbkcolor(BLACK);

                    cleardevice();
                     ceas_analog();



            }

     }

 //return 0;


}




//CEAS ANALOG-START


void ceas_analog() {

//initwindow(950,600);

    bg(950,600,1);
    int L=950;
int l=600;
setcolor(WHITE);
rectangle(800,270,900,320);

setbkcolor(BLACK);
outtextxy(805,285,"LIGHT");
//circles(L-1-30,l-1-30,50,248,156,19,0,0,1);

    //selectez ora minutele si secundele timpului actual


    int hours = iaTimpul_ora();
    int minutes = iaTimpul_minutele();
    int seconds = iaTimpul_secundele();


    //stop
    setcolor(BLACK);
setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

    if(hours>=12){
        hours=hours-12;

        outtextxy(890,555,"PM");
    }
    else outtextxy(890,555,"AM");

  const float pi = 3.14159265;
setcolor(BLACK);
setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

    outtextxy(950 / 2 - textwidth("CEAS ANALOG") / 2, 30,"CEAS ANALOG");
    setcolor(RGB(64,123,225));

    int xcentru = 475, ycentru = 350;
    setlinestyle(0, 0, 5);
    circle(475, 350, 180);
    setcolor(RGB(248,156,19));
    circle(475, 350, 200);
    circle(475, 350, 210);

    circle(475, 350, 3);

    int xcurent1, ycurent1, xcurent2, ycurent2, xcurent3, ycurent3;
    int raza1 = 80, raza2 = 130, raza3 = 30, raza4 = 160;
    float unghi1, unghi2, unghi3, unghi4;
    int nr = -1;
    unghi1=0;

            for (unghi1 = 0; unghi1 <= 2 * pi; unghi1 += 2 * pi / 60) // minutar
    {
        nr++;
        xcurent1 = xcentru + raza4 * cos(unghi1 - pi / 2);
        ycurent1 = ycentru + raza4 * sin(unghi1 - pi / 2);
        setlinestyle(0, 0, 2);
        setcolor(WHITE);

        if (nr % 5 == 0) {
            circle(xcurent1, ycurent1, 3);
            circle(xcurent1, ycurent1, 1);
        } else
            circle(xcurent1, ycurent1, 1);
    }
drawSmallText(950 / 2 - textwidth("12") / 2,350-170,"12");
drawSmallText(950 / 2 - textwidth("6") / 2,350+150,"6");
drawSmallText(475-170,344,"9");
drawSmallText(475+150,344,"3");
unghi3=hours*(2*pi/12)+(minutes/12)*(2 * pi / 60);
unghi1=minutes*(2*pi/60);
unghi2=seconds*(2*pi/60);
int bucla=1;
int sfert=0;
while(bucla){

    int iesire=0;
    for (unghi3 ; unghi3 <= 2 * pi; unghi3 += 2 * pi / 60) {  //Ora
        sfert=0;
        xcurent3 = xcentru + raza3 * cos(unghi3 - pi / 2);
        ycurent3 = ycentru + raza3 * sin(unghi3 - pi / 2);

        setlinestyle(0, 0, 3);
        setcolor(WHITE);
        line(xcentru, ycentru, xcurent3, ycurent3);

        for (unghi1 ; unghi1 <= 2 * pi; unghi1 += 2 * pi / 60) {   //Minutar

            xcurent1 = xcentru + raza1 * cos(unghi1 - pi / 2);
            ycurent1 = ycentru + raza1 * sin(unghi1 - pi / 2);
            setlinestyle(0, 0, 2);
            setcolor(WHITE);

            line(xcentru, ycentru, xcurent1, ycurent1);
            for (unghi2 ; unghi2 <= 2 * pi; unghi2 += 2 * pi / 60) {  //Secundar
               // circles(xcentru,ycentru,20,248,156,19,0,0,1);
                  if(exit()==1){
                    iesire=1;


               break;

               }

                if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);

            if ((mx > 800 && mx < 900 ) && (my >270  && my < 320)) {

                    cleardevice();
                    setbkcolor(WHITE);
                    cleardevice();
                    ceas_analog_light();





            }
                }

                    circles(xcentru,ycentru,10,248,156,19,0,0,1);
            setlinestyle(0, 0, 3);
        setcolor(WHITE);
        line(xcentru, ycentru, xcurent3, ycurent3);
                xcurent2 = xcentru + raza2 * cos(unghi2 - pi / 2);
                 setlinestyle(0, 0, 2);
            setcolor(WHITE);

            line(xcentru, ycentru, xcurent1, ycurent1);
                ycurent2 = ycentru + raza2 * sin(unghi2 - pi / 2);
                setcolor(rand() % 15 + 1);
                setlinestyle(0, 0, 1);
                line(xcentru, ycentru, xcurent2, ycurent2);
                playTickTockSound();
                setcolor(WHITE);
                circle(xcentru, ycentru, 2);
                delay(1000);





                setcolor(BLACK);
                setlinestyle(0, 0, 1);
                line(xcentru, ycentru, xcurent2, ycurent2);
                setcolor(WHITE);
                circle(xcentru, ycentru, 2);

            }
            sfert++;
            if(sfert%12==0){
                    unghi3 += 2 * pi / 60;
            }
            unghi2=2 * pi / 60;
            setlinestyle(0, 0, 2);
            setcolor(BLACK);
            line(xcentru, ycentru, xcurent1, ycurent1);
            if(iesire==1)
                break;
        }
        unghi1=2 * pi / 60;
        setlinestyle(0, 0, 3);
        setcolor(BLACK);
        line(xcentru, ycentru, xcurent3, ycurent3);
        if(iesire==1)
            break;

    }
    if(iesire==1)
        break;
    unghi3=0;
}


       getch();
       cleardevice();

}
 //CEAS ANALOG-END


//CEAS ANALOG light-START


void ceas_analog_light() {

//initwindow(950,600);

    bg(950,600,0);
    int L=950;
int l=600;
setcolor(BLACK);
rectangle(800,270,900,320);
circles(L/2,1,125,64,123,255,255,255,254);
setbkcolor(WHITE);
setcolor(BLACK);

circles(L-1-30,l-1-30,50,248,156,19,255,255,254);
setbkcolor(RGB(248,156,19));


    //selectez ora minutele si secundele timpului actual

  int hours = iaTimpul_ora();
    int minutes = iaTimpul_minutele();
    int seconds = iaTimpul_secundele();


    //stop
    setcolor(BLACK);

settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
setbkcolor(WHITE);
outtextxy(810,285,"DARK");
setbkcolor(RGB(248,156,19));
setcolor(WHITE);
outtextxy(905,25,"X");

    if(hours>=12){
        hours=hours-12;

        outtextxy(890,555,"PM");
    }
    else outtextxy(890,555,"AM");

  const float pi = 3.14159265;
setcolor(WHITE);
setbkcolor(RGB(64,123,255));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

    outtextxy(950 / 2 - textwidth("CEAS ANALOG") / 2, 30,"CEAS ANALOG");
    setcolor(RGB(64,123,225));

    int xcentru = 475, ycentru = 350;
    setlinestyle(0, 0, 5);
    circle(475, 350, 180);
    setcolor(RGB(248,156,19));
    circle(475, 350, 200);
    circle(475, 350, 210);

    circle(475, 350, 3);

    int xcurent1, ycurent1, xcurent2, ycurent2, xcurent3, ycurent3;
    int raza1 = 80, raza2 = 130, raza3 = 30, raza4 = 160;
    float unghi1, unghi2, unghi3, unghi4;
    int nr = -1;
    unghi1=0;

            for (unghi1 = 0; unghi1 <= 2 * pi; unghi1 += 2 * pi / 60) // minutar
    {
        nr++;
        xcurent1 = xcentru + raza4 * cos(unghi1 - pi / 2);
        ycurent1 = ycentru + raza4 * sin(unghi1 - pi / 2);
        setlinestyle(0, 0, 2);
        setcolor(BLACK);

        if (nr % 5 == 0) {
            circle(xcurent1, ycurent1, 3);
            circle(xcurent1, ycurent1, 1);
        } else
            circle(xcurent1, ycurent1, 1);
    }

drawSmallText_L(950 / 2 - textwidth("12") / 2,350-170,"12");
drawSmallText_L(950 / 2 - textwidth("6") / 2,350+150,"6");
drawSmallText_L(475-170,344,"9");
drawSmallText_L(475+150,344,"3");
unghi3=hours*(2*pi/12)+(minutes/12)*(2 * pi / 60);
unghi1=minutes*(2*pi/60);
unghi2=seconds*(2*pi/60);
int bucla=1;
int sfert=0;
while(bucla){

    int iesire=0;
    for (unghi3 ; unghi3 <= 2 * pi; unghi3 += 2 * pi / 60) {  //Ora
        sfert=0;
        xcurent3 = xcentru + raza3 * cos(unghi3 - pi / 2);
        ycurent3 = ycentru + raza3 * sin(unghi3 - pi / 2);

        setlinestyle(0, 0, 3);
        setcolor(BLACK);
        line(xcentru, ycentru, xcurent3, ycurent3);

        for (unghi1 ; unghi1 <= 2 * pi; unghi1 += 2 * pi / 60) {   //Minutar

            xcurent1 = xcentru + raza1 * cos(unghi1 - pi / 2);
            ycurent1 = ycentru + raza1 * sin(unghi1 - pi / 2);
            setlinestyle(0, 0, 2);
            setcolor(BLACK);

            line(xcentru, ycentru, xcurent1, ycurent1);
            for (unghi2 ; unghi2 <= 2 * pi; unghi2 += 2 * pi / 60) {  //Secundar
               // circles(xcentru,ycentru,20,248,156,19,0,0,1);
                  if(exit_L()==1){
                    iesire=1;


               break;

               }






                    circles(xcentru,ycentru,10,248,156,19,0,0,1);
            setlinestyle(0, 0, 3);
        setcolor(BLACK);
        line(xcentru, ycentru, xcurent3, ycurent3);
                xcurent2 = xcentru + raza2 * cos(unghi2 - pi / 2);
                 setlinestyle(0, 0, 2);
            setcolor(BLACK);

            line(xcentru, ycentru, xcurent1, ycurent1);
                ycurent2 = ycentru + raza2 * sin(unghi2 - pi / 2);
                setcolor(rand() % 15 + 1);
                setlinestyle(0, 0, 1);
                line(xcentru, ycentru, xcurent2, ycurent2);
                playTickTockSound();
                delay(1000);
                setcolor(BLACK);




                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                line(xcentru, ycentru, xcurent2, ycurent2);
                setcolor(BLACK);
                circle(xcentru, ycentru, 2);

            }
            sfert++;
            if(sfert%12==0){
                    unghi3 += 2 * pi / 60;
            }
            unghi2=2 * pi / 60;
            setlinestyle(0, 0, 2);
            setcolor(WHITE);
            line(xcentru, ycentru, xcurent1, ycurent1);
            if(iesire==1)
                break;
        }
        unghi1=2 * pi / 60;
        setlinestyle(0, 0, 3);
        setcolor(WHITE);
        line(xcentru, ycentru, xcurent3, ycurent3);
        if(iesire==1)
            break;

    }
    if(iesire==1)
        break;
    unghi3=0;
}


       getch();
       cleardevice();

}
 //CEAS ANALOG light-END








//CEAS DIGITAL-START


void ceas_digital(){
    //initwindow(950,600,"Ceas digital");
    settextstyle(0,0,3);

   bg(950,600,1);
    int L=950;
int l=600;


//circles(L-1-30,l-1-30,50,248,156,19,0,0,1);
//circles(L/2,0,125,64,123,255,0,0,1);
setcolor(BLACK);
setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

    outtextxy(950 / 2 - textwidth("CEAS DIGITAL") / 2, 30,"CEAS DIGITAL");
setcolor(RGB(248,156,19));
setbkcolor(BLACK);
int h=60;
int w=320;

 setcolor(RGB(236,143,0));
 rectangle(950 / 2 - w / 2-100,355 - h,950 / 2 + w / 2+100,355 + h+20);
 setfillstyle(SOLID_FILL,RGB(236,143,1));
 line(950 / 2 - w / 2-100,355 - h,950 / 2 - w / 2,355 - h-50);//linie stanga sus


 line(950 / 2 + w / 2+100,355 + h+20,950 / 2 + w / 2+200,355 + h+20-50);//linie dreapta jos


 line(950 / 2 + w / 2+100,355 -h,950 / 2 + w / 2+200,355 - h-50);//linie dreapta sus

 line(950 / 2 + w / 2+200,355 - h-50,950 / 2 + w / 2+200,355 + h+20-50);//linie dreapta verticala
 line(950 / 2 - w / 2,355 - h-50,950 / 2 + w / 2+200,355 - h-50);//linie dreapta orizontala
line(950 / 2 - w / 2-100,355 - h,950 / 2 + w / 2+200,355 - h-50);//diagonala sus
line(950 / 2 + w / 2+100,355 + h+20,950 / 2 + w / 2+200,355 - h-50);//linie jos diagonala


         floodfill(950 / 2 - w / 2,355 - h-40,RGB(236,143,0));
         floodfill(950 / 2 + w / 2+190,355 - h-20,RGB(236,143,0));
         setfillstyle(SOLID_FILL,RGB(248,156,19));
         floodfill(950 / 2 + w / 2+100,350 -h,RGB(236,143,0));
          floodfill(950 / 2 + w / 2+120,355 -h,RGB(236,143,0));
          setcolor(RGB(248,156,19));
          rectangle(950 / 2 - w / 2-100,355 - h,950 / 2 + w / 2+100,355 + h+20);
 circles(L/2,599,140,248,156,19,0,0,1);//date cerc

    do
    {
       /*auto ora = system_clock::now();
        time_t ora_t = system_clock::to_time_t(ora);
        tm* localTime = localtime(&ora_t);
*/
        int hours = iaTimpul_ora();
        int minutes =iaTimpul_minutele();
        int seconds = iaTimpul_secundele();
        int day=iaTimpul_zilele();
        int month=iaTimpul_luna();
        int year=iaTimpul_anul();


        // Format and display time
        char timeStr[10];
        //rectangle(950 / 2 - textwidth(timeStr) / 2-100,355 - textheight(timeStr),950 / 2 + textwidth(timeStr) / 2+100,355 + textheight(timeStr));
        sprintf(timeStr, "%02d:%02d:%02d", hours, minutes, seconds);//
        //rectangle(950 / 2 - textwidth(timeStr) / 2-100,355 - textheight(timeStr),950 / 2 + textwidth(timeStr) / 2+100,355 + textheight(timeStr));
setcolor(rand() % 15);
rectangle(950 / 2 - w / 2-100,355 - h,950 / 2 + w / 2+100,355 + h+20);
        setcolor(RGB(64,123,255));

        settextstyle(0, 0, 6);

//exiiiit
 exit();
        outtextxy(950 / 2 - textwidth(timeStr) / 2, 350, timeStr);
         playTickTockSound();

char dateStr[12];
sprintf(dateStr, "%02d. %02d. %04d", day, month, year);
setcolor(BLACK);
setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
        outtextxy(950 / 2 - textwidth(dateStr) / 2, 550, dateStr);
        setbkcolor(BLACK);
        delay(1000);

    }
    while (!kbhit());



}

//CEAS DIGITAL-END


void exit_stopwatch(){
     if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);

            if ((mx > 900 && mx < 950 ) && (my >0  && my < 50)) {

                    cleardevice();
                    setbkcolor(WHITE);

                    cleardevice();
                     meniu();
            }

}

}



   //STOPWATCH-START


int h = 0, m = 0, s = 0;
int t;



void stopwatch_afisare() {
    char timeString[8];
    sprintf(timeString, "%02d:%02d:%02d", h, m, s);

    setcolor(WHITE);
    settextstyle(3, 0, 8);
    outtextxy(950/2-textwidth(timeString)/2, 230, timeString);

}

void drawButtons(int stareActuala) {
    setcolor(RGB(248,156,19));
    settextstyle(3, 0, 2);

    // BUTTON DE START
    rectangle(950/2-137,410, 950/2-65,450);


    // BUTON DE PAUZA
    rectangle(950/2+65,410,950/2+130,450);


    // BUTON DE RESETARE
    rectangle(950/2-30,360,950/2+30,400);
//exit();

}


int este_accesat(int x, int y, int buttonX, int buttonY, int buttonWidth, int buttonHeight) {
    //exit();
    return (x >= buttonX && x <= buttonX + buttonWidth && y >= buttonY && y <= buttonY + buttonHeight);

}

void stopwatch() {
    // initwindow(950,600);
    bg(950,600,1);
    int L=950;
int l=600;


circles(L-1-30,l-1-30,50,248,156,19,0,0,1);
//circles(L/2,0,125,64,123,255,0,0,1);
setcolor(BLACK);
setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);


    outtextxy(950 / 2 - textwidth("STOPWATCH") / 2, 30,"STOPWATCH");
    circles(L/2,350,220,64,123,254,64,123,255);
    circles(L/2,350,210,248,156,19,64,123,255);
    setbkcolor(BLACK);
    setcolor(RGB(64,123,255));
     circles(L/2,390,45,248,156,19,64,123,255);
 circles(L/2+100,430,45,248,156,19,64,123,255);
  circles(L/2-100,430,45,248,156,19,64,123,255);
  setbkcolor(RGB(248,156,19));

    settextstyle(SMALL_FONT, HORIZ_DIR, 7);
    outtextxy((L / 2) - (textwidth("STOP") / 2),385,"STOP");


    outtextxy(L/2-140,425,"START");

    outtextxy(L/2+75,425,"RES");
    setbkcolor(BLACK);

    int stareActuala = 3; // STAREA INITIALA E LA RESETARE
    // settextstyle(3, 0, 8);

    while (1) {
       // exit_stopwatch();
        stopwatch_afisare();

       // drawButtons(stareActuala);
       // exit();
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            if (este_accesat(x, y, 950, 0, 900, 50)) {
            cleardevice();
            setbkcolor(WHITE);
            meniu();
            break;  // iiese din bucla si se intoarce la meniu
        }

            if (este_accesat(x, y, 950/2-140,400, 950/2-60,465) && stareActuala == 3) {
                // APAS  BUTON PT A INCEPE SA CRONOMETREZE
                 //settextstyle(3, 0, 8);
                stareActuala = 1; // FUNCTIONEAZA


            }

            else if (este_accesat(x,y,950/2-40,350,950/2+50,450) && stareActuala == 1) {
                // CLICK PE BUTONUL DE PAUZA

                stareActuala = 2; // PAUZA


            }

            else if (este_accesat(x, y, 950/2+60,400,950/2+140,465)) {
                // CLICK PE BUTONUL DE RESETEAZA
                stareActuala = 3; // STAREA 3 E PT RESETAT
                s = m = h = 0; //RESETEZ DE LA ZERO


                stopwatch_afisare();
            }
             else if (este_accesat(x, y, 950,0,900,50)) {
                 cleardevice();
                    setbkcolor(WHITE);

                    cleardevice();
                     meniu();
                     break;
            }

        }

        if (stareActuala == 1) {
//exit();
            delay(1000); //PUNEM DELAY DE O SECUNDA
         playTickTockSound();
            s++;

            if (s == 60) {
                s = 0;
                m++;

                if (m == 60) {
                    m = 0;
                    h++;

                    if (h == 24) {
                        h = 0;
                    }
                }
            }
        }

    }

    closegraph();
}




//STOPWATCH-END

//fus orar
void fus_orar(){
   // initwindow(950, 600, "Ceas digital");
    settextstyle(0, 0, 3);
    bg(950,600,1);
    int l=600;
    int L=950;

circles(L-1,l-1,160,0,0,0,0,0,0);
circles(0,l-1,160,0,0,0,0,0,0);
    setcolor(BLACK);
setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);


    outtextxy(950 / 2 - textwidth("FUS ORAR") / 2, 30,"FUS ORAR");
   setcolor(RGB(64,123,255));
    //LINIA 1
    rectangle(40,145,250,245);
    rectangle(370,145,580,245);
    rectangle(700,145,910,245);
    //LINIA 2
    rectangle(40,295,250,395);
    rectangle(370,295,580,395);
    rectangle(700,295,910,395);

    //LINIA 3
setfillstyle(SOLID_FILL,BLACK);
    rectangle(40,445,250,545);
    rectangle(370,445,580,545);
    rectangle(700,445,910,545);

 setcolor(RGB(248,156,19));

 setfillstyle(SOLID_FILL,RGB(248,156,19));





      //LINIA 1 S
    rectangle(40,145,250,175);
    rectangle(370,145,580,175);
    rectangle(700,145,910,175);
    //LINIA 2 S
    rectangle(40,295,250,325);
    rectangle(370,295,580,325);
    rectangle(700,295,910,325);

    //LINIA 3 S

    rectangle(40,445,250,475);
    rectangle(370,445,580,475);
    rectangle(700,445,910,475);

    floodfill(45, 150,RGB(248,156,19));
    floodfill(375, 150,RGB(248,156,19));
    floodfill(705, 150,RGB(248,156,19));
    floodfill(45, 300,RGB(248,156,19));
    floodfill(375, 300,RGB(248,156,19));
    floodfill(705, 300,RGB(248,156,19));
    floodfill(45, 450,RGB(248,156,19));
    floodfill(375, 450,RGB(248,156,19));
    floodfill(705, 450,RGB(248,156,19));


setcolor(BLACK);
setbkcolor(RGB(248,156,19));

outtextxy(50, 150, "St. Petersburg");
outtextxy(425, 150, "London");
 outtextxy(760, 150, "Madrid");
 outtextxy(110, 300, "Berlin");
 outtextxy(445, 300, "Paris");
  outtextxy(750, 300, "Moscow");
  outtextxy(95, 450, "Helsinki");
  outtextxy(435, 450, "Tokyo");
  outtextxy(745, 450, "New York");


    do
    {
        exit();
        setbkcolor(BLACK);
setcolor(WHITE);
        // St. Petersburg fus orar

        auto currentTimeStPetersburg = system_clock::now();
        time_t currentTimeStPetersburg_t = system_clock::to_time_t(currentTimeStPetersburg);
        tm* petersburgTime = localtime(&currentTimeStPetersburg_t);
 petersburgTime->tm_hour += 1; // Adaug o ora (offset)
        char timeStPetersburgStr[20];
        strftime(timeStPetersburgStr, sizeof(timeStPetersburgStr), "%H:%M", petersburgTime);
        outtextxy(110, 200, timeStPetersburgStr);

        // London fus orar
        auto currentTimeLondon = system_clock::now();
        time_t currentTimeLondon_t = system_clock::to_time_t(currentTimeLondon);
        tm* londonTime = gmtime(&currentTimeLondon_t);

        char timeLondonStr[20];
        strftime(timeLondonStr, sizeof(timeLondonStr), "%H:%M", londonTime);
        outtextxy(440, 200, timeLondonStr);

        // Madrid fus orar
        auto currentTimeMadrid = system_clock::now();
        time_t currentTimeMadrid_t = system_clock::to_time_t(currentTimeMadrid);
        tm* madridTime = localtime(&currentTimeMadrid_t);
        madridTime->tm_hour += -1; // scad o ora pt madrid

        char timeMadridStr[20];
        strftime(timeMadridStr, sizeof(timeMadridStr), "%H:%M", madridTime);
        outtextxy(770, 200, timeMadridStr);

        // Berlin fus orar
        auto currentTimeBerlin = system_clock::now();
        time_t currentTimeBerlin_t = system_clock::to_time_t(currentTimeBerlin);
        tm* berlinTime = localtime(&currentTimeBerlin_t);
        berlinTime->tm_hour += -1; // scad o ora
        char timeBerlinStr[20];
        strftime(timeBerlinStr, sizeof(timeBerlinStr), "%H:%M", berlinTime);
        outtextxy(110, 350, timeBerlinStr);

        // Paris time (UTC+1)
        auto currentTimeParis = system_clock::now();
        time_t currentTimeParis_t = system_clock::to_time_t(currentTimeParis);
        tm* parisTime = localtime(&currentTimeParis_t);
        parisTime->tm_hour += -1; // scade o ora

        char timeParisStr[20];
        strftime(timeParisStr, sizeof(timeParisStr), "%H:%M", parisTime);
        outtextxy(440, 350, timeParisStr);

        // Moscow time
        auto currentTimeMoscow = system_clock::now();
        time_t currentTimeMoscow_t = system_clock::to_time_t(currentTimeMoscow);
        tm* moscowTime = localtime(&currentTimeMoscow_t);
        moscowTime->tm_hour += 1; // adauga o ora

        char timeMoscowStr[20];
        strftime(timeMoscowStr, sizeof(timeMoscowStr), "%H:%M", moscowTime);
        outtextxy(770, 350, timeMoscowStr);

        // Helsinki time
        auto currentTimeHelsinki = system_clock::now();
        time_t currentTimeHelsinki_t = system_clock::to_time_t(currentTimeHelsinki);
        tm* helsinkiTime = localtime(&currentTimeHelsinki_t);


        char timeHelsinkiStr[20];
        strftime(timeHelsinkiStr, sizeof(timeHelsinkiStr), "%H:%M", helsinkiTime);
        outtextxy(110, 500, timeHelsinkiStr);

           // Tokyo time
        auto currentTimeTokyo = system_clock::now();
        time_t currentTimeTokyo_t = system_clock::to_time_t(currentTimeTokyo);
        tm* tokyoTime = localtime(&currentTimeTokyo_t); // Use localtime for local time

        // adaug 7 ore
        tokyoTime->tm_hour += 7;
        //mktime(tokyoTime); // Ensure correct values after modification

        char timeTokyoStr[20];
        strftime(timeTokyoStr, sizeof(timeTokyoStr), "%H:%M", tokyoTime);
        outtextxy(440, 500, timeTokyoStr);
        // New York time (UTC-5)
        auto currentTimeNewYork = system_clock::now();
        time_t currentTimeNewYork_t = system_clock::to_time_t(currentTimeNewYork);
        tm* nyTime = gmtime(&currentTimeNewYork_t);
        nyTime->tm_hour -= 5; // Subtract 5 hours for New York

        char timeNewYorkStr[20];
        strftime(timeNewYorkStr, sizeof(timeNewYorkStr), "%H:%M", nyTime);
        outtextxy(770, 500, timeNewYorkStr);

       //adaug delay
        delay(1000);
    } while (!kbhit());

}




//Alarma


int zileLuna (int luna, int an){
    if (luna == 1 || luna == 3 || luna == 5 || luna == 7 || luna == 8 || luna == 10 || luna == 12)
        return 31;
    else if (luna == 2){
        if(an % 4 == 0)
            return 29;
        else
            return 28;
    }
    else return 30;
}
void displayAlarm(char s[], char q[]) {
    char v[100];
    outtextxy(100, 50, s);
    outtextxy(100, 79, q);
    exit();
    delay(500);
    exit();


}
void afisareTimer( int oreRamase, int minuteRamase, int secundeRamase){

    char s[50];
    settextstyle(SMALL_FONT, HORIZ_DIR, 20);
    sprintf(s, "    %02d:%02d:%02d    ", oreRamase, minuteRamase, secundeRamase);
    outtextxy( 1100/2-textwidth("%02d:%02d:%02d")/2, 250, s);
}
void extractDate(const std::chrono::system_clock::time_point& timePoint, int& day, int& month, int& year) {
    std::time_t time = std::chrono::system_clock::to_time_t(timePoint);
    std::tm* localTime = std::localtime(&time);

    day = localTime->tm_mday;
    month = localTime->tm_mon + 1;  // lunile incep de la 0 asa ca adaugam 1
    year = localTime->tm_year + 1900;  // tm_year e de la anul 1900
}
int getValue1(char* tipPagina) {
    char inputStr[3] = "";
    while (1) {
        if (kbhit()) {
            char ch = getch();
            if (isdigit(ch) && strlen(inputStr) < 2) {
                int len = strlen(inputStr);
                inputStr[len] = ch;
                inputStr[len + 1] = '\0';

                cleardevice();
                setbkcolor(BLACK);
                cleardevice();
                  bg(950,600,1);

setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

    outtextxy(950 / 2 - textwidth(tipPagina) / 2, 30,tipPagina);
                outtextxy(950 / 2 - textwidth("INTRODUCETI NUMERE DE 2 CIFRE: ") / 2, 200, "INTRODUCETI NUMERE DE DOUA CIFRE: ");
                outtextxy(950 / 2 - textwidth(inputStr)/2, 400, inputStr);
            } else if (ch == 13 && strlen(inputStr) > 0) {
                int value = atoi(inputStr);

                if (value >= 0 && value <= 99) {
                    return value;
                } else {
                    inputStr[0] = '\0';
                    cleardevice();
                }
            }
        }
    }
}



int getValue_an(char* tipPagina) {
    char inputStr[5] = "";
    while (1) {
        if (kbhit()) {
            char ch = getch();
            if (isdigit(ch) && strlen(inputStr) < 4) {
                int len = strlen(inputStr);
                inputStr[len] = ch;
                inputStr[len + 1] = '\0';

                cleardevice();
                setbkcolor(BLACK);
                cleardevice();
                  bg(950,600,1);

setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

    outtextxy(950 / 2 - textwidth(tipPagina) / 2, 30,tipPagina);
                outtextxy(950 / 2 - textwidth("INTRODUCETI NUMERE DE PATRU CIFRE: ") / 2, 200, "INTRODUCETI NUMERE DE PATRU CIFRE: ");
                outtextxy(950 / 2 - textwidth(inputStr)/2, 400, inputStr);
            } else if (ch == 13 && strlen(inputStr) > 0) {
                int value = atoi(inputStr);

                if (value >= 0 && value <= 9999) {
                    return value;
                } else {
                    inputStr[0] = '\0';
                    cleardevice();
                }
            }
        }
    }
}








int dayOfWeek(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int c = year / 100;
    year = year % 100;
    int h = (c / 4 - 2 * c + year + year / 4 + 13 * (month + 1) / 5 + day - 1) % 7;
    h = (h+7)% 7;
    return h;
}

bool timpAlarma(int ora, int minut, int zi, int luna){
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm tm_now = *std::localtime(&now);
    int ziCurenta, lunaCurenta, anCurent;
    char dateStr[12];
    auto oraa = system_clock::now();
    time_t oraa_t = system_clock::to_time_t(oraa);
    tm* timpLocal= localtime(&oraa_t);
    strftime(dateStr, sizeof(dateStr), "%d.%m.%Y", timpLocal);
    extractDate(oraa, ziCurenta, lunaCurenta, anCurent);
    return tm_now.tm_hour == ora && tm_now.tm_min == minut && ziCurenta == zi && lunaCurenta == luna;
}


void alarma(){


    bg(950,600,1);
setcolor(BLACK);
setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

    outtextxy(950 / 2 - textwidth("ALARMA") / 2, 30,"ALARMA");
    auto TimpCurent = std::chrono::system_clock::now();

    char dateStr[12];
    auto ora = system_clock::now();
    int zi, luna, an;
    extractDate(ora, zi, luna, an);

    int oraAlarma, minutAlarma, ziAlarma, lunaAlarma;
    //cleardevice();
   // outtextxy(100, 50, "Introduceti ziua: ");
    outtextxy(950 / 2 - textwidth("INTRODUCETI ZIUA: ") / 2, 200, "INTRODUCETI ZIUA: ");
    ziAlarma = getValue1("ALARMA");
    cleardevice();
    setbkcolor(BLACK);
    cleardevice();
    bg(950,600,1);
    outtextxy(950 / 2 - textwidth("ALARMA") / 2, 30,"ALARMA");

setbkcolor(RGB(248,156,19));
    outtextxy(950 / 2 - textwidth("INTRODUCETI LUNA: ") / 2, 200, "INTRODUCETI LUNA: ");
    lunaAlarma = getValue1("ALARMA");
    cleardevice();
    setbkcolor(BLACK);
    cleardevice();
    bg(950,600,1);
    outtextxy(950 / 2 - textwidth("ALARMA") / 2, 30,"ALARMA");
    outtextxy(950 / 2 - textwidth("INTRODUCETI ORA: ") / 2, 200, "INTRODUCETI ORA: ");
    oraAlarma = getValue1("ALARMA");
    cleardevice();
    setbkcolor(BLACK);
    cleardevice();
    bg(950,600,1);
    outtextxy(950 / 2 - textwidth("ALARMA") / 2, 30,"ALARMA");
    outtextxy(950 / 2 - textwidth("INTRODUCETI MINUTELE: ") / 2, 200, "INTRODUCETI MINUTELE: ");
    minutAlarma = getValue1("ALARMA");
    cleardevice();
    setbkcolor(BLACK);
    cleardevice();
    bg(950,600,1);
    outtextxy(950 / 2 - textwidth("ALARMA") / 2, 30,"ALARMA");
    int anAlarma = 2024;
    int h;
    h = dayOfWeek(anAlarma , lunaAlarma, ziAlarma);

    const char* s[] = { "Duminica", "Luni", "Marti", "Miercuri", "Joi", "Vineri", "Sambata"};
    char v[10], w[15];
    strcpy(v, s[h]);
    const char* q[] = {"Ianuarie", "Feb", "Mar", "Aprilie", "Mai", "Iunie", "Iulie", "August", "Septembrie", "Oct", "Noiem", "DEcem"};
    strcpy(w, q[lunaAlarma-1]);


cleardevice();
setbkcolor(BLACK);
cleardevice();
bg(950,600,1);
    outtextxy(950 / 2 - textwidth("ALARMA") / 2, 30,"ALARMA");



    setcolor(RGB(255,255,254));
      setfillstyle(SOLID_FILL,RGB(248,156,19));

    rectangle(350,510,600,530);
    floodfill(355,515,RGB(255,255,254));
    circles(475,380,150,248,156,19,255,255,255);
     circles(350,250,50,248,156,19,255,255,254);
     circles(600,250,50,248,156,19,255,255,254);
     circles(350,250,35,64,123,255,255,255,254);
     circles(600,250,35,64,123,255,255,255,254);


settextstyle(SMALL_FONT, HORIZ_DIR, 15);
setbkcolor(BLACK);

setcolor(RGB(248,156,19));
setbkcolor(RGB(64,123,255));
setcolor(WHITE);
char timeStr1[10];
sprintf(timeStr1, "    %02d:%02d:00    ", oraAlarma, minutAlarma);
outtextxy(950 / 2 - textwidth(timeStr1) / 2, 400, timeStr1);
setbkcolor(BLACK);
int OK=0;
do
    {


        int hours = iaTimpul_ora();
        int minutes = iaTimpul_minutele();
        int seconds = iaTimpul_secundele();

        // Format and display time
        char timeStr[10];
        //rectangle(950 / 2 - textwidth(timeStr) / 2-100,355 - textheight(timeStr),950 / 2 + textwidth(timeStr) / 2+100,355 + textheight(timeStr));
        sprintf(timeStr, "    %02d:%02d:%02d    ", hours, minutes, seconds);//
        //rectangle(950 / 2 - textwidth(timeStr) / 2-100,355 - textheight(timeStr),950 / 2 + textwidth(timeStr) / 2+100,355 + textheight(timeStr));

settextstyle(SMALL_FONT, HORIZ_DIR, 15);
setbkcolor(BLACK);
 outtextxy(950 / 2 - textwidth(timeStr) / 2, 340, timeStr);
         playTickTockSound();


        setbkcolor(BLACK);

//exiiiit

        if(timpAlarma(oraAlarma, minutAlarma, ziAlarma, lunaAlarma)){
               // cleardevice();

            displayAlarm(v, w);
            playAlarmSound();
            exit();
            break;

        //delay(1000);
    }

 exit();

        delay(1000);

    }
    while (!kbhit());
}

//TIMER-START
/*void afisareTimer( int oreRamase, int minuteRamase, int secundeRamase){

    char s[50];
    settextstyle(SMALL_FONT, HORIZ_DIR, 20);
    sprintf(s, "    %02d:%02d:%02d    ", oreRamase, minuteRamase, secundeRamase);
    outtextxy( 1100/2-textwidth("%02d:%02d:%02d")/2, 250, s);
}*/


//TIMEEERRRRR-START
int getValue() {
    char inputStr[3] = ""; // cresc marimea pentru a putea primi si numere de doua cifre
    while (1) {
        if (kbhit()) {
            char ch = getch();
            if (isdigit(ch) && strlen(inputStr) < 2) {
                // Append the character to the input string
                int len = strlen(inputStr);
                inputStr[len] = ch;
                inputStr[len + 1] = '\0';

                // Display the input string
                cleardevice();
                setbkcolor(BLACK);
                cleardevice();
                bg(950,600,1);
                outtextxy(950 / 2 - textwidth("TIMER") / 2, 30,"TIMER");
                outtextxy(950 / 2 - textwidth("INTRODU UN NUMAR DE DOUA CIFRE") / 2, 200,"INTRODU UN NUMAR DE DOUA CIFRE");
                //outtextxy(, 50, "Enter a two-digit number:");
                outtextxy(950 / 2 - textwidth(inputStr) / 2, 300, inputStr);
            } else if (ch == 13 && strlen(inputStr) > 0) { // Enter key
                int value = atoi(inputStr);

                // Check if the entered value is a two-digit number
                if (value >= 0 && value <= 99) {
                    return value;
                } else {
                    // Clear the input string and display an error message
                    inputStr[0] = '\0';
                    //cleardevice();
                    outtextxy(100, 50, "Invalid input. Please enter a two-digit number:");
                }
            }
        }
    }
}


void timer(){
    //initwindow(950, 600, "Timer");
    bg(950,600,1);

    int ore, minute, secunde;
setcolor(BLACK);
setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);

    outtextxy(950 / 2 - textwidth("TIMER") / 2, 30,"TIMER");

    outtextxy(950 / 2 - textwidth("INTRODUCETI ORA: ") / 2, 200, "INTRODUCETI ORA: ");
    ore = getValue();
     cleardevice();
                setbkcolor(BLACK);
                cleardevice();
                bg(950,600,1);
                outtextxy(950 / 2 - textwidth("TIMER") / 2, 30,"TIMER");
    outtextxy(950 / 2 - textwidth("INTRODUCETI MINUTELE : ") / 2, 200, "INTRODUCETI MINUTELE: ");
    minute = getValue();
     cleardevice();
                setbkcolor(BLACK);
                cleardevice();
                bg(950,600,1);
                outtextxy(950 / 2 - textwidth("TIMER") / 2, 30,"TIMER");
    outtextxy(950 / 2 - textwidth("INTRODUCETI SECUNDELE: ") / 2, 200, "INTRODUCETI SECUNDELE: ");
    secunde = getValue();
    cleardevice();
    setbkcolor(BLACK);
cleardevice();
settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
bg(950,600,1);
outtextxy(950 / 2 - textwidth("TIMER") / 2, 30,"TIMER");

    auto duration = std::chrono::hours(ore) + std::chrono::minutes(minute) + std::chrono::seconds(secunde); ///transformam tot timpul introdus in secunde

    auto timpInitial = std::chrono::high_resolution_clock::now();
    bool pause = false;
    bool running = true;

    if (ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            int x = mousex();
            int y = mousey();
            if ( x > 300 && x<450 && y>300 && y<350){
                pause = false;
                timpInitial = std::chrono::high_resolution_clock::now();
                running = true;
            }
             bg(950,600,1);
             outtextxy(950 / 2 - textwidth("TIMER") / 2, 30,"TIMER");
    }
    while (running) {
             //bg(950,600,1);
        auto timpCurent = std::chrono::high_resolution_clock::now();
        auto secundeTrecute = std::chrono::duration_cast<std::chrono::seconds>(timpCurent - timpInitial).count();
        auto timpRamas = std::max(std::chrono::seconds(0), duration - std::chrono::seconds(secundeTrecute));
if(exit()==1){
    break;
}
        int oreRamase = std::chrono::duration_cast<std::chrono::hours>(timpRamas).count();
        int minuteRamase = std::chrono::duration_cast<std::chrono::minutes>(timpRamas % std::chrono::hours(1)).count();
        int secundeRamase = std::chrono::duration_cast<std::chrono::seconds>(timpRamas % std::chrono::minutes(1)).count();


        afisareTimer(oreRamase, minuteRamase, secundeRamase);

        delay(1000);
        playTickTockSound();
       // playTickTockSound();
       // cleardevice();
}

}


//TIMER-END



//SCHIMBA ORA------START
void schimba_ora(){
    settextstyle(0, 0, 3);
    bg(950,600,1);
    int l=600;
    int L=950;



    setcolor(BLACK);
setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
outtextxy(950 / 2 - textwidth("ORA SI DATA") / 2, 30,"ORA SI DATA");
//setbkcolor(WHITE);
setcolor(BLACK);
int r=200;
setfillstyle(SOLID_FILL,BLACK);


setcolor(RGB(255,65,247));


rectangle(200,r,750,250);
rectangle(200,r+150,750,r+200);
rectangle(200,r+300,750,r+350);
floodfill(250,r+5,RGB(255,65,247));
floodfill(250,r+165,RGB(255,65,247));
floodfill(250,r+315,RGB(255,65,247));

setcolor(WHITE);
setbkcolor(BLACK);
outtextxy(950 / 2 - textwidth("RAMAI/REVIN-O LA TIMPUL ACTUAL") / 2, r+15,"RAMAI/REVIN-O LA TIMPUL ACTUAL");
    outtextxy(950 / 2 - textwidth("SCHIMBA DATA") / 2, r+165,"SCHIMBA DATA");
    outtextxy(950 / 2 - textwidth("SCHIMBA ORA") / 2, r+315,"SCHIMBA ORA");
 while (!kbhit()) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);

            if ((mx > 200 && mx < 750 ) && ((my >r)  && (my < 250))) {
                          zz=0;
                          aa=0;
                          ll=0;
                          oo=0;
                          mm=0;
                    cleardevice();
              setbkcolor(WHITE);
                    cleardevice();
                    meniu();
                    break;


            }
              if ((mx > 200 && mx < 750 ) && ((my >r+300)  && (my < r+350))) {

                    cleardevice();
                    setbkcolor(BLACK);
                    cleardevice();
                   schimba_timp();
                    break;


            }
             if ((mx > 200 && mx < 750 ) && ((my >r+150)  && (my < r+200))) {

                    cleardevice();
                    setbkcolor(BLACK);
                    cleardevice();
                    schimba_data();
                    break;


            }
             if ((mx > 900 && mx < 950 ) && (my >0  && my < 50)) {

                    cleardevice();
                    setbkcolor(WHITE);

                    cleardevice();
                     meniu();}







            clearmouseclick(WM_LBUTTONDOWN);
        }
}

}

void schimba_data(){
      settextstyle(0, 0, 3);
    bg(950,600,1);
    int l=600;
    int L=950;

ll=0;
zz=0;
aa=0;
int llc,zzc,aac;

    setcolor(BLACK);
setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
outtextxy(950 / 2 - textwidth("ORA SI DATA") / 2, 30,"ORA SI DATA");
int lunaSchimba,anSchimba,ziSchimba;


outtextxy(950 / 2 - textwidth("ORA SI DATA") / 2, 30,"ORA SI DATA");
    outtextxy(950 / 2 - textwidth("INTRODUCETI ANUL: ") / 2, 200, "INTRODUCETI ANUL: ");
    anSchimba = getValue_an("ORA SI DATA");

    aac=calculeaza_diferenta(iaTimpul_anul(),anSchimba);
    aa=aac;
    cleardevice();
    setbkcolor(BLACK);
    cleardevice();
    bg(950,600,1);

outtextxy(950 / 2 - textwidth("ORA SI DATA") / 2, 30,"ORA SI DATA");
outtextxy(950 / 2 - textwidth("INTRODUCETI LUNA: ") / 2, 200, "INTRODUCETI LUNA: ");
    lunaSchimba = getValue1("ORA SI DATA");
    //if(lunaSchimba>12 || lunaSchimba==0)
       // lunaSchimba=1;
    llc=calculeaza_diferenta(iaTimpul_luna(),lunaSchimba);
    ll=llc;
    cleardevice();
    setbkcolor(BLACK);
    cleardevice();
    bg(950,600,1);




    outtextxy(950 / 2 - textwidth("ORA SI DATA") / 2, 30,"ORA SI DATA");
    outtextxy(950 / 2 - textwidth("INTRODUCETI ZIUA: ") / 2, 200, "INTRODUCETI ZIUA: ");
    ziSchimba = getValue1("ORA SI DATA");
    //if(ziSchimba>31 || ziSchimba==0)
        //ziSchimba=1;
    zzc=calculeaza_diferenta(iaTimpul_zilele(),ziSchimba);
    zz=zzc;


    cleardevice();
    setbkcolor(WHITE);
    cleardevice();
    meniu();

}
void schimba_timp(){
      settextstyle(0, 0, 3);
    bg(950,600,1);
    int l=600;
    int L=950;
oo=0;
mm=0;

int oraSchimba,minuteSchimba;

    setcolor(BLACK);
setbkcolor(RGB(248,156,19));
settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
outtextxy(950 / 2 - textwidth("ORA SI DATA") / 2, 30,"ORA SI DATA");
int ooc;
outtextxy(950 / 2 - textwidth("INTRODUCETI ORA: ") / 2, 200, "INTRODUCETI ORA: ");
    oraSchimba = getValue1("ORA SI DATA");
    if(oraSchimba>=24)
        oraSchimba=0;
    ooc=calculeaza_diferenta(iaTimpul_ora(),oraSchimba);
    oo=ooc;
    cleardevice();
    setbkcolor(BLACK);
    cleardevice();
    bg(950,600,1);
    outtextxy(950 / 2 - textwidth("ORA SI DATA") / 2, 30,"ORA SI DATA");
    outtextxy(950 / 2 - textwidth("INTRODUCETI MINUTELE: ") / 2, 200, "INTRODUCETI MINUTELE: ");
    minuteSchimba = getValue1("ORA SI DATA");
    if(minuteSchimba>=60)
        minuteSchimba=0;
    mm=calculeaza_diferenta(iaTimpul_minutele(),minuteSchimba);

    cleardevice();
    setbkcolor(WHITE);
    cleardevice();
    meniu();
}

//SCHIMBA ORA-------END


int main()
{

 introducere();
meniu();
selectie_meniu();



    getch();
    closegraph();
    return 0;
}
