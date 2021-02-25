#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> targets;
unordered_set<int> outputs;
int number_of_operations;
int counted_operations = 0;
string infile = "inputs/final_input.txt";

void read_input() {
	ifstream f(infile);
	int n;
	while(f >> n) 
		targets.push_back(n);
	f.close();
} 

void read_number_of_operations() {
	cin >> number_of_operations;
}

bool verify_seen(int x, int y) {
	bool have_seen = true;
	if(x != 1 && outputs.find(x) == outputs.end()) {
		cout << "used value " << x << " without first computing it" << endl;
		have_seen = false;
	}
	if(y != x && y != 1 && outputs.find(y) == outputs.end()) {
		cout << "used value " << y << " without first computing it" << endl;
		have_seen = false;
	}
	return have_seen;
}

void read_addition_chain() {
	int x, y;
    bool have_seen = true;
	while(cin >> x >> y) {
		if(!verify_seen(x,y))
			have_seen = false;
		outputs.insert(x + y);
		counted_operations++;
	}
	if(have_seen)
		cout << "valid operations performed" << endl;
}

void verify_number_of_operations() {
	if(counted_operations == number_of_operations) 
		cout << "number of operations verified" << endl;
	else
		cout << "expected " << number_of_operations << " but counted " << counted_operations << " operations" << endl; 
	
}

void verify_all_targets_hit() {
	bool all_hit = true;
	for(int i : targets) 
		if(outputs.find(i) == outputs.end()) {
			cout << "expected target " << i << " was not computed by the addition chain" << endl;
			all_hit = false;
		}
	if(all_hit) 
		cout << "all targets hit" << endl;
}

int main() {
	read_input();
	read_number_of_operations();
	read_addition_chain(); // also verifies values used are first computed
	verify_number_of_operations();
	verify_all_targets_hit();
	return 0;
}
