#include <iostream>
#include <vector>

using namespace std;

vector<int> getSequence(int n){
    int count = 0;
    vector<int> result;
    for (int i = n; i != 1;){
        if( i % 2 == 1){
            --i;
            result.push_back(i);
            ++count;
        }
        i /= 2;
        result.push_back(i);
        ++count;
    }
    return result;
}

int main() {
    vector<int> result;
    for(int i = 2; i <= 20; ++i){
        result = getSequence(i);
        cout << "sequence length for " << i << " = " << result.size() << ": sequence = ";
        for(unsigned long j = result.size() ; j > 0; --j){
            cout << result[j-1] << " ";
        }
        cout << endl;
    }
    return 0;
}
