#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int xsize = 20;
int ysize = 18;
int gameOver = 1;
int point = 0;
bool update = true;
string O;

int main() {
again:
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	srand((unsigned)time(0));
	int playerx = rand() % 15 + 5;
	int playery = rand() % 13 + 5;
	int boxX = rand() % 15 + 5;
	int boxY = rand() % 13 + 5;
	int gate = 1 + (rand() % 4);

	while (gameOver == 1) {
		if (gate == 1) {
			if (playerx > xsize || playerx < 0 || playery > ysize || playery < 0) {  //Duvara çarpma
				gameOver = 0;
				update = false;
			}
			if ( boxY <= 0) {  // Kutuyu Duvara götürme
				gameOver = 3;
				update = false;
			}
			if (boxX <= 0 || boxX >= xsize || boxY >= ysize) {			//yanlýþ duvar
				gameOver = 2;
				update = false;
			}
		}
		if (gate == 2) {
			if (playerx > xsize || playerx < 0 || playery > ysize || playery < 0) {  //Duvara çarpma
				gameOver = 0;
				update = false;
			}
			if (boxY >= ysize) {  // Kutuyu Duvara götürme
				gameOver = 3;
				update = false;
			}
			if (boxX <= 0 || boxX >= xsize || boxY <= 0) {			//yanlýþ duvar
				gameOver = 2;
				update = false;
			}
		}
		if (gate == 3) {
			if (playerx > xsize || playerx < 0 || playery > ysize || playery < 0) {  //Duvara çarpma
				gameOver = 0;
				update = false;
			}
			if (boxX <= 0) {  // Kutuyu Duvara götürme
				gameOver = 3;
				update = false;
			}
			if (boxY <= 0 || boxX >= xsize || boxY >= ysize) {			//yanlýþ duvar
				gameOver = 2;
				update = false;
			}
		}
		if (gate == 4) {
			if (playerx > xsize || playerx < 0 || playery > ysize || playery < 0) {  //Duvara çarpma
				gameOver = 0;
				update = false;
			}
			if (boxX >= xsize) {  // Kutuyu Duvara götürme
				gameOver = 3;
				update = false;
			}
			if (boxX <= 0 || boxY <= 0 || boxY >= ysize) {			//yanlýþ duvar
				gameOver = 2;
				update = false;
			}
		}
		if (update == true) {
			system("cls");
			for (int i = 0; i <= ysize; i++) {
				for (int j = 0; j <= xsize; j++) {
					if (gate == 1) {						//gate1
						if (i == 0) {//ÜST
							SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << " #";
							SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
						}
						else if (i == ysize) {//ALT
							cout << " #";
						}
						else if (j == 0) {//SOL
							cout << " #";
						}
						else if (j == xsize) {//SAÐ
							cout << " #";
						}
						else if (i == playery && j == playerx) {  //player
							cout << " X";
						}
						else if (i == boxY && j == boxX) {    //Box
							cout << "[]";
						}
						else {
							cout << "  ";
						}
						if (j == xsize) {
							cout << endl;
						}
					}
					else if (gate == 2) {						//gate2
						if (i == 0) {//ÜST
							cout << " #";
						}
						else if (i == ysize) {//ALT
							SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << " #";
							SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
						}
						else if (j == 0) {//SOL
							cout << " #";
						}
						else if (j == xsize) {//SAÐ
							cout << " #";
						}
						else if (i == playery && j == playerx) {  //player
							cout << " X";
						}
						else if (i == boxY && j == boxX) {    //Box
							cout << "[]";
						}
						else {
							cout << "  ";
						}
						if (j == xsize) {
							cout << endl;
						}
					}
					else if (gate == 3) {						//gate3
						if (i == 0) {//ÜST
							cout << " #";
						}
						else if (i == ysize) {//ALT
							cout << " #";
						}
						else if (j == 0) {//SOL
							SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << " #";
							SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
						}
						else if (j == xsize) {//SAÐ
							cout << " #";
						}
						else if (i == playery && j == playerx) {  //player
							cout << " X";
						}
						else if (i == boxY && j == boxX) {    //Box
							cout << "[]";
						}
						else {
							cout << "  ";
						}
						if (j == xsize) {
							cout << endl;
						}
					}
					else if (gate == 4) {						//gate4
						if (i == 0) {//ÜST
							cout << " #";
						}
						else if (i == ysize) {//ALT
							cout << " #";
						}
						else if (j == 0) {//SOL
							cout << " #";
						}
						else if (j == xsize) {//SAÐ
							SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << " #";
							SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
						}
						else if (i == playery && j == playerx) {  //player
							cout << " X";
						}
						else if (i == boxY && j == boxX) {    //Box
							cout << "[]";
						}
						else {
							cout << "  ";
						}
						if (j == xsize) {
							cout << endl;
						}
					}
				}
			}
			update = false;
		}
		else {
			if (GetAsyncKeyState(VK_RIGHT) < 0) { //Player controller

				if (playerx == boxX - 1 && playery == boxY) {
					boxX++;
				}
				playerx++;
				update = true;
			}
			else if (GetAsyncKeyState(VK_LEFT) < 0) {
				if (playerx == boxX + 1 && playery == boxY) {
					boxX--;
				}
				playerx--;
				update = true;
			}
			else if (GetAsyncKeyState(VK_UP) < 0) {
				if (playery == boxY + 1 && playerx == boxX) {
					boxY--;
				}
				playery--;
				update = true;
			}
			else if (GetAsyncKeyState(VK_DOWN) < 0) {
				if (playery == boxY - 1 && playerx == boxX) {
					boxY++;
				}
				playery++;
				update = true;
			}
		}
	}
	if (gameOver == 0) {						//Lose
		system("cls");
		cout << " Ouch! You hit a wall" << endl;
		cout << "	Game Over" << endl;
		cout << "Score: " << point << endl;
		cout << "try again? y/n" << endl;
		cin >> O;
		system("pause");
		if (O == "y") {
			update = true;
			gameOver = 1;
			goto again;
		}
		else if (O == "n") {
			cout << "Oyunu Begendiniz mi?" << endl;
			cin >> O;
			cout << "Napim" << endl;
			cin >> O;
		}
	}
	if (gameOver == 2) {					//Wrong Wall
		point--;
		system("cls");
		cout << "     Next Time try to hit the green wall" << endl;
		cout << "Score: " << point << endl;
		cout << "try again? y/n" << endl;
		cin >> O;
		system("pause");
		if (O == "y") {
			update = true;
			gameOver = 1;
			goto again;
		}
		else if (O == "n") {
			cout << "Oyunu Begendiniz mi?" << endl;
			cin >> O;
			cout << "Napim" << endl;
			cin >> O;
		}
	}
	if (gameOver == 3) {					//Win
		point++;
		system("cls");
		cout << "     YOU WIN" << endl;
		cout << "Score: " << point << endl;
		cout << "try again? y/n" << endl;
		cin >> O;
		system("pause");
		if (O == "y") {
			update = true;
			gameOver = 1;
			goto again;
		}
		else if (O == "n") {
			cout << "Oyunu Begendiniz mi?" << endl;
			cin >> O;
			cout << "Napim" << endl;
			cin >> O;
		}
	}
	return 0;
}