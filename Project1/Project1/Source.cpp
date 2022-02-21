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
			std::cout << "\nШирина = 154 мм, Высота = 75 мм";
		else if (banknote_denomination == 200)
			std::cout << "\nШирина = 145 мм, Высота = 65 мм";
		else if (banknote_denomination <= 100)
			std::cout << "\nШирина = 130 мм, Высота = 60 мм";
	}
	void Condition_Bank()
	{
		if (condition == 1)
			std::cout << "\nСостояние банкноты = отличное";
		else if (condition == 0)
			std::cout << "\nСостояние банкноты = ужасное";
		else
			std::cout << "\nНеопределенное состояние банкноты;";
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
		std::cout << "Введите номинал: ";
		std::cin >> banknote_denomination;
		std::cout << "Введите состояние купюры: ";
		std::cin >> condition;
		std::cin.ignore();
		std::cout << "Введите страну: ";
		std::getline(std::cin, country);
		std::cout << "Введите производителя: ";
		std::getline(std::cin, production);
	}
	void Print()
	{
		std::cout << "\n------------------------\nНоминал: " << banknote_denomination << "\nСтрана: " << country << "\nПроизводитель: " << production;
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