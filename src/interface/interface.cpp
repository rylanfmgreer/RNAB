#include "interface.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include "interface_phrases.hpp" 
#include "../transaction/transaction.hpp"

using namespace std;
using namespace RNAB_Phrases;

namespace RNAB
{
    Interface::Interface()
    :m_stay_alive(true)
    {
        //m_instance.read_data("MyCSV.csv");
        run();
    }

    void Interface::run()
    {
        greet();
        while(m_stay_alive)
            act();
    }
    void Interface::dump_data() const
    {
        m_instance.dump_data();
    }

    void Interface::greet() const
    {
        cout << GREETING;
    }

    void Interface::view_accounts() const
    {
        m_instance.print_accounts();
    }

    void Interface::view_budgets() const
    {
        m_instance.print_budgets();
    }

    void Interface::act()
    {
        std::cout << ACT_QUESTION;
        std::cout << OPTIONS;
        int option;
        std::cin >> option;
        if(option == 1)
            add_transaction();
        else if(option == 2)
            view_accounts();
        else if(option == 3)
            view_budgets();
        else if(option == 4)
            quit();
        else quit();
    }

    void Interface::quit()
    {
        m_stay_alive = false;
        std::cout << QUIT_GOODBYE;
        dump_data();
    }

    void Interface::add_transaction()
    {
        std::cout << ADD_TRANSACTION_PHRASE;
        int amount;
        std::string account, budget;

        std::cout << ADD_TRANSACTION_AMOUNT;
        std::cin >> amount;

        std::cout << ADD_TRANSACTION_BUDGET;
        std::cin >> budget;

        std::cout << ADD_TRANSACTION_ACCOUNT;
        std::cin >> account;

        Transaction this_transaction(amount, account, budget);
        m_instance.add_transaction(this_transaction);

    }
    void add_account(){}
    void add_budget(){}

    
} // namespace RNAB
