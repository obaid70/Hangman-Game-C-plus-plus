#include<iostream>
#include<time.h>
using namespace std;
void hangman(int &,int &,int &);
int lengthofArray(char []);
void blankword(int);
bool playAgain(int);
void copyArray(char [],char []);
void alive();
void dead();
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
	char array1[10]={"peach"},array2[10]={"banana"},array3[10]={"pakistan"},array4[10]={"nederland"},array5[10]={"triangle"},array6[10]={"mobile"},array7[10]={"soccer"},array8[10]={"badminton"},array9[10]={"window"},array10[10]={"gorilla"};
	char dictionary[10]={"\0"},store[10]={"*********"},guess='\0',used[25]={"\0"};
	int count=0,position=0,playagain=0,q=0;
	srand(time(0));
	int n=rand()%10;
	if(n==0)
	{
		copyArray(array1,dictionary);
	}
	else if(n==1)
	{
		copyArray(array2,dictionary);
	}
	else if(n==2)
	{
		copyArray(array3,dictionary);
	}
	else if(n==3)
	{
		copyArray(array4,dictionary);
	}
	else if(n==4)
	{
		copyArray(array5,dictionary);
	}
	else if(n==5)
	{
		copyArray(array6,dictionary);
	}
	else if(n==6)
	{
		copyArray(array7,dictionary);
	}
	else if(n==7)
	{
		copyArray(array8,dictionary);
	}
	else if(n==8)
	{
		copyArray(array9,dictionary);
	}
	else if(n==9)
	{
		copyArray(array10,dictionary);
	}
	cout<<"\n\n Word : ";	
	blankword(lengthofArray(dictionary));
	for(int m=1;m<3;m++)
	{
		cout<<"\n\n\n THIS IS YOUR "<<m<<" TRY : \n"<<endl;
		store[lengthofArray(dictionary)]='\0';
		for(int i=0;store[i]!='\0';i++)
		{	
			cout<<store[i];
		}	 
		for(int j=1;j<11;j++)
		{
			cout<<"\n\n PLEASE ENTER "<<j<<" ALPHABET : ";
			cin>>guess;
			if(used[q]!=guess)
			{
				used[q]=guess;	
				q++;
			}		
			cout<<endl;
			for(int i=0;i<lengthofArray(dictionary);i++)
			{
				if(dictionary[i]==guess)
				{
					position=i;
					store[i]=guess;
					count++;
				}
			}
			store[lengthofArray(dictionary)]='\0';
			cout<<"These alphabets have been used : ";
			for(int i=0;used[i]!='\0';i++)
			{	
				cout<<used[i]<<",";
			}
			cout<<"\n"<<endl;
			for(int i=0;store[i]!='\0';i++)
			{	
				cout<<store[i];
			}
			if(count==lengthofArray(dictionary))
			{
				break;
			}		
		}
		if(count==lengthofArray(dictionary))
		{
			break;
		}
	}
	if(count!=lengthofArray(dictionary))
	{
		cout<<"\n\n UNFORTUNATELY! YOU COULDN'T GUESS THE WORD AND YOU LOST THE GAME :-( \n"<<endl;
		dead();
		lost++;
	}
	else
	{
		cout<<"\n\n\n CONGRATULATIONS! YOU CORRECTLY GUESSED THE WORD AND YOU WON THE GAME :-) \n"<<endl;
		alive();
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

void copyArray(char source[],char destination[])
{
	int i=0;
	for(i=0;source[i]!='\0';i++)
	{
		destination[i]=source[i];
	}
	destination[i]='\0';
	return;
}

void alive()
{
	cout<<"				  O"<<endl;
	cout<<"			         \\|/"<<endl;
	cout<<"				  | "<<endl;
	cout<<"				 / \\"<<endl;
	return;
}

void dead()
{
	cout<<"			       |"<<endl;
	cout<<"			       |_O"<<endl;
	cout<<"			        /|\\"<<endl;
	cout<<"			         | "<<endl;
	cout<<"			        / \\"<<endl;
	return;
}