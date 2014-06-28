//
//  main.cpp
//  Ch8
//
//  Created by Ryan Morshead on 6/27/14.
//  Copyright (c) 2014 RyanMorshead. All rights reserved.
//

#include <fstream>
#include <iostream>
using namespace std;

int main ()
{
    ifstream infile("test_file.txt");
    int a, b;
    infile >> a >> b;
    cout<<a<<","<<b;
    return 0;
}