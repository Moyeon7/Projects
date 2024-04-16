//Voting System
#include<iostream>
using namespace std;

int main(){

    int n, vote, spoilt_ballot=0;
    cout<<"Enter the number of voters: ";
    cin>>n;
    int ballot[]={1,2,3,4,5};

    for(int i=1; i<=n; i++){
        cout<<"\n----------------------------------------------------";
        cout<<"\n1) 1st Candidate";
        cout<<"\n2) 2nd Candidate";
        cout<<"\n3) 3rd Candidate";
        cout<<"\n4) 4th Candidate";
        cout<<"\n5) 5th Candidate";
        cout<<"\n----------------------------------------------------";
        cout<<"\nVote for your Candidate by entering the number next to it: ";

        cin>>vote;
        switch(vote){
            case 1: 
                ballot[vote-1]++;
                break;
            case 2:
                ballot[vote-1]++;
                break;
            case 3:
                ballot[vote-1]++;
                break;
            case 4:
                ballot[vote-1]++;
                break;
            case 5:
                ballot[vote-1]++;
                break;
            default:
                spoilt_ballot++;
                break;
        }

    }
    cout<<"\n----------------------------------------------------\n";
    for(int j=1; j<=5; j++){
        cout<<"Votes of "<<(j)<<" Candidate = "<<ballot[j-1]-j<<endl;
    }
    cout<<"Spoilt Ballots: "<<spoilt_ballot;

    return 0;
}