#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<fstream.h>
#include<stdio.h>
#include<ctype.h>
#include<process.h>
#include<string.h>

class Cars
{	int ModelNo,Mileage,Variant;
	long int BasePrice,SalePrice;
	char ModelName[30],Engine[30];
	public:
	void ViewCars();
	void AddCars();
	void DelCars();
	void ModifyCars();
	int GetModelNo()
	{	return ModelNo;
	}
	long int ReturnBasePrice()
	{	return BasePrice;
	}
	char *GetModelName()
	{	return ModelName;
	}
	char *ReturnEng()
	{	return Engine;
	}
	void DelMod(int X)
	{	fstream fa("Cars.dat",ios::in|ios::binary);
		fstream fb("TempCar.dat",ios::out|ios::binary);
		fa.seekg(0);
		while(fa.read((char*)&Ca,sizeof(Ca)))
		{	if(Ca.GetModelNo()!=X)
			{
				fb.write((char*)&Ca,sizeof(Ca));
			}
		}
		fa.close();
		fb.close();
		remove("Cars.dat");
		rename("TempCar.dat","Cars.dat");
	}
};
Cars Ca;
void Cars::AddCars()
{	cout<<"\nEnter Model Number. ";
	cin>>ModelNo;
	cout<<"\nEnter Model Name. ";
	gets(ModelName);
	cout<<"\nEnter Base Price. ";
	cin>>BasePrice;
	cout<<"\nEnter Mileage. ";
	cin>>Mileage;
	cout<<"\nEnter Engine Specifications. ";
	gets(Engine);
}
void Cars::DelCars()
{       int MNo;
	cout<<"\nEnter Model No. you want to remove. ";
	cin>>MNo;
	fstream fa("Cars.dat",ios::in|ios::binary);
	fstream fb("TempCar.dat",ios::out|ios::binary);
	fa.seekg(0);
	while(fa.read((char*)&Ca,sizeof(Ca)))
	{	if(Ca.GetModelNo()!=MNo)
		{
			fb.write((char*)&Ca,sizeof(Ca));
		}
	}
	fa.close();
	fb.close();
	remove("Cars.dat");
	rename("TempCar.dat","Cars.dat");
	cout<<"\nRecord has been deleted. ";
}
void Cars::ViewCars()
{	cout<<setw(12)<<ModelNo<<setw(16)<<ModelName;
	cout<<setw(16)<<BasePrice<<setw(10)<<Mileage;
	cout<<setw(12)<<Engine<<"\n";
}
void Cars::ModifyCars()
{       char NewMName[30],NewEngine[30];
	long int NewBP;
	cout<<"\nEnter New Model Name. (Press . to retain.) ";
	gets(NewMName);
	cout<<"\nEnter New Base Price. (Press 0 to retain.) ";
	cin>>NewBP;
	cout<<"\nEnter New Engine. (Press . to retain.) ";
	cin>>NewEngine;
	ModelNo+=100;

	if(strcmp(NewEngine,".")!=0)
	{	strcpy(Engine,NewEngine);
	}
	if(NewBP!=0)
	{	BasePrice=NewBP;
	}
	if(strcmp(NewMName,".")!=0)
	{	strcpy(ModelName,NewMName);
	}
}
class CustCar
{	int CustNo,Warranty;
	char CustName[30];
	char PhNo[11];
	public:
	void DelCust();
	void AddCust();
	void ModifyCust();
	void SearchCust();
	int GetCustNo()
	{	return CustNo;
	}
	void ViewCust();
	char *GetCustName()
	{	return CustName;
	}
	void ModDel(int Y)
	{	fstream ca("CustCar.dat",ios::in|ios::binary);
		fstream cb("tempcust.dat",ios::out|ios::binary);
		ca.seekg(0);
		while(ca.read((char*)&C1,sizeof(C1)))
		{	if(C1.GetCustNo()!=Y)
			{	cb.write((char*)&C1,sizeof(C1));
			}
		}
		ca.close();
		cb.close();
		remove("CustCar.dat");
		rename("tempcust.dat","CustCar.dat");
	}
};
CustCar C1;
void CustCar::ViewCust()
{	cout<<setw(12)<<CustNo<<setw(16)<<CustName;
	cout<<setw(16)<<PhNo<<setw(20)<<Warranty<<"\n";
}
void CustCar::AddCust()
{	cout<<"\nCustomer No: ";
	cin>>CustNo;
	cout<<"\nCustomer Name: ";
	gets(CustName);
	cout<<"\nCustomer Phone No: ";
	cin>>PhNo;
	cout<<"\nEnter Warranty Time. ";
	cin>>Warranty;
}
void CustCar::ModifyCust()
{       char NewName[30],NewPh[11];
	cout<<"\nEnter New Name. (Press . to retain.) ";
	gets(NewName);
	cout<<"\nEnter New Phone Number.(Press . to retain.) ";
	cin>>NewPh;
	CustNo+=100;
	if(strcmp(NewName,".")!=0)
	{	strcpy(CustName,NewName);
	}
	if(strcmp(NewPh,".")!=0)
	{	strcpy(PhNo,NewPh);
	}
}
void CustCar::DelCust()
{       int CuNo;
	cout<<"\nEnter Customer no. you want to remove. ";
	cin>>CuNo;
	fstream ca("CustCar.dat",ios::in|ios::binary);
	fstream cb("tempcust.dat",ios::out|ios::binary);
	ca.seekg(0);
	while(ca.read((char*)&C1,sizeof(C1)))
	{	if(C1.GetCustNo()!=CuNo)
		{	cb.write((char*)&C1,sizeof(C1));
		}
	}
	ca.close();
	cb.close();
	remove("CustCar.dat");
	rename("tempcust.dat","CustCar.dat");
	cout<<"\nRecord has been deleted. ";
	getch();
}
void Booking()
{	fstream CBook("Cars.dat",ios::in|ios::binary);
	int Choice,Units,Var,TempCust;
	char Va[4];
	char *Temp,*NameTemp,*TempEng;
	long int y,SP,Paid;
	clrscr();
	cout<<"\nCar list: ";
	cout<<"\n\t\t\t\tCAR RECORDS";
	cout<<"\n********************************************************************************";
	cout<<"\n"<<setw(12)<<"Model No"<<setw(16)<<"Model Name";
	cout<<setw(16)<<"Base Price"<<setw(10)<<"Mileage";
	cout<<setw(12)<<"Engine\n";
	while(CBook.read((char*)&Ca,sizeof(Ca)))
	{	Ca.ViewCars();
	}
	CBook.close();
	cout<<"\nEnter your choice. ";
	cin>>Choice;
	cout<<"\nEnter number of units. ";
	cin>>Units;
	CBook.open("Cars.dat",ios::in|ios::binary);
	CBook.seekg(ios::beg);
	while(CBook.read((char*)&Ca,sizeof(Ca)))
	{	if(Choice==Ca.GetModelNo())
		{	y=Ca.ReturnBasePrice();
			Temp=Ca.GetModelName();
			TempEng=Ca.ReturnEng();
			break;
		}
	}
	CBook.close();
	cout<<"\nEnter 1 for LXI, 2 for ZXI. ";
	cin>>Var;
	if(Var==1)
	{	SP=y;
		strcpy(Va,"LXI");
	}
	else
	{	SP=y+5000;
		strcpy(Va,"ZXI");
	}
	fstream fadd("CustCar.dat",ios::binary|ios::app);
	if(!fadd)
	{	fstream fadd("CustCar.dat",ios::out|ios::binary);
		if(!fadd)
		{	cout<<"File not found. ";
			exit(0);
		}
	}
	C1.AddCust();
	cout<<"Record added. ";
	fadd.write((char*)&C1,sizeof(C1));
	fadd.seekg((-1)*sizeof(C1),ios::cur);
	NameTemp=C1.GetCustName();
	TempCust=C1.GetCustNo();
	fadd.close();
	cout<<"\Press enter to continue. ";
	getch();
	clrscr();
	gotoxy(1,1);
	cout<<"********************************************************************************";
	gotoxy(18,2);
	cout<<"Cust No: "<<TempCust;
	gotoxy(38,2);
	cout<<"INVOICE";
	gotoxy(58,2);
	cout<<"Customer: "<<NameTemp;
	gotoxy(1,3);
	cout<<"********************************************************************************";
	gotoxy(1,5);
	cout<<setw(5)<<"MNo"<<setw(20)<<"Model Name"<<setw(7)<<"BP";
	cout<<setw(12)<<"Variant"<<setw(5)<<"Qty"<<setw(10)<<"SP"<<setw(12)<<"Engine\n";
	cout<<setw(5)<<Choice<<setw(20)<<Temp<<setw(7)<<y<<setw(12)<<Va;
	cout<<setw(5)<<Units<<setw(10)<<SP*Units<<setw(12)<<TempEng<<"\n";
	gotoxy(30,15);
	cout<<"NET AMT: AED"<<SP*Units;
	gotoxy(30,16);
	cout<<"AMT PAID: AED";cin>>Paid;
	gotoxy(30,17);
	cout<<"CHANGE: AED"<<Paid-(SP*Units);
	gotoxy(10,19);
	cout<<"THANK YOU FOR DEALING WITH TOYOTA. HAVE A NICE DAY!";
}
void main()
{       clrscr();
	int Ch1,Ch2,Ch3;
	while(1)
	{       clrscr();
		gotoxy(32,8);
		textcolor(2);
		textbackground(0);
		cprintf("TOYOTA DEALERSHIP");
		gotoxy(30,14);
		cout<<"Guided by Mrs Reshma Premarajan. ";
		gotoxy(30,16);
		cout<<"Done By Shikhar Chaurasia. ";
		gotoxy(30,18);
		cout<<"Class: XII B";
		gotoxy(30,20);
		cout<<"Roll No: 27610025";
		getch();
		clrscr();
		gotoxy(30,6);
		cout<<"MAIN MENU";
		gotoxy(30,8);
		cout<<"1) For Car details.";
		gotoxy(30,10);
		cout<<"2) For Cust records.";
		gotoxy(30,12);
		cout<<"3) For Booking.";
		gotoxy(30,14);
		cout<<"4) For Exiting. ";
		cin>>Ch1;
		switch(Ch1)
	{
	case 1: {	clrscr();
	clrscr();
	char password[10],ch,opt2;
	int i;
	      do
		{       i=0;
			clrscr();
			gotoxy(30,12);
			cout<<"Enter Admin Password";
			gotoxy(30,14);
			while((ch=getch())!='\r')
			{
				cout<<'*';
				password[i]=ch;
				i++;
			}
			password[i]='\0';
			if(strcmp(password,"cars")!=0)
				{	gotoxy(20,16);
					cout<<"Wrong password. Try again? (Y for Yes) ";
					cin>>opt2;
					if(tolower(opt2)=='y')
				       {	continue; }
					else
					{	gotoxy(30,18);
						cout<<"Exiting program. ";
						getch();
						exit(0);
					}
				}
			else
			break;
		}while(opt2=='y'||opt2=='Y');
	clrscr();
	gotoxy(30,12);
	cout<<"Entering into main menu.";
	getch();
	clrscr();
	cout<<"\t\t\t\tWELCOME TO CAR SHOWROOM. ";
	cout<<"\n*******************************************************************************";
	cout<<"\n\n\n\t\t\tEnter 1 for Adding Records. ";
	cout<<"\n\t\t\tEnter 2 for Viewing Records. ";
	cout<<"\n\t\t\tEnter 3 for Deleting Records. ";
	cout<<"\n\t\t\tEnter 4 for Modifying. ";
	cout<<"\n\t\t\tEnter 5 for Exiting. ";
	cin>>Ch2;
	switch(Ch2)
	{       clrscr();
		case 1:{        clrscr();
				cout<<"\nAdding Records. ";
				fstream CAdd("Cars.dat",ios::app|ios::out|ios::binary);
				if(!CAdd)
				{	fstream CAdd("Cars.dat",ios::out|ios::binary);
					if(!CAdd)
					{	cout<<"\nCannot find file. ";
						exit(0);
					}
				}
				Ca.AddCars();
				CAdd.write((char*)&Ca,sizeof(Ca));
				cout<<"\nRecord Added. ";
				cout<<"\n********************************************************************************";
				cout<<"\n"<<setw(12)<<"Model No"<<setw(16)<<"Model Name";
				cout<<setw(16)<<"Base Price"<<setw(10)<<"Mileage";
				cout<<setw(12)<<"Engine\n";
				Ca.ViewCars();
				CAdd.close();
				getch();
				break;
			}

		case 2:{        clrscr();
				fstream CView("Cars.dat",ios::in|ios::binary);
				if(!CView)
				{	cout<<"Cannot open file. ";
					exit(0);
				}
				CView.seekg(0);
				cout<<"\n\t\t\t\t\tCAR RECORDS";
				cout<<"\n********************************************************************************";
				cout<<"\n"<<setw(12)<<"Model No"<<setw(16)<<"Model Name";
				cout<<setw(16)<<"Base Price"<<setw(10)<<"Mileage";
				cout<<setw(12)<<"Engine\n";
				while(CView.read((char*)&Ca,sizeof(Ca)))
				{
					Ca.ViewCars();
				}
				CView.close();
				getch();
				break;
			}
		case 3:{	clrscr();
				cout<<"\nDeleting Records. ";
				fstream CView("Cars.dat",ios::in|ios::binary);
				if(!CView)
				{	cout<<"Cannot open file. ";
					exit(0);
				}
				CView.seekg(0);
				cout<<"\n\t\t\t\t\tCAR RECORDS";
				cout<<"\n********************************************************************************";
				cout<<"\n"<<setw(12)<<"Model No"<<setw(16)<<"Model Name";
				cout<<setw(16)<<"Base Price"<<setw(10)<<"Mileage";
				cout<<setw(12)<<"Engine\n";
				while(CView.read((char*)&Ca,sizeof(Ca)))
				{
					Ca.ViewCars();
				}
				CView.close();
				getch();
				Ca.DelCars();
				cout<<"\nPress any key to return to main menu. ";
				getch();
				break;
		       }
		case 4:{	fstream CMod("Cars.dat",ios::binary|ios::in|ios::out);
				int RecNo;
				char found='y';
				fstream CView("Cars.dat",ios::in|ios::binary);
				if(!CView)
				{	cout<<"Cannot open file. ";
					exit(0);
				}
				CView.seekg(0);
				cout<<"\n\t\t\t\t\tCAR RECORDS";
				cout<<"\n********************************************************************************";
				cout<<"\n"<<setw(12)<<"Model No"<<setw(16)<<"Model Name";
				cout<<setw(16)<<"Base Price"<<setw(10)<<"Mileage";
				cout<<setw(12)<<"Engine\n";
				while(CView.read((char*)&Ca,sizeof(Ca)))
				{
					Ca.ViewCars();
				}
				CView.close();
				getch();
				cout<<"\nEnter Record to be modified. ";
				cin>>RecNo;
				while(!CMod.eof())
				{
					CMod.read((char*)&Ca,sizeof(Ca));
					if(Ca.GetModelNo()==RecNo)
					{	Ca.ModifyCars();
						found=='y';
						CMod.write((char*)&Ca,sizeof(Ca));
						CMod.seekg((-2)*sizeof(Ca));
						Ca.DelMod(RecNo);	//mod here
						break;
					}
				}

				CMod.close();
				if(found=='n')
				{	cout<<"Record not found. ";
				}
				cout<<"\nRecord is now modified as follows.\n ";
				cout<<"\n********************************************************************************";
				cout<<"\n"<<setw(12)<<"Model No"<<setw(16)<<"Model Name";
				cout<<setw(16)<<"Base Price"<<setw(10)<<"Mileage";
				cout<<setw(12)<<"Engine\n";
				Ca.ViewCars();
				getch();
				break;
			}
		case 5:{
				break;
		       }
		       }
				break;
		       }
	case 2: {clrscr();
	char password1[10],ch1,cc;
	int i1;
	      do
		{       i1=0;
			clrscr();
			gotoxy(30,12);
			cout<<"Enter Password";
			gotoxy(30,14);
			while((ch1=getch())!='\r')
			{
				cout<<'*';
				password1[i1]=ch1;
				i1++;
			}
			password1[i1]='\0';
			if(strcmp(password1,"cust")!=0)
				{	gotoxy(20,16);
					cout<<"Wrong password. Try again? (Y for Yes) ";
					cin>>cc;
					if(tolower(cc)=='y')
				       {	continue; }
					else
					{	gotoxy(30,18);
						cout<<"Exiting program. ";
						getch();
						exit(0);
					}
				}
			else
			break;
		}while(cc=='y'||cc=='Y');
	clrscr();
	gotoxy(30,12);
	cout<<"Entering into main menu.";
	getch();
	clrscr();
		cout<<"\n\t\t\t\tCUSTOMER DATA";
		cout<<"\n\t\t******************************************";
		cout<<"\n\t\t1) For Viewing Customer Records. ";
		cout<<"\n\t\t2) For Modifying Customer Records. ";
		cout<<"\n\t\t3) For Deleting Customer Records. ";
		cout<<"\n\t\t4) For Exiting. ";
		cin>>Ch3;
		switch(Ch3)
		{
			case 1: {      clrscr();
				gotoxy(30,1);
				cout<<"CUSTOMER RECORDS";
				fstream fin("CustCar.dat",ios::in|ios::binary);
				if(!fin)
				{	cout<<"\nFile not found. ";
					exit(0);
				}
				cout<<"\n*******************************************************************************";
				cout<<"\n"<<setw(12)<<"Customer No"<<setw(16)<<"Customer Name";
				cout<<setw(16)<<"Customer Phone"<<setw(20)<<"Warranty Time\n";
				fin.seekg(0);
				while(fin.read((char*)&C1,sizeof(C1)))
				{	C1.ViewCust();
				}
				getch();
				fin.close();
				break;
				}
			case 2: {       clrscr();
					fstream fmod("CustCar.dat",ios::binary|ios::in|ios::out);
					int CNo;
					char found='n';
				cout<<"CUSTOMER RECORDS";
				fstream fin("CustCar.dat",ios::in|ios::binary);
				if(!fin)
				{	cout<<"\nFile not found. ";
					exit(0);
				}
				cout<<"\n*******************************************************************************";
				cout<<"\n"<<setw(12)<<"Customer No"<<setw(16)<<"Customer Name";
				cout<<setw(16)<<"Customer Phone"<<setw(20)<<"Warranty Time\n";
				fin.seekg(0);

				while(fin.read((char*)&C1,sizeof(C1)))
				{	C1.ViewCust();
				}
				getch();
				fin.close();
					cout<<"\nEnter Customer Number to be modified. ";
					cin>>CNo;
					while(!fmod.eof())
					{
						fmod.read((char*)&C1,sizeof(C1));
						if(C1.GetCustNo()==CNo)
						{	C1.ModifyCust();
							fmod.write((char*)&C1,sizeof(C1));
							fmod.seekg((-2)*sizeof(C1));
							C1.ModDel(CNo);
							found=='y';
						}
					}
					fmod.close();
					cout<<"\nRecord is now modified as follows. ";
					cout<<"\n*******************************************************************************";
					cout<<"\n"<<setw(12)<<"Customer No"<<setw(16)<<"Customer Name";
					cout<<setw(16)<<"Customer Phone"<<setw(20)<<"Warranty Time\n";
					C1.ViewCust();
					getch();
					break;
				}
			case 3:{	clrscr();
					cout<<"\nDeleting Records. ";
					cout<<"CUSTOMER RECORDS";
					fstream fin("CustCar.dat",ios::in|ios::binary);
					if(!fin)
					{	cout<<"\nFile not found. ";
						exit(0);
					}
					cout<<"\n*******************************************************************************";
					cout<<"\n"<<setw(12)<<"Customer No"<<setw(16)<<"Customer Name";
					cout<<setw(16)<<"Customer Phone"<<setw(20)<<"Warranty Time\n";
					fin.seekg(0);
					while(fin.read((char*)&C1,sizeof(C1)))
					{	C1.ViewCust();
					}
					getch();
					fin.close();
					C1.DelCust();
					getch();
					break;
			       }
			case 4:	{
					break;
				}
		}
		break;
	}
	case 3:{	clrscr();
			cout<<"\nCar Booking. ";
			Booking();
			getch();
			break;
		}
	case 4: {exit(0);
	}
	getch();
}
	}
	getch();
}
