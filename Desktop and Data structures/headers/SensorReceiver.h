/**
 * @brief Header file for the SensorReceiver class 
 * @details This goes over all the functions and declartations for SensorReceiver
 * @author Will Malisch
 *
 */

using namespace std;

#ifndef SENSORRECEIVER_H
#define SENSORRECEIVER_H
#define SERVER_PORT htons(5050)

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <thread>
#include <string>
#include <vector>
#include <sstream>
#include "Activity.h"

class SensorReceiver
{
    public:
        static SensorReceiver * instance();
        ~SensorReceiver();
        int sensor_initialize();
        int run_sensor();
        void end_sensor();
        int getSwitch() const;
        void setSwitch(int n);
        void calculateSteps();
        int getSteps();

    protected:
        SensorReceiver();
    private:
        vector<double> xvector;
        vector<double> yvector;
        vector<double> zvector;
        static SensorReceiver * _instance;
        int server_socket;
        int client_socket;
        sockaddr_in server_addr;
        sockaddr_in client;
        socklen_t client_size;
        char buffer[4096];
        int onSwitch;
        int steps;

};

#endif