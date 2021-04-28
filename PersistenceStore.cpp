#include "PersistenceStore.h"

PersistenceStore::PersistenceStore() : is_open(false)
{

}

void PersistenceStore::open(const mqtt::string &clientId, const mqtt::string &serverURI)
{
    is_open = true;
}

void PersistenceStore::close()
{
    is_open = false;
}

void PersistenceStore::clear() noexcept
{
    persistence_store.clear();

}

bool PersistenceStore::contains_key(const mqtt::string &key) noexcept
{
    return !persistence_store.empty();
}

mqtt::string_collection PersistenceStore::keys() const
{
    mqtt::string_collection key_list;
    for (const auto& key : persistence_store)
        key_list.push_back(key.first);
    return key_list;
}

void PersistenceStore::put(const mqtt::string &key, const std::vector<mqtt::string_view> &bufs)
{
    std::string value;
    for (const auto& buf : bufs)
        value.append(buf.data(), buf.size());
    persistence_store[key] = std::move(value);
}

mqtt::string PersistenceStore::get(const mqtt::string &key) const
{
    auto value = persistence_store.find(key);
    if (value == persistence_store.end())
        throw mqtt::persistence_exception();

    return value->second;
}

void PersistenceStore::remove(const mqtt::string &key)
{
    auto value = persistence_store.find(key);
    if (value == persistence_store.end())
        throw mqtt::persistence_exception();
    persistence_store.erase(value);
}
