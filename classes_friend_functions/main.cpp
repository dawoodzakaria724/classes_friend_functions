#include <iostream>
#include <string>
#include <vector>

class User
{
	std::string status = "Gold";
	static int user_count;

public:
	static int get_user_count()
	{
		return user_count;
	}

	std::string get_status()
	{
		return status;
	}
	void set_status(std::string status)
	{
		if (status == "Gold" || status == "Silver" || status == "Bronze")
		{
			this->status = status;
		}
		else
		{
			this->status = "No status";
		}
	}

	std::string first_name;
	std::string last_name;

	User()
	{
		//std::cout << "Constructor" << std::endl;
		user_count++;
	}
	User(std::string first_name, std::string last_name,
		std::string status)
	{
		this->first_name = first_name;
		this->last_name = last_name;
		this->status = status;
		user_count++;
	}
	~User()
	{
		//std::cout << "Destructor" << std::endl;
		user_count--;
	}

	friend std::ostream& operator << (std::ostream& output, const User user);
	friend std::istream& operator >> (std::istream& input, User &user);
};

int User::user_count = 0;

class Position
{
public:
	int x = 10;
	int y = 20;
	Position operator +(Position pos)
	{
		Position new_pos;
		new_pos.x = x + pos.x;
		new_pos.y = y + pos.y;
		return new_pos;
	}
	bool operator ==(Position pos)
	{
		if (x == pos.x && y == pos.y)
		{
			return true;
		}
		return false;
	}
};

std::ostream& operator << (std::ostream& output, const User user)
{
	output << "First name: " << user.first_name << "\nLast name: " <<
		user.last_name << "\nStatus: " << user.status;
	return output;
}

std::istream& operator >> (std::istream& input, User &user)
{
	input >> user.first_name >> user.last_name >> user.status;
	return input;
}

int main()
{
	User user;
	std::cout << "Enter your first name, last name, and status with a space between each:\n";
	std::cin >> user;
	std::cout << user << std::endl;
	return 0;
}