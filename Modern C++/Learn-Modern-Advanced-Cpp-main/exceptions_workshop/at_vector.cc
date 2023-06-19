#include <vector>
#include <iostream>
#include <string>

using namespace std;

int& at(vector<int>& vec, int pos) {
	// Check index corresponds to a valid element
	// If not, throw std::out_of_range with a suitable error message
	if (vec.size() < pos + 1) {
		string str{ "Oops! No element at index "s + to_string(pos) };
		throw std::out_of_range(str);
	}
	
	// Return the element
	return vec[pos];
}

int main() {
	//vector<int> vec;
	vector<int> vec {1, 2, 3};
	
	try {
		int& el = at(vec, 2);
		++el;
	
		// Print out the vector elements
		for (auto v : vec)
			cout << v << ", ";
	}
	catch (const std::exception& e) {           // Will handle all subclasses of std::exception
		cout << "Exception caught: " << e.what() << endl;               // Print out a description of the exception
	}
}