#ifndef MQTT_WRAPPER_PERSISTENCESTORE_H
#define MQTT_WRAPPER_PERSISTENCESTORE_H

#include "mqtt/client.h"
class PersistenceStore : virtual public mqtt::iclient_persistence
{
public:
	/**
	 * Default constructor
	 */
    PersistenceStore();

    /**
     * @copydoc mqtt::iclient_persistence::open()
     */
    void open(const mqtt::string &clientId, const mqtt::string &serverURI) override;

    /**
     * @copydoc mqtt::iclient_persistence::close()
     */
    void close() override;

    /**
     * @copydoc mqtt::iclient_persistence::clear()
     */
    void clear() noexcept override;

    /**
     * @copydoc mqtt::iclient_persistence::contains_key()
     */
    bool contains_key(const mqtt::string &key) noexcept override;

    /**
     * @copydoc mqtt::iclient_persistence::keys()
     */
    mqtt::string_collection keys() const override;

    /**
     * @copydoc mqtt::iclient_persistence::put()
     */
    void put(const mqtt::string &key, const std::vector<mqtt::string_view> &bufs) override;

    /**
     * @copydoc mqtt::iclient_persistence::get()
     */
    mqtt::string get(const mqtt::string &key) const override;

    /**
     * @copydoc mqtt::iclient_persistence::remove()
     */
    void remove(const mqtt::string &key) override;

private:
	/**
	 * Whether the persistence store is open.
	 */
    bool is_open;

    /**
     * Persistence store key value pairs.
     */
    std::map<std::string, std::string> persistence_store;
};


#endif //MQTT_WRAPPER_PERSISTENCESTORE_H
