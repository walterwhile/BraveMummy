#ifndef _MUMMY_
#define _MUMMY_

#include<iostream>
#include<string>

class Mummy
{
private:
	std::string name;
	int age;

public:
	Mummy(std::string _name, int _age)
	{
		name = _name;
		age = _age;
	}

	std::string getName() const
	{
		return name;
	}

	int getAge() const
	{
		return age;
	}

	friend std::ostream& operator<<(std::ostream& output, const Mummy& myMummy);
};

std::ostream& operator<<(std::ostream& output, const Mummy& myMummy)
{
	std::cout << ("Mummy's name is ") << myMummy.getName() << "." << std::endl;
	std::cout << ("Mummy is ") << myMummy.getAge() << " years old." << std::endl;

	return output;
}

#endif



