#include<iostream>
using namespace std;
char space[3][3]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token='x';
bool tie=false;;
string n1="";
string n2="";
string n="";
void drawBoard(char *spaces);
void playerMove(char *spaces, char players);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char players,char computer);
bool checkTie(char *spaces);
char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
char player = 'X';
char computer = 'O';
bool running = true;

void functionOne()
{
	cout<<"    |"<<"       "<<"|\n";
	cout<<"  "<<space[0][0]<<" |"<<"   "<<space[0][1]<<"   |"<<" "<<space[0][2]<<endl;
	cout<<" __||_"<<endl;	cout<<"    |"<<"       "<<"|\n";
	cout<<"  "<<space[1][0]<<" |"<<"   "<<space[1][1]<<"   |"<<" "<<space[1][2]<<endl;
	cout<<" __||_"<<endl;	cout<<"    |"<<"       "<<"|\n";
	cout<<"  "<<space[2][0]<<" |"<<"   "<<space[2][1]<<"   |"<<" "<<space[2][2]<<endl;
	cout<<"    |"<<"       "<<"|\n";
}
void functionTwo()
{
	int digit;
	if(token=='x')
	{
		cout<<n1<<" please enter "<<endl;
		cin>>digit;
	}
	if(token=='0')
	{
		cout<<n2<<" please enter "<<endl;
		cin>>digit;
	}
	if(digit==1)
	{
		row=0;
		column=0;
	}
	if(digit==2)
	{
		row=0;
		column=1;
	}
	if(digit==3)
	{
		row=0;
		column=2;
	}
	if(digit==4)
	{
		row=1;
		column=0;
	}
	if(digit==5)
	{
		row=1;
		column=1;
	}
	if(digit==6)
	{
		row=1;
		column=2;
	}
	if(digit==7)
	{
		row=2;
		column=0;
	}
	if(digit==8)
	{
		row=2;
		column=1;
	}
	if(digit==9)
	{
		row=2;
		column=2;
	}
	else if(digit<1 || digit>9)
	{
		cout<<"Invalid!!!"<<endl;
	}
	if(token=='x' && space[row][column]!='x' && space[row][column]!='0')
	{
		space[row][column]='x';
		token='0';
	} else if(token='0' && space[row][column]!='x' && space[row][column]!='0')
	{
		space[row][column]='0';
		token='x';
	}
	else
	{
		cout<<"There is no empty space! "<<endl;
		functionTwo();
	}
}
bool functionThree()
{
	for(int i=0; i<3; i++)
	{
		if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
		{
			return true;
		}
	}
	if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
	{
		return true;
	}
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(space[i][j]!='x' && space[i][j]!='0')
			{
				return false;
			}
		}
	}
	tie=true;
	return true;
}
void functionFour()
{
	void drawBoard(char *spaces);
	void playerMove(char *spaces, char players);
	void computerMove(char *spaces, char computer);
	bool checkWinner(char *spaces, char players,char computer);
	bool checkTie(char *spaces);
	drawBoard(spaces);
	while(running)
	{
		playerMove(spaces, player);
		drawBoard(spaces);
		if(checkWinner(spaces,player,computer))
		{
			running = false;
			break;
		}
		computerMove(spaces,computer);
		drawBoard(spaces);
		if(checkWinner(spaces,player,computer))
		{
			running = false;
			break;
		}
		else if (checkTie(spaces)) {
			running = false;
			break;
		}
	}
	std::cout<<"THNAKS FOR PLAYING!\n";
}
void drawBoard(char *spaces)
{
	std::cout << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
	std::cout << "||_" << '\n';	std::cout << "     |     |     " << '\n';
	std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
	std::cout << "||_" << '\n';	std::cout << "     |     |     " << '\n';
	std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << '\n';
}
void playerMove(char *spaces, char players)
{
	int number;
	do {
		std::cout<< "Enter a spot to place a marker(1-9): ";
		std::cin>> number;
		number--;
		if(spaces[number]==' ') {
			spaces[number] = players;
			break;
		}

	} while(!number>0 || !number<8);

}
void computerMove(char *spaces, char computer)
{
	int number;
	srand(tie(0));
	while(true) {
		number = rand() % 9;
		if(spaces[number] == ' ') {
			spaces[number] = computer;
			break;
		}
	}


}
bool checkWinner(char *spaces, char players,char computer)
{
	if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1]== spaces[2])
	{
		spaces[0]== players ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOOSE\n";
	}
	else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4]== spaces[5]) {
		spaces[3]== players ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOOSE\n";
	}
	else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7]== spaces[8]) {
		spaces[6]== players ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOOSE\n";
	}
	else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3]== spaces[6]) {
		spaces[0]== players ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOOSE\n";
	}
	else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4]== spaces[7]) {
		spaces[1]== players ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOOSE\n";
	}
	else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5]== spaces[8]) {
		spaces[2]== players ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOOSE\n";
	}
	else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4]== spaces[8]) {
		spaces[0]== players ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOOSE\n";
	}
	else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4]== spaces[6]) {
		spaces[2]== players ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOOSE\n";
	}
	else {
		return false;
	}


	return true;
}
bool checkTie(char *spaces)
{
	for(int i = 0 ; i< 9; i++) {
		if(spaces[i]==' ') {
			return false;
		}
	}
	std::cout<<"IT'S A TIE\n";
	return true;
}
int main()
{
	cout<<"Welcome to Tic Tac Toe "<<endl;
	cout<<"Menu\n";
	cout<<"1. Play with Computer\n"<<"2. Play with Friends \n";
	int option;
	cout<<"Enter your Choice "<<endl;
	cin>>option;
	switch(option)
	{
	case 1:
	cout<<"Enter your name: "<<endl;
	cin>>n;
		functionFour();
		break;
	case 2:
		cout<<"Enter 1st player name: "<<endl;
	cin>>n1;
		cout<<"Enter 2nd player name: "<<endl;
	cin>>n2;
	cout<<n1<<" will play first"<<endl;
	cout<<n2<<" will play second"<<endl;
	    while(!functionThree())
	{
		functionOne();
		functionTwo();
		functionThree();
	}
	if(token=='x' && tie==false)
	{
		cout<<n2<<" Wins!!"<<endl;
	} else if(token=='0' && tie==false)
	{
		cout<<n1<<" Wins!!"<<endl;
	} else
	{
		cout<<"It's a draw ";
	}
	break;
	
	return 0;
}