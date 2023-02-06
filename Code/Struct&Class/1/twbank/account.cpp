#include "account.h"
#include <iostream>
#include <iomanip>
twbank::account::account()
:account(0.00f,credit::D)
{
}
twbank::account::account(float money)
:account(money,credit::D)
{
}
twbank::account::account(float money,const credit::creditLevel score)
:m_money(money)
,m_creditScore("")
{
    creditScore(score);
}
    
float twbank::account::money() const{
        return m_money;
}
float& twbank::account::money(){
        return m_money;
}
    
//get&set creditScore
const char* twbank::account::showCreditScore() const
{
    return m_creditScore;
}
void twbank::account::creditScore(credit::creditLevel score)
{
    switch(score){
        case credit:: Daddy : m_creditScore = "S"; break;
        case credit:: A : m_creditScore = "A"; break;
        case credit:: B : m_creditScore = "B"; break;
        case credit:: C : m_creditScore = "C"; break;
        case credit:: D : m_creditScore = "D"; break;
        case credit:: E : m_creditScore = "E"; break;
        case credit:: F : m_creditScore = "F"; break;
        default : break;
    }
}
    //存錢
void twbank::account::deposit(int deposit)
{
    m_money += deposit;
}
    //領錢
bool twbank::account::withdraw(int withdraw)
{
    if(m_money >= withdraw){
        m_money -= withdraw;
        return true;
    }
    else{
        return false;
    }
}
    //餘額
float twbank::account::balance() const
{
    return m_money;
}
