#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

void find_addends(int x, unordered_set<int> &usable, unordered_set<string> &addends) 
{
    int addend = x/2;
   
    if (usable.find(addend) == usable.end()) 
        find_addends(x/2, usable, addends);

    string output = to_string(addend) + " " + to_string(addend);
    int set_size = addends.size();

    addends.insert(output); 
    if (set_size != addends.size())
        cout << output << endl;

    bool plus_one = x % 2; 

    if (plus_one) {
        output = to_string(2 * addend) + " 1";
        set_size = addends.size();
        addends.insert(to_string(addend) + " 1"); 
        if (set_size != addends.size()) 
            cout << output << endl;
    }

    usable.insert(addend + addend);
    if(plus_one)  
        usable.insert(addend + addend + 1);
}

int main() {
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
