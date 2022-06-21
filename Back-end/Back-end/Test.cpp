//#include "Client.h"
//
//
//int main() {
//	db_pool db;
//
//	if (db.connect("postgresql://host='localhost' dbname='postgres' user='postgres' password='*****'")) {
//		try
//		{
//			soci::session sql(*db.get_pool());
//			std::string query_str = "CREATE TABLE IF NOT EXISTS test (id SERIAL PRIMARY KEY, login VARCHAR(255), password INTEGER)";
//
//			sql << query_str;
//			
//			Client client;
//
//			client.login = "Vasya228";
//			client.password = "12345";
//			
//			sql << "INSERT INTO test (login, password) VALUES (:login, :password)", soci::use(client);
//		
//			client.login = "ZHEKA";
//			client.password = "987765";
//
//			sql << "INSERT INTO test (login, password) VALUES (:login, :password)", soci::use(client);
//			
//			soci::indicator ind;
//			
//			client.clear();
//			
//			sql << "SELECT * FROM test WHERE login = :label LIMIT 1", soci::use(std::string("ZHEKA"), "label"), soci::into(client, ind);
//			
//			if (ind == soci::i_null) std::cout << "не удалось выбрать данные из БД ..." << std::endl;
//			else client.print();
//
//			
//		}
//		catch (std::exception const& e) 
//		{ 
//			std::cerr << e.what() << std::endl; 
//		}
//	}
//}