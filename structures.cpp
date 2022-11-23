#include <cstring>
using namespace std;

struct date {
    int day, month, year;
};

struct incomes {
    date theDate;
    string account;
    double amount;
};

struct expenses {
    date theDate;
    string account;
    string category;
    double amount;
};

struct accounts {
    int year;
    int month;
    string account;
    double total;
};

struct categories {
    int year;
    int month;
    string category;
    double total;
};

struct month {
    int index;
    string name;
};
