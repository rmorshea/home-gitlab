//
//  main.cpp
//  Ch2
//
//  Created by Ryan Morshead on 6/24/14.
//  Copyright (c) 2014 RyanMorshead. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

pair<int,int> sub_if_less(int coin, int dif) {
    if (coin-dif<0) {
        int rem = dif%coin; //amount remaining
        int num = dif/coin; //number of coins used
        pair<int,int> ans(rem,num);
        return ans;
    }
    else {
        pair<int,int> ans(dif,0);
        return ans;
    }
}

int main() {
    /*
     determines the change you should recieve for an item
     when paying a specified amount in dollar bills.
     */
    
    //specify coin values
    const int P = 1;
    const int N = 5;
    const int Di = 10;
    const int Q = 25;
    const int Do = 100;
    
    //requests amount due
    cout << "Specify amount due in dollars (can be float): ";
    double amnt_due;
    cin >> amnt_due;
    
    //requests amount payed
    cout << "Specify amount payed in dollars (can be float): ";
    double amnt_pay;
    cin >> amnt_pay;
    
    double change = amnt_pay-amnt_due;
    
    //in the case where amount payed is less than the amount due
    while (change<0) {
        //calculates the remainder and asks requests additional payment
        cout << "\nINSIFICIENT PAYMENT: "
                << "remainder = " << -change <<endl
                << "Can you cover this remainder (y/n)? ";
        string can_pay;
        cin >> can_pay;
        
        //if can_pay=="y" calculates new remainder based on additional payment
        if (can_pay=="y") {
            cout << "Specify additional payment in dollars: ";
            double add_pay;
            cin >> add_pay;
            amnt_pay+=add_pay;
            change=amnt_pay-amnt_due;
        }
        //if can_pay=="n" main() ends
        else {
            cout << "I'm sorry. Return when you have the funds.\n";
            return 0;
        }
    }
    //converts dollars into pennies for conversion double-->int
    cout<<"\n";
    double dif = 100*change;
    int Do_num, Q_num, Di_num, N_num, P_num;
    
    //determine how many coins make up the remainder
    tie(dif,Do_num) = sub_if_less(Do,dif);
    tie(dif,Q_num) = sub_if_less(Q,dif);
    tie(dif,Di_num) = sub_if_less(Di,dif);
    tie(dif,N_num) = sub_if_less(N,dif);
    tie(dif,P_num) = sub_if_less(P,dif);
    
    //in the case where there is no remainder
    tuple<int,int,int,int> none(0,0,0,0);
    if (tie(Do_num,Q_num,Di_num,P_num)==none) {
        cout<< "You have no change.\n";
    }
    
    //in the case where there is change only print coins which are not zero
    else {
        cout << "Your change is:\n";
        if (Do_num!=0) {cout << Do_num << " Dollars\n";}
        if (Q_num!=0)  {cout << Q_num << " Quarters\n";}
        if (Di_num!=0) {cout << Di_num << " Dimes\n";}
        if (N_num!=0)  {cout << N_num << " Dimes\n";}
        if (P_num!=0)  {cout << P_num << " Pennies\n";}
    }
    
    //main() ends
    cout << "Goodbye!\n\n";
    return 0;
    
}

