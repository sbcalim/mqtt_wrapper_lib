#include "MqttWrapper.h"
#include "Callback.h"

const int MqttWrapper::DEFAULT_KEEP_ALIVE_INTERVAL = 20;
const bool MqttWrapper::DEFAULT_IS_CLEAN_SESSION = true;
const std::string MqttWrapper::DEFAULT_SERVER_ADDRESS = "tcp://localhost:1883";
const std::string MqttWrapper::DEFAULT_CLIENT_ID = "default_id";
const int MqttWrapper::DEFAULT_QOS = 1;

MqttWrapper::MqttWrapper()
{
	initConnectOptions();
}

void MqttWrapper::initConnectOptions()
{
	connectionOptions.set_keep_alive_interval(DEFAULT_KEEP_ALIVE_INTERVAL);
	connectionOptions.set_clean_session(DEFAULT_IS_CLEAN_SESSION);
}

void MqttWrapper::connect()
{
	client = std::unique_ptr<mqtt::client>(new mqtt::client(DEFAULT_SERVER_ADDRESS, DEFAULT_CLIENT_ID, &persistenceStore));
	client->set_callback(callback);
	client->connect(connectionOptions);
}

void MqttWrapper::publish(std::string &topic, std::string &message)
{
	int i = 10;
	while(!callback.isConnected() && i--)
	{
		std::cout << "Connection is not established yet. Waiting..." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	auto messageToPublish = mqtt::make_message(topic, message);
	messageToPublish->set_qos(DEFAULT_QOS);
	client->publish(messageToPublish);
}
