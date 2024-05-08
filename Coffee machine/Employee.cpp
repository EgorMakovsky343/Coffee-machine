#include <iostream>

using namespace std;

class Person
{
private:
	string name;
	unsigned int age;
public:
	Person(string name, unsigned int age) : name(name), age(age) {}

	void Print()
	{
		cout << "Name: " << name << "\tAge: " << age << endl;
	}
	~Person()
	{
		cout << "Person deleted." << endl;
	}
};

class Employee : public Person
{
private:
	string company;
public:
	Employee(string name, unsigned int age, string company) : Person(name, age), company(company) {}

	Employee(const Employee& other) : Person(other)
	{
		company = other.company;
	}
	~Employee()
	{
		cout << "Employee deleted." << endl;
	}
};

int main()
{
	Employee egor("Egor", 19, "SpaceX");
	egor.Print();
	Employee vadzim("Vadzim", 43, "Avtostimul");
	vadzim.Print();
	Employee ilya(egor);
	ilya.Print();

	return 0;
}