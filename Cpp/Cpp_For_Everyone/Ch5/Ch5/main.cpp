//
//  main.cpp
//  Ch5
//
//  Created by Ryan Morshead on 6/25/14.
//  Copyright (c) 2014 RyanMorshead. All rights reserved.
//

#include <iostream>
using namespace std;

void print_triangle(int side_length)
{/*Prints a triangle with a given side length.
  @param side_length the side length (number of [] along the base)
  */
    if (side_length < 1) { return; }
    print_triangle(side_length - 1);
    for (int i = 0; i < side_length; i++)
    {
        cout << "[]";
    }
    cout << endl;
}


int main()
{
    cout << "Enter the side length: "; int input;
    cin >> input; print_triangle(input);
    return 0;
}

