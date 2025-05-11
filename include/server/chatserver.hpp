#pragma once

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
using namespace muduo;
using namespace muduo::net;

// 聊天服务器的主类
class ChatServer
{
public:
    // 初始化聊天服务器对象
    ChatServer(EventLoop *loop,
               const InetAddress &listenAddr,
               const string &nameArg);

    // 启动服务
    void start();

private:
    // 回调函数:处理新连接和连接断开
    void onConnection(const TcpConnectionPtr &);

    // 回调函数:处理已连接用户的读写事件 (接收消息)
    void onMessage(const TcpConnectionPtr &,
                   Buffer *,
                   Timestamp);

    TcpServer _server; // 组合 Muduo 库的 TcpServer 对象，实现服务器核心功能
    EventLoop *_loop;  //  指向事件循环对象的指针，用于控制服务器的事件处理
};