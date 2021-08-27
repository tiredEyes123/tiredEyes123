//A GAME OF TICKTACKTOE BY tiredEyes aka Adam

#include<iostream>
#include<iomanip>
#include<strings.h>
#define DEPTH 12 //DO NOT CHANGE
#define WIDTH 12//DO NOT CHANGE

using namespace std;
char foaie[DEPTH+2][WIDTH+2];


void intro()
{
        cout<<R"(
          _______ _____     _  _________         _ _______
         |__   __|_   _|   | |/ /__   __|       | |__   __|
            | |    | |  ___| ' /   | | __ _  ___| | _| | ___   ___
            | |    | | / __|  <    | |/ _` |/ __| |/ / |/ _ \ / _ \
            | |   _| || (__| . \   | | (_| | (__|   <| | (_) |  __/
            |_|  |_____\___|_|\_\  |_|\__,_|\___|_|\_\_|\___/ \___|
        )"<<'\n';
        cout<<setw(60)<<right<<"By Adam\a"<<'\n';// please dont change
}


void generare_foaie(){
      int i,j;
      for(i=0;i<=DEPTH;i++)
        for(j=0;j<=WIDTH;j++)
          if(i==0||j==0||i==DEPTH||j==WIDTH)//borders of the paper
              {

                foaie[i][j]='#';

              }
              else if(i%4==0 || j%4==0)// dividing the paper
                  foaie[i][j]='#';
              else foaie[i][j]=' ';
            }
  void afisare_foaie(){//Displays paper
    int i,j;
    for(i=0;i<=DEPTH;i++)
        {cout<<setw(26);
          for(j=0;j<=WIDTH;j++)
          {  cout<<foaie[i][j]<<" ";}
          cout<<endl;
        }
        cout<<endl;

}
int winner(char s[3][3]){
        int i=0 , j = 0,x=0,o=0 ,win=-1;
        for(i=0;i<3;i++){
                    if(s[i][i]=='x') x++;
                    if(s[i][i]=='o')o++;}
                if(x==3) win=1;
                else
                if(o==3)win = 0;
        else{
          x=0;
          o=0;}
        for(i=0;i<3;i++){
                    if(s[i][3-1-i]=='x') x++;
                    if(s[i][3-1-i]=='o')o++;}
                if(x==3) win=1;
                else
                if(o==3)win = 0;
        else{
          x=0;
          o=0;}
          //PARCURGERE PE ORIZONTALA
          for(i=0;i<3;i++)
          {
          for(j=0;j<3;j++){
            if(s[i][j]=='x')x++;
            if(s[i][j]=='o')o++;
          }
          if(x==3){win =1; break;}
          else
          if(o==3){win = 0; break;}
          if(x!=3)x=0;
          if(o!=3)o=0;
          }


         //PARCURGERE PE VERTICALA
          for(j=0;j<3;j++){
            for(i=0;i<3;i++)
            {
            if(s[i][j]=='x')x++;
            if(s[i][j]=='o')o++;
          }
          if(x==3){win =1; break;}
          else
          if(o==3){win = 0; break;}
          if(x!=3)x=0;
          if(o!=3)o=0;
          }


return win;
}



void pune_x(int y, int x){
  int i , j  ;
  int w=y*4+1, z=x*4+1;
  for(i=w;i<=w+2;i++)
  {
    foaie[i][z++]='X';

  }
  z--;
  for(i=w;i<=w+2;i++)

  foaie[i][z--]='X';


}
void pune_o(int y ,int x){
foaie[y*4+2][x*4+1]='O';
foaie[y*4+2][x*4+3]='O';
foaie[y*4+1][x*4+2]='O';
foaie[y*4+3][x*4+2]='O';


}



int main() {
  short i=0;
  short j=0;
  char scheme[3][3];
  for(i=0;i<=2;i++)//problema
  for(j=0 ;j<=2;j++)
  scheme[i][j]=' ';

  string play;
  intro();
  generare_foaie();
  afisare_foaie();
  //gameplay
  int ch;
  ch= '@';
  short y=1,x=1  ;
  short w=4*y,z=4*x   ;
  //scheme[y][x]='@';
    for(i=w;i<=w+4;i++)
      for(j=z;j<=z+4;j++)
      if(i==w || j==z ||i==w+4 ||j== z+4)
      foaie[i][j]='@';


    //foaie[4*y+2][4*x+2]=scheme[y][x];//scaling the scheme to the display
  bool loop = true;
  cout<<setw(60)<<right<<"w IS UP , s IS DOWN , d IS RIGHT , a IS LEFT , x to put x and o to put o\n";
  cout<<"enter any key to play\n";
  cin>>play;

short k=0;
bool ok = false;
afisare_foaie();





  while(loop){


    switch((ch=getchar()))// movemets of the character
    { case 'x'://if(scheme[y][x]=='x' || scheme[y][x]=='o' )break;
              if(ok == false){cout<<"ESTE RANDUL LUI O!!\n";break;}
            scheme[y][x]='x';
              //foaie[4*y+2][4*x+2]=scheme[y][x];
              pune_x(y,x);
              k++; ok=false;
              afisare_foaie();
              break;

    case 'o':if(ok == true){cout<<"ESTE RANDUL LUI X !!\n"; break;}
            scheme[y][x]='o';
              //foaie[4*y+2][4*x+2]=scheme[y][x];
              pune_o(y,x);
              k++;ok= true;
              afisare_foaie();break;


      case 'w':

              for(i=w;i<=w+4;i++)
              for(j=z;j<=z+4;j++)
              if(i==w || j==z ||i==w+4 ||j== z+4)
              foaie[i][j]='#';

              if(y-1<0)break;
              --y;
              w=4*y;z=4*x;
              for(i=w;i<=w+4;i++)
              for(j=z;j<=z+4;j++)
              if(i==w || j==z ||i==w+4 ||j== z+4)
              foaie[i][j]='@';  //scheme[y][x];
              afisare_foaie();
    break;
    case 's':
            for(i=w;i<=w+4;i++)
            for(j=z;j<=z+4;j++)
            if(i==w || j==z ||i==w+4 ||j== z+4)
            foaie[i][j]='#';

            if(y+1>2)break;
            ++y;
        w=4*y;z=4*x;
            for(i=w;i<=w+4;i++)
            for(j=z;j<=z+4;j++)
            if(i==w || j==z ||i==w+4 ||j== z+4)
            foaie[i][j]='@';  //scheme[y][x]

                  afisare_foaie();
          break;
    case 'd':
            for(i=w;i<=w+4;i++)
            for(j=z;j<=z+4;j++)
            if(i==w || j==z ||i==w+4 ||j== z+4)
            foaie[i][j]='#';

            if(x+1>2)break;
            ++x;
          w=4*y;z=4*x;
            for(i=w;i<=w+4;i++)
            for(j=z;j<=z+4;j++)
            if(i==w || j==z ||i==w+4 ||j== z+4)
    foaie[i][j]='@';  //scheme[y][x]          //scheme[y][x];
            afisare_foaie();
    break;
    case 'a':
          for(i=w;i<=w+4;i++)
          for(j=z;j<=z+4;j++)
          if(i==w || j==z ||i==w+4 ||j== z+4)
          foaie[i][j]='#';

            if(x-1<0)break;
          --x;
          w=4*y;z=4*x ;
          for(i=w;i<=w+4;i++)
          for(j=z;j<=z+4;j++)
          if(i==w || j==z ||i==w+4 ||j== z+4)
          foaie[i][j]='@';  //scheme[y][x]        //scheme[y][x];
            afisare_foaie();
    break;

    }
    if(winner(scheme)==0){cout<<"O ESTE CATIGATORUL !!!"<<endl;break;}
if(winner(scheme)==1){cout<<"X ESTE CASTIGATORUL !!!"<<endl; break;}



if(k==9) loop = 0 ;
}

  cout<<"GAME OVER\n";
  for(i=0;i<3;i++)
  {
  for(j=0;j<3;j++)
  cout<<scheme[i][j]<<" ";
  cout<<endl;
}


  return 0;
  return 0;
}
