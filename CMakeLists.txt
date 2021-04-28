project(mqtt_wrapper_lib)
cmake_minimum_required(VERSION 3.19)

set (THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(OpenSSL REQUIRED)
find_library(paho-mqttpp3 NAMES libpaho-mqttpp3.so REQUIRED)
find_library(paho-mqtt3a NAMES libpaho-mqtt3a.so REQUIRED)

message("Paho Mqttpp library path: [${paho-mqttpp3}]")
message("Paho Mqtt library path: [${paho-mqtt3a}]")

add_library(pahottpp STATIC IMPORTED)
set_target_properties(pahottpp PROPERTIES IMPORTED_LOCATION ${paho-mqttpp3})
add_library(pahomqtt3a SHARED IMPORTED)
set_property(TARGET pahomqtt3a PROPERTY IMPORTED_LOCATION ${paho-mqtt3a})

add_library(mqtt_wrapper_lib
        Callback.h
        Callback.cpp
        PersistenceStore.h
        PersistenceStore.cpp
        MqttWrapper.h
        MqttWrapper.cpp)

target_link_libraries(mqtt_wrapper_lib pahottpp pahomqtt3a)