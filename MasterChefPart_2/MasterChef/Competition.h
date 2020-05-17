#ifndef COMPETITION_H_INCLUDED
#define COMPETITION_H_INCLUDED

#include <string>

using namespace std;

class Competition
{
    protected: // Needs to be protected because this varialbes will be used in child classes

        int id; // monadikos afxon arithmos gia kathe agonisma
        string name; // Onoma tou agonismatos
        string winner; // onoma tou nikiti agonismatos (omada i pektis)

    public:
        Competition();
        Competition(int idt,string namet);
        ~Competition();


        void setIdName(int idt,string namet);
        void setWin(string winnert);

        void getWin();
        void getName();
        void getID();

        void getInformStatus();




};

#endif // COMPETITION_H_INCLUDED
