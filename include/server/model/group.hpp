#pragma once

#include <string>
#include <vector>

#include "groupuser.hpp"

// User表的ORM类
class Group
{
   public:
    Group(int id = -1, std::string name = "", std::string desc = "")
    {
        this->id = id;
        this->name = name;
        this->desc = desc;
    }

    void setId(int id) { this->id = id; }
    void setName(std::string name) { this->name = name; }
    void setDesc(std::string desc) { this->desc = desc; }

    int getId() { return this->id; }
    std::string getName() { return this->name; }
    std::string getDesc() { return this->desc; }
    std::vector<GroupUser>& getUsers() { return this->users; }

   private:
    int id;
    std::string name;
    std::string desc;
    std::vector<GroupUser> users;  // 存储该群组的所有成员信息
};
