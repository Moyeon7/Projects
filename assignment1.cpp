//Banking system

#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

class customer{
    unsigned long int ACno=1;
    
    char name[20];
    char branch[10];
    int amount;
    long double save_bal;
    long double current_bal;

    public:
        unsigned long int Accno_arr[100];
        int input(int);
        void deposit(void);
        void withdrawal(void);
        void check_bal(void);};

int customer :: input(int l){
    cin.ignore();
    cout<<"-------------------------------------------------------------------------";
    cout<<"\nEnter your name: ";
    cin.getline(name,30);

    cout<<"Enter your branch: ";
    cin>>branch;

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        ACno = (ACno * 10) + (rand() % 10); 
    }

    cout<<"Account No.: "<<ACno<<endl;
    Accno_arr[l]=ACno;
    cout<<"\nEnter the amount of cash present in your SAVING account: ";
    cin>>save_bal;
    cout<<"\nEnter the amount of cash present in your CURRENT account: ";
    cin>>current_bal;
}

void customer :: deposit(void){
    int select;
    while(1){
        cout<<"\n\nDEPOSIT:";
        cout<<"\n1) Saving Account \n2) Current Account  \n3) Exit\n";
        cout<<"Choose the account in which you want to deposit: ";
        cin>>select;

        switch(select){
            case 1:
                cout<<"\nEnter the amount to be deposited: ";
                cin>>amount;
                save_bal+=amount;
                break;
            case 2:
                cout<<"\nEnter the amount to be deposited: ";
                cin>>amount;
                current_bal+=amount;
                break;
            case 3:
                return;
        }
    }
    
}

void customer :: withdrawal(void){
    int select;
    while(1){
        cout<<"\nWITHDRAWAL:";
        cout<<"\n1) Saving Account \n2) Current Account  \n3) Exit\n";
        cout<<"Choose the account from which you want to withdraw: ";
        cin>>select;

        switch(select){
            case 1:
                cout<<"\nEnter the amount to be withdraw: ";
                cin>>amount;
                save_bal-=amount;
                break;
            case 2:
                cout<<"\nEnter the amount to be withdraw: ";
                cin>>amount;
                current_bal-=amount;
                break;
            case 3:
                return ;
        }
    }
}

void customer :: check_bal(void){
    int select;
    while(1){
		cout<<"\n-------------------------------------------------------------------------\n";
        cout<<"\nCHECK BALANCE:";
        cout<<"\n1) Saving Account \n2) Current Account  \n3) Exit\n";
        cout<<"Choose the account whose balance you want to check: ";
        cin>>select;

        switch(select){
            case 1:
                cout<<"\nBalance of Saving Account: "<<save_bal<<endl;;
                break;
            case 2:
                cout<<"\nBalance of Current Account: "<<current_bal<<endl;
                break;
            case 3:
                return;
        }
    }
}

int main(){

    int choice, n, check;
    unsigned long acno;
    customer *c;
    
	cout<<"\nEnter the number of entries: ";
	cin>>n;
	c=new customer[n];
	for(int i=0; i<n; i++){
		c[i].input(i);
	}

    cout<<"\n----------------------GEC BANK----------------------\n";
	
    cout<<"\nEnter your account number: ";
    cin>>acno;
    bool valid=false;
    for(int i=0; i<n; i++){
        if(acno==c[i].Accno_arr[i]){
            int check=0;
            valid=true;
            while(check==0){
				cout<<"\n-------------------------------------------------------------------------\n";
				cout<<"1) Deposit\n";
				cout<<"2) Withdrawal\n";
				cout<<"3) Check Balance\n";
                cout<<"4) Try Other A/C number\n";
				cout<<"5) Exit\n";
				cout<<"Select your choice: ";
				cin>>choice;
				switch(choice){
					case 1:
						c[i].deposit();
						break;
					case 2:
						c[i].withdrawal();
						break;                   
					case 3:
						c[i].check_bal();
						break;
					case 4:
                        cout<<"\nEnter your account number: ";
                        cin>>acno;
                        check=1;
						break;
                    case 5:
                        exit(1);
					default:
						cout<<"~~Invalid Option~~";
						break;
				}
			}
		}
			
	}
	if(!valid){
		cout<<"~~Invalid Account Number~~";
	}

    return 0;
}
