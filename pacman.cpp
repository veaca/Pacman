#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


//int start_t= clock();
int labirin[50][50];
int currentScreen=1;
int nextScreen=2;
int keyInput=-1;
int x=12;
int y=12;
int counter=0;

bool moveup=false;
bool movedown=false;
bool moveleft=false;
bool moveright=false;
bool kalah=false;

bool musuhupa=false;
bool musuhdowna=false;
bool musuhlefta=false;
bool musuhrighta=false;

bool musuhupb=false;
bool musuhdownb=false;
bool musuhleftb=false;
bool musuhrightb=false;

bool musuhupc=false;
bool musuhdownc=false;
bool musuhleftc=false;
bool musuhrightc=false;

int a1=17, a2=6;
int b1=4, b2=4;
int c1=2, c2=14;

void gotoxy(short x,short y){
    	COORD pos={x,y};
    	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    }

void cls(){
      system("cls");
    }

void start(){
	printf ("PACMAN!\n");
	if (nextScreen==2){
		printf ("-> START <-\n");
		printf ("   EXIT\n");
	}
	else if (nextScreen==0){
		printf ("   START\n");
		printf ("-> EXIT <-\n");
		
	}
	
}

void menang(){
	printf ("CONGRATULATIONS!\n");
	printf ("PRESS ENTER TO EXIT!\n");
}

void end(){
	printf ("GAME OVER!\n");
	printf ("PRESS ENTER TO EXIT!\n");
}

int kotak(){
	int i,j;
	//kotak luar
	for (i=1;i<=1;i++){
		for (j=1;j<=23;j++){
			labirin [i][j]=1;
			labirin	[j][i]=1;	
		}
	}
	for (i=23;i<=23;i++){
		for (j=1;j<=23;j++){
			labirin [i][j]=1;
			labirin	[j][i]=1;	
		}
	}
	
	// labirin dalam
	for (i=2;i<=22;i++){
		for (j=2;j<=22;j++){
			if (j==4){
				if (i==3){
					labirin[i][j]=1;
				}
			}
			if (j==3 || j==5 || j==6 || j==7 ||j==8 ||j==9||j==10||j==11||j==12||j==13||j==14||j==15||j==16||j==17){
				labirin[i][j]=1;
				if (j==3 && (i==2 || i==22)){
					labirin [i][j]=0;
				}
				if (j==5 && (i==2 || (i==5) || (i==12) || (i==20))){
					labirin [i][j]=0;
				}
				if (j==6) {
					if (i==2||(i==5 || (i==20)|| (i==22))) labirin [i][j]=0;
					if (i==12||i==13||i==14||i==15||i==17||i==18) labirin [i][j]=0;
				}
				if (j==7){
					if (i==6||i==7||i==11||i==13||i==14||i==15||i==16||i==17||i==19||i==21) labirin [i][j]=1;
					else labirin [i][j]=0;
				}
				if (j==8){
					if (i==3||i==4||i==6||i==7||i==9||i==11||i==13||i==19||i==21){
						labirin[i][j]=1;
					}
					else labirin [i][j]=0;
				}
				if (j==9||j==10||j==11){
					if (i==3||i==4||i==6||i==7||i==9||i==11||i==13||i==15||i==17||i==19||i==21){
						labirin[i][j]=1;
					}
					else labirin [i][j]=0;
				}
				if (j==12){
					if (i==3||i==4) labirin [i][j]=1;
					else labirin [i][j]=0;
				}
				if (j==13){
					if (i==5||i==12||i==14||i==19||i==22) labirin [i][j]=0;
				}
				if (j==14){
					if (i==13||i==15||i==16||i==17||i==18||i==20||i==21) labirin [i][j]=1;
					else labirin [i][j]=0;
				}
				if (j==15){
					if (i==4||i==12||i==14||i==16) labirin [i][j]=0;
				}
				if (j==16){
					if (i==4||i==12||i==11||i==10||i==16) labirin [i][j]=0;
				}
				if (j==17){
					if (i==2||i==3||i==5||i==6||i==7||i==8||i==9||i==11|i==13||i==14||i==15) labirin [i][j]=1;
					else labirin [i][j]=0;
				}
			}
			if (j==18||j==19||j==20||j==21){
				labirin [i][j]=1;
				if (j==18){
					if (i==3||i==11||i==13||i==15||i==17||i==18||i==20||i==21) labirin [i][j]=1;
					else labirin [i][j]=0;
				}
				if (j==19){
					if (i==2||i==12||i==14||i==16||i==19||i==22) labirin [i][j]=0;
				}
				if (j==20){
					if (i==17||i==18||i==20||i==21) labirin [i][j]=1;
					else labirin [i][j]=0;
				}
				if (j==21){
					if (i==2||i==16||i==22) labirin [i][j]=0;
				}
			}
		}
	}
}

void rules(){
	gotoxy(25,1);printf (" # = TEMBOK");
	gotoxy(25,2);printf (" < = PACMAN");
	gotoxy(25,3);printf (" @ = MUSUH");
	gotoxy(25,4);printf (" $ = MAKANAN");
	gotoxy(25,5);printf (" TARGET : 5 MAKANAN");
	gotoxy(25,6);printf (" SCORE  : %d\n", counter);
}

void pacman(){
	int temp;
	if (moveup) labirin[y][x]='v';
	else if (movedown) labirin[y][x]='^';
	else if (moveleft) labirin[y][x]='>';
	else if (moveright) labirin[y][x]='<';
	else labirin [y][x]='<';
//	labirin[y][x]='>';
}

void makanan(){
	if (counter==0){
		labirin[2][7]='$';
		labirin[22][6]='$';
		labirin[14][18]='$';
		labirin[2][18]='$';
		labirin[22][22]='$';
	}
}

void dimakan(){
	if (labirin[y][x]=='$'){
		labirin[y][x]=0;
		counter++;
	}
}

void musuh(){
	labirin[a1][a2]='@';
	labirin[b1][b2]='@';
	labirin[c1][c2]='@';
//	labirin [d1][d2]='@';
}

void gerakmusuh(){
			//kiri=atas
	if (keyInput==75){
		musuhupa=true;
		musuhupb=true;
		musuhupc=true;
		if (labirin[a1-1][a2]=='#' || labirin[a1-1][a2]=='$') musuhupa=false;
		if (labirin[b1-1][b2]=='#' || labirin[b1-1][b2]=='$') musuhupb=false;
		if (labirin[c1-1][c2]=='#' || labirin[c1-1][c2]=='$') musuhupc=false;
		if (musuhupa==true){
			labirin[a1][a2]=0;
			a1--;
			musuhdowna=false;
			musuhlefta=false;
			musuhrighta=false;
		}
		if (musuhupb==true){
			labirin[b1][b2]=0;
			b1--;
			musuhdownb=false;
			musuhleftb=false;
			musuhrightb=false;
		}
		if (musuhupc==true){
			labirin[c1][c2]=0;
			c1--;
			musuhdownc=false;
			musuhleftc=false;
			musuhrightc=false;
		}	
	}
	//kanan=bawah
	if (keyInput==77){
		musuhdowna=true;
		musuhdownb=true;
		musuhdownc=true;
		if (labirin[a1+1][a2]=='#' || labirin[a1+1][a2]=='$') musuhdowna=false;
		if (labirin[b1+1][b2]=='#' || labirin[b1+1][b2]=='$') musuhdownb=false;
		if (labirin[c1+1][c2]=='#' || labirin[c1+1][c2]=='$') musuhdownc=false;
		if (musuhdowna==true){
			labirin[a1][a2]=0;
			a1++;
			musuhupa=false;
			musuhlefta=false;
			musuhrighta=false;
		}
		if (musuhdownb==true){
			labirin[b1][b2]=0;
			b1++;
			musuhupb=false;
			musuhleftb=false;
			musuhrightb=false;
		}
		if (musuhdownc==true){
			labirin[c1][c2]=0;
			c1++;
			musuhupc=false;
			musuhleftc=false;
			musuhrightc=false;
		}	
	}
	//bawah=kiri
	if (keyInput==80){
		musuhlefta=true;
		musuhleftb=true;
		musuhleftc=true;
		if (labirin[a1][a2-1]=='#' || labirin[a1][a2-1]=='$') musuhlefta=false;
		if (labirin[b1][b2-1]=='#' || labirin[b1][b2-1]=='$') musuhleftb=false;
		if (labirin[c1][c2-1]=='#' || labirin[c1][c2-1]=='$') musuhleftc=false;
		if (musuhlefta==true){
			labirin[a1][a2]=0;
			a2--;
			musuhdowna=false;
			musuhupa=false;
			musuhrighta=false;
		}
		if (musuhleftb==true){
			labirin[b1][b2]=0;
			b2--;
			musuhdownb=false;
			musuhupb=false;
			musuhrightb=false;
		}
		if (musuhleftc==true){
			labirin[c1][c2]=0;
			c2--;
			musuhdownc=false;
			musuhupc=false;
			musuhrightc=false;
		}	
	}
	//atas
	if (keyInput==72){
		musuhrighta=true;
		musuhrightb=true;
		musuhrightc=true;
		if (labirin[a1][a2+1]=='#' || labirin[a1][a2+1]=='$') musuhrighta=false;
		if (labirin[b1][b2+1]=='#' || labirin[b1][b2+1]=='$') musuhrightb=false;
		if (labirin[c1][c2+1]=='#' || labirin[c1][c2+1]=='$') musuhrightc=false;
		if (musuhrighta==true){
			labirin[a1][a2]=0;
			a2++;
			musuhdowna=false;
			musuhlefta=false;
			musuhupa=false;
		}
		if (musuhrightb==true){
			labirin[b1][b2]=0;
			b2++;
			musuhdownb=false;
			musuhleftb=false;
			musuhupb=false;
		}
		if (musuhrightc==true){
			labirin[c1][c2]=0;
			c2++;
			musuhdownc=false;
			musuhleftc=false;
			musuhupc=false;
		}	
	}
}

void mati(){
	if (labirin[y][x]=='@'){
		labirin[y][x]=0;
		kalah=true;
	}
}

void gamescreen(){
	musuh();
	dimakan();
	mati();
	pacman();
}

void inisialisasi(){
	kotak();
	makanan();
	
}

int ontouch(){
	
	int temp;
	//atas
	if (keyInput==72){
		moveup=true;
		if (labirin[y-1][x]=='#') moveup=false;
		if (moveup==true){
			labirin[y][x]=0;
			y--;
			movedown=false;
			moveleft=false;
			moveright=false;
		}
	}
	//bawah
	if (keyInput==80){
		movedown=true;
		if (labirin[y+1][x]=='#') movedown=false;
		if (movedown==true){
			labirin[y][x]=0;
			y++;
			moveup=false;
			moveleft=false;
			moveright=false;
		}
	}
	//kiri
	if (keyInput==75){
		moveleft=true;
		if (labirin[y][x-1]=='#') moveleft=false;
		if (moveleft==true){
			labirin[y][x]=0;
			x--;
			moveup=false;
			movedown=false;
			moveright=false;
		}
	}
	//kanan
	if (keyInput==77){
		moveright=true;
		if (labirin[y][x+1]=='#') moveright=false;
		if (moveright==true){
			labirin[y][x]=0;
			x++;
			moveup=false;
			movedown=false;
			moveleft=false;
		}
	}
}

int show(){
	int i,j;
		for (i=1;i<=23;i++){
		for (j=1;j<=23;j++){
			if (labirin[i][j]==1){
				labirin [i][j]='#';
			}
			printf ("%c", labirin[i][j]);
		}
		printf ("\n");	
	}
	
	rules();
}


int main(){
	while (currentScreen!=0){
		if (currentScreen==1){
			start();
		}
		keyInput=getch();
		if (currentScreen==1){
			if (keyInput==72){
				nextScreen=2;
			}
			if (keyInput==80){
				nextScreen=0;
			}
			if (keyInput==13){
				if (nextScreen==2){
					currentScreen=nextScreen;
					inisialisasi(); //Deklarasi game
				}
				else if (nextScreen==0){
					exit(0);
				}
			}
		}
		cls();
		if (currentScreen==2){
			ontouch();	//Listener
			gerakmusuh();
			gamescreen(); //Update
			show(); //Show
		}
			if (counter==5){
				currentScreen=3;
				cls();
				if (currentScreen==3){
					menang();
				if (keyInput==13){
					exit(0);
				}
			}
		}
		if (kalah){
			currentScreen=4;
			cls();
			if (currentScreen==4){
				end();
				if (keyInput==13){
					exit(0);
				}
			}
		}
	}
}
