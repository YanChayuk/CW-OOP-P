#include"Header.h"
//#include <thread>

#define BLACK_TEXT      0
#define BLUE_TEXT       FOREGROUND_BLUE
#define GREEN_TEXT      FOREGROUND_GREEN
#define CYAN_TEXT       (FOREGROUND_GREEN | FOREGROUND_BLUE)
#define RED_TEXT        FOREGROUND_RED
#define MAGENTA_TEXT    (FOREGROUND_RED | FOREGROUND_BLUE)
#define YELLOW_TEXT     (FOREGROUND_RED | FOREGROUND_GREEN)
#define WHITE_TEXT      (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

#define BLACK_BACKGROUND       0
#define BLUE_BACKGROUND        BACKGROUND_BLUE
#define GREEN_BACKGROUND       BACKGROUND_GREEN
#define CYAN_BACKGROUND        (BACKGROUND_GREEN | BACKGROUND_BLUE)
#define RED_BACKGROUND         BACKGROUND_RED
#define MAGENTA_BACKGROUND     (BACKGROUND_RED | BACKGROUND_BLUE)
#define YELLOW_BACKGROUND      (BACKGROUND_RED | BACKGROUND_GREEN)
#define WHITE_BACKGROUND       (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE)

using namespace std;

/*
 

     cout<<":----:  :----:                                                " << endl
     cout<<" +++++   +++++                                                " << endl
     cout<<"  +++++   +++++                                               " << endl
     cout<<"   -----   -----                                              " << endl 
     cout<<":::::::::::::::    .:::::::::::::::::::   =+=+++++   =+=   =+=" << endl
     cout<<"+++++++++++++   .:+++++++++++++++++++++   =+=        =+=   =+=" << endl
     cout<<"+++++++++++   .++++++++++++++++++++++++   =+=        =+=   =+=" << endl
     cout<<"            ++++++                        =+=++++:   =+=:::=+=" << endl 
     cout<<"++++++++  +++++++   +++++++++++++++++++   =+=   ++:        =+=" << endl 
     cout<<"+++++++  ++++++   +++++++++++++++++++++   =+=   ++:        =+=" << endl 
     cout<<"::::::  +++++   +++++::::::::::::::::::   =+=++++:         =+=" << endl   
     cout<<"       :++++   +++++:                                         " << endl 
     cout<<"       :+++:  :++++:                                          " << endl
     cout<<"       :---:  :----:                                          " << endl


 cout << "============================================================================" << endl;  Sleep(700);
 cout << "======     ==      =========================================================" << endl;  Sleep(700);
 cout << "=======     ==      ========================================================" << endl;  Sleep(700);
 cout << "========     ==      =======================================================" << endl;  Sleep(700);
 cout << "=========     ==      ======================================================" << endl;  Sleep(700);
 cout << "=====                 -+++-                    ===         ===   +=+   =====" << endl;  Sleep(700);
 cout << "=====               -+-                        ===   =========   +=+   =====" << endl;  Sleep(700);
 cout << "=====            -+-                           ===   =========   +=+   =====" << endl;  Sleep(700);
 cout << "=====++++++++++++-         ++++++++++++++++++++===         ===         =====" << endl;  Sleep(700);
 cout << "=====         -+-       -+-                    ===   +=+    ========   =====" << endl;  Sleep(700);
 cout << "=====        -+-      -+-                      ===   +=+    ========   =====" << endl;  Sleep(700);
 cout << "=====      -+-      -+-                        ===         =========   =====" << endl;  Sleep(700);
 cout << "=============      -+-     =================================================" << endl;  Sleep(700);
 cout << "=============     -+-     ==================================================" << endl;  Sleep(700);
 cout << "=============     -+-     ==================================================" << endl;  Sleep(700);
 cout << "============================================================================" << endl;  Sleep(700);

  
     $$        __  
  $$$$ $$$$$$$ |_  |_|
  $$$ $$$$$$$$ |_)   |
     $$

*/

void authorization(vector<Passenger>& arr_of_pass, vector<Dispatcher>& arr_of_disp)
{
    Passenger pass; Dispatcher disp;
    pass.fillPassengers(arr_of_pass); disp.fillDispatchers(arr_of_disp);
    int current_access = 1, i = 0;
    current_role = -1; current_attempt = 0;
    string current_password, current_login;
    title("Авторизация");
    cout << "\n\tВведите ваш логин  - "; 
    current_login = inputStringLogin();
    current_attempt = 0;
    cout << "\n\tВведите ваш пароль - ";
    current_password = passwordEncryption();
    current_attempt = 0;
    Authorization::total_number_of_account = arr_of_pass.size() + arr_of_disp.size();
    while (i < Authorization::total_number_of_account && current_role == -1)
    {
        if (i < arr_of_pass.size() && arr_of_pass[i].authorization.getLogin() == current_login && arr_of_pass[i].authorization.getPassword() == current_password )
        {
            current_role = arr_of_pass[i].authorization.getRole();
            current_access = arr_of_pass[i].authorization.getAccess();
            current_i = i;
        }
        else
        {
            if (i < arr_of_disp.size() && arr_of_disp[i].authorization.getLogin() == current_login && arr_of_disp[i].authorization.getPassword() == current_password )
            {
                current_role = arr_of_disp[i].authorization.getRole();
                current_access = arr_of_disp[i].authorization.getAccess();
                current_i = i;
            }
            else i++;
        }
    }
    if (current_role == -1)
    {
        cout << endl << "\n\tПользователя с таким логином и паролем не существует." << endl << endl;
        current_login = "";
        system("pause");
        main_menu();
    }
    else
    {
        if (current_access == 1)
        {
            if (current_role == 1)
            {
                cout << "\n\n\tВы вошли как администратор - " << current_login << endl << endl;
                system("pause");
                menuDispatcher(arr_of_pass, arr_of_disp);
            }
            if (current_role == 0)
            {
                cout << "\n\n\tВы вошли как пользователь - " << current_login << endl << endl;
                system("pause");
                menuPassenger(arr_of_pass);
            }
        }
        else
        {
            cout << "\n\n\tПользователь с таким логином и паролем заблокирован." << endl << endl;
            current_role = -1;
            system("pause");
            main_menu();
        }
    }
}

void regisration(vector<Passenger>& arr_of_pass, vector<Dispatcher>& arr_of_disp)
{
    int new_role, new_access, mark = 0, i = 0, j = 0;
    string new_login, new_password;
    title("Регистрация нового пользователя");
    cout << "\n\tВведите новый логин  - ";
    new_login = inputStringLogin();
    cout << "\n\tВведите новый пароль - ";
    new_password = inputStringPassword();
    i = 0; j = 0;
    while (i < arr_of_pass.size() || j < arr_of_disp.size())
    {
        if (i < arr_of_pass.size() && arr_of_pass[i].authorization.getLogin() == new_login )
        {
            cout << "\nPASS с таким логином уже существует" << endl;
            Sleep(10);
            i = Passenger::number_of_pass;
            mark = 1;
            break;
        }
        else
        {
            i++;
            if (j < arr_of_disp.size() && arr_of_disp[j].authorization.getLogin() == new_login )
            {
                cout << "\nDISP с таким логином уже существует"<< endl;
                Sleep(10);
                j = Dispatcher::number_of_disp;
                mark = 1;
                break;
            }
            else j++;
        }
    }
    if (current_role == 1 && mark == 0 && arr_of_disp.size() < 51) //number_of_disp < RESERVE_SIZE - number_of_pass)
    {
        new_role = 1;
        new_access = 1;
        int new_id = (Dispatcher::number_of_disp+1) * 10 + 1;
        string new_name, new_surname, new_patronimic, new_key;
        Dispatcher new_disp;
        new_disp.authorization.setLogin(new_login);
        new_disp.authorization.setPassword(new_password);
        new_disp.authorization.setRole(new_role);
        new_disp.authorization.setAccess(new_access);
        new_disp.authorization.setId(new_id);
        cout << "\n\tВведите фамилию: ";
        new_surname = inputString();
        cout << "\n\tВведите имя: ";
        new_name = inputString();
        cout << "\n\tВведите отчество: ";
        new_patronimic = inputString();
        cout << "\n\tВведите ключ доступа: ";
        new_key = inputString();
        new_disp.setName(new_name); new_disp.setSurname(new_surname); new_disp.setPatronimic(new_patronimic); new_disp.setKey(new_key);
        
        cout << "\n\n\tDISP успешно добавлен" << endl << endl;
        
        arr_of_disp.push_back(new_disp);
        new_disp.addDispatcher();
        system("pause");
    }
    if (current_role == 0 && mark == 0 && arr_of_pass.size() < 51) //&& number_of_pass < RESERVE_SIZE - number_of_disp)
    {
        new_role = 0;
        new_access = 1;
        int new_id = (Passenger::number_of_pass+1) * 10;
        string new_name, new_surname, new_patronimic, new_mail, new_phone, new_passport;
        Passenger new_pass;
        new_pass.authorization.setLogin(new_login);
        new_pass.authorization.setPassword(new_password);
        new_pass.authorization.setRole(new_role);
        new_pass.authorization.setAccess(new_access);
        new_pass.authorization.setId(new_id);
        
        cout << "\n\tВведите фамилию: ";
        new_surname = inputString();
        cout << "\n\tВведите имя: ";
        new_name = inputString();
        cout << "\n\tВведите отчество: ";
        new_patronimic = inputString();
        cout << "\n\tВведите почту: ";
        new_mail = inputStringMail();
        cout << "\n\tВведите номер телефона: ";
        new_phone = inputStringMail();
        cout << "\n\tВведите серию и номер паспорта: ";
        new_passport = inputStringLogin();
        
        new_pass.setName(new_name); new_pass.setSurname(new_surname); new_pass.setPatronimic(new_patronimic);
        new_pass.setMail(new_mail); new_pass.setPhoneNumber(new_phone); new_pass.setPassportData(new_passport);
        cout << "\n\n\tPASS успешно добавлен" << endl << endl;
        
        arr_of_pass.push_back(new_pass);
        new_pass.addPassenger();
        system("pause");
    }
}

void title(const string text_zagolovok)
{
    system("cls");
    cout.fill('~');
    cout << "  " << setw(73) << "" << endl;
    cout << "  $                             $$        __                              $" << endl; //75   
    cout << "  $                          $$$$ $$$$$$$ |_  |_|                         $" << endl;
    cout << "  $                          $$$ $$$$$$$$ |_)   |                         $" << endl;
    cout << "  $                             $$                                        $" << endl;
    cout << "  " << setw(73) << "" << endl;
    if (current_login != "")
    {
        cout.fill(' ');
        cout << "  $\t" << setw(37) << current_login << setw(30) << "$" << endl;
        cout.fill('~');
        cout << "  " << setw(73) << "" << endl;
    }
    cout << "  $                   Билетные операции на ж/д станции                    $" << endl;
    cout << "  " << setw(73) << "" << endl;
    cout.fill(' ');
    cout << "  $\t" << setw(37) << text_zagolovok << setw(30)<<"$" << endl;
    cout.fill('~');
    cout << "  " << setw(73) << "" << endl;
}

void intro()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, WHITE_BACKGROUND | BLUE_TEXT);

    system("cls");
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t\t\t" << ":----:  :----:                                                " << endl; Sleep(500);
    cout << "\t\t\t\t\t\t" << " +++++   +++++                                                " << endl; Sleep(500);
    cout << "\t\t\t\t\t\t" << "  +++++   +++++                                               " << endl; Sleep(500);
    cout << "\t\t\t\t\t\t" << "   -----   -----                                              " << endl; Sleep(500);
    cout << "\t\t\t\t\t\t" << ":::::::::::::::    .:::::::::::::::::::   =+=+++++   =+=   =+=" << endl; Sleep(500);
    cout << "\t\t\t\t\t\t" << "+++++++++++++   .:+++++++++++++++++++++   =+=        =+=   =+=" << endl; Sleep(500);
    cout << "\t\t\t\t\t\t" << "+++++++++++   .++++++++++++++++++++++++   =+=        =+=   =+=" << endl; Sleep(500);
    cout << "\t\t\t\t\t\t" << "            ++++++                        =+=++++:   =+=:::=+=" << endl; Sleep(500);
    cout << "\t\t\t\t\t\t" << "++++++++  +++++++   +++++++++++++++++++   =+=   ++:        =+=" << endl; Sleep(500);
    cout << "\t\t\t\t\t\t" << "+++++++  ++++++   +++++++++++++++++++++   =+=   ++:        =+=" << endl; Sleep(500);
    cout << "\t\t\t\t\t\t" << "::::::  +++++   +++++::::::::::::::::::   =+=++++:         =+=" << endl; Sleep(500);
    cout << "\t\t\t\t\t\t" << "       :++++   +++++:                                         " << endl; Sleep(500);
    cout << "\t\t\t\t\t\t" << "       :+++:  :++++:                                          " << endl; Sleep(500);
    cout << "\t\t\t\t\t\t" << "       :---:  :----:                                          " << endl;
    Sleep(3000);
    system("cls");
    /*cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t\t" << "============================================================================" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "======     ==      =========================================================" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "=======     ==      ========================================================" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "========     ==      =======================================================" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "=========     ==      ======================================================" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "=====                 -+++-                    ===         ===   +=+   =====" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "=====               -+-                        ===   =========   +=+   =====" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "=====            -+-                           ===   =========   +=+   =====" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "=====++++++++++++-         ++++++++++++++++++++===         ===         =====" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "=====         -+-       -+-                    ===   +=+    ========   =====" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "=====        -+-      -+-                      ===   +=+    ========   =====" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "=====      -+-      -+-                        ===         =========   =====" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "=============      -+-     =================================================" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "=============     -+-     ==================================================" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "=============     -+-     ==================================================" << endl;  Sleep(700);
    cout << "\t\t\t\t\t" << "============================================================================" << endl;
    Sleep(3000);
    system("cls");*/
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    wcout << L"\t\t\t\t\t\t\t\t\tСардэчна вітаю!" << endl; Sleep(3000);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    system("color F5");
}

//void editPaintings()
//{
//    printPaintings();
//    int choice;
//    cout << "Выберите номер записи для редактирования(0 для пропуска редактирования): ";
//    cin >> choice;
//
//    if (choice == 0)
//        return;
//
//    if (choice<0 || choice > authors_of_paintings.size())
//        return;
//
//    Accessory new_author;
//    cin.get();
//    new_author.editAuthor();
//
//    authors_of_paintings.insert(authors_of_paintings.begin() + choice - 1, new_author);
//    authors_of_paintings.erase(authors_of_paintings.begin() + choice);
//
//
//    Smartphone* new_painting = new Smartphone();
//    new_painting->editExhibit();
//
//    vec_of_paintings.insert(vec_of_paintings.begin() + choice - 1, *new_painting);
//    vec_of_paintings.erase(vec_of_paintings.begin() + choice);
//
//    delete new_painting;
//}
//
//
//void editFile()
//{
//    Catalog temp_exhibition;
//
//    temp_exhibition.readFile();
//
//    cout.setf(ios::right);
//    cout.width(47);
//    cout << temp_exhibition.getExhibition() << endl
//        << setw(45) << temp_exhibition.getLocation() << endl;
//
//    temp_exhibition.editPaintings();
//    cout << endl << endl;
//    temp_exhibition.editSculptures();
//
//
//    ofstream fout(FILE_OF_EXHIBITIONS, ios::out);
//
//    for (int i = 0; i < temp_exhibition.authors_of_paintings.size(); i++)
//    {
//        fout << temp_exhibition.authors_of_paintings[i].getName() << endl
//            << temp_exhibition.authors_of_paintings[i].getStyle() << endl
//            << temp_exhibition.vec_of_paintings[i].getExhibit() << endl
//            << temp_exhibition.vec_of_paintings[i].getGenre() << endl;
//    }
//
//    for (int i = 0; i < temp_exhibition.authors_of_paintings.size(); i++)
//    {
//        if (i == temp_exhibition.authors_of_paintings.size() - 1)
//        {
//            fout << temp_exhibition.authors_of_sculptures[i].getName() << endl
//                << temp_exhibition.authors_of_sculptures[i].getStyle() << endl
//                << temp_exhibition.vec_of_sculptures[i].getExhibit() << endl
//                << temp_exhibition.vec_of_sculptures[i].getMaterial();
//        }
//        else
//        {
//            fout << temp_exhibition.authors_of_sculptures[i].getName() << endl
//                << temp_exhibition.authors_of_sculptures[i].getStyle() << endl
//                << temp_exhibition.vec_of_sculptures[i].getExhibit() << endl
//                << temp_exhibition.vec_of_sculptures[i].getMaterial() << endl;
//        }
//    }
//
//    fout.close();
//}
//
//void deleteFromFile()
//{
//    Catalog temp_exhibition;
//
//    temp_exhibition.readFile();
//
//    cout.setf(ios::right);
//    cout.width(47);
//    cout << temp_exhibition.getExhibition() << endl
//        << setw(45) << temp_exhibition.getLocation() << endl;
//
//    temp_exhibition.deletePainting();
//    cout << endl << endl;
//    temp_exhibition.deleteSculpture();
//
//
//    ofstream fout(FILE_OF_EXHIBITIONS, ios::out);
//
//    for (int i = 0; i < temp_exhibition.authors_of_paintings.size(); i++)
//    {
//        fout << temp_exhibition.authors_of_paintings[i].getName() << endl
//            << temp_exhibition.authors_of_paintings[i].getStyle() << endl
//            << temp_exhibition.vec_of_paintings[i].getExhibit() << endl
//            << temp_exhibition.vec_of_paintings[i].getGenre() << endl;
//    }
//
//    for (int i = 0; i < temp_exhibition.authors_of_paintings.size(); i++)
//    {
//        if (i == temp_exhibition.authors_of_paintings.size() - 1)
//        {
//            fout << temp_exhibition.authors_of_sculptures[i].getName() << endl
//                << temp_exhibition.authors_of_sculptures[i].getStyle() << endl
//                << temp_exhibition.vec_of_sculptures[i].getExhibit() << endl
//                << temp_exhibition.vec_of_sculptures[i].getMaterial();
//        }
//        else
//        {
//            fout << temp_exhibition.authors_of_sculptures[i].getName() << endl
//                << temp_exhibition.authors_of_sculptures[i].getStyle() << endl
//                << temp_exhibition.vec_of_sculptures[i].getExhibit() << endl
//                << temp_exhibition.vec_of_sculptures[i].getMaterial() << endl;
//        }
//    }
//
//    fout.close();
//}
//
//void searchFile()
//{
//
//    Catalog temp_exhibition;
//
//    temp_exhibition.readFile();
//
//    string str;
//    int choice = 0;
//
//    cout << "=======================================" << endl;
//    cout << "| 0.Выход.                            |" << endl;
//    cout << "| 1.Поиск по автору.                  |" << endl;
//    cout << "| 2.Поиск по названию картины.        |" << endl;
//    cout << "| 3.Поиск по названию скульптуры.     |" << endl;
//    cout << "=======================================" << endl;
//
//    while (true)
//    {
//        cout << "Выберите действие: ";
//        try
//        {
//            cin >> choice;
//
//            if (cin.fail())
//                throw runtime_error("Ошибка: некорректный ввод данных!");
//
//            cin.get();
//            break;
//        }
//        catch (const runtime_error& ex)
//        {
//            cerr << ex.what() << endl;
//            cin.clear();
//            cin.ignore(10, '\n');
//        }
//    }
//
//    cout << endl;
//
//    switch (choice)
//    {
//    case 0:
//        return;
//    case 1:
//        cout << "Введите автора: ";
//        getline(cin, str);
//
//        for (int i = 0; i < temp_exhibition.authors_of_paintings.size(); i++)
//        {
//            if (temp_exhibition.authors_of_paintings[i].getName().find(str) != -1)
//            {
//                cout << "Автор: " << temp_exhibition.authors_of_paintings[i].getName()
//                    << "	Жанр работ автора: " << temp_exhibition.authors_of_paintings[i].getStyle() << endl
//                    << "Картина: " << temp_exhibition.vec_of_paintings[i].getExhibit()
//                    << "	Жанр картины: " << temp_exhibition.vec_of_paintings[i].getGenre() << endl << endl;
//            }
//        }
//
//        for (int i = 0; i < temp_exhibition.authors_of_sculptures.size(); i++)
//        {
//            if (temp_exhibition.authors_of_sculptures[i].getName().find(str) != -1)
//            {
//                cout << "Автор: " << temp_exhibition.authors_of_sculptures[i].getName()
//                    << "	Жанр работ автора: " << temp_exhibition.authors_of_sculptures[i].getStyle() << endl
//                    << "Скульптура: " << temp_exhibition.vec_of_sculptures[i].getExhibit()
//                    << "	Материал скульптуры: " << temp_exhibition.vec_of_sculptures[i].getMaterial() << endl << endl;
//            }
//        }
//        break;
//    case 2:
//        cout << "Введите название картины: ";
//        getline(cin, str);
//
//        for (int i = 0; i < temp_exhibition.authors_of_paintings.size(); i++)
//        {
//            if (temp_exhibition.vec_of_paintings[i].getExhibit().find(str) != -1)
//            {
//                cout << "Автор: " << temp_exhibition.authors_of_paintings[i].getName()
//                    << "	Жанр работ автора: " << temp_exhibition.authors_of_paintings[i].getStyle() << endl
//                    << "Картина: " << temp_exhibition.vec_of_paintings[i].getExhibit()
//                    << "	Жанр картины: " << temp_exhibition.vec_of_paintings[i].getGenre() << endl << endl;
//            }
//        }
//        break;
//    case 3:
//        cout << "Введите название скульптуры: ";
//        getline(cin, str);
//
//        for (int i = 0; i < temp_exhibition.authors_of_sculptures.size(); i++)
//        {
//            if (temp_exhibition.vec_of_sculptures[i].getExhibit().find(str) != -1)
//            {
//                cout << "Автор: " << temp_exhibition.authors_of_sculptures[i].getName()
//                    << "	Жанр работ автора: " << temp_exhibition.authors_of_sculptures[i].getStyle() << endl
//                    << "Скульптура: " << temp_exhibition.vec_of_sculptures[i].getExhibit()
//                    << "	Материал скульптуры: " << temp_exhibition.vec_of_sculptures[i].getMaterial() << endl << endl;
//            }
//        }
//        break;
//    default:  cout << "Неверный выбор!" << endl; system("pause"); system("cls");
//    }
//}
//






string getDate(int day, int month, int year)
{
    return to_string(day) + '.' + to_string(month) + '.' + to_string(year);
}

string getTime(int sec, int min, int hour)
{
    return to_string(hour) + ':' + to_string(min) + ':' + to_string(sec);
}

