#include "mysql_data.h"
#include <iostream>
#include <string>
#include <mysql/mysql.h>

MysqlDB::MysqlDB() {
    if ((mysql_init(&mysql) == NULL)) {
        std::cout << "init mysql error" << std::endl;
        exit(-1);
    }
}

MysqlDB::~MysqlDB() {
    mysql_close(&mysql);
}
void MysqlDB::connect(std::string host, std::string user, std::string passwd, std::string database) {
    if (!mysql_real_connect(&mysql,host.c_str(), host.c_str(), passwd.c_str(), database.c_str(), NULL, 0, 0)) {
        std::cout << "conect error" << std::endl;
        exit(-1);
    }
}
bool MysqlDB::check(std::string name, std::string passwd) {
    std::string sql = "select * from uerdata WHERE name ='" + name + "';";
    mysql_query(&mysql, sql.c_str());
    result = mysql_store_result(&mysql);
    if (!result) {
        std::cout << "result error" << std::endl;
        return false;
    }
    int num;
    num = mysql_num_fields(result);
    row = mysql_fetch_row(result);

    std::string str;
    std::string fname;
    std::cout << row << std::endl;

    if (!row) {
        return false;
    }

    for (int i = 0; i < num; i++) {
        field = mysql_fetch_field_direct(result, i);
        std::cout << field->name << row[i];
        fname = field->name;

        if (fname == "password") {
            str = row[i];
        }

    }
    if (str == passwd) {
        return true;
    } else if (str != passwd) {
        return false;
    }
}

int MysqlDB::checkuild(std::string name, std::string passwd) {
    std::string sql = "select * from uerdata WHERE name ='" + name + "';";
    mysql_query(&mysql, sql.c_str());

    result = mysql_store_result(&mysql);
    if (!result) {
        std::cout << "result error";
        return -1;
    }
    int num = mysql_num_fields(result);
    row = mysql_fetch_row(result);

    std::string str;
    std::string suid;
    std::string fname;
    std::cout << row << std::endl;

    if (!row) {
        return -1;
    }
    for (int i = 0; i < num; i++) {
        field = mysql_fetch_field_direct(result, i);
        std::cout << field->name << row[i];
        fname = field->name;
        if (fname == "UID") {
            suid = row[i];
        }
        if (fname == "password") {
            str = row[i];
        }
    }
    if (str == passwd) {
        int uid = atoi(suid.c_str());
        return uid;
    } else if (str != passwd) {
        return -1;
    }
}



