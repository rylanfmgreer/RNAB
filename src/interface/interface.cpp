#include "interface.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include "interface_phrases.hpp" 

using namespace std;
using namespace RNAB_Phrases;

namespace RNAB
{
    Interface::Interface()
    {
        run();
    }

    void Interface::run()
    {
        greet();
        while(m_stay_alive) act();
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
        quit();
    }

    void Interface::quit()
    {
        m_stay_alive = false;
        std::cout << QUIT_GOODBYE;
    }

    void add_transaction(){}
    void add_account(){}
    void add_budget(){}

    
} // namespace RNAB
