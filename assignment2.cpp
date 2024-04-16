#include<iostream>
using namespace std;

class consumer{
    public:
        char name[30];
        float unit;
        float charge(float);
};
    
float consumer :: charge(float unit){
    float total=5000;

    for(int i=1; i<=unit; i++){
        if(i>0 && i<=100){
            total+=(60);
        }
        if(i>100 && i<=300){
            total+=(80);
        }
        if(i>300){
            total+=(90);   
        }
    }
    total/=100;
    return total;
}

int main(){
    consumer *c;
    int n;
    
    cout<<"Enter the number of consumers: ";
    cin>>n;
    float bill[n];

    c=new consumer[n];
    for(int i=0; i<n; i++){
        cin.ignore();
        cout<<"\n-------------------------------------------------------------------------";
        cout<<"\nEnter consumer's name: ";
        cin.getline(c[i].name,30);
        cout<<"\nEnter number of units consumed: ";
        cin>>c[i].unit;

        bill[i]=c[i].charge(c[i].unit);
    }

    for(int i=0; i<n; i++){
        cout<<"\n-------------------------------------------------------------------------";
        cout<<"\nConsumer's Name: "<<c[i].name;
        cout<<"\nUnits consumed: "<<c[i].unit;
        cout<<"\nCharges: "<<bill[i];
    }


    return 0;
}


