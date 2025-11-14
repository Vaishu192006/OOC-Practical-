
#include <conio.h>
#include <iostream.h>
#include <string.h>
#include <stdlib.h>
static int p = 0;
class a

{
  char busn[5], busname[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:

  void install();

  void allotment();

  void empty();

  void show();

  void avail();

  void position(int i);

}

bus[10];
void vline(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
}

void a::install()
{

  cout<<"\n\n\n\t\t\tEnter bus no: ";

  cin>>bus[p].busn;

  cout<<"\n\t\t\tEnter Bus name: ";

  cin>>bus[p].busname;

  cout<<"\n\t\t\tArrival time: ";

  cin>>bus[p].arrival;

  cout<<"\n\t\t\tDeparture: ";

  cin>>bus[p].depart;

  cout<<"\n\t\t\tFrom: ";

  cin>>bus[p].from;

  cout<<"\n\t\t\tTo: ";

  cin>>bus[p].to;

  bus[p].empty();

  p++;

  cout<<"\n\t\t\tBus added Sucessfully ";

}
void a::allotment()

{

  int seat;

  char number[5];

  top:

  cout<<"\n\n\n\t\t\tBus no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\n\t\t\tSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\n\t\t\tThere are only 32 seats available in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

	cout<<"\t\t\tEnter passanger's name: ";

	cin>>bus[n].seat[seat/4][(seat%4)-1];

	cout<<"\t\t\tSeat Reserved Sucessfully ";

	break;

      }

    else

      cout<<"\t\t\tThe seat no. is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"\t\t\tEnter correct bus no.\n";

      goto top;

    }

  }


void a::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}

void a::show()

{

  int n;

  char number[5];

  cout<<"\t\t\tEnter bus no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

while(n<=p)

{

   vline('*');

  cout<<"\tBus no: \n\t"<<bus[n].busn

  <<"\n\tBus name: \t"<<bus[n].busname<<"\tArrival time: \t"

  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart

  <<"\n\tFrom: \t\t"<<bus[n].from<<"\tTo: \t"<<

  bus[n].to<<"\n";

   vline('*');

  bus[0].position(n);
  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\n\t\t\tThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"\t\t\tEnter correct bus no: ";

}

void a::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

	{

	  cout.width(5);

	  cout.fill(' ');

	  cout<<s<<".";

	  cout.width(10);

	  cout.fill(' ');

	  cout<<bus[l].seat[i][j];

	  p++;

	}

	else

	{

	cout.width(5);

	cout.fill(' ');

	cout<<s<<".";

	cout.width(10);

	cout.fill(' ');

	cout<<bus[l].seat[i][j];

	}

      }

    }

  cout<<"\n\n\t\t\tThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;

  }

void a::avail()

{


  for(int n=0;n<p;n++)

  {

    vline('*');

    cout<<"\tBus no: \t\n"<<bus[n].busn<<"\tBus name:\t"<<bus[n].busname

    <<"\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time:\t"

    <<bus[n].depart<<"\tFrom: \t"<<bus[n].from<<"\tTo: \t"

    <<bus[n].to<<"\n";

    vline('*');

    //vline('_');

  }

 }

int main()

{

system("cls");

int w,c,i,ch;
cout<<"\nEnter Your Role:\t1.Admin\t2.User";
cin>>c;                       switch(c)
{
   case 1: for(i=0;i<2;i++)
	  {
	     bus[i].install();
	  }
	  break;

   case 2:cout<<"\nNo buses Available";
	  break;
   default: cout<<"\nInvalid Choice";
}
cout<<"\n\n\n\t\t\t***Only For Passenger***";
bus[0].avail();

while(1)

{


  cout<<"\n\n\n\n\n";

  cout<<"\t\t\tBus Reservation System\n\n";


  cout<<"\t\t\t1.Seat Reservation\n\t\t\t"

  <<"2.Show\n\t\t\t"

  <<"3.Buses Available. \n\t\t\t"

  <<"4.Exit";

  cout<<"\n\t\t\tEnter your choice:-> ";

  cin>>w;

  switch(w)

  {



    case 1:  bus[p].allotment();

      break;

    case 2:  bus[0].show();

      break;

    case 3:  bus[0].avail();

      break;

    case 4:  exit(0);

  }

}

return 0;

}
