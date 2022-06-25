

#include "Client.h"


int main() {

	db_pool db;

	if (db.connect("postgresql://host='localhost'  dbname='bank' user='root' password='root'")) {
		try {
			soci::session sql(*db.get_pool());
			Client info;
			soci::indicator ind;
			info.clear();
			sql << "SELECT * FROM bank_login WHERE login = :login AND password = :password LIMIT 1", soci::use(std::string("Pashka"), "login"), soci::use(std::string("PaShampusik"), "password"), soci::into(info, ind);
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

