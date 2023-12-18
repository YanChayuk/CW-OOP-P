#pragma once

#define _CRT_SECURE_NO_WARNINGS


//#include <stdio.h>
//#include <locale.h>
//#include <ctype.h>
//#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <istream>
#include <iomanip>
#include <windows.h>
#include <chrono>
#include <ctime>
#include <fstream>
#include <time.h>
#include <thread>

using namespace std;

static const string PATH_FILE_OF_PASSENGERS = "C:\\Users\\Asus\\Documents\\OOP&P\\Passenger.txt";
static const string PATH_FILE_OF_DISPATCHERS = "C:\\Users\\Asus\\Documents\\OOP&P\\Dispatcher.txt";
static const string PATH_FILE_OF_TICKETS = "C:\\Users\\Asus\\Documents\\OOP&P\\Ticket.txt";
static const string PATH_FILE_OF_TRAINS = "C:\\Users\\Asus\\Documents\\OOP&P\\Train.txt";
static const string PATH_FILE_OF_VANS = "C:\\Users\\Asus\\Documents\\OOP&P\\Van.txt";
static const string PATH_FILE_OF_FREESEATS = "C:\\Users\\Asus\\Documents\\OOP&P\\FreeSeats.txt";
static const string PATH_FILE_OF_ROUTES = "C:\\Users\\Asus\\Documents\\Route.txt";
static const string PATH_FILE_OF_STOPOVERS = "C:\\Users\\Asus\\Documents\\Stopover.txt";


static const int RESERVE_SIZE = 100; //Максимальное количество элементов массива
static int current_role, current_i, current_attempt;
static string current_login;
static const string encryption_key = "МирТанков";

namespace Yan
{

}
extern void main_menu();
extern void title(const string text_zagolovok);

extern string decryptPassword(const string& encryptedPassword, const string& key);
extern string encryptPassword(const string& password, const string& key);

extern int choice();
extern int inputNumber(int left_range, int right_range);
extern float inputNumberFloat(float left_range, float right_range);
extern bool isNumberNumeric();
extern bool isNumberRangeCorrect(int number, int left_range, int right_range);
extern bool isNumberRangeCorrectFloat(float number, float left_range, float right_range);

extern bool isLogin(const string& str);
extern bool isPassword(const string& str);
extern bool isString(const string& str);
extern bool isMail(const string& str);
extern string inputStringPassword();
extern string inputStringLogin();
extern string inputString();
extern string inputStringMail();
extern string passwordEncryption();

extern string getCurrentDate();
extern string getCurrentTime();
extern string getDate(int day, int month, int year);
extern string getTime(int sec, int min, int hour);

extern void intro();
extern void printConsoleCentered(const string& text, int width);
extern void consoleWidthHeight();
extern void getCurrentTimeGPT();



class Van
{
	string type;
	string class_of_service;
	vector<int> seats;
	int number_of_seats;
	int number;
public:
	static int number_of_vans;

	Van() : type(""), number(0), number_of_seats(0), class_of_service("") { seats.reserve(100); }
	Van(int number, string type, int number_of_seats, vector<int> seats, string class_of_service) : number(number), type(type),
		seats(seats), class_of_service(class_of_service), number_of_seats(number_of_seats) {}
	/*Van(const Van& other)
	{
		this->number = other.number;
		this->type = other.type;
		this->seats = other.seats;
		this->class_of_service = other.class_of_service;
		this->number_of_seats = other.number_of_seats;
	}*/

	void setType(string type) { this->type = type; }
	string getType() { return this->type; }

	void setServiceClass(string service) { this->class_of_service = service; }
	string getServiceClass() { return this->class_of_service; }

	void setNumber(int number) { this->number = number; }
	int getNumber() { return this->number; }

	void setSeatsNumber(int number_of_seats) { this->number_of_seats = number_of_seats; }
	int getSeatsNumber() { return this->number_of_seats; }
	
	vector<int> getSeats() { return this->seats; }

	void fillSeats(int del_seat)
	{
		int i = 0, num = 0, k=1;
		while (i < number_of_seats)
		{
			if (i + 1 == del_seat) num = 1;
			i++;
		}
		i = 0;
		if (num == 1)
		{
			number_of_seats--;
			while (i < number_of_seats)
			{
				if (i + 1 == del_seat) k = 2;
				seats.push_back(i + k);
				i++;
			}
		}
		else
		{
			while (i < number_of_seats)
			{
				seats.push_back(i + k);
				i++;
			}
		}
	}

	void showVanInfo()
	{
		string number = to_string(this->number);
		title("Информация о вагоне №" + number);
		cout << "  " << setw(59) << "" << endl; cout.fill(' ');
		cout << "  $" << setw(11) << "Тип" << " $" << setw(19) << "Класс обслуживания" << " $" 
			<< setw(22) << "Кол-во свободных мест" << " $" << endl;

		cout.fill('~');
		cout << "  " << setw(59) << "" << endl;
		cout.fill(' ');

		cout << "  $" << setw(11) << this->type << " $" << setw(19) << this->class_of_service << " $"
			<< setw(22) << this->number_of_seats << " $" << endl;
		cout.fill('~');
		cout << "  " << setw(59) << "" << endl;
	}

	void showVansInfo(vector<Van>& arr_of_van)
	{
		int i = 0;
		title("Информация о вагонах");
		cout << "  " << setw(55) << "" << endl; cout.fill(' ');
		cout << "  $" << setw(6) << "Номер" << " $" << setw(11) << "Тип" << " $" << setw(19) << "Класс обслуживания" << " $"
			<< setw(12) << "Кол-во мест" << " $" << endl;

		cout.fill('~');
		cout << "  " << setw(55) << "" << endl;
		cout.fill(' ');
		while (i < arr_of_van.size())
		{
			cout << "  $" << setw(6) << arr_of_van[i].number << " $" << setw(11) << arr_of_van[i].type << " $" 
				<< setw(19) << arr_of_van[i].class_of_service << " $"
				<< setw(12) << arr_of_van[i].number_of_seats << " $" << endl;
			cout.fill('~');
			cout << "  " << setw(55) << "" << endl;
			i++;
		}
	}

	friend ostream& operator<<(ostream& s, Van& van)
	{
		s << " " << van.number << " $ " << van.type << " $ " << van.class_of_service << " $ " << van.number_of_seats << " $";
		return s;
	}

	friend istream& operator>>(istream& s, Van& train)
	{
		string temp;

		getline(s, temp, ' ');

		if (!s.good())
		{
			return s;
		}

		number_of_vans++;

		
		getline(s, temp, '$');
		temp.pop_back();
		train.setNumber(stoi(temp));

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		train.setType(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		train.setServiceClass(temp);

		/*s.get();
		getline(s, temp, '$');
		temp.pop_back();
		train.seats[stoi(temp)];*/

		return s;
	}

	void fillVans(vector<Van>& arr_of_vans)
	{
		Van van;
		ifstream file;
		file.open(PATH_FILE_OF_VANS);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}

		arr_of_vans.clear();

		while (file >> van)
		{
			arr_of_vans.push_back(van);
			if (!file.good()) break;
		}
		file.close();
	}

	void writeVans(vector<Van>& arr_of_vans)
	{
		ofstream file;
		file.open(PATH_FILE_OF_VANS);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}

		number_of_vans = 0;

		for (int i = 0; i < arr_of_vans.size(); i++)
		{
			number_of_vans++;
			file << arr_of_vans[i];
			if (i != arr_of_vans.size() - 1)
			{
				file << endl;
			}
		}
		file.close();
	}

	void addVan()
	{
		ofstream file;
		file.open(PATH_FILE_OF_VANS, ios::app);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}
		number_of_vans++;

		file.seekp(0, ios::end);
		if (file.tellp() == 0)
		{

			file << *this;
		}
		else
		{
			file << endl << *this;
		}
		file.close();
	}


};

class Stopover
{
	string name;
public:
	Stopover() : name("") {}
	Stopover(string name): name(name) {}
	/*Stopover(const Stopover& other)
	{
		this->name = other.name;
	}*/

	void setName(string name) { this->name = name; }
	string getName() { return this->name; }

	void showStopoverInfo()
	{
		title("Информация о станции ");
		cout << "  " << setw(49) << "" << endl; cout.fill(' ');
		cout << "  $" << setw(15) << "Название" << " $" << endl;

		cout.fill('~');
		cout << "  " << setw(49) << "" << endl;
		cout.fill(' ');

		cout << "  $" << setw(15) << this->name << " $" << endl;

		cout.fill('~');
		cout << "  " << setw(49) << "" << endl;
	}

	void showStopoversInfo(vector<Stopover>& arr_of_stop)
	{
		int i = 0;
		title("Информация о станциях");
		cout << "  " << setw(49) << "" << endl; cout.fill(' ');
		cout << "  $" << setw(15) << "Название" << " $" << endl;

		cout.fill('~');
		cout << "  " << setw(49) << "" << endl;
		cout.fill(' ');
		while (i < arr_of_stop.size())
		{
			cout << "  $" << setw(15) << arr_of_stop[i].name << " $" << endl;

			cout.fill('~');
			cout << "  " << setw(49) << "" << endl;
			i++;
		}
	}

	friend ostream& operator<<(ostream& s, Stopover& stop)
	{
		s << " " << stop.name << " $";
		return s;
	}

	friend istream& operator>>(istream& s, Stopover& stop)
	{
		string temp;

		getline(s, temp, ' ');

		if (!s.good())
		{
			return s;
		}

		
		getline(s, temp, '$');
		temp.pop_back();
		stop.setName(temp);

		
		return s;
	}

	void fillStopovers(vector<Stopover>& arr_of_stop)
	{
		Stopover stop;
		ifstream file;
		file.open(PATH_FILE_OF_STOPOVERS);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}

		arr_of_stop.clear();

		while (file >> stop)
		{
			arr_of_stop.push_back(stop);
			if (!file.good()) break;
		}
		file.close();
	}

	void writeStopovers(vector<Stopover>& arr_of_stop)
	{
		ofstream file;
		file.open(PATH_FILE_OF_STOPOVERS);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}

		for (int i = 0; i < arr_of_stop.size(); i++)
		{
			file << arr_of_stop[i];
			if (i != arr_of_stop.size() - 1)
			{
				file << endl;
			}
		}
		file.close();
	}

	void addStopover()
	{
		ofstream file;
		file.open(PATH_FILE_OF_STOPOVERS, ios::app);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}

		file.seekp(0, ios::end);
		if (file.tellp() == 0)
		{

			file << *this;
		}
		else
		{
			file << endl << *this;
		}
		file.close();
	}



};

class Ticket
{
	int number;
	int place;
	float price;
	string tariff;
	vector<Stopover> route;
	vector<string> date;
	vector<string> time;
public:
	static int number_of_tickets;

	Ticket() : number(0), place(0), price(0), tariff("") { route.reserve(10); date.push_back(""); date.push_back(""); time.push_back(""); time.push_back(""); }
	Ticket(int number, int place, float price, string tariff, vector<Stopover> route, vector<string> date, vector<string> time)
	{
		this->number = number; this->place = place; this->price = price;
		this->tariff = tariff; this->route = route; this->date = date; this->time = time;
	}
	/*Ticket(const Ticket& other)
	{
		this->number = other.number; this->place = other.place; this->price = other.price;
		this->tariff = other.tariff; this->route = other.route; this->date = other.date; this->time = other.time;
	}*/
	

	void setNumber(int number) { this->number = number; }
	int getNumber() { return this->number; }

	void setPlace(int place) { this->place = place; }
	int getPlace() { return this->place; }

	void setPrice(float price) { this->price = price; }
	float getPrice() { return this->price; }

	void setTariff(string tariff) { this->tariff = tariff; }
	string getTariff() { return this->tariff; }

	void setArrTime(string arr_time) { this->time[0] = arr_time; }
	string getArrTime() { return this->time[0]; }

	void setDepTime(string dep_time) { this->time[1] = dep_time; }
	string getDepTime() { return this->time[1]; }

	void setArrDate(string arr_date) { this->date[0] = arr_date; }
	string getArrDate() { return this->date[0]; }

	void setDepDate(string dep_date) { this->date[1] = dep_date; }
	string getDepDate() { return this->date[1]; }

	void enterRoute()
	{
		cout << "Введите станцию отправления: ";
		this->route[0].setName(inputStringMail());
		cout << "Введите станцию прибытия: ";
		this->route[1].setName(inputStringMail());
	}

	void setArrStop(string arr_stop) { this->route[0].setName(arr_stop); }
	string getArrStop() { return this->route[0].getName(); }

	void setDepStop(string dep_stop) { this->route[1].setName(dep_stop); }
	string getDepStop() { return this->route[1].getName(); }

	void showTicketInfo()
	{
		string number = to_string(this->number);
		title("Информация о билете №" + number);
		cout << "  " << setw(108) << "" << endl; cout.fill(' ');
		cout << "  $" << setw(6) << "Место" << " $" << setw(7) << "Цена" << " $" << setw(7) << "Тариф" << " $"
			<< setw(36) << "Маршрут" << " $" << setw(41) << "Дата и время" << " $" << endl;

		cout.fill('~');
		cout << "  " << setw(108) << "" << endl;
		cout.fill(' ');

		cout << "  $" << setw(6) << this->place << " $" << setw(7) << fixed << setprecision(2) << this->price << " $" 
			<< setw(7) << this->tariff << " $" << setw(36) << this->route[0]<<" - " << this->route[1] << " $" << setw(41) 
			<< this->time[0]<<" "<< this->date[0]<< " - " << this->time[1] << " " << this->date[1] << " $" << endl;
		cout.fill('~');
		cout << "  " << setw(108) << "" << endl;
	}

	void showTicketsInfo(vector<Ticket> arr_of_tick)
	{
		int i = 0;
		title("Информация о билетах");
		cout << "  " << setw(108) << "" << endl; cout.fill(' ');
		cout << "  $" << setw(6) << "Место" << " $" << setw(7) << "Цена" << " $" << setw(7) << "Тариф" << " $"
			<< setw(36) << "Маршрут" << " $" << setw(41) << "Дата и время" << " $" << endl;

		cout.fill('~');
		cout << "  " << setw(108) << "" << endl;
		cout.fill(' ');
		while (i < arr_of_tick.size())
		{
			cout << "  $" << setw(6) << arr_of_tick[i].place << " $" << setw(7) << fixed << setprecision(2) << arr_of_tick[i].price << " $"
				<< setw(7) << arr_of_tick[i].tariff << " $" << setw(36) << arr_of_tick[i].route[0] << " - " << arr_of_tick[i].route[1] << " $" << setw(41)
				<< arr_of_tick[i].time[0] << " " << arr_of_tick[i].date[0] << " - " << arr_of_tick[i].time[1] << " " << arr_of_tick[i].date[1] << " $" << endl;
			cout.fill('~');
			cout << "  " << setw(108) << "" << endl;
			i++;
		}
	}

	friend ostream& operator<<(ostream& s, Ticket& ticket)
	{
		s << " " << ticket.number << " $ " << ticket.route[0].getName() << " - " << ticket.route[1].getName()
			<< " $ " << ticket.date[0] << " - " << ticket.date[1] << " $ " << ticket.time[0] << " - " << ticket.time[1] << " $ "
			<< ticket.getPlace() << " $ " << ticket.getPrice()<< " $ " << ticket.getTariff() << " $";
		return s;
	}

	friend istream& operator>>(istream& s, Ticket& ticket)
	{
		string temp;

		getline(s, temp, ' ');

		if (!s.good())
		{
			return s;
		}

		number_of_tickets++;

		
		getline(s, temp, '$');
		temp.pop_back();
		ticket.setNumber(stoi(temp));

		s.get();
		getline(s, temp, '-');
		temp.pop_back();
		ticket.route[0].setName(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		ticket.route[1].setName(temp);

		s.get();
		getline(s, temp, '-');
		temp.pop_back();
		ticket.date.push_back(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		ticket.date.push_back(temp);

		s.get();
		getline(s, temp, '-');
		temp.pop_back();
		ticket.time.push_back(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		ticket.time.push_back(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		ticket.setPlace(stoi(temp));

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		ticket.setPrice(stoi(temp));

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		ticket.setTariff(temp);

		return s;
	}

	void fillTickets(vector<Ticket>& arr_of_ticket)
	{
		Ticket ticket;
		ifstream file;
		file.open(PATH_FILE_OF_TICKETS);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}

		arr_of_ticket.clear();

		while (file >> ticket)
		{
			arr_of_ticket.push_back(ticket);
			if (!file.good()) break;
		}
		file.close();
	}

	void writeTickets(vector<Ticket>& arr_of_tickets)
	{
		ofstream file;
		file.open(PATH_FILE_OF_TICKETS);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}

		number_of_tickets = 0;

		for (int i = 0; i < arr_of_tickets.size(); i++)
		{
			number_of_tickets++;
			file << arr_of_tickets[i];
			if (i != arr_of_tickets.size() - 1)
			{
				file << endl;
			}
		}
		file.close();
	}

	void addTicket()
	{
		ofstream file;
		file.open(PATH_FILE_OF_TICKETS, ios::app);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}
		number_of_tickets++;

		file.seekp(0, ios::end);
		if (file.tellp() == 0)
		{

			file << *this;
		}
		else
		{
			file << endl << *this;
		}
		file.close();
	}


};

class Train
{
	int number;
	vector<Ticket> tickets;
	vector<Stopover> route;
	vector<Van> vans;
	vector<string> date;
	vector<string> time;
	int number_of_vans;
	int number_of_stopover;
public:
	static int number_of_trains;

	Train() : number(0) { route.reserve(10); vans.reserve(10); tickets.reserve(10); date.push_back(""); date.push_back(""); time.push_back(""); time.push_back(""); }
	Train(int number, vector<Ticket> tickets, vector<Stopover> route, vector<Van> vans, vector<string> date)
	{
		this->number = number;
		this->tickets = tickets;
		this->route = route;
		this->vans = vans;
		this->date = date;
	}
	/*Train(const Train& other)
	{
		this->number = other.number;
		this->tickets = other.tickets;
		this->route = other.route;
		this->vans = other.vans;
		this->date = other.date;
	}*/

	void setNumber(int number) { this->number = number; }
	int getNumber() { return this->number; }

	void setVansNumber(int number_of_vans) { this->number_of_vans = number_of_vans; }
	int getVansNumber() { return this->number_of_vans; }

	void setStopoverNumber(int number_of_stopover) { this->number_of_stopover = number_of_stopover; }
	int getStopoverNumber() { return this->number_of_stopover; }

	string getRoute() { return route[route.size()-1].getName(); }

	string getArrStop() { return route[0].getName(); }
	string getDepStop() { return route[number_of_stopover-1].getName(); }
 
	int getNumberSeats(int seat) { return this->vans[seat].getSeatsNumber(); }
	int getNumberVans() { return this->number_of_vans; }

	void setArrTime(string arr_time) { this->time[0] = arr_time; }
	string getArrTime() { return this->time[0]; }

	void setDepTime(string dep_time) { this->time[1] = dep_time; }
	string getDepTime() { return this->time[1]; }

	void setArrDate(string arr_date) { this->date[0] = arr_date; }
	string getArrDate() { return this->date[0]; }

	void setDepDate(string dep_date) { this->date[1] = dep_date; }
	string getDepDate() { return this->date[1]; }

	void deleteSeat(int place, int van)
	{
		this->vans[van].fillSeats(place);
	}

	void writeSeats()
	{
		vector<int> van;
		ofstream file;
		file.open(PATH_FILE_OF_FREESEATS);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}
		file << " ";
		for (int i = 0; i < vans.size(); i++)
		{
			van = vans[i].getSeats();
			for (int j = 0; j < van.size(); j++)
			{
				file << van[i] << " $ ";
				if (i != vans.size() - 1)
				{
					file << endl;
				}
			}
		}
		file.close();

		int i = 0;
		while (i < vans.size())
		{

		}
	}

	void setRoute()
	{
		Stopover stop;
		int i = 0;
		while (i < this->number_of_stopover)
		{
			cout << "\n\tВведите название станции маршрута: ";
			stop.setName(inputString());
			route.push_back(stop);
			cout << endl;
			i++;
		}
	}

	string getRouteName(int i)
	{
		return route[i].getName();
	}

	void setVans(int number_of_vans)
	{
		this->number_of_vans = number_of_vans;
		int i = 0, number_of_seats; Van van;
		string type, class_of_service;
		while (i < number_of_vans)
		{
			cout << "\n\tВагон №"<< i+1 << endl;
			van.setNumber(this->number * 10 + i);
			cout << "\n\tВведите тип вагона: ";
			type = inputString();
			van.setType(type);
			cout << "\n\tВведите количество мест(до 50): ";
			number_of_seats = inputNumber(1, 50);
			van.setSeatsNumber(number_of_seats);
			van.fillSeats(-1);
			cout << "\n\tВведите класс обслуживания: ";
			class_of_service = inputString();
			van.setServiceClass(class_of_service);
			vans.push_back(van);
			van.addVan();
			this->tickets.resize(tickets.size()+number_of_seats);
			i++;
		}
	}
	
	void readRoute()
	{
		Train train;
		string temp;
		ifstream file;
		file.open(PATH_FILE_OF_ROUTES);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}
		while (!file.eof())
		{
			file.get();
			getline(file, temp, '$');
			train.setNumber(stoi(temp));
			if (train.getNumber() == this->number)
			{
				while (file.get() != '\n')
				{
					file.get();
					getline(file, temp, '$');
					temp.pop_back();
					this->route.push_back(temp);
					if (!file.good()) break;
				}
			}
		}
		file.close();
	}

	void showTrainInfo()
	{
		string number = to_string(this->number);
		title("Информация о поезде №" + number);
		cout << "  " << setw(67) << "" << endl; cout.fill(' ');
		cout << "  $" << setw(36) << "Маршрут" << " $" << setw(41) << "Дата и время" << " $" << setw(15) << "Кол-во вагонов" << " $"
			<< setw(15) << "Свободных мест" << " $" << endl;

		cout.fill('~');
		cout << "  " << setw(67) << "" << endl;
		cout.fill(' ');

		cout << "  $" << setw(18) << this->route[0].getName() << " - " << setw(18) << this->route[route.size()-1].getName()
			<< " $" << setw(20) << this->getArrDate() << " - " << setw(20) << this->getDepDate() << "   " 
			<< setw(20) << this->getArrTime() << " - " << setw(20) << this->getDepTime() << " $"
			<< setw(15) << this->number_of_vans << " $" << setw(15) << this->tickets.size() << " $" << endl;
		cout.fill('~');
		cout << "  " << setw(67) << "" << endl;
	}

	void showTrainsInfo(vector<Train> arr_of_train)
	{
		int i = 0;
		title("Информация о поездах");
		cout << "  " << setw(67) << "" << endl; cout.fill(' ');
		cout << "  $" << setw(36) << "Маршрут" << " $" << setw(41) << "Дата и время" << " $" << setw(15) << "Кол-во вагонов" << " $"
			<< setw(15) << "Свободных мест" << " $" << endl;

		cout.fill('~');
		cout << "  " << setw(67) << "" << endl;
		cout.fill(' ');
		while (i < arr_of_train.size())
		{
			cout << "  $" << setw(18) << arr_of_train[i].route[0].getName() << " - " << setw(18) << arr_of_train[i].route[route.size() - 1].getName()
				<< " $" << setw(20) << arr_of_train[i].date[0] << " - " << setw(20) << arr_of_train[i].date[1] << " $"
				<< setw(15) << arr_of_train[i].number_of_vans << " $" << setw(15) << arr_of_train[i].tickets.size() << " $" << endl;
			cout.fill('~');
			cout << "  " << setw(67) << "" << endl;
			i++;
		}
	}

	bool showTrainsInfoByRoute(vector<Train> arr_of_train, string arrival, string depart)
	{
		int i = 0, k=0;
		while (i < arr_of_train.size())
		{
			if (arr_of_train[i].getArrStop() == arrival && arr_of_train[i].getDepStop() == depart)
			{
				k = 1;
			}
			i++;
		}
		if (k == 1)
		{
			("Информация о поездах");
			cout << "  " << setw(67) << "" << endl; cout.fill(' ');
			cout << "  $" << setw(36) << "Маршрут" << " $" << setw(41) << "Дата и время" << " $" << setw(15) << "Кол-во вагонов" << " $"
				<< setw(15) << "Свободных мест" << " $" << endl;

			cout.fill('~');
			cout << "  " << setw(67) << "" << endl;
			cout.fill(' ');
			while (i < arr_of_train.size())
			{
				if (arr_of_train[i].getArrStop() == arrival && arr_of_train[i].getDepStop() == depart)
				{
					cout << "  $" << setw(18) << arr_of_train[i].route[0].getName() << " - " << setw(18) << arr_of_train[i].route[route.size() - 1].getName()
						<< " $" << setw(20) << arr_of_train[i].date[0] << " - " << setw(20) << arr_of_train[i].date[1] << " $"
						<< setw(15) << arr_of_train[i].number_of_vans << " $" << setw(15) << arr_of_train[i].tickets.size() << " $" << endl;
					cout.fill('~');
					cout << "  " << setw(67) << "" << endl;
				}
				i++;
			}
			return true;
		}
		else cout << "\n\tПоездов с таким маршрутом нет!" << endl; return false;
	}

	friend ostream& operator<<(ostream& s, Train& train)
	{
		s << " " << train.number << " $ " << train.route[0].getName() << " - " << train.getRoute()
			<< " $ " << train.date[0] << " - " << train.date[1] << " $ "
			<< " $ " << train.time[0] << " - " << train.time[1] << " $ "
			<< train.number_of_vans << " $ " << train.tickets.size() << " $";
		return s;
	}

	friend istream& operator>>(istream& s, Train& train)
	{
		string temp;

		getline(s, temp, ' ');

		if (!s.good())
		{
			return s;
		}

		number_of_trains++;

		
		getline(s, temp, '$');
		temp.pop_back();
		train.setNumber(stoi(temp));

		s.get();
		getline(s, temp, '-');
		temp.pop_back();
		train.route[0].setName(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		train.route[1].setName(temp);

		s.get();
		getline(s, temp, '-');
		temp.pop_back();
		train.date[0].push_back(stoi(temp));

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		train.date[1].push_back(stoi(temp));

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		train.vans[stoi(temp)];

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		train.tickets[stoi(temp)];

		return s;
	}

	void fillTrains(vector<Train>& arr_of_trains)
	{
		Train train;
		ifstream file;
		file.open(PATH_FILE_OF_TRAINS);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}

		arr_of_trains.clear();

		while (file >> train)
		{
			arr_of_trains.push_back(train);
			if (!file.good()) break;
		}
		file.close();
	}

	void writeTrains(vector<Train>& arr_of_trains)
	{
		ofstream file;
		file.open(PATH_FILE_OF_TRAINS);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}

		number_of_trains = 0;

		for (int i = 0; i < arr_of_trains.size(); i++)
		{
			number_of_trains++;
			file << arr_of_trains[i];
			if (i != arr_of_trains.size() - 1)
			{
				file << endl;
			}
		}
		file.close();
	}

	void addTrain()
	{
		ofstream file;
		file.open(PATH_FILE_OF_TRAINS, ios::app);
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}
		number_of_trains++;

		file.seekp(0, ios::end);
		if (file.tellp() == 0)
		{

			file << *this;
		}
		else
		{
			file << endl << *this;
		}
		file.close();
	}


};

class Human
{
protected:
	string surname;
	string name;
	string patronimic;
public:
	Human(): surname(""), name(""), patronimic(""){}
	Human(string surname, string name, string patronimic): surname(surname), name(name), patronimic(patronimic) {}
	Human(const Human& other)
	{
		this->surname = other.surname;
		this->name = other.name;
		this->patronimic = other.patronimic;
	}
	
	virtual void setName(string name) { this->name = name; }
	virtual string getName() { return name; }
	
	virtual void setSurname(string surname) { this->surname = surname; }
	virtual string getSurname() { return surname; }

	virtual void setPatronimic(string patronimic) { this->patronimic = patronimic; }
	virtual string getPatronimic() { return patronimic; }

	virtual void showAccountInfo() = 0;
	virtual void corAccount() = 0;
};

class Authorization
{
	int id;
	string login;
	string password;
	int role;
	int access;
public:
	static int total_number_of_account;

	Authorization(): login(""), password(""), role(0), access(0), id(0){}
	Authorization(string login, string password, int id, int role, int access): login(login), password(password), id(id), 
		role(role), access(access){}
	/*Authorization(const Authorization& other)
	{
		this->id = other.id;
		this->login = other.login;
		this->password = other.password;
		this->role = other.role;
		this->access = other.access;
	}*/
	
	void setLogin(string login) { this->login = login; }
	string getLogin() { return this->login; }

	void setPassword(string password) { this->password = password; }
	string getPassword() { return this->password; }

	void setRole(int role) { this->role = role; }
	int getRole() { return this->role; }

	void setAccess(int access) { this->access = access; }
	int getAccess() { return this->access; }

	void setId(int id) { this->id = id; }
	int getId() { return this->id; }
};

class Passenger: public Human
{
	float balance;
	string mail;
	string phone_number;
	string passport_data;//серия и номер паспорта
public:
	Authorization authorization;
	static int number_of_pass;

	Passenger(): mail(""), phone_number(""), passport_data(""), authorization(), balance(100) {}
	/*Passenger(string mail, string phone_number, string passport_data, float balance, Authorization* authorization) : mail(mail),
		phone_number(phone_number), passport_data(passport_data), authorization(authorization), balance(balance) {}*/
	/*Passenger(const Passenger& other)
	{
		this->mail = other.mail;
		this->phone_number = other.phone_number;
		this->passport_data = other.passport_data;
		this->authorization = other.authorization;
		this->balance = other.balance;
	}*/
	
	void setName(string name) override { this->name = name; }
	string getName() { return name; }

	void setSurname(string surname) override { this->surname = surname; }
	string getSurname() { return surname; }

	void setPatronimic(string patronimic) override { this->patronimic = patronimic; }
	string getPatronimic() { return patronimic; }

	void setBalance(float balance) { this->balance = balance; }
	float getBalance() { return this->balance; }
	
	void setMail(string mail) { this->mail = mail; }
	string getMail() { return this->mail; }

	void setPhoneNumber(string phone_number) { this->phone_number = phone_number; }
	string getPhoneNumber() { return this->phone_number; }

	void setPassportData(string data) { this->passport_data = data; }
	string getPassportData() { return this->passport_data; }

	void pay(float price)
	{
		this->balance = this->balance - price;
	}

	void showAccountInfo() override
	{
		title("Информация о пассажире");
		cout << "  " << setw(129) << "" << endl;
		cout.fill(' ');
		cout << "  $" << setw(20) << "Фамилия" << " $" << setw(10) << "Имя" << " $" << setw(19) << "Отчество" << " $" << setw(9)<< "Баланс"<<" $"<<
			setw(25) << "Электронная почта    " << " $" << setw(19) << "Номер телефона" << " $" << setw(23) << "Серия и номер паспорта" << " $" << endl;
		cout.fill('~');
		cout << "  " << setw(129) << "" << endl;
		cout.fill(' ');
		cout << "  $" << setw(20) << this->getSurname() << " $" << setw(10) << this->getName() << " $" << setw(19) << this->getPatronimic() << " $" << setw(9) << setprecision(2) << this->getBalance()
			<< " $" << setw(25) << this->mail << " $" << setw(19) << this->phone_number << " $" << setw(23) << this->passport_data << " $" << endl;
		cout.fill('~');
		cout << "  " << setw(129) << "" << endl;
	}

	void corAccount() override 
	{
		string choose, new_password, new_login, new_surname, new_name, new_patrominic, new_mail, new_phone, new_passport;
		bool flag_exit = true;
		int choice, n = 1;
		while (flag_exit)
		{
			system("CLS");
			title("Ваш аккаунт");
			cout << "  $                                                                       $" << endl;
			cout << "  $    0 - Назад                                                          $" << endl;
			cout << "  $    1 - Изменить логин                                                 $" << endl;
			cout << "  $    2 - Изменить пароль                                                $" << endl;
			cout << "  $    3 - Изменить фамилию                                               $" << endl;
			cout << "  $    4 - Изменить имя                                                   $" << endl;
			cout << "  $    5 - Изменить отчество                                              $" << endl;
			cout << "  $    6 - Изменить электронную почту                                     $" << endl;
			cout << "  $    7 - Изменить номер телефона                                        $" << endl;
			cout << "  $    8 - Изменить серию и номер паспорта                                $" << endl;
			cout << "  $                                                                       $" << endl;
			cout << "  " << setw(73) << "" << endl;
			cout << "\n\tВыберите пункт: ";
			choice = inputNumber(0, 8);
			switch (choice)
			{
			case 1:
				n = 1;
				cout << "\nВведите новый логин: " << endl;
				new_login = inputStringLogin();
				while (n != 0)
				{
					cout << "\n\tСохранить изменения? (Да/Нет) " << endl << "\t";
					choose = inputString();
					if (choose == "Да")
					{
						this->authorization.setLogin(new_login);
						cout << "\n\tКорректировка сохранена\n";
						n = 0;
					}
					else
					{ 
						if (choose == "Нет")
						{
							cout << "\n\tКорректировка отменена\n";
							n = 0;
						} 
					}
				}
				break;
			case 2:
				n = 1;
				cout << "\nВведите новый пароль: " << endl;
				new_password = inputStringPassword();
				while (n != 0)
				{
					cout << "\n\tСохранить изменения? (Да/Нет) " << endl << "\t";
					choose = inputString();
					if (choose == "Да")
					{
						this->authorization.setPassword(new_password);
						cout << "\n\tКорректировка сохранена\n";
						n = 0;
					}
					else
					{
						if (choose == "Нет")
						{
							cout << "\n\tКорректировка отменена\n";
							n = 0;
						}
					}
				}
				break;
			case 3:
				n = 1;
				cout << "\nВведите новую фамилию: " << endl;
				new_surname = inputString();
				while (n != 0)
				{
					cout << "\n\tСохранить изменения? (Да/Нет) " << endl << "\t";
					choose = inputString();
					if (choose == "Да")
					{
						this->setSurname(new_surname);
						cout << "\n\tКорректировка сохранена\n";
						n = 0;
					}
					else
					{
						if (choose == "Нет")
						{
							cout << "\n\tКорректировка отменена\n";
							n = 0;
						}
					}
				}
				break;
			case 4:
				n = 1;
				cout << "\nВведите новое имя: " << endl;
				new_name = inputString();
				while (n != 0)
				{
					cout << "\n\tСохранить изменения? (Да/Нет) " << endl << "\t";
					choose = inputString();
					if (choose == "Да")
					{
						this->setName(new_name);
						cout << "\n\tКорректировка сохранена\n";
						n = 0;
					}
					else
					{
						if (choose == "Нет")
						{
							cout << "\n\tКорректировка отменена\n";
							n = 0;
						}
					}
				}
				break;
			case 5:
				n = 1;
				cout << "\nВведите новое отчество: " << endl;
				new_patrominic = inputString();
				while (n != 0)
				{
					cout << "\n\tСохранить изменения? (Да/Нет) " << endl << "\t";
					choose = inputString();
					if (choose == "Да")
					{
						this->setPatronimic(new_patrominic);
						cout << "\n\tКорректировка сохранена\n";
						n = 0;
					}
					else
					{
						if (choose == "Нет")
						{
							cout << "\n\tКорректировка отменена\n";
							n = 0;
						}
					}
				}
				break;
			case 6:
				n = 1;
				cout << "\nВведите новую электронную почту: " << endl;
				new_mail = inputStringMail();
				while (n != 0)
				{
					cout << "\n\tСохранить изменения? (Да/Нет) " << endl << "\t";
					choose = inputString();
					if (choose == "Да")
					{
						this->setMail(new_mail);
						cout << "\n\tКорректировка сохранена\n";
						n = 0;
					}
					else
					{
						if (choose == "Нет")
						{
							cout << "\n\tКорректировка отменена\n";
							n = 0;
						}
					}
				}
				break;
			case 7:
				n = 1;
				cout << "\nВведите новый номер телефона: " << endl;
				new_phone = inputStringMail();
				while (n != 0)
				{
					cout << "\n\tСохранить изменения? (Да/Нет) " << endl << "\t";
					choose = inputString();
					if (choose == "Да")
					{
						this->setPhoneNumber(new_phone);
						cout << "\n\tКорректировка сохранена\n";
						n = 0;
					}
					else
					{
						if (choose == "Нет")
						{
							cout << "\n\tКорректировка отменена\n";
							n = 0;
						}
					}
				}
				break;
			case 8:
				n = 1;
				cout << "\nВведите новые серию и номер паспорта: " << endl;
				new_passport = inputStringLogin();
				while (n != 0)
				{
					cout << "\n\tСохранить изменения? (Да/Нет) " << endl << "\t";
					choose = inputString();
					if (choose == "Да")
					{
						this->setPassportData(new_passport);
						cout << "\n\tКорректировка сохранена\n";
						n = 0;
					}
					else
					{
						if (choose == "Нет")
						{
							cout << "\n\tКорректировка отменена\n";
							n = 0;
						}
					}
				}
				break;
			case 0: flag_exit = false;
				break;
			}
		}
	}

	void delAccount(vector<Passenger>& arr_of_pass)
	{
		title("Удаление аккаунта");
		int number_of_deleted = current_i;
		string choose;
		bool flag_exit = true;

		while (flag_exit)
		{
			cout << "\n\tУдалить Ваш аккаунт безвозратно? (Да/Нет)"<< endl<<"\t";
			choose = inputString();
			if (choose == "Да")
			{
				cout << "\n\tВаш аккаунт удален";
				for (int i = number_of_deleted; i < arr_of_pass.size() - 1; i++)
				{
					arr_of_pass[i] = arr_of_pass[i + 1];
				}
				Authorization::total_number_of_account--;
				this->writePassengers(arr_of_pass);
				this->fillPassengers(arr_of_pass);
				main_menu();
				//flag_exit = false;
			}
			if (choose == "Нет")
			{
				cout << "\n\tУдаление отменено";
				flag_exit = false;
			}
		}
		cout << endl;
		system("pause");
	}

	void menuAccount(vector<Passenger>& arr_of_pass)
	{
		int choice, number_start = 0;
		bool flag_exit = true;
		while (flag_exit)
		{
			title("Меню работы с аккаунтом");
			cout << "  $                                                                       $" << endl;
			cout << "  $    0 - Назад                                                          $" << endl;
			cout << "  $    1 - Просмотр личных данных                                         $" << endl;
			cout << "  $    2 - Редактирование личных данных                                   $" << endl;
			cout << "  $    3 - Удаление аккаунта                                              $" << endl;
			cout << "  $                                                                       $" << endl;
			cout.fill('~');
			cout << "  " << setw(73) << "" << endl;
			cout.fill(' ');
			cout << "\n  Выберите пункт меню: ";
			choice = inputNumber(0, 3);
			switch (choice)
			{
			case 0: flag_exit = false; break;
			case 1:
			{
				this->showAccountInfo();
				cout << endl; system("pause");
			}
			break;
			case 2:
			{
				this->corAccount();
				this->writePassengers(arr_of_pass);
				cout << endl; system("pause");
			}
			break;
			case 3:
			{
				this->delAccount(arr_of_pass);
				cout << endl; system("pause");
			}
			break;
			default: false; cout << "\n\tВы ввели неверный параметр." << endl; break;
			}
		}
	}

	friend ostream& operator<<(ostream& s, Passenger& pass)
	{ 
		s << " " << pass.authorization.getId() << " $ " << pass.authorization.getLogin() << " $ "
			<< encryptPassword(pass.authorization.getPassword(), encryption_key) << " $ " << setprecision(2) << pass.balance << " $ "
			<< pass.getSurname() << " $ " << pass.getName() << " $ "
			<< pass.getPatronimic() << " $ " << pass.mail << " $ " << pass.phone_number << " $ "
			<< encryptPassword(pass.passport_data, encryption_key) << " $ " << pass.authorization.getAccess() << " $";
		return s;
	}

	friend istream& operator>>(istream& s, Passenger& pass)
	{
		string temp;

		//getline(s, temp, '$');
		getline(s, temp, ' ');
		
		if (!s.good() || s.eof())
		{
			return s;
		}

		number_of_pass++;

		pass.authorization.setRole(0);

		//s.get();
		getline(s, temp, '$');
		temp.pop_back();
		pass.authorization.setId(stoi(temp));

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		pass.authorization.setLogin(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		pass.authorization.setPassword(decryptPassword(temp, encryption_key));

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		pass.setBalance(stoi(temp));

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		pass.setSurname(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		pass.setName(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		pass.setPatronimic(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		pass.setMail(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		pass.setPhoneNumber(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		pass.setPassportData(decryptPassword(temp, encryption_key));

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		pass.authorization.setAccess(stoi(temp));

		return s;
	}

	static void fillPassengers(vector<Passenger>& arr_of_pass)
	{
		Passenger pass; int mark = 0;
		ifstream file;
		file.open(PATH_FILE_OF_PASSENGERS);//("Passenger.txt");
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}

		number_of_pass = 0;
		arr_of_pass.clear();

		while (file >> pass && mark!=1)
		{
			arr_of_pass.push_back(pass);
			//if (file.eof()) { mark = 1; break; }
			if (!file.good()) break;
		}
		file.close();
	}

	static void writePassengers(vector<Passenger>& arr_of_pass)
	{
		ofstream file;
		file.open(PATH_FILE_OF_PASSENGERS);//("Passenger.txt");
		if (!file.is_open()) 
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}

		number_of_pass = 0;

		for (int i = 0; i < arr_of_pass.size(); i++) 
		{
			number_of_pass++;
			file << arr_of_pass[i];
			if (i != arr_of_pass.size() - 1) 
			{
				file << endl;
			}
		}
		file.close();
	}

	void addPassenger()
	{
		ofstream file;
		file.open(PATH_FILE_OF_PASSENGERS, ios::app);//("Passenger.txt");
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}
		number_of_pass++;

		file.seekp(0, ios::end);
		if (file.tellp() == 0) 
		{

			file << *this;
		}
		else
		{
			file << endl << *this;
		}
		file.close();
	}

};

class Dispatcher: public Human
{
	string key;//ключ подтверждения действий в системе
public:
	static int number_of_disp;
	Authorization authorization;

	Dispatcher(): key(""), authorization() {}
	/*Dispatcher(string key): key(key) {}*/
	/*Dispatcher(const Dispatcher& other)
	{
		this->key = other.key;
		this->authorization = other.authorization;
	}*/

	void setKey(string key) { this->key = key; }
	string getKey() { return this->key; }

	void setName(string name) override { this->name = name; }
	string getName() { return name; }

	void setSurname(string surname) override { this->surname = surname; }
	string getSurname() { return surname; }

	void setPatronimic(string patronimic) override { this->patronimic = patronimic; }
	string getPatronimic() { return patronimic; }

	void showAccountInfo() override
	{
		title("Информация о диспетчере");
		cout << "  " << setw(77) << "" << endl; cout.fill(' ');
		cout << "  $" << setw(20) << "Фамилия " << " $" << setw(10) << "Имя" << " $" << setw(19) << "Отчество" << " $" << setw(19)
			<< "Текущий ключ" << " $" << endl;
		cout.fill('~');
		cout << "  " << setw(77) << "" << endl;
		cout.fill(' ');
		cout << "  $" << setw(20) << this->getSurname() << " $" << setw(10) << this->getName() << " $" << setw(19) << this->getPatronimic()
			<< " $" << setw(19) << this->key << " $" << endl;
		cout.fill('~');
		cout << "  " << setw(77) << "" << endl; 
	}

	void corAccount() override
	{
		string choose, new_password, new_login, new_surname, new_name, new_patrominic;
		bool flag_exit = true;
		int choice, n = 1;
		while (flag_exit)
		{
			system("CLS");
			title("Ваш аккаунт");
			cout << "  $                                                                       $" << endl;
			cout << "  $    0 - Назад                                                          $" << endl;
			cout << "  $    1 - Изменить логин                                                 $" << endl;
			cout << "  $    2 - Изменить пароль                                                $" << endl;
			cout << "  $    3 - Изменить фамилию                                               $" << endl;
			cout << "  $    4 - Изменить имя                                                   $" << endl;
			cout << "  $    5 - Изменить отчество                                              $" << endl;
			cout << "  $                                                                       $" << endl;
			cout << "  " << setw(73) << "" << endl;
			cout << "\n\tВыберите пункт: ";
			choice = inputNumber(0, 5);
			switch (choice)
			{
			case 1:
				n = 1;
				cout << "\nВведите новый логин: " << endl;
				new_login = inputStringLogin();
				while (n != 0)
				{
					cout << "\n\tСохранить изменения? (Да/Нет) "<<endl<<"\t";
					choose = inputString();
					if (choose == "Да")
					{
						this->authorization.setLogin(new_login);
						cout << "\n\tКорректировка сохранена\n";
						n = 0;
					}
					else
					{
						if (choose == "Нет")
						{
							cout << "\n\tКорректировка отменена\n";
							n = 0;
						}
					}
				}
				break;
			case 2:
				n = 1;
				cout << "\nВведите новый пароль: " << endl;
				new_password = inputStringPassword();
				while (n != 0)
				{
					cout << "\n\tСохранить изменения? (Да/Нет) " << endl << "\t";
					choose = inputString();
					if (choose == "Да")
					{
						this->authorization.setPassword(new_password);
						cout << "\n\tКорректировка сохранена\n";
						n = 0;
					}
					else
					{
						if (choose == "Нет")
						{
							cout << "\n\tКорректировка отменена\n";
							n = 0;
						}
					}
				}
				break;
			case 3:
				n = 1;
				cout << "\nВведите новую фамилию: " << endl;
				new_surname = inputString();
				while (n != 0)
				{
					cout << "\n\tСохранить изменения? (Да/Нет) " << endl << "\t";
					choose = inputString();
					if (choose == "Да")
					{
						this->setSurname(new_surname);
						cout << "\n\tКорректировка сохранена\n";
						n = 0;
					}
					else
					{
						if (choose == "Нет")
						{
							cout << "\n\tКорректировка отменена\n";
							n = 0;
						}
					}
				}
				break;
			case 4:
				n = 1;
				cout << "\nВведите новое имя: " << endl;
				new_name = inputString();
				while (n != 0)
				{
					cout << "\n\tСохранить изменения? (Да/Нет) " << endl << "\t";
					choose = inputString();
					if (choose == "Да")
					{
						this->setName(new_name);
						cout << "\n\tКорректировка сохранена\n";
						n = 0;
					}
					else
					{
						if (choose == "Нет")
						{
							cout << "\n\tКорректировка отменена\n";
							n = 0;
						}
					}
				}
				break;
			case 5:
				n = 1;
				cout << "\nВведите новое отчество: " << endl;
				new_patrominic = inputString();
				while (n != 0)
				{
					cout << "\n\tСохранить изменения? (Да/Нет) " << endl << "\t";
					choose = inputString();
					if (choose == "Да")
					{
						this->setPatronimic(new_patrominic);
						cout << "\n\tКорректировка сохранена\n";
						n = 0;
					}
					else
					{
						if (choose == "Нет")
						{
							cout << "\n\tКорректировка отменена\n";
							n = 0;
						}
					}
				}
				break;
			case 0: flag_exit = false;
				break;
			}
		}
	}

	void delAccount(vector<Dispatcher>& arr_of_disp)
	{
		title("Удаление аккаунта");
		int number_of_deleted = current_i;
		string choose;
		bool flag_exit = true;

		while (flag_exit)
		{
			cout << "\n\tУдалить Ваш аккаунт безвозратно? (Да/Нет)"<< endl<<"\t";
			choose = inputString();
			if (choose == "Да")
			{
				cout << "\n\tВаш аккаунт удален";
				for (int i = number_of_deleted; i < arr_of_disp.size() - 1; i++)
				{
					arr_of_disp[i] = arr_of_disp[i + 1];
				}
				//Authorization::total_number_of_account--;
				this->writeDispatchers(arr_of_disp);
				arr_of_disp[0].fillDispatchers(arr_of_disp);
				main_menu();
				flag_exit = false;
			}
			if (choose == "Нет")
			{
				cout << "\n\tУдаление отменено";
				flag_exit = false;
			}
		}
		cout << endl;
		system("pause");
	}

	void menuAccount(vector<Dispatcher>& arr_of_disp)
	{
		int choice;
		bool flag_exit = true;
		while (flag_exit)
		{
			title("Меню работы с аккаунтом");
			cout << "  $                                                                       $" << endl;
			cout << "  $    0 - Назад                                                          $" << endl;
			cout << "  $    1 - Просмотр личных данных                                         $" << endl;
			cout << "  $    2 - Редактирование личных данных                                   $" << endl;
			cout << "  $    3 - Удаление аккаунта                                              $" << endl;
			cout << "  $                                                                       $" << endl;
			cout.fill('~');
			cout << "  " << setw(73) << "" << endl;
			cout.fill(' ');
			cout << "\n  Выберите пункт меню: ";
			choice = inputNumber(0, 3);
			switch (choice)
			{
			case 0: flag_exit = false; break;
			case 1:
			{
				this->showAccountInfo();
				cout << endl; system("pause");
			}
			break;
			case 2:
			{
				this->corAccount();
				this->writeDispatchers(arr_of_disp);
				cout << endl; system("pause");
			}
			break;
			case 3:
			{
				this->delAccount(arr_of_disp);
				cout << endl; system("pause");
			}
			break;
			default: false; cout << "\n\tВы ввели неверный параметр." << endl; break;
			}
		}
	}

	void menuData()
	{
		int choice;
		bool flag_exit = true;
		while (flag_exit)
		{
			title("Меню работы с данными");
			cout << "  $                                                                       $" << endl;
			cout << "  $    0 - Назад                                                          $" << endl;
			cout << "  $    1 - Добавить поезд                                                 $" << endl;
			cout << "  $    2 - Просмотреть поезда                                             $" << endl;
			cout << "  $    3 - Просмотреть станции                                            $" << endl;
			cout << "  $                                                                       $" << endl;
			cout.fill('~');
			cout << "  " << setw(73) << "" << endl;
			cout.fill(' ');
			cout << "\n  Выберите пункт меню: ";
			choice = inputNumber(0, 3);
			switch (choice)
			{
			case 0: flag_exit = false; break;
			case 1:
			{
				bool flag = true; int i = 0, k = 0;
				Train train; vector<Train> arr_of_train;
				train.fillTrains(arr_of_train);
				while (flag)
				{
					cout << "\n\tВведите номер поезда: ";
					train.setNumber(inputNumber(1, 1000));
					
					while (i < arr_of_train.size())
					{
						if (train.getNumber() == arr_of_train[i].getNumber())
						{
							cout << "\n\tТакой поезд уже есть!" << endl;
							k = 1;
							break;
						}
						
						i++;
					}
					if (k == 1) break;
					cout << "\n\tВведите количество станций маршрута(до 30): ";
					train.setStopoverNumber(inputNumber(1, 30));
					train.setRoute();

					ofstream file;
					file.open(PATH_FILE_OF_ROUTES);
					if (!file.is_open())
					{
						cout << "Не удалось открыть файл" << endl;
						exit(0);
					}
					train.setStopoverNumber(train.getStopoverNumber()+1);
					file << " " << train.getNumber() << " $ ";
					for (int i = 0; i < train.getStopoverNumber(); i++)
					{
						file << train.getRouteName(i) << " $ ";
						if (i != train.getStopoverNumber() - 1)
						{
							file << endl;
						}
					}
					file.close();
					
					int day1, month1, year1, sec1, min1, hour1,q=0, day2, month2, year2, sec2, min2, hour2;
					cout << "\n\tВведите дату отправления(день,месяц,год): ";
					day1 = inputNumber(1, 31); month1 = inputNumber(1, 12); year1 = inputNumber(2023, 2024);
					train.setArrDate(getDate(day1,month1,year1));
					while (q != 1)
					{                              
						cout << "\n\tВведите дату прибытия(день,месяц,год): ";
						day2 = inputNumber(1, 31); month2 = inputNumber(1, 12); year2 = inputNumber(2023, 2024);
						if (year2 == year1)
						{
							if (month2 == month1)
							{
								if (day2 == day1) q = 0;
								else
								{
									if (day2 < day1) q = 0;
									else
									{
										if (day2 > day1) q = 1;
									}
								}
							}
							else
							{
								if (month2 < month1) q = 0;
								else
								{
									if (month2 > month1) q = 1;
								}
							}
						}
						else
						{
							if (year2 < year1) q = 0;
							else
							{
								if (year2 > year1) q = 1;
							}
						}
					}
					train.setDepDate(getDate(day2, month2, year2));
					cout << "\n\tВведите время отправления(часы,минуты,секунды): ";
					hour1 = inputNumber(1, 24); min1 = inputNumber(1, 60); sec1 = inputNumber(1, 60);
					train.setArrTime(getTime(sec1, min1, hour1));
					cout << "\n\tВведите время прибытия(часы,минуты,секунды): ";
					hour2 = inputNumber(1, 24);  min2 = inputNumber(1, 60); sec2 = inputNumber(1, 60);
					train.setDepTime(getTime(sec2, min2, hour2));
					int number_of_vans;
					cout << "\n\tВведите количество вагонов(до 15): ";
					number_of_vans = inputNumber(1, 15);
					train.setVans(number_of_vans);


					if (k == 0)
					{
						arr_of_train.push_back(train);
						train.addTrain();
						flag = false;
					}
					
				}
				cout << endl; system("pause");
			}
			break;
			case 2:
			{
				Train train; vector<Train> arr_of_train;
				train.fillTrains(arr_of_train);
				if (arr_of_train.size() > 0)
				{
					train.showTrainsInfo(arr_of_train);
				}
				else cout << "\n\tПоезда отсутствуют!" << endl;
				cout << endl; system("pause");
			}
			break;
			case 3:
			{
				Stopover stop; vector<Stopover> arr_of_stop;
				stop.fillStopovers(arr_of_stop);
				if (arr_of_stop.size() > 0)
				{
					stop.showStopoversInfo(arr_of_stop);
				}
				else cout << "\n\tСтанции отсутсвуют!" << endl;
				cout << endl; system("pause");
			}
			break;
			default: false; cout << "\n\tВы ввели неверный параметр." << endl; break;
			}
		}
	}



	//void addTicket() override
	//{
	//	string current_key;
	//	while (current_attempt < 3)
	//	{
	//		cout << "Enter key: ";
	//		getline(cin, current_key);
	//		if (current_key == this->key)
	//		{
	//			cout << "Enter number of train";
	//		}
	//		else
	//		{
	//			cout << "Not avaliable key, repid enter!" << endl;
	//			current_attempt++;
	//		}
	//		if (current_attempt == 3)
	//		{
	//			cout << "\tПовторите вход!\n";
	//			system("pause");
	//			//main_menu();
	//		}
	//		current_attempt = 0;
	//	}
	//}

	friend ostream& operator<<(ostream& s, Dispatcher& disp)
	{
		s << " " << disp.authorization.getId() << " $ " << disp.authorization.getLogin() << " $ "
			<< encryptPassword(disp.authorization.getPassword(), encryption_key) << " $ " << disp.getSurname() << " $ " << disp.getName() << " $ "
			<< disp.getPatronimic() << " $ " << encryptPassword(disp.getKey(), encryption_key) << " $ " << disp.authorization.getAccess() << " $";
		return s;
	}

	friend istream& operator>>(istream& s, Dispatcher& disp)
	{
		string temp;

		//getline(s, temp, ' '); 
		getline(s, temp, ' ');

		if (!s.good() || s.eof())
		{
			return s;
		}

		number_of_disp++;

		disp.authorization.setRole(1);

		//s.get();
		getline(s, temp, '$');
		temp.pop_back();
		disp.authorization.setId(stoi(temp));

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		disp.authorization.setLogin(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		disp.authorization.setPassword(decryptPassword(temp, encryption_key));

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		disp.setSurname(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		disp.setName(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		disp.setPatronimic(temp);

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		disp.setKey(decryptPassword(temp, encryption_key));

		s.get();
		getline(s, temp, '$');
		temp.pop_back();
		disp.authorization.setAccess(stoi(temp));

		return s;
	}

	static void fillDispatchers(vector<Dispatcher>& arr_of_disp)
	{
		Dispatcher disp; int mark = 0;
		ifstream file;
		file.open(PATH_FILE_OF_DISPATCHERS);//("Dispatcher.txt");
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}

		number_of_disp = 0;
		arr_of_disp.clear();

		while (file >> disp && mark!=1)
		{
			arr_of_disp.push_back(disp); 
			if (file.eof()) { mark = 1; break; }
			//if (!file.good()) break;
		}
		file.close();
	}

	static void writeDispatchers(vector<Dispatcher>& arr_of_disp)
	{
		ofstream file;
		file.open(PATH_FILE_OF_DISPATCHERS);//("Dispatcher.txt");
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}

		number_of_disp = 0;

		for (int i = 0; i < arr_of_disp.size(); i++)
		{
			number_of_disp++;
			file << arr_of_disp[i];
			if (i != arr_of_disp.size() - 1)
			{
				file << endl;
			}
		}
		file.close();
	}

	void addDispatcher()
	{
		ofstream file;
		file.open(PATH_FILE_OF_DISPATCHERS, ios::app);//("Dispatcher.txt");
		if (!file.is_open())
		{
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}
		number_of_disp++;

		file.seekp(0, ios::end);
		if (file.tellp() == 0)
		{

			file << *this;
		}
		else
		{
			file << endl << *this;
		}
		file.close();
	}

};




extern void regisration(vector<Passenger>& arr_of_pass, vector<Dispatcher>& arr_of_disp);
extern void authorization(vector<Passenger>& arr_of_pass, vector<Dispatcher>& arr_of_disp);

extern void menuPassenger(vector<Passenger>& arr_of_pass);
extern void menuDispatcher(vector<Passenger>& arr_of_pass, vector<Dispatcher>& arr_of_disp);







//extern string encryptPassword(const string& password, const string& key);
//extern string decryptPassword(const string& encryptedPassword, const string& key);



//extern void menuAccount(vector<Passenger>& arr_of_pass, vector<Dispatcher>& arr_of_disp);
//extern void writeFIOToFile(const string& filename, const string& firstName, const string& lastName, const string& middleName);
//extern void writeEncryptedPasswordToFile(const string& filename, const int& id, const string& encryptedPassword);

//class Date
//{
//	int day;
//	int month;
//	int year;
//public:
//	Date() : day(0), month(0), year(0) {}
//	Date(int year, int month, int day) : day(day), month(month), year(year) {}
//	Date(const Date& other)
//	{
//		this->day = other.day;
//		this->month = other.month;
//		this->year = other.year;
//	}
//
//	void setDay(int day) { this->day = day; }
//	int getDay() { return this->day; }
//
//	void setMonth(int month) { this->month = month; }
//	int getMonth() { return this->month; }
//
//	void setYear(int year) { this->year = year; }
//	int getYear() { return this->year; }
//
//
//};
//
//class Time
//{
//	int seconds;
//	int minutes;
//	int hours;
//public:
//	Time() : seconds(0), minutes(0), hours(0) {}
//	Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {}
//	Time(const Time& other)
//	{
//		this->hours = other.hours;
//		this->minutes = other.minutes;
//		this->seconds = other.seconds;
//	}
//
//	void setHours(int hours) { this->hours = hours; }
//	int getHours() { return this->hours; }
//
//	void setMinutes(int minutes) { this->minutes = minutes; }
//	int getMinutes() { return this->minutes; }
//
//	void setSeconds(int seconds) { this->minutes; }
//	int getSeconds() { return this->seconds; }
//
//
//};
