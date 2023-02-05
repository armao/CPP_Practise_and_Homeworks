#include <iostream>
#include <iomanip>
#include "twbank/account.h"

int main(int argc, const char * argv[]) {
    

    twbank::account acc1; //0
    std::cout << acc1.money() << std::endl;
    
    twbank::account acc2(500.50f); //500.50
    std::cout << acc2.money() << std::endl;
    
    //twbank::account acc3 = 500.0f; //compile error
    
    acc1.deposit(400);   //+400 存錢函數，呼叫時只能輸入整數
    std::cout << acc1.money() << std::endl;
    
    acc1.withdraw(500);   //-500 領錢函數，呼叫時只能輸入整數
    
    std::cout << std::boolalpha << acc1.withdraw(500)<<std::endl; //不夠錢的話 print false
    
    std::cout << acc1.balance() << std::endl;  //print結果，格式須為 900.50 或 50.55，依此類推


    return 0;
}
