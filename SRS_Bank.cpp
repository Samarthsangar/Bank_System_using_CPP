/*************************************************************** Bank Server *************************************************************************/
/*
Name : Samarth Rajendra Sangar
Date : 01/12/2024
Project Name : Bank server using C++.
*/

#include<iostream>			//including header file's
#include<stdlib.h>
#include<unistd.h>
#include<cstring>
#include "Bank.h"

using namespace std;			//use of namespce

unsigned int Flag,Account_NO,Index;	//flag to chcek condition's
unsigned char c;

class Bank			//class of name Bank
{
    private :			//privte data members of class

    	string Mobile_Number;
    	string Gender;
	int Password;
    public: 			//public members of class
	string Name;
    	double Balance;
    	long int Account_Number;

	void ADD_Account()		//function call to add account into bank
	{
	    	getchar();
		cout<<BLUE<<"Enter the Account Holder Name : "<<RESET;		//taking information from user
		getline(cin,Name);
		Account_Number=1000000+(++Account_NO);			//generating automatic account number

		cout<<BLUE<<"Enter the Current account Balance : "<<RESET;
		cin>>Balance;
	
		getchar();	
		label1:
		cout<<BLUE<<"Enter the Mobile number : "<<RESET;
		getline(cin,Mobile_Number);
		if((Mobile_Number.length())!=10)
		{
	    		cout<<RED<<"Please Enter correct Mobile number !!"<<RESET<<endl;
	    		goto label1;
		}
		int temp=0;

		label3:
		cout<<YELLOW<<"Select gender : 1.Male  2.Female  3.Trans"<<RESET<<endl<<BLUE<<"--> "<<RESET;
		cin>>temp;
		Gender=(temp==1?"Male":(temp==2?"Female":(temp==3?"Trans":"NO")));

		if((Gender.length())==2)
		{
	    		cout<<RED<<"Wrong entry !!"<<RESET<<endl;
	    		goto label3;
		}

		label4:
		cout<<BLUE<<"Set Password [4-digit only & numerical only] : "<<RESET;
		cin>>Password;
		if(Password<=999 || Password>=10000)
		{
		    cout<<RED<<"Please enter Passowed of 4 digit !!"<<RESET<<endl;
		    goto label4;
		}
		system("clear");
		cout<<SMILE<<GREEN<<" WELCOME "<<Name<<" in online bank"<<RESET<<endl<<BLUE<<"You account created sucessfullay"<<RESET<<endl;
		cout<<BLUE<<"Your Acount Number : "<<RESET<<Account_Number<<endl;
		cout<<BLUE<<"Your passowrd : "<<RESET<<Password<<endl;
		sleep(4);
	}

	int Deposite_Amount()				//function to deposite amount into particular account
	{
	    long int Deposite=0,password=0;
	    cout<<endl<<BLUE<<"Acount Holder Name : "<<RESET<<Name<<endl;		//display of account information
	    cout<<BLUE<<"Acount Holder Mobile Number : "<<RESET<<Mobile_Number<<endl;
	    cout<<BLUE<<"Account Number : "<<RESET<<Account_Number<<endl;
	    cout<<BLUE<<"Acount Holder Account current Balance : "<<RESET<<Balance<<endl;
	    cout<<BLUE<<"Acount Holder Gender : "<<RESET<<Gender<<endl;
	    cout<<YELLOW<<"Want to Deposite in this account (Y/N) : "<<RESET;
	    cin>>c;
	    if(c!='y' && c!='Y')		//taking input from user
    		return 0;
	    label5:
	    cout<<YELLOW<<"Enter amount to deposite [Min 500$] : "<<RESET;
	    cin>>Deposite;
	    if(Deposite<500)
	    {
		cout<<RED<<"Please do min 500$ Deposite !!"<<RESET<<endl;
		goto label5;
	    }
	    cout<<YELLOW<<"Enter Password [4-digit] : "<<RESET;			//taking password
	    cin>>password;
	    if(Password!=password)
	    {
		cout<<RED<<"Wrong Passowrd !! "<<RESET<<endl;
		return 0;
	    }
	    Balance+=Deposite;
	    return 1;    
	}
	int Withdrow_Amount()				//function to withdrow amount from particular acount
	{
	    long int Withdrow=0,password=0;
	    cout<<endl<<BLUE<<"Acount Holder Name : "<<RESET<<Name<<endl;		//printing user information
	    cout<<BLUE<<"Acount Holder Mobile Number : "<<RESET<<Mobile_Number<<endl;
	    cout<<BLUE<<"Account Number : "<<RESET<<Account_Number<<endl;
	    cout<<BLUE<<"Acount Holder Account current Balance : "<<RESET<<Balance<<endl;
	    cout<<BLUE<<"Acount Holder Gender : "<<RESET<<Gender<<endl;
	    cout<<YELLOW<<"Want to Withdrow amount in this account (Y/N) : "<<RESET;
	    cin>>c;
	    if(c!='y' && c!='Y')			//taking input from user
    		return 0;
	    W_Label1:
	    cout<<YELLOW<<"Enter withdrow amount [min 100$ & max 10000&] : "<<RESET;
	    cin>>Withdrow;
	    if(Withdrow<=99 || (Withdrow>=10001))
	    {
		cout<<RED<<"Enter Amount in between 100-10000 only !!"<<RESET<<endl;
		goto W_Label1;
	    }
	    else if(Withdrow>Balance)
	    {
		cout<<RED<<"Insufficient Balance in your account !!"<<RESET<<endl;
		goto W_Label1;
	    }

	    cout<<YELLOW<<"Enter Password [4-digit] : "<<RESET;
	    cin>>password;
	    if(Password!=password)
	    {
		cout<<RED<<"Wrong Passowrd !! "<<RESET<<endl;
		return 0;
	    }
	    Balance-=Withdrow;
	    return 1;
	}
	int Transfer_Amount(class Bank *ref,int i)		//function call to transfer amount
	{
	    long int transfer=0,password=0;
	    cout<<endl<<BLUE<<"Acount Holder Name : "<<RESET<<Name<<endl;		//printing information of receiver acount
	    cout<<BLUE<<"Acount Holder Mobile Number : "<<RESET<<Mobile_Number<<endl;
	    cout<<BLUE<<"Account Number : "<<RESET<<Account_Number<<endl;
	    cout<<BLUE<<"Acount Holder Gender : "<<RESET<<Gender<<endl;
	    cout<<YELLOW<<"Want to Transfer amount to this account (Y/N) : "<<RESET;
	    cin>>c;
	    if(c!='y' && c!='Y')		//taking input from user
    		return 0;
	    cout<<endl<<BLUE<<"Acount Holder Name : "<<RESET<<ref[i].Name<<endl;	//printing information of sender acount
	    cout<<BLUE<<"Acount Holder Mobile Number : "<<RESET<<ref[i].Mobile_Number<<endl;
	    cout<<BLUE<<"Account Number : "<<RESET<<ref[i].Account_Number<<endl;
	    cout<<BLUE<<"Acount Holder Account current Balance : "<<RESET<<ref[i].Balance<<endl;
	    cout<<BLUE<<"Acount Holder Gender : "<<RESET<<ref[i].Gender<<endl;
	    cout<<YELLOW<<"Want to Transfer amount from this account (Y/N) : "<<RESET;
	    cin>>c;
	    if(c!='y' && c!='Y')			//taking input from user
    		return 0;
            T_Label1:
	    cout<<endl<<YELLOW<<"Enter trnasfer amount [min 100$ & max 10000&] :"<<RESET;
	    cin>>transfer;
	    if(transfer<=99 || (transfer>=10001))
	    {
		cout<<RED<<"Enter Amount in between 100-10000 only !!"<<RESET<<endl;
		goto T_Label1;
	    }
	    else if(transfer>ref[i].Balance)
	    {
		cout<<RED<<"Insufficient Balance in your account !!"<<RESET<<endl;
		goto T_Label1;
	    }

	    cout<<YELLOW<<"Enter Password [4-digit] : "<<RESET;
	    cin>>password;
	    if(ref[i].Password!=password)
	    {
		cout<<RED<<"Wrong Passowrd !! "<<RESET<<endl;
		return 0;
	    }
	    ref[i].Balance-=transfer;
	    Balance+=transfer;
	    return 1;
	}
	void Check_balance()		//function call to check balance
	{

	    cout<<endl<<BLUE<<"Acount Holder Name : "<<RESET<<Name<<endl;	//printing user information
	    cout<<BLUE<<"Acount Holder Mobile Number : "<<RESET<<Mobile_Number<<endl;
	    cout<<BLUE<<"Account Number : "<<RESET<<Account_Number<<endl;
	    cout<<BLUE<<"Acount Holder Account current Balance : "<<RESET<<Balance<<endl;
	    cout<<BLUE<<"Acount Holder Gender : "<<RESET<<Gender<<endl;
	}
        void Bank_Server(class Bank *ref)		//function call to print all account holder information
        {
		for(int i=0; i<Flag; i++)
		{

	    		cout<<endl<<BLUE<<"Acount Holder Name : "<<RESET<<ref[i].Name<<endl;
	   	 	cout<<BLUE<<"Acount Holder Mobile Number : "<<RESET<<ref[i].Mobile_Number<<endl;
	    		cout<<BLUE<<"Account Number : "<<RESET<<ref[i].Account_Number<<endl;
	    		cout<<BLUE<<"Acount Holder Account current Balance : "<<RESET<<ref[i].Balance<<endl;
	    		cout<<BLUE<<"Acount Holder Gender : "<<RESET<<ref[i].Gender<<endl<<endl;
		}
		cout<<YELLOW<<"To exit press any key : "<<RESET;
		cin>>c;
		getchar();	
	}
	int Delete_account()		//function call to delete account
	{
   		cout<<endl<<BLUE<<"Acount Holder Name : "<<RESET<<Name<<endl;
	   	cout<<BLUE<<"Acount Holder Mobile Number : "<<RESET<<Mobile_Number<<endl;
	    	cout<<BLUE<<"Account Number : "<<RESET<<Account_Number<<endl;
	    	cout<<BLUE<<"Acount Holder Account current Balance : "<<RESET<<Balance<<endl;
	    	cout<<BLUE<<"Acount Holder Gender : "<<RESET<<Gender<<endl<<endl;
		cout<<RED<<"Do you want to procced to delete (Y/N) : "<<RESET;
		cin>>c;
		if(c!='Y' && c!='y')
		{
			return 0;
		}
		return 1;
	} 
};

int search(long int Number,class Bank *ref)		//funcction to search particular user
{
        int i=0;
	for(;i<Flag; i++)
	{
		if(ref[i].Account_Number==Number)
		    return i;
	}
	return Flag;
}

int main()			//main function
{
    Bank *bank=new Bank[1];	//creating space
    Bank *temp=new Bank[1];
    //shared_ptr<Bank> bank(new Bank[1]);
    //shared_ptr<Bank> temp(new Bank[1]);
    int entry,num=0;
    while(1)		//continuous loop for server login
    {
	Server_label:		//label of server login
	system("clear");
	cout<<RED<<"*****************"<<RESET<<" Welcome to Online Bank "<<RED<<"********************"<<RESET<<endl<<endl;
	cout<<BLUE<<"1.Server Login only for Bank User's"<<endl<<"2.Client Login"<<endl<<"3.ADD Account"<<endl<<"4.Exit"<<RESET<<endl<<YELLOW<<"-->"<<RESET;
	cin>>entry;
	switch(entry)	//switch case based on input do particular task
	{
	    case 1:
		{
		    cout<<BLUE<<"Enter Bank secreat code : "<<RESET;
		    cin>>num;
		    if(num!=2002)
			cout<<RED<<"Wrong Secreat code !!"<<RESET<<endl;
		    else
		    {
			cout<<BLUE<<"Enter Passowrd [4-digit] : "<<RESET;
			cin>>num;
			if(num!=1104)
			    cout<<RED<<"Wrong Password !!"<<RESET<<endl;
			else
			   {
			       if(Flag==0)
				   cout<<YELLOW<<"No Accounts found !!"<<RESET<<endl;
			       else
				   bank->Bank_Server(bank);
			   }
		    }
		    sleep(4);
		    break;
		}
	    case 2:
		if(Flag==0)
		{
		    cout<<RED<<"First ADD Account in the Bank !!"<<RESET<<endl;
		    sleep(4);
		    break;
		}
	        cout<<YELLOW<<"Enter the Account Number : "<<RESET;
		cin>>num;
		Index=search(num,bank);
		if(Index==Flag)
		{
			cout<<RED<<"No Account Number found !!"<<RESET<<endl;
			sleep(4);
			break;
		}
		goto Clinet_Label;
		break;
	    case 3:
		{
	            temp=new Bank[++Flag];
	            for(int i=0; i<Flag-1; i++)
			temp[i]=bank[i];		    
	            bank=temp;
		    bank[Flag-1].ADD_Account();
		    break;
     		}
	    case 4:
		goto Exit_Label;
		break;
	    default:
		cout<<RED<<"Invalid Entry !!"<<RESET<<endl;
		sleep(3);
		break;
	}
    }
    while(1)		//loop for client login
    {
	Clinet_Label:		//label for client login
	system("clear");
	cout<<RED<<"*****************"<<RESET<<" Welcome to Online Bank "<<RED<<"********************"<<RESET<<endl<<endl;
	cout<<RED<<"\t\t    WELCOME "<<bank[Index].Name<<RESET<<SMILE<<endl<<endl;
	cout<<BLUE<<"1.Deposite Amount\n2.Withedrow Amount\n3.Transfer amount\n4.Chcek Balance\n5.Delete account\n6.Exit"<<RESET<<endl;
	cout<<YELLOW<<"Enter Your Choice : "<<RESET;
	cin>>entry;
	system("clear");
	switch(entry)		//switch case for particuler evnet
	{
	   case 1 :
		{
		    if((bank[Index].Deposite_Amount())==1)
			cout<<BLUE<<"Amount deposited sucessfully "<<RESET<<SMILE<<endl;
		    else
			cout<<YELLOW<<"Exit from Depositing Amount "<<RESET<<endl;
		    sleep(4);
		    break;	    
    		}
	  case 2:
		{
			if((bank[Index].Withdrow_Amount())==1)
			    cout<<BLUE<<"Amount withdow sucessfullay ,Ramaining balance is : "<<RESET<<bank[Index].Balance<<endl;
			else
			    cout<<YELLOW<<"Exit from Withdrowing amount "<<RESET<<endl;
			sleep(4);
			break;
    		}
	  case 3:
		{

			if(Flag<=1)
			{
			    cout<<RED<<"ADD min two account to do Transaction !!"<<RESET<<endl;
			    sleep(4);
			    break;
			}
	            	cout<<BLUE<<"Enter the Receiver amount Account Number : "<<RESET;
		    	cin>>num;
		    	int Index1=search(num,bank);
		    	if(Index1==Flag)
		    	{
				cout<<RED<<"No Receiver Account Number found !!"<<RESET<<endl;
				sleep(4);
				break;
		    	
			}
			if((bank[Index1].Transfer_Amount(bank,Index))==1)
			    cout<<BLUE<<"Amount Transfer sucessfullay ,Ramaining balance is : "<<RESET<<bank[Index].Balance<<endl;
			else
			    cout<<YELLOW"Exit from Transfering amount "<<RESET<<endl;
			sleep(4);
			break;
    		}
 	  case 4:
		{
		    bank[Index].Check_balance();
		    cout<<BLUE<<"Check sucessfully "<<RESET<<SMILE<<endl;
		    sleep(4);
		    break;	    
    		}
	  case 5:
		{

	            temp=new Bank[Flag-1];
		    if(bank[Index].Delete_account()==1)
		    {
	        	int i,flag=0;
			for(i=0; i<Flag; i++)
			{
				if(i==Index)
				{
					flag=1;
			    		continue;
				}
				if(flag==1)
			    		temp[i-1]=bank[i];
				else
			    		temp[i]=bank[i];
			}
			Flag--;
			bank=temp;
		    	cout<<RED<<"Account deleteed Sucessfully "<<RESET<<endl;
			sleep(3);
			goto Server_label;
		    }
		    cout<<BLUE<<"Account is safe !! "<<RESET<<SMILE<<endl;
		    sleep(3);
		    break;
		}
	  case 6: 
		goto Server_label;
		break;

	  default :
		{
		    cout<<RED<<"Wrong Entry !!"<<RESET<<endl;
		    sleep(4);
		    break;
    		}		    
	}
    }
    Exit_Label:	//exit label
    return 0;
}
