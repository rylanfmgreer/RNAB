#include "instance.hpp"
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../data/csv_reader/csv_reader.hpp"


namespace RNAB
{

    void Instance::dump_data() const
    {
        std::ofstream output_csv("MyCSV.csv");
        output_csv << "amount,account,budget\n";
        std::vector<std::string> rows = m_master_ledger.get_text_representations();
        for(int i(0); i < rows.size(); ++i) output_csv << rows[i] << '\n';
        output_csv.close();
    }

    void Instance::read_data(const std::string& p_filename)
    {
        std::ifstream myfile;
        myfile.open(p_filename);

        int c = 0;
        CSVIterator loop(myfile);
        loop++;
        for(; loop != CSVIterator(); ++loop)
        {
            
            auto x = (*loop)[0];
            std::string_view _amount = (*loop)[0];
            std::string_view _account = (*loop)[1];
            std::string_view _budget = (*loop)[2];

            int amount = std::stoi( std::string(_amount));
            std::string account = std::string(_account);
            std::string budget = std::string(_budget);

            TransactionPtr this_transaction(new Transaction(amount, account, budget));
            add_budget_if_not_exists(budget);
            add_account_if_not_exists(account);
            add_transaction(this_transaction);

        }


    }
}