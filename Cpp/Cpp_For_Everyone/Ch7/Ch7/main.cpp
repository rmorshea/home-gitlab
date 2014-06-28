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
    
    double* x1=new double[1];
    cin>>x1[0];
    
    int count=2;
    double input;
    while (cin>>input)
    {
        double* x2 = new double[count];
        x2[count-1]=input;
        
        copy(x1, x1+count-1, x2);
        delete[] x1;
        x1 = x2;
        for (int i=0;  i < count; i++)
        {
            cout << x1[i] << ",";
        }
        cout<<"\n";
        count++;
    }
    return 0;
}

int P2()
{
    int a[3] = {3,1,4};
    int b[5];
    for(int i=0; i<5; i++)
    {
        cout<<b[i]<<",";
    }
    cout<<endl;
    copy(a,a+3,b);
    
    for(int i=0; i<5; i++)
    {
        cout<<b[i]<<",";
    }
    cout<<endl;
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
        if (input=="P2") {
            cout << "Running " << input <<
            "...\n--------------------------\n";
            P2();break;
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