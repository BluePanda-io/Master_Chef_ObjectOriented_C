#ifndef VOTE_H_INCLUDED
#define VOTE_H_INCLUDED
#include <iostream>

using namespace std;

class Vote
{
    string voted;
    string reason;

public:

    Vote()
    {
        voted="";
        reason="";
    }

    Vote(string kV, string kReas="ETSI")
    {
        voted=kV;
        reason=kReas;
    }

    ~Vote()
    {

    }

    string getVoted()
    {
        return voted;
    }

    string getReason()
    {
        return reason;
    }

    void setVoted(string kV)
    {
        voted=kV;
    }

    void setReason(string kV)
    {
        reason=kV;
    }

    void status()
    {
        cout<<"\nVoted Person: "<<voted<<endl;
        cout<<"\nReason for being voted: "<<reason<<endl;
    }
};

#endif // VOTE_H_INCLUDED
