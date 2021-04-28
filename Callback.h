#ifndef MQTT_WRAPPER_CALLBACK_H
#define MQTT_WRAPPER_CALLBACK_H

#include "mqtt/client.h"

class Callback : public virtual mqtt::callback
{
public:
    /**
     * @copydoc mqtt::callback::connected()
     */
    void connected(const mqtt::string &string) override;

    /**
     * @copydoc mqtt::callback::connection_lost()
     */
    void connection_lost(const mqtt::string &string) override;

    /**
     * @copydoc mqtt::callback::message_arrived()
     */
    void message_arrived(mqtt::const_message_ptr ptr) override;

    /**
     * @copydoc mqtt::callback::delivery_complete
     */
    void delivery_complete(mqtt::delivery_token_ptr delivery_token) override;

    /**
     * Whether the client is connected to the broker.
     * @return Whether the client is connected to the broker.
     */
	bool isConnected();

	/**
	 * Setter function to determine whether the connection is established with the broker.
	 * @param isConnected True if the connection is established with the broker.
	 */
	void setConnected(bool isConnected);

private:
	/**
	 * Whether the connection is established with the broker.
	 */
	bool is_connected = false;

	/**
	 * Mutex to tock is_connection setter and getters.
	 */
	std::mutex connectedMutex;
};


#endif //MQTT_WRAPPER_CALLBACK_H
