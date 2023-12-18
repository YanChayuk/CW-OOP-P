#include"Header.h"

using namespace std;

int Authorization::total_number_of_account = 0;
int Passenger::number_of_pass = 0;
int Dispatcher::number_of_disp = 0;
int Ticket::number_of_tickets = 0;
int Van::number_of_vans = 0;
int Train::number_of_trains = 0;

int main()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("chcp 1251");
	//system("cls");
	system("color F5");
	current_login[0] = '\0';
	current_role = -1;
	current_i = 0;
	current_attempt = 0;
	cout.fill('~');

	intro();
	main_menu();
	
	return 0;
}

void main_menu()
{
	vector<Passenger> arr_of_pass;
	arr_of_pass.reserve(10);
	vector<Dispatcher> arr_of_disp;
	arr_of_disp.reserve(10);
	int choice = 0;
	bool flag_exit = true;

	Passenger pass; Dispatcher disp;

	//pass.setName("user"); pass.setSurname("user"); pass.setPatronimic("user"); pass.setPhoneNumber("+375(33)245-87-09"); pass.setPassportData("AB4476520"); pass.setMail("user@mail.ru"); pass.authorization->setId(10); pass.authorization->setAccess(1); pass.authorization->setLogin("user1234"); pass.authorization->setPassword("user1234"); pass.authorization->setRole(0);
	//pass.addPassenger();
	//disp.setName("admin"); disp.setSurname("admin"); disp.setPatronimic("admin"); disp.authorization->setId(11); disp.authorization->setAccess(1); disp.authorization->setLogin("admin1234"); disp.authorization->setPassword("admin1234"); disp.authorization->setRole(1); disp.setKey("admin");
	//disp.addDispatcher();

	pass.fillPassengers(arr_of_pass); disp.fillDispatchers(arr_of_disp);
	while (true)
	{
		title("Основное меню");
		cout << "  $                                                                       $\n";
		cout << "  $    0 - Выход                                                          $\n";
		cout << "  $    1 - Авторизация                                                    $\n";
		cout << "  $    2 - Регистрация пользователем                                      $\n";
		cout << "  $                                                                       $\n";
		cout.fill('~');
		cout << "  " << setw(73) << "" << endl;
		cout.fill(' ');
		cout << "\n  Выберите пункт меню: ";
		choice = inputNumber(0, 2);
		switch (choice)
		{
		case 0: exit(1); break;
		case 1: authorization(arr_of_pass, arr_of_disp); break;
		case 2: regisration(arr_of_pass, arr_of_disp); break;
		}
	}
}

void menuPassenger(vector<Passenger>& arr_of_pass)
{
	vector<Ticket> order;
	order.reserve(10);
	Train train; vector<Train> arr_of_train; train.fillTrains(arr_of_train);
	int choice = 0, cur_i = 0, i_van = 0;;
	bool flag_exit = true;
	while (flag_exit)
	{
		title("Меню пассажира");
		cout << "  $                                                                       $\n";
		cout << "  $    0 - Назад                                                          $\n";
		cout << "  $    1 - Личный кабинет                                                 $\n";
		cout << "  $    2 - Выбрать билет                                                  $\n";
		cout << "  $    3 - Сделать заказ                                                  $\n";
		cout << "  $                                                                       $\n";
		cout.fill('~');
		cout << "  " << setw(73) << "" << endl;
		cout.fill(' ');
		cout << "\n  Выберите пункт меню: ";
		choice = inputNumber(0, 3);
		switch (choice)
		{
		case 0: {current_role = -1; current_login = " "; flag_exit = false; } break;
		case 1:
		{
			arr_of_pass[current_i].menuAccount(arr_of_pass);
		}
		break;
		case 2: 
		{
			Ticket ticket;
			int i = 0, k = 0;
			ticket.enterRoute();

			if (train.showTrainsInfoByRoute(arr_of_train, ticket.getArrStop(), ticket.getDepStop()))
			{
				cout << "\n\tВыберите номер поезда: ";
				train.setNumber(inputNumber(1, 1000));
				while (i < arr_of_train.size())
				{
					if (train.getNumber() == arr_of_train[i].getNumber())
					{
						cur_i = i;
						k = 1;
					}
					i++;
				}
				if (k == 1)
				{
					int j = 0;
					cout << "\n\tВагоны:" << endl;
					while (j < arr_of_train[cur_i].getNumberVans())
					{
						cout << "[" << j + 1 << "]" << "  ";
					}
					cout << "\n\tВвыберите вагон: ";
					i_van = inputNumber(1, arr_of_train[cur_i].getNumberVans()) - 1;
					cout << "\n\tМеста:" << endl;
					j = 0;
					while (j < arr_of_train[cur_i].getNumberSeats(cur_i))
					{
						if (j == 15 || j == 30 || j == 45 || j == 60) cout << endl;
						cout << "[" << j + 1 << "]" << "  ";
					}
					cout << "\n\tВвыберите место: ";
					ticket.setPlace(inputNumber(1, arr_of_train[cur_i].getNumberSeats(cur_i)));
					ticket.enterRoute();
					ticket.setPrice(18.32 + cur_i*10);
					ticket.setNumber(100 * cur_i);
					ticket.setTariff("Полный");
					ticket.setArrDate(arr_of_train[cur_i].getArrDate());
					ticket.setDepDate(arr_of_train[cur_i].getDepDate());
					ticket.setArrTime(arr_of_train[cur_i].getArrTime());
					ticket.setDepTime(arr_of_train[cur_i].getDepTime());
					order.push_back(ticket);
					ticket.addTicket();
					cout << "\n\tВаш билет: " << endl;
					ticket.showTicketInfo();

				}
				else cout << "\n\tТакого поезда нет!" << endl;
			}
		}
		break;
		case 3:
		{
			string chose; float price = 0; int  i = 0;
			if (order.empty())
			{
				cout << "\n\tВы не выбрали билеты" << endl;
			}
			else
			{
				order[0].showTicketsInfo(order);
				cout << "\n\tОплатить заказ?(Да/Нет)" << endl << "\t";
				chose = inputString();
				if (chose == "Да")
				{
					while (i < order.size())
					{
						price = price + order[i].getPrice();
					}
					i = 0;
					while (i < order.size())
					{
						arr_of_train[cur_i].deleteSeat(order[i].getPlace(), i_van);
						i++;
					}
					order[0].writeTickets(order);
					arr_of_pass[current_i].pay(price);

					arr_of_train[cur_i].writeSeats();

					cout << "\n\tЗаказ оплачен\n";
				}
				if (chose == "Нет")
				{
					order.clear();
					cout << "\n\tЗаказ отменен\n";
				}
			}

		}
		break;
		default: cout << "Error" << endl;
		}
	}
}

void menuDispatcher(vector<Passenger>& arr_of_pass, vector<Dispatcher>& arr_of_disp)
{
	int choice;
	bool flag_exit = true;
	while (flag_exit)
	{
		title("Меню диспетчера");
		cout << "  $                                                                       $\n";
		cout << "  $    0 - Назад                                                          $\n";
		cout << "  $    1 - Личный кабинет                                                 $\n";
		cout << "  $    2 - Работа с данными                                               $\n";
		cout << "  $    3 - Добавить диспетчера                                            $\n";
		cout << "  $                                                                       $\n";
		cout.fill('~');
		cout << "  " << setw(73) << "" << endl;
		cout.fill(' ');
		cout << "\n  Выберите пункт меню: ";
		choice = inputNumber(0, 3);
		switch (choice)
		{
		case 0: {current_role = -1; current_login = " "; flag_exit = false; } break;
		case 1: arr_of_disp[current_i].menuAccount(arr_of_disp);
			break;
		case 2: arr_of_disp[current_i].menuData();
			break;
		case 3: regisration(arr_of_pass, arr_of_disp);
			break;
		default: cout << "Error" << endl;
		}
	}
}





