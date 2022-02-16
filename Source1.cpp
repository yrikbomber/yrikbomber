#include <iostream>
#include <iostream>
#include<string>
#include <conio.h>
#include<vector>
#include <algorithm>
class Note
{
protected:
	std::string text;
	std::string header;
	std::string category;
	int date;
public:
	Note()
	{
		this->text = "";
		this->header = "";
		this->category = "";
		this->date = 0;
	}
	friend std::ostream& operator<<(std::ostream& out, const Note& nt)
	{
		out << "Header: " << nt.header << "\tCategory: " << nt.category << "\tText: " << nt.text << "Date: " << nt.date;
		return out;
	}
	Note(std::string text, std::string header, std::string category, int date)
	{
		this->category = category;
		this->header = header;
		this->text = text;
		this->date = date;
	}
	inline std::string getCategory() const
	{
		return this->category;
	}
	inline std::string getHeader() const
	{
		return this->header;
	}
	inline std::string getText() const
	{
		return this->text;
	}
	inline int getDate() const
	{
		return this->date;
	}
	void setCategory(std::string category)
	{
		this->category = category;
	}
	void setText(std::string text)
	{
		this->text = text;
	}
	void setHeader(std::string header)
	{
		this->header = header;
	}
	void setDate(int date)
	{
		this->date = date;
	}
	void Add()
	{
		std::cout << "Введите заголовок: ";
		std::getline(std::cin, header);
		std::cout << "Введите категорию(Отдых/культура): ";
		std::getline(std::cin, category);
		std::cout << "Введите текст заметки: ";
		std::getline(std::cin, text);
		std::cout << "Введите дату заметки: ";
		std::cin >> date;
	}
	void add_Category()
	{
		std::cout << "Введите категорию: ";
		std::getline(std::cin, category);
	}
	void Show()
	{
		std::cout << "\t\t\t" << header << "\n\t" << category << "\n" << text << "\n\t\t\t\t" << date << "\n--------NEW NOTES--------\n";
	}
	// ПЕРЕГРУЗКА СРАВНЕНИЯ ДЛЯ УДАЛЕНИЯ ЗАМЕТКИ
	inline bool operator== (const Note& other) const {
		return this->header < other.header;
	}
	inline bool operator!= (const Note& other) const {
		return this->header < other.header;
	}
};
class Notes
{
	std::vector<Note> notes;
	std::vector<Note> ::iterator result;
public:
	Notes()
	{

	}
	void addNote(Note note)
	{
		notes.push_back(note);
		std::cin.ignore();
	}
	void show()
	{
		for (auto i : notes)
			i.Show();
	}
	void removeNote(Note note)
	{
		auto res = std::find(notes.begin(), notes.end(), note);
		notes.erase(res);
	}
};
int main()

{

	Notes notes;
	Note note;
	setlocale(0, "");
	char ch;
	do
	{
		system("cls");
		std::cout << "\tМеню.\n";
		std::cout << "1 - Добавить заметку.\n";
		std::cout << "2 - Вывод заметки.\n";
		std::cout << "3 - Редактирование категории.\n";
		std::cout << "4 - Удаления заметки.\n";
		std::cout << "5 - Редактирования заметки.\n";
		std::cout << "Esc - Выход.\n";
		std::cout << "Ваш выбор: ";
		ch = _getch();
		switch (ch)
		{
		case '1':system("cls");
			note.Add();
			notes.addNote(note);
			std::cout << "\tЗаметка создана.\n";
			break;

		case '2':system("cls");
			notes.show();
			break;

		case '3':system("cls");
			note.Show();
			note.add_Category();
			note.Show();
			std::cout << "\tВывод.\n";
			break;
		case '4':system("cls");
			notes.removeNote(note);
			std::cout << "\tУдалено.\n";
			break;

		case '5':system("cls");
			note.Show();
			note.setCategory("Test");
			note.setText("Test");
			note.setDate(25);
			note.setHeader("Test");
			note.Show();
			std::cout << "\tИзменено.\n";
			break;
		}
		system("pause");
	} while (ch != 0);
}