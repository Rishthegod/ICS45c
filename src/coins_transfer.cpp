#include "coins.hpp"
#include <iostream>
#include <string>

using namespace std;

constexpr int CENTS_FOR_CHIPS = 149;

int main(){
  Coins piggyBank(50,50,50,50);
  Coins pocket(8,3,6,8);
  cout << "Initial piggy bank: " << piggyBank << endl;
  cout << "Initial pocket: " << pocket<< endl<<endl;
  
  Coins pay_for_chips = pocket.extract_exact_change(coins_required_for_cents(CENTS_FOR_CHIPS));
  cout << "Bought chips using pocket"<<endl;
  cout << "Chips required the coins: " << pay_for_chips<<endl;
  cout << "Pocket after paying for chips: " << pocket <<endl<<endl;

  Coins transfer_money = piggyBank.extract_exact_change(coins_required_for_cents(405));
  cout<<"Transferring money to pocket"<<endl;
  cout<< "Coins for transfer: "<<transfer_money<<endl;
  pocket.deposit_coins(transfer_money);
  cout << "Pocket: " << pocket <<endl;
  cout<< "Piggy bank: " << piggyBank<<endl<<endl;

  Coins sofa(10,10,10,10);
  cout<<"Transferring sofa change to piggy bank"<<endl;
  cout << "Sofa: " << sofa <<endl;
  piggyBank.deposit_coins(sofa);
  cout << "Piggy bank: " << piggyBank << endl<<endl;

  int piggy_total = piggyBank.total_value_in_cents();
  cout<<"Piggy bank total: ";
  print_cents(piggy_total, cout);
  cout<<endl;
  
  
}
