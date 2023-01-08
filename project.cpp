#include<iostream>
#include<time.h>
using namespace std;
void hangman(int &,int &,int &);
int lengthofArray(char []);
void blankword(int);
bool playAgain(int);

int main()
{
	int win=0,& a=win,lost=0,& b=lost,total=1,& c=total;
	hangman(a,b,c);
	return 0;
}

void hangman(int & win,int & lost,int & total)
{
	cout<<"\n\n 					\"WELCOME TO THE HANGMAN GAME\" \n"<<endl;
	cout<<"\n\n 			\"YOU WILL BE GIVEN 10 CHARACTER OPTIONS FOR EACH TRY.\" \n"<<endl;
	cout<<"\n\n 				\"ONE CHARACTER CAN ONLY BE ENTERED ONCE.\" \n"<<endl;
	cout<<"\n\n 			BEST OF LUCK! YOU HAVE ONLY 2 TRIES TO GUESS THE FOLLOWING WORD : \n"<<endl;
	char dictionary[10][10]={"peach","banana","pakistan","nederland","triangle","mobile","soccer","badminton","window","gorilla"},store[10]={"*********"},guess='\0';
	int count=0,position=0,playagain=0;
	srand(time(0));
	int n=rand()%10;
	cout<<"\n\n Word : ";	
	blankword(lengthofArray(dictionary[n]));
	for(int m=1;m<3;m++)
	{
		cout<<"\n\n\n THIS IS YOUR "<<m<<" TRY : \n"<<endl;
		store[lengthofArray(dictionary[n])]='\0';
		for(int i=0;store[i]!='\0';i++)
		{	
			cout<<store[i];
		}	 
		for(int j=1;j<11;j++)
		{
			cout<<"\n\n PLEASE ENTER "<<j<<" ALPHABET : ";
			cin>>guess;
			for(int i=0;i<lengthofArray(dictionary[n]);i++)
			{
				if(dictionary[n][i]==guess)
				{
					position=i;
					store[i]=guess;
					count++;
				}	
			}
			store[lengthofArray(dictionary[n])]='\0';
			for(int i=0;store[i]!='\0';i++)
			{	
				cout<<store[i];
			}
			if(count==lengthofArray(dictionary[n]))
			{
				break;
			}		
		}
		if(count==lengthofArray(dictionary[n]))
		{
			break;
		}
	}
	if(count!=lengthofArray(dictionary[n]))
	{
		cout<<"\n\n UNFORTUNATELY! YOU COULDN'T GUESS THE WORD AND YOU LOST THE GAME :-( \n"<<endl;
		lost++;
	}
	else
	{
		cout<<"\n\n\n CONGRATULATIONS! YOU CORRECTLY GUESSED THE WORD AND YOU WON THE GAME :-) \n"<<endl;
		win++;
	}
	cout<<"\n WOULD YOU LIKE TO PLAY AGAIN ?\n"<<endl;
	cout<<"\n ENTER 1 FOR YES AND 0 FOR NO : ";
	cin>>playagain;
	if(playAgain(playagain)==true)
	{
		total++;
		hangman(win,lost,total);
	}
	else
	{
		cout<<"\n\n\n TOTAL GAMES PLAYED : "<<total<<endl;
		cout<<"\n\n TOTAL GAMES WON : "<<win<<endl;
		cout<<"\n\n TOTAL GAMES LOST : "<<lost<<endl;
	}
	return;
}

int lengthofArray(char array[])
{
	int count=0;
	for(int i=0;array[i]!='\0';i++)
	{
		count++;
	}
	return count;
}

void blankword(int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<"*";
	}
	return;
}

bool playAgain(int yes)
{
	if(yes==1)
	{
		return true;
	}
	else
	{
		return false;
	}		
}
