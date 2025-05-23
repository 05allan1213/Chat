#include "model/usermodel.hpp"

#include <iostream>

#include "database.hpp"

// User表的增加方法
bool UserModel::insert(User& user)
{
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, "insert into user(name, password, state) values('%s', '%s', '%s')",
            user.getName().c_str(), user.getPwd().c_str(), user.getState().c_str());

    // 2. 初始化并连接数据库
    MySQL mysql;
    if (mysql.connect())
    {
        // 3. 执行插入操作
        if (mysql.update(sql))
        {
            // 获取插入成功的用户数据生成的主键id
            user.setId(mysql_insert_id(mysql.getConnection()));
            return true;
        }
    }
    return false;
}

// 根据用户号码查询用户信息
User UserModel::query(int id)
{
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, "select * from user where id = %d", id);

    // 2. 初始化并连接数据库
    MySQL mysql;
    if (mysql.connect())
    {
        // 3. 执行查询操作
        MYSQL_RES* res = mysql.query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row = mysql_fetch_row(res);  // 从结果集中获取一行数据
            if (row != nullptr)
            {
                User user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setPwd(row[2]);
                user.setState(row[3]);
                mysql_free_result(res);  // 释放结果集的内存资源
                return user;
            }
            mysql_free_result(res);  // 即使无数据也要释放
        }
    }
    // 4. 查询失败，返回一个默认构造的 User 对象
    return User();
}

// 更新用户的状态信息
bool UserModel::updateState(User user)
{
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, "update user set state = '%s' where id = %d", user.getState().c_str(),
            user.getId());

    // 2. 初始化并连接数据库
    MySQL mysql;
    if (mysql.connect())
    {
        // 3. 执行更新操作
        if (mysql.update(sql))
        {
            return true;
        }
    }
    return false;
}

// 重置用户的状态信息
void UserModel::resetState()
{
    // 1.组装sql语句
    char sql[1024] = "update user set state = 'offline' where state = 'online'";
    // 2. 初始化并连接数据库
    MySQL mysql;
    if (mysql.connect())
    {
        // 3. 执行重置操作
        mysql.update(sql);
    }
}