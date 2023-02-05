練習＆學習關於物件的宣告、特性與語法同時並分類整理代碼

題目與預寫內容如下：

創立一個Class或者Struct，名為account，並讓下列預寫內容可以如要求運作。

```
#include <iostream>
#include <iomanip>
#include "twbank/account.h"

int main(int argc, const char * argv[]) {

  twbank::account acc1;           // 0
  twbank::account acc2(500.50f);  // 500.50
  twbank::account acc3 = 500.0f;  // compile error
  
  cc1.deposit(400);    //+400 存錢函數，呼叫時只能輸入整數
  cc1.withdraw(500);   //-500 領錢函數，呼叫時只能輸入整數
  
  std::cout << std::boolalpha << acc.withdraw(500)<<std::endl;  //不夠錢的話 print false
  
  std::cout << acc1.balance() << std::endl;  //print結果，格式須為 900.50 或 50.55，依此類推
  
  return 0;
}
