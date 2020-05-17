#include "Player.h"
#include <iostream>
#include <string>
#include<time.h>
#include<stdlib.h>

using namespace std;

Player::Player() // An gini terastio lathos kai
{

    srand(time(NULL));

    name="";
    sex="";
    age=0;
    occupation="";

    skill=rand()%81; // To random tou skill tha einai apo 0 eos 80
    tiredLVL=0;
    popLVL=50;

}

Player::Player(string nam, string se,int ag,string occup)
{
    srand(time(NULL));

    name=nam;
    sex=se;
    age=ag;
    occupation=occup;

    skill=rand()%81;
    tiredLVL=0;
    popLVL=50;

}


Player::~Player()
{

    cout<<"\n\n\n\n\n This object is destroyed already"<<endl;
}


void Player::setNSAO(string nam, string se,int ag,string occup) // Changes information of a player
{
    name=nam;
    sex=se;
    age=ag;
    occupation=occup;
}

void Player::showPlayer() // Show the status of a player
{
    cout<<"Name "<<name<<"\nsex "<<sex<<"\nage "<<age<<"\noccupation "<<occupation<<endl;
    cout<<"Skill "<<skill<<"\ntiredLVL "<<tiredLVL<<"\npopLVL "<<popLVL<<endl<<endl;
}

void Player::DuringWeek()
{
    srand(time(NULL));

    tiredLVL=tiredLVL+rand()%21+20;
    skill=skill*1.05;
}

void Player::talkPeople()
{
    srand(time(NULL));


    float Pers;

    // Klasiki methodos gia anebasma tis metablitis kata 10 i -10 i kati anamesa %
    Pers=rand()%21-10;
    Pers=Pers*0.01;
    Pers=Pers+1;


    popLVL=popLVL*Pers;

}

void Player::endOfWeek()
{
    srand(time(NULL));

    int randomChoice;

    randomChoice=rand()%2;

    if (randomChoice==0) // O pektis tixea epelexe na kimithi
    {
        tiredLVL=0;
    }
    else // O pektis tixea epelexe na exaskithi
    {
        skill+=5;
    }

}

void Player::simetoxiSeDiagonismo()
{
    srand(time(NULL));


    float Pers;

    Pers=rand()%11+10;
    Pers=Pers*0.01;
    Pers=Pers+1;

    tiredLVL=tiredLVL*Pers;
}

string Player::getName()
{
    return(name);
}











