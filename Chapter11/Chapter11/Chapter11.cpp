// Chapter11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

class Fruit
{
	std::string m_name;
	std::string m_color;
	
public:
	Fruit(std::string name, std::string color) :m_name(name), m_color(color)
	{
	}

	std::string getNameandColor() const
	{
		return m_name + ',' + m_color;
	}
};

class Apple:public Fruit
{
	double m_fiber;

public:
	Apple(std::string name, std::string color,double fiber) :Fruit(name,color),m_fiber(fiber)
	{
	}

	friend std::ostream& operator<<(std::ostream &out, const Apple &apple);
	
};

std::ostream& operator<<(std::ostream &out,const Apple &apple)
{
	out << "Apple(" << apple.getNameandColor() << ", " << apple.m_fiber << ")\n";
	return out;
}


class Banana:public Fruit
{
public:
	Banana(std::string name, std::string color) :Fruit(name, color)
	{
	}
	
	friend std::ostream& operator<<(std::ostream &out, Banana &banana);
};

std::ostream& operator<<(std::ostream &out, const Banana &banana)
{
	out << "Banana(" << banana.getNameandColor() << ")\n";
	return out;
}

int main()
{
	const Apple a("Red delicious", "red", 4.2);
	std::cout << a;

	const Banana b("Cavendish", "yellow");
	std::cout << b;

	return 0;
}

