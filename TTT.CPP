#include <iostream.h>
#include<conio.h>
#include<string.h>

class board
{
	private:
		char box[9];
	public:
		board();
		void print_board();
		int win();

		int full();
		void set(int a, char v)
		{
			box[a-1] = v;
		}

};

void main()
{
	clrscr();
	board obj;
	obj.print_board();
	while(obj.full() != 1)
	{
		int p1,p2;
		cout<<"p1: ";
		cin>>p1;
		obj.set(p1,'X');
		clrscr();
		obj.print_board();
		if (obj.full() == 1)
			break;
		if (obj.win() == 1)
		{
			cout<<"player 1 wins"<<endl;
			break;
		}
		cout<<"p2: ";
		cin>>p2;
		obj.set(p2,'0');
		clrscr();
		obj.print_board();
		if (obj.win() == 1)
		{
			cout<<"player 2 wins"<<endl;
			break;
		}
		}
	cout << "Press any key to terminate...";
	getch();
}

int board::win()
{
	for(int i=0; i<9; i=i+3)
	{
		if (box[i] == box[i+1] && box[i] == box[i+2])
		{
			return 1;
		}
	}
	for (int j=0; j<3; j++)
	{
		if (box[j] == box[j+3] && box[j] == box[j+6])
		{
			return 1;
		}
	}
	if (box[2] == box[4] && box[2] == box[6])
	{
		return 1;
	}
	else if (box[0] == box[4] && box[0] == box[8])
	{
		return 1;
	}
	return 0;
}





board::board()
		{
			char x='1';
			for(int i=0; i < 9; i++)
			{
				box[i]=x;
				x++;
			}

		}


int board::full()
 {
	for (int i=0; i<9; i++)
	{
		if(box[i]!='0' && box[i]!='X')
			return 0;
	}
	return 1;
}



void board::print_board()
{
	textcolor(CYAN);
	cprintf("-------------");
	cout<<endl;
	for (int i=1 ; i<=9; i++)
	{
		textcolor(CYAN);
		cprintf("| ");
		if (box[i-1]=='X')
			textcolor(RED);
		else if (box[i-1]=='0')
			textcolor(YELLOW);
		else
			textcolor(LIGHTCYAN);

		cprintf("%c ", box[i-1]);
		if (i%3==0)
		{
			textcolor(CYAN);
			cprintf("|");
			cout<<endl;
			cprintf("-------------");
			cout<<endl;
		}
	}
	textcolor(WHITE);
}