#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

void find_addends(int x, unordered_set<int> &usable, unordered_set<string> &addends) 
{
    int addend = x/2;

    if (usable.find(addend) == usable.end()) 
        find_addends(addend, usable, addends);

    string output = to_string(addend) + " " + to_string(addend);

    if (addends.find(output) == addends.end())
        cout << output << endl;

    addends.insert(output); 
    usable.insert(2 * addend);
    if (x % 2) {
        output = to_string(2 * addend) + " 1";

        if (addends.find(output) == addends.end()) 
            cout << output << endl;

        addends.insert(to_string(addend) + " 1"); 
        usable.insert(2 * addend + 1);
    }
}

int main() 
{
    // int input[] = {2, 5};
    int input[] = {2, 5, 10, 15, 16, 24, 25};
    unordered_set<int> usable;
    unordered_set<string> addends;

    usable.insert(1);
    for (int i : input) 
        find_addends(i, usable, addends);

    cout << "Number of Add Operations : " <<  addends.size();
    return 0;
}
