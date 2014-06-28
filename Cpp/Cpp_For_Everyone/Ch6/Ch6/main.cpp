//
//  main.cpp
//  Ch6
//
//  Created by Ryan Morshead on 6/26/14.
//  Copyright (c) 2014 RyanMorshead. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int P1()
{
    cout<<"Enter numbers (Q to quit)"<<endl;
    
    double input;
    int count=0;
    vector<double> vect;
    while (cin>>input)
    {
        vect.push_back(input);
        count++;
    }
    for(int i=0;i<count-1;i++)
    {
        cout<<vect[i]<<",";
    }
    cout<<vect[count-1]<<endl;
    
    return 0;
}

int main()
{
    bool valid=true;
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
            {cout << "Failed to run."; valid=false;}
        }
    }
    while (valid);
    
    return 0;
}