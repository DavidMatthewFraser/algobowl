//
//  main.cpp
//  Algobowl Chain Checker
//
//  Created by Samuel Billingham on 2/24/2021.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctype.h>


using namespace std;

int main() {
    ifstream inFile;
    istringstream line;
    string filename, tempstring;
    int item1, item2, length;
    vector<int> seen;
    bool valid = true;
    
    seen.push_back(1);
    filename = "input.txt";  //change file path as needed

    inFile.open(filename);
    
    if(!inFile){
        cerr << "Unable to open " << filename << "." << endl;
        exit(1);
    }
    
    cout << "Loading Items Data......" << endl;
    
    while (inFile){
        inFile >> length;
        while (!inFile.eof()){
            getline(inFile, tempstring);
            if (!tempstring.empty()) {
                istringstream tmp(tempstring);
                tmp >> item1 >> item2;
                if(binary_search(seen.begin(), seen.end(), item1) && binary_search(seen.begin(), seen.end(), item2)){
                    seen.push_back(item1 + item2);
                    sort(seen.begin(), seen.end());
                } else {
                    valid = false;
                    cout << "Item Not Found - ";
                }
            }
        }
    }
    
    inFile.close();
    
    if(length + 1 != seen.size()){
        if(valid) cout << "Incorrect Length - ";
        valid = false;
    }
    
    if(valid){
        cout << "Valid Chain." << endl;
        cout << "Items Are:  ";
        
        for(int i = 0; i < seen.size(); i++){
            cout << seen[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Chain Invalid." << endl;
    }
}
