#include <iostream>
#include<string>
class Banknote
{
protected:
	int banknote_denomination;
	int condition;
	std::string production;
	std::string country;
public:
	Banknote()
	{
		this->condition = 0;
		this->banknote_denomination = 0;
		this->country = "";
		this->production = "";
	}
	Banknote(int condition, int banknote_denomination, std::string production, std::string country)
	{
		this->condition = condition;
		this->banknote_denomination = banknote_denomination;
		this->production = production;
		this->country = country;
	}
	void sizeB()
	{
		if (banknote_denomination == 500)
			std::cout << "\n������ = 154 ��, ������ = 75 ��";
		else if (banknote_denomination == 200)
			std::cout << "\n������ = 145 ��, ������ = 65 ��";
		else if (banknote_denomination <= 100)
			std::cout << "\n������ = 130 ��, ������ = 60 ��";
	}
	void Condition_Bank()
	{
		if (condition == 1)
			std::cout << "\n��������� �������� = ��������";
		else if (condition == 0)
			std::cout << "\n��������� �������� = �������";
		else
			std::cout << "\n�������������� ��������� ��������;";
	}
	int getDenom()
	{
		return this->banknote_denomination;
	}
	std::string getCountry()
	{
		return this->country;
	}
	std::string getProduction()
	{
		return this->production;
	}

	void Add()
	{
		std::cout << "������� �������: ";
		std::cin >> banknote_denomination;
		std::cout << "������� ��������� ������: ";
		std::cin >> condition;
		std::cin.ignore();
		std::cout << "������� ������: ";
		std::getline(std::cin, country);
		std::cout << "������� �������������: ";
		std::getline(std::cin, production);
	}
	void Print()
	{
		std::cout << "\n------------------------\n�������: " << banknote_denomination << "\n������: " << country << "\n�������������: " << production;
	}

};
int main()
{
	setlocale(0, "");
	Banknote ba;
	ba.Add();
	ba.getCountry();
	ba.getDenom();
	ba.getProduction();
	ba.Print();
	ba.sizeB();
	ba.Condition_Bank();
}