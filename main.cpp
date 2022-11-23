#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.cpp"
using namespace std;

int main() {
    // fstream incomeData("./data/income.bin");
    // fstream expenseData("./data/expense.bin"); 
    // fstream accountData("./data/account.bin");

    int menu; menu = mainMenu();
    switch (menu)
    {
    case 1:
        inputIncome();
        break;
    // case 2:
    //     inputExpense();
    //     break;
    
    default:
        break;
    }

    return 0;
}