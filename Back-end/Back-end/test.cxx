#ifndef test_cxx
#define test_cxx

#include "user_info.hpp"

// g++ -std=c++11 test.cxx -o test -lsoci_core -lsoci_postgresql -lsoci_mysql && ./test
int main() {

    db_pool db;

    ///// \note �������� "postgresql" �� ���� ������, ����� �������� ��� �� � ������������ � �������
    //if (db.connect("postgresql://host='localhost' dbname='test' user='test' password='test'")) {
    //    try {
    //        soci::session sql(*db.get_pool());

    //        // ���������� ������ �������� �������
    //        std::string query_str = "CREATE TABLE IF NOT EXISTS users(id";

    //        // ��� ����� ��� ������� �������, ������� ���������� ��� ����-�������� ��� ���� id
    //        if (sql.get_backend_name() == "postgresql") query_str += " SERIAL ";
    //        else if (sql.get_backend_name() == "mysql") query_str += " INT AUTO_INCREMENT ";
    //        else query_str += " INT ";

    //        query_str += "NOT NULL PRIMARY KEY, birthday TIMESTAMP DEFAULT CURRENT_TIMESTAMP, firstname TEXT DEFAULT NULL, lastname TEXT DEFAULT NULL, friends TEXT DEFAULT NULL)";

    //        // ��������� ������
    //        sql << query_str;

    //        // ��������� ����
    //        user_info info;
    //        std::time_t t = std::time(nullptr); info.birthday = *std::localtime(&t);
    //        info.firstname = "Dmitrij";
    //        info.lastname = "Volin";
    //        info.friends = { 1,2,3,4,5,6,7,8,9 };

    //        sql << "INSERT INTO users(birthday, firstname, lastname, friends) VALUES(:birthday, :firstname, :lastname, :friends)", soci::use(info);

    //        t = std::time(nullptr); info.birthday = *std::localtime(&t);
    //        info.firstname = "Vasy";
    //        info.lastname = "Pupkin";
    //        info.friends = { 11,22,33,44,55,66,77,88,99 };

    //        // ������ ��� ���� ������ � ��
    //        sql << "INSERT INTO users(birthday, firstname, lastname, friends) VALUES(:birthday, :firstname, :lastname, :friends)", soci::use(info);

    //        // ��������� ��� �������, ����� ����: soci::i_ok, soci::i_null
    //        soci::indicator ind;

    //        // ��� MySQL �������� id ��������� ����������� ������, ��� AUTO_INCREMENT:
    //        // sql.get_backend()->get_last_insert_id(sql, "users", reinterpret_cast<long&>(id));
    //        //
    //        // ��� PostgreSQL ����� �������� id ��������� ������, ����� ������������ ������ ���:
    //        // sql << "INSERT INTO users(birthday, firstname, lastname, friends) VALUES(:birthday, :firstname, :lastname, :friends) RETURNING id", soci::use(info), soci::into(id, ind);

    //        // ������� ����� �������� �� ��
    //        info.clear();

    //        // ������ ������� ����� ������ � ��������� ���������, �� ���� `lastname'
    //        sql << "SELECT * FROM users WHERE lastname = :label LIMIT 1", soci::use(std::string("Volin"), "label"), soci::into(info, ind);
    //        if (ind == soci::i_null) std::cout << "�� ������� ������� ������ �� �� ..." << std::endl;
    //        else info.print();

    //        std::cout << "++++++++++++++++++++++++++++++++++++++" << std::endl;

    //        // ������ ������� ������ �������
    //        soci::rowset<user_info> rs = (sql.prepare << "SELECT * FROM users");
    //        for (auto it = rs.begin(); it != rs.end(); it++) {
    //            user_info& i = *it;
    //            i.print();
    //        }

    //        // ������� �������
    //        sql << "DROP TABLE IF EXISTS users";

    //    }
    //    catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
    //}

}

#endif