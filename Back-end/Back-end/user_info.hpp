#ifndef user_info_hpp
#define user_info_hpp

#include "db_pool.hpp"
#include <ctime>
#include <vector>
#include <regex>
#include <numeric>
#include <algorithm>
#include <iomanip>

// некоторые вспомогательные ф-ии для преобразования массивов в векторы и обратно
template<typename T>
static void extract_integers(const std::string& str, std::vector<T>& result) {
    result.clear();
    using re_iterator = std::regex_iterator<std::string::const_iterator>;
    using re_iterated = re_iterator::value_type;
    std::regex re("([\\+\\-]?\\d+)");
    re_iterator rit(str.begin(), str.end(), re), rend;
    std::transform(rit, rend, std::back_inserter(result), [](const re_iterated& it) {return std::stoi(it[1]); });
}

template<typename T>
static void split_integers(std::string& str, const std::vector<T>& arr) {
    str = "{";
    if (arr.size()) {
        str += std::accumulate(arr.begin() + 1, arr.end(), std::to_string(arr[0]),
            [](const std::string& a, T b) {return a + ',' + std::to_string(b); });
    } str += "}";
}

// структура таблицы `users'
class user_info {
public:

    int id; // айди пользователя
    std::tm birthday; // день рождения
    std::string firstname, lastname; // имя и фамилия
    std::vector<int> friends; // айдишники друзей

    user_info() :id(0), birthday(), firstname(), lastname(), friends() {}

    void print() {
        std::cout.imbue(std::locale("ru_RU.utf8"));
        std::cout << "id: " << id << std::endl;
        std::cout << "birthday: " << std::put_time(&birthday, "%c %Z") << std::endl;
        std::cout << "firstname: " << firstname << std::endl;
        std::cout << "lastname: " << lastname << std::endl;
        std::string arr_str;
        split_integers(arr_str, friends);
        std::cout << "friends: " << arr_str << std::endl;
    }

    void clear() { id = 0; firstname = lastname = ""; friends.clear(); }

    user_info& operator=(const user_info& rhs) {
        if (this != &rhs) {
            id = rhs.id;
            birthday = rhs.birthday;
            firstname = rhs.firstname;
            lastname = rhs.lastname;
            friends = rhs.friends;
        }
        return *this;
    }

};

// для работы со своими типами, в SOCI имеются конвертеры
namespace soci {

    template<> struct type_conversion<user_info> {
        typedef values base_type;

        static void from_base(values const& v, indicator ind, user_info& p) {
            if (ind == i_null) return;
            try {
                p.id = v.get<int>("id", 0);
                p.birthday = v.get<std::tm>("birthday", {});
                p.firstname = v.get<std::string>("firstname", {});
                p.lastname = v.get<std::string>("lastname", {});

                std::string arr_str = v.get<std::string>("friends", {});
                extract_integers(arr_str, p.friends);
            }
            catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
        }

        static void to_base(const user_info& p, values& v, indicator& ind) {
            try {
                v.set("id", p.id);
                v.set("birthday", p.birthday);
                v.set("firstname", p.firstname);
                v.set("lastname", p.lastname);

                std::string arr_str;
                split_integers(arr_str, p.friends);
                v.set("friends", arr_str);

                ind = i_ok;
                return;
            }
            catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
            ind = i_null;
        }

    };

}

#endif