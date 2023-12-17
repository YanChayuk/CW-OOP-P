#include"Header.h"
#include <conio.h>
#include <cctype>
#include <limits>

using namespace std;

int choice()
{
	int choice;
	while (true)
	{
		try
		{
			cin >> choice;
			if (cin.fail())
				throw runtime_error("Ошибка: некорректный ввод данных!");
			return choice;
		}
		catch (const runtime_error& ex)
		{
			cerr << ex.what() << endl;
			cin.clear();
			cin.ignore(255, '\n');
		}
	}
}

int inputNumber(int left_range, int right_range)
{
	int number = 0;
	current_attempt = 0;
	while (current_attempt < 3)
	{
		cin >> number;
		if (isNumberNumeric() && isNumberRangeCorrect(number, left_range, right_range))
		{
			current_attempt = 0;
			return number;
		}
		else
		{
			current_attempt++;
			if (current_attempt == 3) break;
			cout<<"\n  Некорректный ввод! Повторите попытку: ";
		}
	}
	if (current_attempt == 3)
	{
		current_attempt = 0;
		cout << "\tПовторите вход!\n";
		system("pause");
		main_menu();
	}
	current_attempt = 0;
}

bool isNumberNumeric()
{
	if (cin.get() == '\n')  return true;
	else
	{
		cin.clear();
		cin.ignore(256, '\n');  return false;
	}
}

bool isNumberRangeCorrect(int number, int left_range, int right_range)
{
	if ((number >= left_range) && (number <= right_range))
		return true;
	else
		return false;
}

bool isNumberRangeCorrectFloat(float number, float left_range, float right_range) {
	return (number >= left_range) && (number <= right_range);
}

float inputNumberFloat(float left_range, float right_range) 
{
	float number = 0.0f;
	current_attempt = 0;
	while (current_attempt < 3) 
	{
		cin >> number;
		if (cin.good() && isNumberRangeCorrectFloat(number, left_range, right_range))
		{
			cin.ignore(256, '\n');
			current_attempt = 0;
			return number;
		}
		else 
		{
			cin.clear();
			cin.ignore(256, '\n');
			current_attempt++;
			if (current_attempt == 3) break;
			cout << "\n  Некорректный ввод! Повторите попытку: ";
		}
	}
	if (current_attempt == 3)
	{
		current_attempt = 0;
		cout << "\tПовторите вход!\n";
		system("pause");
		main_menu();
	}
	current_attempt = 0;
	//return 0.0f;
}

//int main() {
//	// Вывод float с двумя символами после точки
//	float floatValue = 3.14159;
//	std::cout << std::fixed << std::setprecision(2) << floatValue << std::endl;
//
//	// Ввод float с двумя символами после точки
//	float userInput;
//	std::cout << "Введите float с двумя символами после точки: ";
//	std::cin >> std::fixed >> std::setprecision(2) >> userInput;
//
//	// Проверка ввода
//	if (std::cin.fail()) {
//		std::cerr << "Ошибка ввода. Некорректное значение." << std::endl;
//	}
//	else {
//		std::cout << "Введенное значение: " << userInput << std::endl;
//	}
//
//	return 0;
//}



bool isLogin(const string& str) 
{
	for (char ch : str) 
	{
		if (!std::isalnum(ch) || ch == '@' || ch == '.' || ch == ' ')
		{
			return false;
		}
	}
	return true;
}

bool isPassword(const string& str) 
{
	for (char ch : str) 
	{
		if ( !std::isalnum(ch) || ch == ' ') 
		{
			return false;
		}
	}
	return true;
}

bool isMail(const string& str)
{
	for (char ch : str)
	{
		if ((!std::isalnum(ch) && ch != '@' && ch != '.' && ch != '_' && ch != '(' && ch != ')' && ch != '-') || ch == ' ' )
		{
			return false;
		}
	}
	return true;
}

bool isRussianLetter(char c)
{
	return (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я');
}

bool isString(const string& str) 
{
	for (char ch : str)
	{
		if ((!std::isalpha(ch)&& !isRussianLetter(ch)) || ch == ' ' )
		{
			return false;
		}
	}
	return true;
}

//bool containsOnlyRussianLetters(const string& str) 
//{
//	for (char c : str) 
//	{
//		if (!isRussianLetter(c)) 
//		{
//			return false;
//		}
//	}
//	return true;
//}

string inputStringPassword() 
{
	string input;
	while (current_attempt < 3)
	{
		getline(cin, input);
		if (isPassword(input) && input.length() <= 20 && input.length()>=8)
		{
			current_attempt = 0;
			return input;
		}
		else
		{
			
			current_attempt++;
			if (current_attempt == 3) break;
			cout << "\n  Некорректный ввод! Повторите попытку (без пробелов/минимум 8 и максимум 20 символов): ";
		}
	}
	if (current_attempt == 3)
	{
		current_attempt = 0;
		cout << "\tПовторите вход!\n";
		system("pause");
		main_menu();
	}
	current_attempt = 0;
}

string inputStringLogin()
{
	string input;
	while (current_attempt < 3)
	{
		getline(cin, input);
		if (isLogin(input) && input.length()<=20 && input.length() >=8)
		{
			current_attempt = 0;
			return input;
		}
		else
		{
			current_attempt++;
			if (current_attempt == 3) break;
			cout << "\n  Некорректный ввод! Повторите попытку (без пробелов/минимум 8 и максимум 20 символов): ";
		}
	}
	if (current_attempt == 3)
	{
		current_attempt = 0;
		cout << "\tПовторите вход!\n";
		system("pause");
		main_menu();
	}
	current_attempt = 0;
}

string inputString()
{
	string input; current_attempt = 0;
	while (current_attempt < 3)
	{
		getline(cin, input);
		if (isString(input) && input.length() <= 30)
		{
			current_attempt = 0;
			return input;
		}
		else
		{
			current_attempt++;
			if (current_attempt == 3) break;
			cout << "\n  Некорректный ввод! Повторите попытку (без пробелов/максимум 30 символов): ";
		}
	}
	if (current_attempt == 3)
	{
		current_attempt = 0;
		cout << "\tПовторите вход!\n";
		system("pause");
		main_menu();
	}
	current_attempt = 0;
}

string inputStringMail()
{
	string input; current_attempt = 0;
	while (current_attempt < 3)
	{
		getline(cin, input);
		if (isMail(input) && input.length() <= 30 && input.length()>=8)
		{
			current_attempt = 0;
			return input;
		}
		else
		{
			current_attempt++;
			if (current_attempt == 3) break;
			cout << "\n  Некорректный ввод! Повторите попытку (без пробелов/минимум 8 и максимум 30 символов): ";
		}
	}
	if (current_attempt == 3)
	{
		current_attempt = 0;
		cout << "\tПовторите вход!\n";
		system("pause");
		main_menu();
	}
	current_attempt = 0;
}

string passwordEncryption()
{
	string password;
	char c;
	while (current_attempt < 3)
	{
		while ((c = _getch()) != '\r')
		{
			if (c == '\b')
			{
				if (!password.empty())
				{
					password.pop_back();
					cout << "\b \b";
				}
			}
			else
			{
				password.push_back(c);
				cout << "*";
			}
		}
		if (password.length() <= 20 && isPassword(password) && password.length()>=8)
		{
			for (char ch : password)
			{
				if (ch == ' ')
				{
					
					current_attempt++;
					cin.clear();
					cin.ignore(255, '\n');
					cout << "\n  Некорректный ввод! Повторите попытку (без пробелов): ";
					break;
				}
			}
			return password;
		}
		else
		{
			
			current_attempt++;
			cin.clear();
			cin.ignore(255, '\n');
			cout << "\n  Некорректный ввод! Повторите попытку (до 20 символов): ";
		}
	}
	if (current_attempt == 3)
	{
		current_attempt = 0;
		cout << "\tПовторите вход!\n";
		system("pause");
		main_menu();
	}
	current_attempt = 0;
}

// Функция для простого шифрования пароля
string encryptPassword(const string& password, const string& key)
{
	string encryptedPassword = password;
	for (size_t i = 0; i < password.length(); ++i) 
	{
		encryptedPassword[i] = password[i] ^ key[i % key.length()];
	}

	return encryptedPassword;
}

string decryptPassword(const string& encryptedPassword, const string& key)
{
	string decryptedPassword = encryptedPassword;
	for (size_t i = 0; i < encryptedPassword.length(); ++i)
	{
		decryptedPassword[i] = encryptedPassword[i] ^ key[i % key.length()];
	}

	return decryptedPassword;
}




//wcout << L"    ⢀⣤⣶⠶⠟⠛⠛⠻⠶⣶⣤⡀⠀⠀⠀⠀" << endl;
//wcout << L"⠀⠀⣠⣾⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣷⣄⠀⠀" << endl;
//wcout << L"⠀⣴⡟⠁⠀⠀⠀⣠⣴⠶⠶⣦⣄⠀⠀⠀⠈⢻⣦⠀" << endl;
//wcout << L"⢸⡟⠀⠀⠀⠀⣾⠋⠀⠀⠀⠀⠙⣷⠀⠀⠀⠀⢻⣇" << endl;
//wcout << L"⣿⠁⠀⠀⠀⠸⣿⠀⠀⠀⠀⠀⠀⣿⠇⠀⠀⠀⠈⣿" << endl;
//wcout << L"⣿⡀⠀⠀⠀⠀⠻⣦⣀⠀⠀⣀⣴⠟⠀⠀⠀⠀⢀⣿" << endl;
//wcout << L"⢸⣧⠀⠀⠀⢀⣤⡾⠿⠛⠛⠿⢷⣤⡀⠀⠀⠀⣼⡏" << endl;
//wcout << L"⠀⠻⣧⡀⢠⡿⠉⠀⠀⠀⠀⠀⠀⠉⢿⡄⢀⣼⠟⠀" << endl;
//wcout << L"  ⠙⢿⣿⣁⠀⠀⠀⠀⠀⠀⠀⠀⣈⣿⡿⠋⠀⠀" << endl;
//wcout << L"⠀ ⠀⠀⠈⠛⠿⢶⣦⣤⣤⣴⡶⠿⠛⠁⠀⠀" << endl;









