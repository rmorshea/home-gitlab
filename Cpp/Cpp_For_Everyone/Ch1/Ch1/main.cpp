//
//  main.cpp
//  Ch1
//
//  Created by Ryan Morshead on 6/24/14.
//  Copyright (c) 2014 RyanMorshead. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    cout<<"\nSECTION P1.2\n\n";
    //P1.2
    
    cout << "Hello!\n" << "What would you like me to do?\n";
    string user_input;
    getline(cin, user_input);
    cout << "Sorry, I can't do that :(\n";
    
    cout<<"\nSECTION: P1.3\n\n";
    //P1.3
    
    cout << "What's your name?\n";
    string user_name;
    getline(cin, user_name);
    cout << "Hello " << user_name << ", it's good to meet you!\n";
    
    return 0;
    
}