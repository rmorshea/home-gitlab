//
//  main.cpp
//  Ch2_Ch3
//
//  Created by Ryan Morshead on 6/25/14.
//  Copyright (c) 2014 RyanMorshead. All rights reserved.
//

#include <iostream>
using namespace std;

//coin values:
const int P_val=1;
const int N_val=5;
const int Di_val=10;
const int Q_val=25;
const int Do_val=100;

pair<int,int> fill_remain(int coin_val,int remain)
{//determines how many coins of the specified value fill the remaining charge
//returns the number of coins used and the new remainder
    
    if (coin_val-remain<0) {
        int num_used=remain/coin_val;
        remain=remain%coin_val;
        return pair<int,int> (remain,num_used);
    }
    else {
        return pair<int,int> (remain,0);
    }
}

int main()
{//determines how much change should be returned based on
//the amount due and the amount payed as specified by the user
    
    //asks how much is due
    cout << "Specify amount due in dollars (can be float): ";
    double amnt_due;
    cin >> amnt_due;
    
    //asks how much is payed
    cout << "Specify amount payed in dollars (can be float): ";
    double amnt_pay;
    cin >> amnt_pay;
    
    //in the case of amnt_pay<amnt_due
    double remain=amnt_pay-amnt_due;
    while (remain<0) {
        //determines the remaining charge
        cout << "\nINSUFICIENT PAYMENT! (remainder = "
            << -remain
            << " dollars)\n";
        //asks if this charge can be covered
        cout << "Can you cover the remaining charge (y/n)? ";
        string yes_no;
        cin >> yes_no;
        
        //if yes_no=="y" then: asks for additional payment
        //and procedes to calculate new remainder
        if (yes_no=="y") {
            cout << "Specify additional payment in dollars: ";
            double add_pay;
            cin >> add_pay;
            remain+=add_pay;
        }
        //if yes_no=="n" then end main()
        else {
            cout << "\nI'm Sorry. Please return when you have the funds.\n"
                <<"Goodbye!\n";
            return 0;
        }
    }
    
    //in the case of no remainder end main()
    cout<<"\n";
    if (remain==0) {
       cout << "You have no change.\n" << "\nThank you for your payment.\n";
    }
    //in the case of over payment:
    else {
        int P_num, N_num, Di_num, Q_num, Do_num;
        remain =  100*remain; //convert cost dollars-->pennies
        
        //*see fill_remain
        tie(remain,Do_num) = fill_remain(Do_val,remain);
        tie(remain,Q_num) = fill_remain(Q_val,remain);
        tie(remain,Di_num) = fill_remain(Di_val,remain);
        tie(remain,N_num) = fill_remain(N_val,remain);
        tie(remain,P_num) = fill_remain(P_val,remain);
        
        //return coins which account for the overpayment
        if (Do_num!=0) {cout << "Your change is: " << Do_num << " dollars.\n";}
        if (Q_num!=0)  {cout << "Your change is: " << Q_num << " quarter.\n";}
        if (Di_num!=0) {cout << "Your change is: " << Di_num << " dimes.\n";}
        if (N_num!=0)  {cout << "Your change is: " << N_num << " nickles.\n";}
        if (P_num!=0)  {cout << "Your change is: " << P_num << " pennies.\n";}
        cout << "\nThank you for your payment.\n";
        
    }
    //end main()
    cout << "Goodbye!\n";
}

