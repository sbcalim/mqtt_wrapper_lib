#ifndef MQTT_WRAPPER_MQTTWRAPPER_H
#define MQTT_WRAPPER_MQTTWRAPPER_H

#include <string>
#include "mqtt/client.h"
#include "PersistenceStore.h"
#include "Callback.h"

class MqttWrapper
{
public:
	/**
	 * Constructor with default values.
	 */
	MqttWrapper();

	/**
	 * Connection to the broker.
	 */
	void connect();

	/**
	 * Publishes a message to the given topic.
	 * @param topic Topic to publish the message to.
	 * @param message Message to publish.
	 */
	void publish(std::string& topic, std::string& message);

private:
	/**
	 * Initialize the connection options.
	 */
	void initConnectOptions();

	/**
	 * Persistence store to hold the connection persistence parameters.
	 */
	PersistenceStore persistenceStore;

	/**
	 * Mqtt client to connect to the broker.
	 */
	std::unique_ptr<mqtt::client> client;

	/**
	 * Callbacks for connection and message publish related parameters.
	 */
	Callback callback;

	/**
	 * Structure to hold necessary connection parameters.
	 */
	mqtt::connect_options connectionOptions;

	/**
	 * Default value for keep alive interval.
	 */
	const static int DEFAULT_KEEP_ALIVE_INTERVAL;

	/**
	 * Default value for whether the previous messages should be deleted.
	 */
	const static bool DEFAULT_IS_CLEAN_SESSION;

	/**
	 * Default broker address.
	 */
	const static std::string DEFAULT_SERVER_ADDRESS;

	/**
	 * Default client ID.
	 */
	const static std::string DEFAULT_CLIENT_ID;

	/**
	 * Default quality of service enum value.
	 */
	const static int DEFAULT_QOS;
};


#endif //MQTT_WRAPPER_MQTTWRAPPER_H
