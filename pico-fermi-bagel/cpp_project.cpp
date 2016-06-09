/*
Program for the game 'Pico Fermi Bagel'
Written by : Tarasha Khurana
             Shruti Singh
*/

#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip.h>
#include <ctype.h>
#include <string.h>
int attempt= 0, playerno = 0;

void MainMenu();
void Play();
void HowToPlay();
void HighestScore();
void Play_SinglePlayer();
void Play_TwoPlayer();
int logic();
int search (int, int[]);

struct Player
{
 char Name [50];
 int Score;
 int Admno;
};

Player players[30];

void main()
{
MainMenu();
}

// Function for the main menu of the game
void MainMenu()
{
 int opt;
 clrscr();
 cout<<setw(50)<<"PiCo FeRmI BaGeL"<<endl<<endl;
 do
 {
 cout<<"Choose an option\n1. PlAy\n2. HoW To PlAy\n3. HiGhEsT ScOrE\n4. ExIt\n";
 cin>>opt;
 } while (opt<1 || opt>4);
 switch (opt)
 {
  case 1 : Play();
			  break;
  case 2 : HowToPlay();
			  break;
  case 3 : HighestScore();
			  break;
  case 4 : exit(0);
			  break;
  }
 getch();
}

// Function for displaying instructions to the user
void HowToPlay()
{
 clrscr();
 cout<<setw(50)<<"PiCo FeRmI BaGeL"<<endl<<endl;
 cout<<"Instructions"<<endl<<endl;
 cout<<"1. The game starts with 30 points in your hand. \nThe computer returns ";
 cout<<"a random three digit number. \nYour sole job";
 cout<<" is to guess the number.\n\n2. ";
 cout<<"You are given 15 chances and each time, you guess a three digit number.";
 cout<<"\nUnfortunately you lose out on 2 points with every wrong guess."<<endl<<endl;
 cout<<"3. If one or more digits, that you enter, are correct and at the ";
 cout<<"correct place, the computer returns Fermi(F). \nIf one or more digits ";
 cout<<"are correct but not at the correct place, the computer \nreturns Pico";
 cout<<"(P). \nIf none of the digits that you enter are correct, the computer";
 cout<<" returns Bagel(B)."<<endl<<endl;
 cout<<"GOODLUCK!\nPress any character to start playing.";
 getch();
 Play();
}

// Function for sorting the array of players and displaying the top three scorers
void HighestScore()
{
 clrscr();
 cout<<setw(50)<<"PiCo FeRmI BaGeL"<<endl<<endl;
 char mm;
 if (attempt == 0)
		cout<<"You are required to play first."<<endl<<endl;
 else
		{
		 for (int i = 0; i<= playerno ;i++)
			 for (int j = 0; j<=(playerno - 1 - i);j++)
				 if (players[j].Score < players[j+1].Score)
					 {
					  Player T = players[j];
					  players[j] = players[j+1];
					  players[j+1] = T;
					 }
		 cout<<setw(15)<<"Player Name"<<setw(20)<<"Player Score"<<setw(20)<<"Player Admno."<<endl;
		 int w;
		 if (playerno < 3)
				w = playerno;
		 else
				w = 3;
				 for (int k = 0; k<w; k++)
			cout<<setw(15)<<players[k].Name<<setw(20)<<players[k].Score<<setw(20)<<players[k].Admno<<endl;
		 cout<<endl;
		}
 cout<<"Want to go the main menu? (Y/N)"<<endl;
 cin>>mm;
 if (mm == 'y' || mm == 'Y')
		MainMenu();
 else
		exit(0);
}

// Function for asking the user's choice for a single or multiplayer game
void Play()
{
 clrscr();
 cout<<setw(50)<<"PiCo FeRmI BaGeL"<<endl<<endl;
 int type;
 do
 {
 cout<<"Enter 1 for a single-player game and 2 for a two-player game"<<endl;
 cin>>type;
 } while (type<1 || type>2);
 switch (type)
 {
  case 1 : attempt++;
	   Play_SinglePlayer();
	   break;
  case 2 : attempt += 2;
	   Play_TwoPlayer();
	   break;
 }
}

// Function for the single player game
void Play_SinglePlayer()
{
 clrscr();
 cout<<setw(50)<<"PiCo FeRmI BaGeL"<<endl<<endl;
 cout<<"Enter your name"<<endl;
 gets(players[playerno].Name);
 players[playerno].Admno = playerno + 1;
 cout<<"Press any key."<<endl;
 getch();
 clrscr();
 cout<<setw(50)<<"PiCo FeRmI BaGeL"<<endl<<endl;
 cout<<players[playerno].Name<<setw(20)<<"Player number "<<(playerno + 1)<<endl<<endl;
 gotoxy (60,3);
 cout<<"Score : 30";
 players[playerno].Score = logic();
 playerno += 1;
 char again,mm;
 cout<<"Do you want to play again? (Y/N)"<<endl;
 cin>>again;
 if ( again == 'Y' || again == 'y')
		Play();
 else if ( again == 'N' || again == 'n')
		{
		cout<<endl<<endl<<"Want to go to the main menu? (Y/N)";
		cin>>mm;
		if (mm == 'y' || mm == 'Y')
				MainMenu();
		else
				exit(0);
		}
}

// Function for searching each digit entered, in the actual number returned by the computer, and its respective place
int search (int a, int b[])
{
 int found = -1;
 for (int i=0; i<3; i++)
 {
  if (a == b[i])
		{
		found = i;
		return found;
		}
 }
 return found;
}

// Function for the multiplayer game
void Play_TwoPlayer()
{
 clrscr();
 cout<<setw(50)<<"PiCo FeRmI BaGeL"<<endl<<endl;
 cout<<"Player 1, enter name "<<endl;
 gets(players[playerno].Name);
 players[playerno].Admno = playerno + 1;
 cout<<"Player 2, enter name "<<endl;
 gets(players[playerno + 1].Name);
 players[playerno + 1].Admno = playerno + 2;
 cout<<"Press any key."<<endl;
 getch();
 clrscr();
 cout<<setw(50)<<"PiCo FeRmI BaGeL"<<endl<<endl;
 cout<<players[playerno].Name<<setw(20)<<"Player number "<<(playerno + 1)<<endl<<endl;
 gotoxy (60,3);
 cout<<"Score : 30";
 players[playerno].Score = logic();
 getch();
 clrscr();
 cout<<setw(50)<<"PiCo FeRmI BaGeL"<<endl<<endl;
 cout<<players[playerno + 1].Name<<setw(20)<<"Player number "<<(playerno + 2)<<endl<<endl;
 gotoxy (60,3);
 cout<<"Score : 30";
 players[playerno + 1].Score = logic();
 if ( players[playerno].Score > players[playerno + 1].Score)
		cout<<players[playerno].Name<<" wins!"<<endl;
 else if ( players[playerno].Score < players[playerno + 1].Score)
		cout<<players[playerno + 1].Name<<" wins!"<<endl;
 else
		cout<<"It's a tie!"<<endl;
 playerno += 2;
 char again, mm;
 cout<<"Do you want to play again? (Y/N)"<<endl;
 cin>>again;
 if ( again == 'Y' || again == 'y')
		Play();
 else if ( again == 'N' || again == 'n')
		{
		cout<<endl<<endl<<"Want to go to the main menu? (Y/N)";
		cin>>mm;
		if (mm == 'y' || mm == 'Y')
				MainMenu();
		else
				exit(0);
		}
}

// Function for the main logic of the game : checking for digits and their places
int logic()
{
 int number, guess = 1,guessnumber, a, b, c, d, e, f, g, h, score = 30;
 randomize();
 do
 {
 number = random(1000);
 } while (number < 99);
 e = number%10;
 f = number/10;
 g = f%10;
 h = number/100;
 int array2[] = {e,g,h};
 int acc = 5;
 do
 {
 cout<<"\nGuess "<<guess<<" ";
 cin>>guessnumber;
 a = guessnumber%10;
 b = guessnumber/10;
 c = b%10;
 d = guessnumber/100;
 guess++;
 int array1[] = {a,c,d};
 int posa = 1, posc = 2, posd = 3, posa_, posc_, posd_;
 if (guessnumber ==  number)
		cout<<" F F F"<<endl<<"You guessed the right number!\nYour score : "<<score<<endl;
 else
		{
		posa_ = search (array1[0], array2);
		if ( posa_ != -1)
		{
		if (posa_ + 1 == posa)
				cout<<" F";
		if (posa_ + 1 != posa)
				cout<<" P";
		}
		posc_ = search (array1[1], array2);
		if ( posc_ != -1)
		{
		if (posc_ + 1 == posc)
				cout<<" F";
		if (posc_ + 1 != posc)
				cout<<" P";
		}
		posd_ = search (array1[2], array2);
		if ( posd_ != -1)
		{
		if (posd_ + 1 == posd)
				cout<<" F";
		if (posd_ + 1 != posd)
				cout<<" P";
		}
		if (posa_ == -1 && posc_ == -1 && posd_ == -1)
			cout<<" B";
		gotoxy (60,3);
		cout<<"Score : "<<(score -= 2)<<" "<<endl;
		gotoxy (1,acc);
		//if (guess<= 11) in case of version 4.5 [because of small screen]
				acc = acc + 2;
		}
 } while ( guess <= 15 && guessnumber!=number);
 if (guess > 15)
		cout<<endl<<endl<<"Sorry, you lost!"<<endl<<"The number was "<<number<<endl;
		return score;
}

