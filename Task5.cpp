#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int xsize = 20;
int ysize = 18;
int gameOver = 1;
bool update = true;
string O ;

int main() {
	srand((unsigned) time(0));
	int playerx = rand() % xsize-5 + 5;
	int playery = rand() % ysize-5 + 5;
	int boxX = rand() % 15 + 5;
	int boxY = rand() % 13 + 5;
	
	while (gameOver == 1) {
		if (playerx > xsize || playerx < 0 || playery > ysize || playery < 0){  //Duvara çarpma
			gameOver = 0;
			update = false;
		}
		if (boxX >= xsize || boxX <= 0 || boxY >= ysize || boxY <= 0){  //Duvara çarpma
			gameOver = 2;
			update = false;
		}
		if (update == true){
			system("cls");
			for(int i = 0; i <= ysize; i++){
				for(int j = 0; j <= xsize; j++){
					if (i == 0 || i == ysize || j ==0 || j == xsize){
						cout<<" #";
					}
					else if(i == playery && j == playerx){  //player
						cout<<" X";
					}
					else if(i == boxY && j == boxX){    //Box
						cout<<"[]";
					}
					else {
						cout<<"  ";
					}
					if (j == xsize){
						cout<<endl;
					}
				}
			}
			update = false;
		}
		else {
			if (GetAsyncKeyState(VK_RIGHT) < 0){ //Player controller
				
				if (playerx == boxX-1 && playery == boxY){
				boxX++;
				}
				playerx++;
				update = true;
			}
			else if (GetAsyncKeyState(VK_LEFT) < 0){ 
				if (playerx == boxX+1 && playery == boxY){
				boxX--;
				}
				playerx--;
				update = true;
			}
			else if (GetAsyncKeyState(VK_UP) < 0){
				if (playery == boxY+1 && playerx == boxX){
				boxY--;
				}
				playery--;
				update = true;
			}
			else if (GetAsyncKeyState(VK_DOWN) < 0){
				if (playery == boxY-1 && playerx == boxX){
				boxY++;
				}
				playery++;
				update = true;
			}
		}
	}
	if (gameOver == 0){
		system("cls");
		cout<<" Ouch! You hit a wall"<<endl;
		cout<<"Game Over"<<endl;
		cout<<"btw that means you lost the game "<<endl;
		system("pause");
		cout<<"Oyunu Begendiniz mi?"<<endl;
		cin>>O;
		cout<<"Napim"<<endl;
		cin>>O;
	}
	if(gameOver == 2){
		system("cls");
		cout<<"     YOU WIN"<<endl;
		system("pause");
		cout<<"Oyunu Begendiniz mi?"<<endl;
		cin>>O;
		cout<<"Napim"<<endl;
		cin>>O;
	}
	
	return 0;
}
