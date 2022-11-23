#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include "structures.cpp"
using namespace std;

// month theMonths[12] = {
//     {1, "January"}, {2, "February"},
//     {3, "March"}, {4, "April"},
//     {5, "May"}, {6, "June"},
//     {7, "July"}, {8, "August"},
//     {9, "September"}, {10, "October"},
//     {11, "November"}, {12, "Desember"}
// };

vector<string> theAccounts = {"Cash", "Bank", "Go-Pay"};
vector<string> theCategories = {"Food", "Transportation", "Household", "Education"};
vector<incomes> theIncomes;
vector<expenses> theExpenses;

/*=====================================================================================*/

fstream txt;
int mainMenu();
void inputIncome();
void getIncome();
void inputExpense();
string chooseCategory();
string chooseAccount();
bool compareDateNewest(const date &d1, const date &d2);

int mainMenu() {
    using namespace std;

    cout<< "========================\n"
        << "Welcome to Money Manager\n"
        << "========================\n";
    
    cout<< "1. Record Income\n"
        << "2. Record Expense\n"
        << "3. History\n"
        << "4. Statistics\n";
    cout<< "Which? ";
    
    int temp; cin >> temp;
    system("cls");

    return temp;
}

void inputIncome() {
    getIncome();
    
    incomes temp;
    cout << "Input date (dd mm yyyy):"; 
    cin >> temp.theDate.day >> temp.theDate.month >> temp.theDate.year;
    system("cls");
    cout << "Choose an Account:\n";
    temp.account = chooseAccount();
    system("cls");
    cout << "Input Amount:";
    cin >> temp.amount;
    system("cls");

    theIncomes.insert(theIncomes.begin(), temp);

    ofstream txt_income("./data/Incomes.txt");
    txt_income << "Date" << '\t' << "Account" << '\t' << "Amount\n";
    for (int i = 0; i < theIncomes.size(); i++) {
        txt_income  << theIncomes[i].theDate.day << '/' << theIncomes[i].theDate.month << '/'
                    << theIncomes[i].theDate.year << '\t' << theIncomes[i].account << '\t' 
                    << theIncomes[i].amount << '\n';
    }

    txt_income.close();

    theIncomes.clear();
}

void getIncome() {
    string top_line;
    string s_temp;
    incomes temp;
    int count = -1;
    txt.open("./data/Incomes.txt");

    while(getline(txt, top_line)) count++;

    theIncomes.clear();
    txt.clear();
    txt.seekg(0); getline(txt, top_line, '\n');

    for (int i = 0; i < count; i++) {
        getline(txt, s_temp, '/');
            temp.theDate.day = stoi(s_temp);
        getline(txt, s_temp, '/');
            temp.theDate.month = stoi(s_temp);
        getline(txt, s_temp, '\t');
            temp.theDate.year = stoi(s_temp);
        getline(txt, s_temp, '\t');
            temp.account = s_temp;
        getline(txt, s_temp, '\n');
            temp.amount = stod(s_temp);
        
        theIncomes.insert(theIncomes.begin(), temp);
    }

    txt.close();

    system("pause"); mainMenu();
}

// void inputExpense() {
//     expenses temp;
//     cout << "Input date (dd mm yyyy):"; 
//     cin >> temp.theDate.day >> temp.theDate.month >> temp.theDate.year;
//     system("cls");
//     cout << "Choose an Account:\n";
//     temp.account = chooseAccount();
//     system("cls");
//     cout << "choose a Category:\n";
//     temp.category = chooseCategory();
//     system("cls");
// }

string chooseCategory() {
    int n = theCategories.size();
    
    int i;
    for (i = 0; i < n; i++) {
        cout << i+1 << ". " << theCategories[i] << '\n';
    }
    cout << i+1 << ". Add Other\nCategory Account: ";
    int temp; cin >> temp; system("cls");

    if (temp > n) {
        string inp;
        cout << "Insert Category Name: "; cin >> inp;
        theCategories.push_back(inp);
        system("cls");
        return chooseCategory();
    }
    else return theCategories[temp-1];
}

string chooseAccount() {
    int n = theAccounts.size();
    
    int i;
    for (i = 0; i < n; i++) {
        cout << i+1 << ". " << theAccounts[i] << '\n';
    }
    cout << i+1 << ". Add Other\nChoose Account: ";
    int temp; cin >> temp; system("cls");

    if (temp > n) {
        string inp;
        cout << "Insert Account Name: "; cin >> inp;
        theAccounts.push_back(inp);
        system("cls");
        return chooseAccount();
    }
    else return theAccounts[temp-1];
}

bool compareDateNewest(const date &d1, const date &d2) {
    if (d1.year > d2.year)
        return true;
    if (d1.year == d2.year && d1.month > d2.month)
        return true;
    if (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day)
        return true;

    return false;
}
