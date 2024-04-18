#include "coins.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Coins::Coins(int q, int d, int n, int p) : quarters{q}, dimes{d}, nickels{n}, pennies{p} {}

 void Coins::print(std::ostream& out)const{
   out << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << pennies << " pennies";
 }

std::ostream& operator<<(std::ostream& out, const Coins& coins){
  coins.print(out);
  return out;
}

Coins Coins::extract_exact_change(const Coins& coins){
  if(coins.quarters <= this->quarters){
    if(coins.dimes <= this->dimes){
      if(coins.nickels <= this->nickels){
        if(coins.pennies <= this->pennies){
          this->quarters -= coins.quarters;
          this->dimes -= coins.dimes;
          this->nickels -= coins.nickels;
          this->pennies -= coins.pennies;
          return Coins(coins.quarters, coins.dimes, coins.nickels, coins.pennies);
        }
      }
    }
  }

  return Coins(0,0,0,0);
}

Coins coins_required_for_cents(int amount_in_cents){
  int q = amount_in_cents / CENTS_PER_QUARTER;
  amount_in_cents -= q * CENTS_PER_QUARTER; 
  int d = amount_in_cents / CENTS_PER_DIME;
  amount_in_cents -= d * CENTS_PER_DIME;
  int n = amount_in_cents / CENTS_PER_NICKEL;
  amount_in_cents -= n * CENTS_PER_NICKEL;
  int p = amount_in_cents;

  return Coins(q,d,n,p);
}


void Coins::deposit_coins(Coins & coins){
  this->quarters += coins.quarters;
  this->dimes += coins.dimes;
  this->nickels += coins.nickels;
  this->pennies += coins.pennies;
  coins.quarters = 0;
  coins.dimes = 0;
  coins.nickels = 0;
  coins.pennies = 0;
}

bool Coins::has_exact_change_for_coins(const Coins& coins) const{
  if(coins.quarters <= this->quarters && coins.dimes <= this->dimes && coins.nickels <= this->nickels && coins.pennies <= this->pennies){
    return true;
  }
  return false;
}

int Coins::total_value_in_cents() const{
  return quarters * CENTS_PER_QUARTER + dimes * CENTS_PER_DIME + nickels * CENTS_PER_NICKEL + pennies;
}

void print_cents(int cents, std::ostream& out){
  double total = cents / 100.00;
  //if (total == 0 || total == 0.0 || total == 0.00){
    // out << "$" << "0.00";
  //}
  //else{
  out << "$" << fixed<<setprecision(2)<< total; //}
  //<< "." << cents % 100;
}

Coins ask_for_coins(std::istream& in, std::ostream& out){
  int q;
  out << "Quarters? ";
  in >> q;
  int d;
  out << "Dimes? ";
  in >> d;
  out << "Nickels? ";
  int n;
  in >> n;
  out << "Pennies? ";
  int p;
  in >> p;
  return Coins(q,d,n,p);
}

void print_menu(std::ostream& out){
  out << "1. Deposit Change" << endl;
  out << "2. Extract Change" << endl;
  out << "3. Print Balance" << endl;
  out << "4. Exit" << endl<<endl;
}


void coins_menu(std::istream& in, std::ostream& out){
  Coins balance(0,0,0,0);
  out << "Coins Menu" <<endl<<endl;
  while(true){
    int input;
    print_menu(out);
    out << "User Input: ";
    in >> input;
    out<< endl;
    if(input == 1){
      Coins dep = ask_for_coins(in,out);
      balance.deposit_coins(dep);
      out<<endl;
      out<<"Thank you!" <<endl<<endl;
      
    }
    else if (input == 2){
      Coins ex = ask_for_coins(in,out);
      if(balance.has_exact_change_for_coins(ex)){
        balance.extract_exact_change(ex);
        out<<endl;
        out<<"Thank you!" <<endl<<endl;
      
      
      }
      else{
        out<<endl;
        out<<"ERROR: Insufficient Funds"<<endl<<endl;
      }
      
    }
    else if(input == 3){
      print_cents(balance.total_value_in_cents(),out);
      out<<endl<<endl;
      out<<"Thank you!" <<endl<<endl;
      
    }
    else if(input == 4){
      break;
    }
    else{
      out << "ERROR: Invalid Command" << endl<<endl;
    }
  }
  
  
}
