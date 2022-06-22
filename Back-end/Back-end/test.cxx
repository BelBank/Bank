#ifndef test_cxx
#define test_cxx

#include "user_info.hpp"
#include "Client.h"


int main() {

    db_pool db;

    if (db.connect("postgresql://host='postgresql-81012-0.cloudclusters.net' port='12018' dbname='bank' user='root' password='drakonkapusta'")) {
        try {
            
            
            
            soci::session sql(*db.get_pool());
            
            //sql << "CREATE TABLE bank_login (id SERIAL PRIMARY KEY, login VARCHAR(30), password VARCHAR(16));";
            Client info;
            //info.login = "root";
            //info.password = "root";

            //sql << "INSERT INTO bank_login(login, password) VALUES(:login, :password)", soci::use(info);

            /*info.login = "Pashka";
            info.password = "PaShampusik";

            sql << "INSERT INTO bank_login(login, password) VALUES(:login, :password)", soci::use(info);*/
           soci::indicator ind;
            info.clear();
            //sql << "SELECT * FROM bank_login WHERE login = :label LIMIT 1", soci::use(std::string("root"), "label"), soci::into(info, ind);
            sql << "SELECT * FROM bank_login WHERE login = :login AND password = :password LIMIT 1", soci::use(std::string("uyguyguyg"), "login"), soci::use(std::string("root"), "password"), soci::into(info, ind);
            if (ind == soci::i_null) std::cout << "не удалось выбрать данные из БД ..." << std::endl;
            else info.print();

            std::cout << "++++++++++++++++++++++++++++++++++++++" << std::endl;
            soci::rowset<Client> rs = (sql.prepare << "SELECT * FROM bank_login");
            for (auto it = rs.begin(); it != rs.end(); it++) {
                Client& i = *it;
                i.print();
            }
            

        }
        catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
    }

}

#endif