#ifndef HEADER_H
#define HEADER_H

class User
{
	std::string status = "Gold";
	static int user_count;

public:
	static int get_user_count();
	std::string get_status();
	void set_status(std::string status);

	std::string first_name;
	std::string last_name;

	User();
	User(std::string first_name, std::string last_name,
		std::string status);
	~User();

	friend std::ostream& operator << (std::ostream& output, const User user);
	friend std::istream& operator >> (std::istream& input, User &user);
};

#endif