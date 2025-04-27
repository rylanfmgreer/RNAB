#pragma once
#ifndef RNAB_INSTANCE
#define RNAB_INSTANCE
#include <vector>
#include "../ledger/ledger.hpp"
#include "../transaction/transaction.hpp"

namespace RNAB
{
    class Instance
    {
        public:
        void add_transaction(Transaction& p_transaction);
        void add_transaction(TransactionPtr p_transaction);
        void print_accounts() const;
        void print_budgets() const;
        void dump_data() const;
        void read_data(const std::string& p_filename);
        void add_transaction_from_csv(TransactionPtr this_transaction);

        private:
        Ledger m_master_ledger;
        std::vector<AccountLedger> m_account_ledgers;
        std::vector<BudgetLedger> m_budget_ledgers;
        void add_account_if_not_exists(const std::string m_account_name);
        void add_budget_if_not_exists(const std::string m_budget_name);
        std::vector<std::string> get_budget_names() const;
        std::vector<std::string> get_account_names() const;


    };
    // from stackoverflow, for csv parsiiing
    std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str);
} // namespace RNAB


#endif