#pragma once

/*
client和server的公共文件
*/

enum EnMsgType
{
    LOGIN_MSG = 1,  // 登录消息
    REG_MSG,        // 注册消息
    REG_MSG_ACK,    // 注册消息响应
};