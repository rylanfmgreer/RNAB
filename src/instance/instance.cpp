#include "instance.hpp"
#include <fstream>
#include <algorithm>
namespace RNAB
{
    void Instance::add_account_if_not_exists(const std::string p_account_name)
    {
        std::vector<std::string> accounts = get_account_names();
        auto loc = std::find(accounts.begin(), accounts.end(), p_account_name);
        if(loc == accounts.end())
        {
            AccountLedger new_account(p_account_name);
            m_account_ledgers.push_back(new_account);
        }
    }

    void Instance::add_budget_if_not_exists(const std::string p_budget_name)
    {
        std::vector<std::string> budgets = get_budget_names();
        auto loc = std::find(budgets.begin(), budgets.end(), p_budget_name);
        if(loc == budgets.end())
        {
            BudgetLedger new_budget(p_budget_name);
            m_budget_ledgers.push_back(new_budget);
        }
    }

    std::vector<std::string> Instance::get_budget_names() const
    {
        std::vector<std::string> these_names(m_budget_ledgers.size());
        std::transform(m_budget_ledgers.begin(), m_budget_ledgers.end(), these_names.begin(), [](BudgetLedger t){ return t.get_name();});
        return these_names;
    }

    std::vector<std::string> Instance::get_account_names() const
    {
        std::vector<std::string> these_names(m_account_ledgers.size());
        std::transform(m_account_ledgers.begin(), m_account_ledgers.end(), these_names.begin(), [](AccountLedger t){ return t.get_name();});
        return these_names;
    }

    void Instance::add_transaction(Transaction& p_transaction)
    {
        TransactionPtr this_transaction(new Transaction(p_transaction));
        add_budget_if_not_exists(this_transaction->get_budget());
        add_account_if_not_exists(this_transaction->get_account());
        add_transaction(this_transaction);
    }

    void Instance::add_transaction(TransactionPtr p_transaction)
    {
        m_master_ledger.add_transaction(p_transaction);

        for(size_t i(0); i < m_account_ledgers.size(); ++i)
            m_account_ledgers[i].add_transaction_if_belongs(p_transaction);

        for(size_t i(0); i < m_budget_ledgers.size(); ++i)
            m_budget_ledgers[i].add_transaction_if_belongs(p_transaction);      
    }

    void Instance::print_accounts() const
    {
        for(int i(0); i < m_account_ledgers.size(); ++i)
            m_account_ledgers[i].text_representation_of_self();
    }

    void Instance::print_budgets() const
    {
        for(int i(0); i < m_budget_ledgers.size(); ++i)
            m_budget_ledgers[i].text_representation_of_self();
    }

}