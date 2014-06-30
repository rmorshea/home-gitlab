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

void encrypt_file(ifstream& in, ofstream& out, int k)
{
    char ch;
    int count=0;
    while (in.get(ch))
    {
        count++;
        out.put(ch + count*k);
    }
}

int main(int argc, char* argv[]) {
    int key = 2;
    int file_count = 0; // The number of files specified
    ifstream in_file;
    ofstream out_file;
    for (int i = 1; i < argc; i++) // Process all command-line arguments
    {
        string arg = argv[i]; // The currently processed argument
        if (arg == "-d") // The decryption option
        {
            key = -2;
        }
        else // It is a file name
        {
            file_count++;
            if (file_count == 1) // The first file name
            {
                in_file.open(arg.c_str());
                if (in_file.fail()) // Exit the program if opening failed
                {
                    cout << "Error opening input file " << arg << endl;
                    return 1;
                }
            }
            else if (file_count == 2) // The second file name
            {
                out_file.open(arg.c_str()); if (out_file.fail())
                {
                    cout << "Error opening output file " << arg << endl;
                    return 1; }
            }
        }
    }
    if (file_count != 2) // Exit if the user didn’t specify two files
    {
        cout << "Usage: " << argv[0] << " [-d] in_file out_file" << endl;
        return 1;
    }
    encrypt_file(in_file, out_file, key);
    
    remove(argv[1]);
    
    return 0;
}