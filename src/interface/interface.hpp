#pragma once
#ifndef RNAB_INTERFACE
#define RNAB_INTERFACE
#include "../instance/instance.hpp"

namespace RNAB
{
    class Interface
    {
        public:
        Interface();

        private:
        void greet() const;
        void print_options() const;
        void view_accounts() const;
        void view_budgets() const;
        void add_transaction();
        void add_account();
        void add_budget();
        
        void run();
        void quit();
        void act();

        Instance m_instance;
        bool m_stay_alive;

    };
    
} // namespace RNAB

#endif