#ifndef test_cxx
#define test_cxx

#include "user_info.hpp"
#include "Client.h"


int main() {

    db_pool db;

    if (db.connect("postgresql://host='localhost' dbname='bank' user='root' password='root'")) {
        try {
            soci::session sql(*db.get_pool());
            Client info;
            info.login = "Vasya228";
            info.password = "drakonkapusta";

            sql << "INSERT INTO bank_login(login, password) VALUES(:login, :password)", soci::use(info);

            info.login = "Pashka";
            info.password = "PaShampusik";

            sql << "INSERT INTO bank_login(login, password) VALUES(:login, :password)", soci::use(info);
           /* soci::indicator ind;
            info.clear();
            sql << "SELECT * FROM abc WHERE lastname = :label LIMIT 1", soci::use(std::string("Volin"), "label"), soci::into(info, ind);
            if (ind == soci::i_null) std::cout << "не удалось выбрать данные из БД ..." << std::endl;
            else info.print();*/

            std::cout << "++++++++++++++++++++++++++++++++++++++" << std::endl;
            soci::rowset<Client> rs = (sql.prepare << "SELECT * FROM bank_login");
            for (auto it = rs.begin(); it != rs.end(); it++) {
                Client& i = *it;
                i.print();
            }
            

        }
        catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
    }

    return 0;
}

#endif