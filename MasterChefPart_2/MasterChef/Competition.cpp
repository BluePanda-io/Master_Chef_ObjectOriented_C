#include "Competition.h"
#include<iostream>
#include<string>

using namespace std;

Competition::Competition()
{
    id = 0;
    name = "";
    winner = "";
}

Competition::Competition(int idt,string namet)
{
    id=idt;
    name=namet;
    winner = "";

}

void Competition::setIdName(int idt,string namet)
{
    id=idt;
    name=namet;
}

void Competition::setWin(string winnert)
{
    winner=winnert;
}

void Competition::getWin()
{
    cout<<"winner "<<winner<<endl;
}

void Competition::getName()
{
    cout<<"name "<<name<<endl;
}

void Competition::getID()
{
    cout<<"Id "<<id<<endl;
}

void Competition::getInformStatus()
{
    cout<<"id "<<id<<"\nname "<<name<<"\nwinner "<<winner<<endl;
}

Competition::~Competition()
{
    cout<<"\n\n\n\n\n This object is destroyed already"<<endl;
}
