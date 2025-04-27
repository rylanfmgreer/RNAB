#pragma once
#ifndef TRANSACTION_RNAB
#define TRANSACTION_RNAB
#include <string>

namespace RNAB
{
    class  Transaction
    {
        //static int transaction_id;

        private:
        int m_value; // in cents;
        std::string m_account;
        std::string m_budget;
        int m_transaction_id;

        public:
        Transaction(int p_value, std::string p_account, std::string p_budget)
        :m_value(p_value), m_account(p_account), m_budget(p_budget){} // m_transaction_id = ++transaction_id; }


        public:
        int get_value() const{ return m_value; }
        void set_value(int p_new_value){m_value = p_new_value;}

        std::string get_account() const { return m_account; }
        void set_account(std::string p_new_account) { m_account = p_new_account; }

        std::string get_budget() const { return m_budget; }
        void set_budget(std::string p_new_budget) { m_budget = p_new_budget; }

        //int get_id() { return m_transaction_id; }


    };

    
} // namespace RNAB

#endif