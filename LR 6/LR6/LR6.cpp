#include <iostream>

using namespace std;

class Place
{
	double space;
	double xCords, yCords;

public:
	Place()
	{
		xCords = 0;
		yCords = 0;
		space = 0;

		cout << "Created empty place" << endl;
	}
	Place(double xCords, double yCords, double space)
	{
		this->xCords = xCords;
		this->yCords = yCords;
		this->space = space;

		cout << "Created place" << endl;
	}
	~Place()
	{
		cout << "deleted place " << this << endl;
	}

	double getXCords()
	{
		return xCords;
	}
	double getYCords()
	{
		return yCords;
	}
	double getSpace()
	{
		return space;
	}

	void setXCords(double x)
	{
		xCords = x;
	}
	void setYCords(double y)
	{
		yCords = y;
	}
	void setSpace(double space)
	{
		this->space = space;
	}
};

class City : public Place
{
	string name;
	int population;
	double budget;

public:
	City()
	{
		name = "empty name";
		population = 0;
		budget = 0;

		cout << "created empty city" << endl;
	}
	City(string name, int population, double budget, double xCords, double yCords, double space)
	{
		this->setXCords(xCords);
		this->setYCords(yCords);
		this->setSpace(space);

		this->name = name;
		this->population = population;
		this->budget = budget;

		cout << "created new city" << endl;
	}
	~City()
	{
		cout << "City " << this->getName() << " was destroyed." << endl;
	}

	string getName()
	{
		return name;
	}
	int getPopulation()
	{
		return population;
	}
	double getbudget()
	{
		return budget;
	}

	void setName(string name)
	{
		this->name = name;
	}
	void setPopulation(int population)
	{
		this->population = population;
	}
	void setBudget(double budget)
	{
		this->budget = budget;
	}
};

class Region : public Place
{
	City mainCity;
	string name;
	int population;
	double budget;

public:
	Region()
	{
		mainCity = City();
		name = "empty region";
		population = 0;
		budget = 0;

		cout << "created empty region" << endl;
	}
	Region(string name, int population, double budget, double xCords, double yCords, double space, City mainCity)
	{
		this->name = name;
		this->population = population;
		this->budget = budget;
		this->setXCords(xCords);
		this->setYCords(yCords);
		this->setSpace(space);
		this->mainCity = mainCity;

		cout << "created new city" << endl;
	}
	~Region()
	{
		cout << "Region " << this->getName() << " was demolished." << endl;
	}

	string getName()
	{
		return name;
	}
	City* getMainCity()
	{
		return& mainCity;
	}
	int getPopulation()
	{
		return population;
	}
	double getBudget()
	{
		return budget;
	}

	void setName(string name)
	{
		this->name = name;
	}
	void setPopulation(int population)
	{
		this->population = population;
	}
	void setBudget(double budget)
	{
		this->budget = budget;
	}
	void setCity(City mainCity)
	{
		this->mainCity = mainCity;
	}
};

class Megapolic : public City
{
public:
	Megapolic()
	{
		setName("empty name");
		setPopulation(0);
		setBudget(0);

		cout << "created empty megapolic" << endl;
	}
	Megapolic(string name, int population, double budget, double xCords, double yCords, double space)
	{
		this->setXCords(xCords);
		this->setYCords(yCords);
		this->setSpace(space);

		this->setName(name);
		this->setPopulation(population);
		this->setBudget(budget);

		cout << "created new megapolic" << endl;
	}
	~Megapolic()
	{
		cout << "Megapolic " << this->getName() << "was destroyed." << endl;
	}
};

int main()
{

	City c = City("CoolCity", 10, 100, 1.25, 2.56, 15);
	cout << "CoolCity created!" << endl << endl;

	Region r = Region("first Reg", 100, 1000, 1.3, 2.8, 50, c);
	cout << "region created!" << endl << endl << r.getMainCity()->getName() << endl << endl;

	Megapolic polic = Megapolic("BigCity", 10000, 2, 5.68, 8.45, 100);
	cout << "Megapolic created!" << endl;

	return getchar();
}
