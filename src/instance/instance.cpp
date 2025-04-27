#include "instance.hpp"
#include <fstream>

namespace RNAB
{
    void Instance::add_transaction(Transaction& p_transaction)
    {
        TransactionPtr this_transaction_ptr = std::make_shared<Transaction>(p_transaction);
        m_master_ledger.add_transaction(this_transaction_ptr);

        for(size_t i(0); i < m_account_ledgers.size(); ++i)
            m_account_ledgers[i].add_transaction_if_belongs(this_transaction_ptr);

        for(size_t i(0); i < m_budget_ledgers.size(); ++i)
         m_budget_ledgers[i].add_transaction_if_belongs(this_transaction_ptr);      
    }

    void Instance::dump_data() const
    {
        std::ofstream output_csv("MyCSV.csv");
        output_csv << "amount,account,budget\n";
        std::vector<std::string> rows = m_master_ledger.get_text_representations();
        for(int i(0); i < rows.size(); ++i) output_csv << rows[i];
        output_csv.close();
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