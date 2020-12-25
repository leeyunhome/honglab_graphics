// bitwise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>

int main()
{
	using namespace std;

	unsigned int a = 0b1100;
	unsigned int b = 0b0110;

	cout << a << " " << b << endl;
	cout << std::bitset<4>(a & b) << endl; // bitwise AND
	cout << std::bitset<4>(a | b) << endl; // bitwise OR
	cout << std::bitset<4>(a ^ b) << endl; // bitwise XOR


	return 0;
}
