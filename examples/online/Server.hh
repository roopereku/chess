#ifndef SERVER_HEADER
#define SERVER_HEADER

#include "../../Engine.hh"
#include "Player.hh"

#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls.hpp>

#include <map>

typedef websocketpp::server<websocketpp::config::asio> websocket;
typedef websocket::message_ptr message_ptr;

class Server
{
public:
	Server();

private:
	Engine e;
	websocket server;

	std::ostringstream getTileData();
    std::map <websocketpp::connection_hdl, Player, std::owner_less <websocketpp::connection_hdl>> players;
};

#endif