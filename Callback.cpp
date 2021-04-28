#include "Callback.h"

void Callback::connected(const mqtt::string &string)
{
	setConnected(true);
	std::cout << "Connected." << std::endl;
    callback::connected(string);
}

void Callback::connection_lost(const mqtt::string &cause)
{
	setConnected(false);
    std::cout << "\nConnection lost" << std::endl;
    if (!cause.empty())
    {
        std::cout << "\tcause: " << cause << std::endl;
    }
}

void Callback::message_arrived(mqtt::const_message_ptr ptr)
{
	std::cout << "Message arrived." << std::endl;
    callback::message_arrived(ptr);
}

void Callback::delivery_complete(mqtt::delivery_token_ptr delivery_token) {
    std::cout << "\n\t[Delivery complete for token: "
              << (delivery_token ? delivery_token->get_message_id() : -1) << "]" << std::endl;
}

bool Callback::isConnected()
{
	std::unique_lock<std::mutex> connectedLock(connectedMutex);
	return is_connected;
}

void Callback::setConnected(bool isConnected)
{
	std::unique_lock<std::mutex> connectedLock(connectedMutex);
	is_connected = isConnected;
}
