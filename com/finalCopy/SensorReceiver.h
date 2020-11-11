#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <../../Desktop and Data structures/Activity.h>

using namespace std;

#ifndef SENSORRECEIVER_H
#define SENSORRECEIVER_H
#define SERVER_PORT htons(5050)

class SensorReceiver
{
    public:
        // Constructor
        SensorReceiver();
        // Destructor
        ~SensorReceiver();
        
        // Sensor connection
        int sensor_initialize();
        int run_sensor();
        void end_sensor();

        // Getters and setters required so far
        int getSwitch() const;

    protected:
    private:
        int server_socket;
        int client_socket;
        sockaddr_in serverAddr;
        sockaddr_in client;
        socklen_t clientSize;
        char buffer[4096];
        int onSwitch;
        Activity activity;

};

#endif