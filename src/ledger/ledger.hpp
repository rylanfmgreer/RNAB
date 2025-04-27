#pragma once
#ifndef RNAB_LEDGER
#define RNAB_LEDGER

#include "../transaction/transaction.hpp"
#include <string>
#include <vector>
namespace RNAB
{
    typedef std::shared_ptr<Transaction> TransactionPtr;
    class Ledger
    {  
        public:
        Ledger(){}
        int get_sum_of_transactions() const;
        void add_transaction(TransactionPtr p_transaction) { m_transactions.push_back(p_transaction); }
        virtual bool transaction_belongs(TransactionPtr p_transaction){ return true; }
        void add_transaction_if_belongs(TransactionPtr p_transaction);
        virtual void text_representation_of_self() const{}

        private:
        std::vector<TransactionPtr> m_transactions;
        void filter_transactions();

    };

    class AccountLedger : public Ledger
    {
        public:
        AccountLedger(std::string p_account) : m_account(p_account){}
        virtual bool transaction_belongs(TransactionPtr p_transaction){ return p_transaction->get_account() == m_account; }
        virtual void text_representation_of_self() const;
        private:
        std::string m_account;
    };

    class BudgetLedger : public Ledger
    {
        public:
        BudgetLedger(std::string p_budget) : m_budget(p_budget){}
        virtual bool transaction_belongs(TransactionPtr p_transaction){ return p_transaction->get_account() == m_budget; }
        virtual void text_representation_of_self() const;

        private:
        std::string m_budget;
    };
    
} // namespace RNAB

#endif