#include<iostream>
#include<string>
#include"Header.h"

int main()
{
	User user;
	std::cout << "Enter your first name, last name, and status (Gold, Silver, or Bronze) with a space between each:\n";
	std::cin >> user;
	std::cout << user << std::endl;

	return 0;
}