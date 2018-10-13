//Bus reservation system
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#include<time.h>
#include<iomanip.h>
#include<fstream.h>
char f[]="f";
char s[]="s";
int addr,ad,flag=0,f1,d,m,i,amt;
float tamt;
class login
{
public:
    char id[100];
    char pass[100];
    char *password;
    void getid()
    {
	cout<<"Enter your id:";
	gets(id);
	password=getpass("Enter the password:");
	strcpy(pass,password);
    }
    void displayid()
    {
	cout<<"Id:";
	puts(id);
	cout<<"Password:";
	puts(pass);
    }
};
class detail
{
public:
    int pnr;
    int bno;
    char bname[100];

    char bp[100];
    char dest[100];
    int c1,c1fare;
    int c2,c2fare;
    int d,m,y;
    void getdetail()
    {
	cout<<"Enter the details as follows\n";
	cout<<"Bus no:";
	cin>>bno;
	cout<<"Bus name:";
	gets(bname);
	cout<<"Boarding point:";
	gets(bp);
	cout<<"Destination pt:";
	gets(dest);
	cout<<"No of seats in first class & fare per ticket:";
	cin>>c1>>c1fare;
	cout<<"No of seats in second class & fare per ticket:";
	cin>>c2>>c2fare;
	cout<<"Date of travel:";
	cin>>d>>m>>y;
    }
    void displaydetail()
   {
   cout<<"\n\tBUS INFORMATION SYSTEM\n";
   cout<<"\n\t\tBus no: "<<bno<<"\n\t\tBus name: "<<bname<<"\n\t\tBoarding point: "<<bp<<"\n\t\tDestination: "<<dest<<"\n\t\tF-class: "<<c1<<"\n\t\tF-fare: "<<c1fare<<"\n\t\tS-class: "<<c2<<"\n\t\tS-fare: "<<c2fare<<"\n\t\tDate:"<<d<<"-"<<m<<"-"<<y;
   }
};
class reser
{
public:
    int pnr;
    int bno;
    char bname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    char clas[10];
    int nosr;
    int i;
    int d,m,y;
    int con;


    float amc;
    void getresdet()
    {
	cout<<"Enter the details as follows\n";
	cout<<"Bus no:";
	cin>>bno;
	cout<<"Bus name:";
	gets(bname);
	cout<<"Boarding point:";
	gets(bp);
	cout<<"Destination pt:";
	gets(dest);
	cout<<"No of seats required:";
	cin>>nosr;
	for(i=0;i<nosr ; i++)
	{
	    cout<<"Passenger name:";
	    gets(pname[i]);
	    cout<<"Passenger age:";
	    cin>>age[i];
	}
	cout<<"Enter the class f-first class s-second class:";
	gets(clas);
	cout<<"Date of travel:";
	cin>>d>>m>>y;
	cout<<"Enter the concession category\n";
	cout<<"1.Military\n2.Senior citizen\n";
	cout<<"3.Children below 5 yrs\n4.None\n";
	cin>>con;
	cout<<"............END OF GETTING DETAILS............\n";
    }
    void displayresdet()
    {
	cout<<"...............................................\n";
	cout<<"Pnr no:"<<pnr;
	cout<<"\nBus no:"<<bno;
	cout<<"\nBus name:";
	puts(bname);
	cout<<"Boarding point:";
	puts(bp);
	cout<<"Destination pt:";
	puts(dest);
	cout<<"No of seats reserved:"<<nosr;
	for(i=0; i<nosr; i++)
	{
	    cout<<"Passenger name:";
	    puts(pname[i]);
	    cout<<"Passenger age:"<<age[i];
	}

	cout<<"\nYour class:";
	puts(clas);
	cout<<"\nDate of reservation:"<<d<<"-"<<m<<"-"<<y;
	cout<<"\nYour concession category:"<<con;
	cout<<"\nYou must pay:"<<amc<<endl;
	cout<<"***********************************************\n";
	cout<<".........END OF RESERVATION.................\n";
	cout<<"***********************************************\n";
    }
};
class canc
{
public:
    int pnr;
    int bno;
    char bname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    int i;
    char clas[10];
    int nosc;
    int d,m,y;
    float amr;
    void getcancdet()
    {
	cout<<"Enter the details as follows\n";
	cout<<"Pnr no:";
	cin>>pnr;
	cout<<"Date of cancellation:";
	cin>>d>>m>>y;
	cout<<"...........END OF GETTING DETAILS...........\n";
    }
    void displaycancdet()
    {
	cout<<"Pnr no:"<<pnr;
	cout<<"\nBus no:"<<bno;
	cout<<"\nBus name:";
	puts(bname);
	cout<<"Boarding point:";
	puts(bp);

	cout<<"Destination pt:";
	puts(dest);
	cout<<"\nYour class:";
	puts(clas);
	cout<<"no of seats to be cancelled:"<<nosc;
	for(i=0; i<nosc; i++)
	{
	    cout<<"\nPassenger name:";
	    puts(pname[i]);
	    cout<<"\npassenger age:"<<age[i];
	}
	cout<<"\nDate of cancellation:"<<d<<"-"<<m<<"-"<<y;

    }
};
void manage();
void user();
void database();
void res();
void reserve();
void displaypassdetail();
void cancell();
void enquiry();
void main()
{
    start:
    clrscr();
    int ch;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<".......WELCOME TO BUS RESERVATION SYSTEM..........\n";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    do
    {
	cout<<"^^^^^^^^^^^^^^^^^^^^^^MAIN MENU^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"\n\t\t1.Admin mode\n\n\t\t2.User mode\n\n\t\t3.Exit\n";
	cout<<"\n\t\tEnter your choice:";
	cin>>ch;
	cout<<endl;
	switch(ch)

	{
	case 1:
	    {
	    database();
	    goto start;
	    }
	case 2:
	    {
	    user();
	    goto start;
	    }
	case 3:
	    exit(0);
	default:
	{
	cout<<"\n\t\tILLEGAL CHOICE TRY AGAIN ...";
	getch();
	goto start;
	}
      }
    }
    while(ch<=3);
    getch();
}
void database()
{
    char *password;
    char *pass="1";
    password=getpass("Enter the admininistrator password:");
    detail a;
    fstream f;
    int ch;
    char c;

    if(strcmp(pass,password)!=0)
    {
	cout<<"Incorrect Password \n";
	goto h;
    }
    if(strcmp(pass,password)==0)
     {

       menu2:
       clrscr();
	char c;

	    cout<<"\n\n\t... A D M I N I S T R A T O R -  M E N U...\n";
	    cout<<"\n\t\t[1] Create detail data base\n\n\t\t[2] Add details\n";
	    cout<<"\n\t\t[3] Display details\n\n\t\t[4] User management\n";
	    cout<<"\n\t\t[5] Display passenger details\n\n\t\t[6] Return to main menu\n";
	    cout<<"\n\t\tEnter your choice:- ";
	    cin>>ch;
	    cout<<endl;
	    switch(ch)
	    {
	    case 1:
		clrscr();
		f.open("t.txt",ios::out|ios::binary);
		do
		{
		    clrscr();
		    a.getdetail();
		    f.write((char *) & a,sizeof(a));
		    cout<<"\n\n\t\tDo you want to add one more record?\n";
		    cout<<"\n\t\tPress Y - for Yes\n\t\tPress N - for No\n";
		    cin>>c;
		}
		while(c=='y');
		f.close();
		goto menu2;
	    case 2:
		clrscr();
		f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
		a.getdetail();
		f.write((char *) & a,sizeof(a));
		f.close();
		goto menu2;
	    case 3:
		clrscr();
		f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
		f.seekg(0);

		while(f.read((char *) & a,sizeof(a)))
		{
		    a.displaydetail();
		    cout<<"\n Press Button for NEXT Bus detail";
		    getch();
		}
		f.close();
		goto menu2;
	    case 4:
		manage();
		{ goto menu2;}
	    case 5:
		displaypassdetail();
		break;
	    case 6:
	    {
	    clrscr();
	    break;
	    }
	    default:
	    {
	    cout<<"\n\t\tWrong choice try again";
	    getch();
	    goto menu2;
	    }
	}

	f.close();
    }
h:
}
void res()
{
    detail a;
    reser b;
    fstream f1,f2;
    time_t t;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary|ios::app);
    int ch;
    b.getresdet();
    while(f1.read((char *) &a,sizeof(a)))
    {
	if(a.bno==b.bno)
	{
	    if(strcmp(b.clas,f)==0)
	    {
		if(a.c1>=b.nosr)

		{
		    amt=a.c1fare;
		    addr=f1.tellg();
		    ad=sizeof(a.c1);
		    f1.seekp(addr-(7*ad));
		    a.c1=a.c1-b.nosr;
		    f1.write((char *) & a.c1,sizeof(a.c1));
		    if(b.con==1)
		    {
			cout<<"Concession category:MILITARY PERSONNEL\n";

			b.amc=b.nosr*((amt*50)/100);
		    }
		    else if(b.con==2)
		    {
			cout<<"Concession category:SENIOR CITIZEN\n";
			b.amc=b.nosr*((amt*60)/100);
		    }
		    else if(b.con==3)
		    {
			cout<<"Concession category:CHILDERN BELOW FIVE\n";
			b.amc=0.0;
		    }
		    else if(b.con==4)
		    {
			cout<<"You cannot get any concession\n";
			b.amc=b.nosr*amt;
		    }

		    srand((unsigned) time(&t));
		    b.pnr=rand();
		    f2.write((char *) & b,sizeof(b));
		    b.displayresdet();
		    cout<<"------------------------------------------------------\n";
		    cout<<"--------------Your ticket is reserved-----------\n";
		    cout<<"-----------------End of reservation menu-------\n";
		}
		else
		{
		    cout<<"**********Sorry req seats not available********\n";

		}
	    }
	    else if(strcmp(b.clas,s)==0)
	    {
		if(a.c2>=b.nosr)
		{
		    amt=a.c2fare;
		    addr=f1.tellg();
		    ad=sizeof(a.c2);
		    f1.seekp(addr-(5*ad));
		    a.c2=a.c2-b.nosr;
		    f1.write((char *) & a.c2,sizeof(a.c2));
		    if(b.con==1)
		    {
			cout<<"Concession category:MILITARY PRESONNEL\n";
			b.amc=b.nosr*((amt*50)/100);
		    }
		    else if(b.con==2)
		    {
			cout<<"Concession category:SENIOR CITIZEN\n";
			b.amc=b.nosr*((amt*60)/100);
		    }
		    else if(b.con==3)
		    {
			cout<<"Concession category:CHILDERN BELOW FIVE\n";
			b.amc=0.0;
		    }
		    else if(b.con==4)
		    {
			cout<<"You cannot get any concession\n";
			b.amc=b.nosr*amt;
		    }
		    f2.write((char *) & b,sizeof(b));
		    b.displayresdet();
		    cout<<"---------------------------------------\n";
		    cout<<"--------Your ticket is reserved--------\n";
		    cout<<"------------End of reservation---------\n";
		}
		else
		{
		    cout<<"********Sorry req no of seats not available*******\n";
		}
	    }
	    getch();
	}
	else
    {
	cout<<"............Wrong Bus no......................\n";
	cout<<"......Enter the Bus no from the data base.....\n";
    }
  } // end of while
    f1.close();
    f2.close();
    getch();
}
void displaypassdetail()
{
    fstream f;
    reser b;
    f.open("p.txt",ios::in|ios::out|ios::binary);
    f.seekg(0);
    while(f.read((char *) & b,sizeof(b)))
    {
	b.displayresdet();
    }
    f.close();
    getch();
}
	void enquiry()
{

    fstream f;
    f.open("t.txt",ios::in|ios::out|ios::binary);
    detail a;
    while(f.read((char *) & a,sizeof(a)))
    {
	a.displaydetail();
    }
    getch();
}
void cancell()
{
    detail a;
    reser b;
    canc c;
    fstream f1,f2,f3;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary);
    f3.open("cn.txt",ios::in|ios::out|ios::binary);
    int count=0;
    cout<<"**********CANCELLATION MENU*********\n";
    f1.seekg(0);
    c.getcancdet();
    while(f2.read((char *) & b,sizeof(b)))
    {

	if(b.pnr==c.pnr)
	{

	 c.bno=b.bno;
	 strcpy(c.bname,b.bname);
	 strcpy(c.bp,b.bp);
	 strcpy(c.dest,b.dest);
	 c.nosc=b.nosr;
	 for(int j=0;j<c.nosc;j++)
	 {
	  strcpy(c.pname[j],b.pname[j]);
	  c.age[j]=b.age[j];
	  }
	  strcpy(c.clas,b.clas);
	    if(strcmp(b.clas,"f")==0)
	    {
		while(f1.read((char *) & a,sizeof(a)))
		{

		    if(a.bno==c.bno)
		    {
			a.c1=a.c1+c.nosc;
			d=a.d;
			m=a.m;
			addr=f1.tellg();
			ad=sizeof(a.c1);
			f1.seekp(addr-(7*ad));
			f1.write((char *) &a.c1,sizeof(a.c1));
			tamt=b.amc;
			if((c.d==d)&&(c.m==m))
			{
			    cout<<"You are cancelling at the date of departure\n";
			    c.amr=tamt-((tamt*60)/100);
			    cout<<"Amt you get : Rs"<<c.amr;
			}
			else if(c.m==m)
			{
			    cout<<"You are cancelling at the month of departure\n";
			    c.amr=tamt-((tamt*50)/100);
			    cout<<"Amt you get : Rs"<<c.amr;
			}
			else if(m>c.m)
			{
			    cout<<"You are cancelling one month before the date of departure\n";
			    c.amr=tamt-((tamt*20)/100);
			    cout<<"Amt you get : Rs"<<c.amr;
			}

			else
			{
			    cout<<"Cancelling after the departure\n";
			    cout<<"Your request cannot be completed\n";
			}

		    }
		}

	    }
	    else if(strcmp(c.clas,"s")==0)
	    {
		while(f1.read((char *) & a,sizeof(a)))
		{

		    if(a.bno==c.bno)
		    {
			a.c2=a.c2+c.nosc;
			d=a.d;
			m=a.m;
			addr=f1.tellg();
			ad=sizeof(a.c2);
			f1.seekp(addr-(5*ad));
			f1.write((char *) &a.c2,sizeof(a.c2));
			tamt=b.amc;
			if((c.d==d)&&(c.m==m))
			{
			    cout<<"You are cancelling at the date of departure\n";
			    c.amr=tamt-((tamt*60)/100);
			}
			else if(c.m==m)
			{
			    cout<<"You are cancelling at the month of departure\n";
			    c.amr=tamt-((tamt*50)/100);
			}
			else if(m>c.m)
			{
			    cout<<"You are cancelling one month before the date of departure\n";
			    c.amr=tamt-((tamt*20)/100);
			   c.displaycancdet();
			}
			else
			{
			    cout<<"Cancelling after the departure\n";
			    cout<<"Your request cannot be completed\n";
			}

		    }
		}
	    }
	    c.displaycancdet();
	    cout<<"\nYou can collect:"<<c.amr<<"-Rs."<<endl;

	}

	else
	{
	    if(b.pnr!=c.pnr)
	f3.write((char *) &b,sizeof(b));

	}
    } // end while loop
    f1.close();
    f2.close();
    f3.close();
    remove("p.txt");
    rename("cn.txt","p.txt");
    getch();
}
void user()
{
    login a;
    int ch;
    cout<<"*****************************************************\n";
    cout<<"***********WELCOME TO THE USER MENU**\n";
    cout<<"****************************************************\n";
    char *password;
    fstream f;
    f.open("id.txt",ios::in|ios::out|ios::binary);
    char id[100];
    puts("Enter your id:");
    gets(id);
    password=getpass("Enter your password:");

    while(f.read((char *) & a,sizeof(a)))
    {
	if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0))
	{
		cout<<"1.Reserve\n2.Cancel\n3.Enquiry\n4.Exit\n";
		cout<<"Enter your choice:";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
		case 1:
		    res();
		    break;
		/*case 2:
		    cancell();
		    break;*/
		case 2:
		    enquiry();
		    break;
		case 3:
		break;
		}    // end of switch
	    } // end if
	 else
	 cout<<"Incorrect id or password \n";
     } //end of while
    getch();
   } // end of user mode
void manage()
{
    menu3:
    clrscr();
    int ch;
    fstream f;
    char c;
    login a;
    cout<<".........WELCOME TO THE USER MANAGEMENT MENU........\n";
    do
    {
	cout<<"1.Create id data base\n2.Add details\n";
	cout<<"3.Display details\n4.Return to the main menu\n";
	cout<<"Enter your choice:";
	cin>>ch;
	cout<<endl;
	switch(ch)
	{
	case 1:
	    f.open("id.txt",ios::out|ios::binary);
	    do
	    {
		a.getid();
		f.write((char *) & a,sizeof(a));
		cout<<"Do you want to add one more record\n";
		cout<<"y-Yes\nn-No\n";
		cin>>c;
	    }
	    while(c=='y');
	    f.close();
	    break;
	case 2:
	    f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);
	    a.getid();
	    f.write((char *) & a,sizeof(a));
	    f.close();
	    break;
	case 3:
	    f.open("id.txt",ios::in|ios::out|ios::binary);

	    f.seekg(0);
	    while(f.read((char *) & a,sizeof(a)))
	    {
		a.displayid();
	    }
	    f.close();
	    break;
	}
    }
    while(ch<=3);
    getch();
}

