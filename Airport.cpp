// 	Header Files 	 
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
// 	classes 	

class passenger
{
int Pno;
char Name[30]; int Age;
char Gender;
long double Mobileno; long double Passportno; public:
void show(); void input(); void genpno();
int retpno(){return Pno;}
};
class flight
{
int Flightno;
char Destination[4],Origin[4]; int arrhr,arrmin;
int dephr,depmin; char Aircraft[40]; long Fare;
public:
int Economy[2],Business[2]; void inpfno();
void input();
int search(char[3],char[3]); int retfno(){return Flightno;} void display();
};
// 	function Prototypes 	 
void book();
void admin(); 
void Register();
void showflights();
void createflight();
void deleteflight(); 
void modifyflight(); 
void viewbookingdata();
void customerbookingdata();
void deletepassenger();
void modifypassenger();
// 	main function 	
void main()
{
clrscr(); 
randomize();
int choice; 
do
{
clrscr();
cout<<"what would you like to do\n1.book a flight\n2. customer registration\n3.exit\n4.admin";
cin>>choice; 
clrscr();
switch(choice)
{
case 1:book();
break;

case 2:Register();
break;

case 4:admin();
}
} while(choice!=3);
}
// 	Function Definitions 	 
void Register()
{
fstream fil; fil.open("PASSINFO.DAT",ios::binary|ios::app);
passenger P;
char choice; 
do
{
P.input();
P.genpno();
P.show();
getch(); 
cout<<endl;
fil.write((char*)&P,sizeof(P)); 
cout<<"\ndo you want to input more(Y/N)"; cin>>choice;
}while(choice=='Y'||choice=='y'); 
fil.close();
getch();
}
void admin()
{
char Password[]="0172",inp[40],I='\0'; 
cout<<"enter password:";
int ctr=0; 
while(I!=13)
{
I=getch(); 
if(I==8&&ctr!=0)
{
ctr--;

cout<<I<<(char)32<<I;
}
else if(I!=13)
{
inp[ctr]=I;
ctr++;
cout<<'*';
}
}
inp[ctr]='\0';
if(!(strcmp(Password,inp)))
{
int choice=1; 
do
{
cout<<"\nwhat do you want to do:\n1.MANAGE FLIGHTS\n2.MANAGE CUSTOMERS\n3.log out\n";
cout<<"Enter choice:"; 
cin>>choice;
if(choice==1)
{
cout<<"what do you want to do\n1.CREATE FLIGHT\n2.DELETE FLIGHT\n3.MODIFY FLIGHT\n4.VIEW FLIGHT DATA";
cin>>choice; clrscr(); 
switch(choice)
{
case 1:
  createflight(); 
break;
case 2:
  deleteflight();
break;
case 3:
  modifyflight();
break;
case 4: 
  viewflightdata();
break;
}
}
if(choice==2)
{
cout<<"what do you want to do\n1.view customer data\n2.delete a customer\n3.modify customer data\n";
cin>>choice; 
switch(choice)
{






}
}
clrscr();
case 1: customerbookingdata(); break;
case 2: deletepassenger(); break;
case 3: modifypassenger();


}while(choice!=3);
}
}
void createflight()
{
flight A; char choice;


fstream fil("FLIGHTS.DAT",ios::binary|ios::app); do
{
A.inpfno();
A.input(); fil.write((char*)&A,sizeof(A)); A.display();
cout<<"do you want to create more flights"; cin>>choice;
}while(choice=='y'||choice=='Y'); fil.close();
}
void deleteflight()
{

flight F;
fstream fil1("FLIGHTS.DAT",ios::binary|ios::in); int flno,flag=0;
cout<<"enter the flightno to be deleted(0 to go back):"; cin>>flno;
if(flno!=0)
{















refunded";
fstream fil1("FLIGHTS.DAT",ios::binary|ios::in); fstream fil2("NEW.DAT",ios::binary|ios::out); while(fil1.read((char*)&F,sizeof(F)))
{
if(!(F.retfno()==flno)) fil2.write((char*)&F,sizeof(F));
else flag++;
}
fil1.close();
fil2.close(); remove("FLIGHTS.DAT"); rename("NEW.DAT","FLIGHTS.DAT");
if(flag)
cout<<"successfully deleted\nAll passengers will be

}


getch();
}
void modifyflight()
{
cout<<"enter the flightno to be modified(0 to go back):"; int flno;
cin>>flno; if(flno)
{
int flag=0; flight T; fstream fil;
fil.open("FLIGHTS.DAT",ios::binary|ios::in|ios::out); while(fil.read((char*)&T,sizeof(T))&&flag==0)
{
if(T.retfno()==fno)
{
fil.seekp(fil.seekg-(sizeof(T))); flight F;
T.input() fil.write((char*)&T,sizeof(T))


flag++;
}
if(flag)
cout<<"flight modified";


else


}

}
}

cout<<"flight not found";


void viewflightdata()
{
flight F; int ctr=0;



fstream file("FLIGHTS.DAT",ios::binary|ios::in); while(file.read((char*)&F,sizeof(F)))
{
F.display(); if(ctr%4==3)
{


getch();
clrscr();
}




getch();
file.close();
}
ctr++;
}


void customerbookingdata()
{
fstream fil1("PASSINFO.DAT",ios::binary|ios::in);
passenger P; int ctr=0; clrscr();
while(fil1.read((char*)&P,sizeof(P)))
{
P.show(); cout<<endl; if(ctr%4==3)
{
getch();
clrscr();
}
ctr++;
}
getch();
fil1.close();

}
void deletepassenger()
{




to go back):";
passenger P; int Pno,flag=0;
cout<<"enter the passengerno of the passenger to be deleted(0

cin>>Pno; if(Pno!=0)
{


fstream fil2("PASSINFO.DAT",ios::binary|ios::in);


fstream temp("NEW.DAT",ios::binary|ios::out); while(fil2.read((char*)&P,sizeof(P)))
{
if(!(P.retpno()==Pno)) temp.write((char*)&P,sizeof(P));
else flag++;
}
fil2.close();
temp.close(); remove("PASSINFO.DAT"); rename("NEW.DAT","PASSINFO.DAT");
if(flag)
cout<<"successfully deleted\n";

}
getch();

}
void modifypassenger()
{
cout<<"enter the Passengerno of the passenger to be modified(0 to go back):";
int flag=0; int pno; cin>>pno; if(pno)
{
int flag=0; passenger T; fstream fil;
fil.open("PASSINFO.DAT",ios::binary|ios::in|ios::out); while(fil.read((char*)&T,sizeof(T))&&flag==0)
{
if(T.retpno()==fno)
{
fil.seekp(fil.seekg-(sizeof(T))); flight F;
T.input() fil.write((char*)&T,sizeof(T)) flag++;
}
if(flag)
cout<<"passenger modified";


else


}

cout<<"passenger not found";




}
void passenger::input()
{
cout<<"PLEASE ENTER YOUR CREDENTIALS"<<endl; cout<<"ENTER YOUR NAME"<<endl;
gets(Name);
cout<<"\nENTER YOUR AGE"<<endl; cin>>Age;
cout<<"ENTER YOUR GENDER(M/F)"<<endl;
cin>>Gender;


cout<<"ENTER YOUR PASSPORT NO"<<endl;
cin>>Passportno;
cout<<"ENTER YOUR MOBILE NO"<<endl;
cin>>Mobileno; int flag; passenger P;
fstream fil("PASSINFO.DAT",ios::binary|ios::in);

}
void passenger::genpno()
{
do
{
Pno=random(1000); flag=0;
while(fil.read((char*)&P,sizeof(P)))
{
if(P.retpno()==Pno) flag++;
}
if(flag==1) fil.seekg(0,ios::beg);
}while(flag==0);
cout<<"Please wait while your unique passenger no. is being generated"<<"......"<<endl;
delay(3000);
cout<<"YOUR UNIQUE PASSENGER ID IS:"<<Pno<<endl;
}
void passenger::show()
{
cout<<"Name:"<<Name<<"	passenger no:"<<Pno; cout<<"\nAge:"<<Age<<"		gender:"<<Gender; cout<<"\nMobileno:"<<Mobileno<<"		passpo rtno:"<<Passportno;
}
void flight::input()
{

cout<<"Enter origin code:"; cin>>Origin;
cout<<"Enter destination code:"; cin>>Destination;
cout<<"Enter arrival time "; cout<<"\nhours:";
cin>>arrhr; cout<<"mins:"; cin>>arrmin;
cout<<"Enter departure time"; cout<<"\nhours:";
cin>>dephr; cout<<"mins:"; cin>>depmin;
cout<<"Enter no of economy seats:"; cin>>Economy[0];
Economy[1]=0;
cout<<"enter no. of business class seats:"; cin>>Business[0];
Business[1]=0;
cout<<"Enter fare for economy:"; cin>>Fare;
cout<<"Enter name of aircraft ";


gets(Aircraft);
}
void flight::inpfno()
{
int flag; fstream fil;
fil.open("FLIGHTS.DAT",ios::binary|ios::in); flight F;
do
{
cout<<"Enter flightno:"; cin>>Flightno;
flag=1; while(fil.read((char*)&F,sizeof(F)))
{
if(F.retfno()==Flightno) flag=0;
}
if(flag==0)
{
cout<<"Flightno already in use"; fil.seekg(0,ios::beg);
}
}while(flag==0);
}

int flight::search(char o[3], char d[3])
{
if(!(strcmpi(o,Origin)||strcmpi(d,Destination))) return 1;
else return 0;
}
void book()
{
int cno,flag=0; passenger P;
cout<<"enter your unique customer number(0 to go back and register):"; cin>>cno;
ifstream fil; fil.open("PASSINFO.DAT");
while(fil.read((char*)&P,sizeof(P))&&flag==0) if(cno)
flag++; fil.close(); if(flag)
{
showflights(); flight F;
int flno=0; flag=0;
cout<<"enter flightno. (0 to go back):"; cin>>flno;
if(flno!=0)
{
fil.open("FLIGHTS.DAT",ios::binary,ios::in); while(fil.read((char*)&F,sizeof(F))&&flag==0)
if(F.retfno()==flno) flag++;
fil.close();


if(flag)
{
char choice='n';
cout<<"do you want business class(Y/N)"; cin>>choice; if(choice=='y'||choice=='Y')
if((F.Business[0]-F.Business[1])>0) F.Business[1]++;
else flag--;
else
if((F.Economy[0]-F.Economy[1])>0) F.Economy[1]++;
else flag--;
if(flag)
{
fil.open("FLIGHTS.DAT",ios::binary|ios::in); fstream temp; temp.open("TEMP.DAT",ios::binary|ios::out); flight T; while(fil.read((char*)&T,sizeof(T)))
{
if(T.retfno()==flno) temp.write((char*)&F,sizeof(F));
else temp.write((char*)&T,sizeof(T));
}
fil.close();
temp.close(); remove("FLIGHTS.DAT"); rename("TEMP.DAT","FLIGHTS.DAT");
cout<<"your booking has been confirmed\nno cancellation and refunds\n seats shall be alloted upon checkin";
}
else
{
cout<<"Seat not available"; getch();
}
}
else
cout<<"invalid flight no."; getch();
}
}
else
cout<<"invalid customer no."; getch();
}
void showflights()
{
char o[4],d[4]; cout<<"enter origin code:"; cin>>o;
cout<<"enter destination code:"; cin>>d;
flight F; fstream fil;
fil.open("FLIGHTS.DAT",ios::binary|ios::in);


int ctr=0; while(fil.read((char*)&F,sizeof(F)))
{

if(F.search(o,d))
{
F.display(); if(ctr%4==3)
{
getch();
clrscr();
}
ctr++;
}
}
fil.close();
}

void flight::display()
{
cout<<"Flightno:"<<Flightno; cout<<"\tORIGIN:"<<Origin<<"\tDestination"<<Destination<<endl; cout<<"economy fare:"<<Fare<<"\tbusiness class fare:"<<4*Fare<<endl; cout<<"economy seats:"<<Economy[0]-Economy[1]<<"\tBusiness class
seats:"<<Business[0]-Business[1]<<endl; cout<<"arrival-"<<arrhr<<':'<<arrmin; cout<<"\tdeparture-"<<dephr<<':'<<depmin; cout<<"	aircraft:"<<Aircraft<<endl;
}
