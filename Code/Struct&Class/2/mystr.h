#pragma once

namespace my
{

class str
{
public:
    explicit account();
    explicit account(float money);
    explicit account(float money,const credit::creditLevel score);
    float money() const;
    float& money();
    const char* showCreditScore() const;
    void creditScore(credit::creditLevel score);
    //存錢
    void deposit(int deposit);
    //領錢
    bool withdraw(int withdraw);
    //餘額
    float balance() const;
private:
    float m_money;
    const char* m_creditScore;
};
}
