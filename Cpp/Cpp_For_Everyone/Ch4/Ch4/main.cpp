//
//  main.cpp
//  Ch4
//
//  Created by Ryan Morshead on 6/25/14.
//  Copyright (c) 2014 RyanMorshead. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int P1()
{/*(interesting piece of code:
  pay attention to '(cin >> input)'
  this evaluates true for double values
  and evaluates false for strings
  due to the prior command 'double input;'
  */
    cout << "See comments in P1 for info" "\n\n";
    
    double total = 0;
    double input = 0;
    cout << "enter numbers: \n";
    while (cin>>input) {
        total = total + input;
        cout << "total count: " << total << endl;
    }
    cout<<"\n" "program ended\n";
    return 0;
}

int main()
{
    int valid=0;
    do {
        string input;
        cout << "What program do you want to run? ";
        cin >> input;
        
        
        if (input=="P1") {
            cout << "Running " << input <<
            "...\n--------------------------\n";
            P1();break;
        }
        else {
            cout << "Program not present.\nTry again (y/n)? ";
            string yes_no;
            cin >> yes_no;
            if (yes_no=="n")
                {cout << "Failed to run."; valid=1;}
        }
    }
    while (valid==0);
    
    return 0;
}

