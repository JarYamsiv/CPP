#include <iostream>
#include <SFML/Network.hpp>
#include <string.h>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
//tcp connection
int main(int argc, char **argv)
{
    unsigned int port;
    if (argc > 1)
    {
        std::stringstream portString(argv[1]);
        portString >> port;
    }
    else
    {
        port = 2000;
    }

    sf::IpAddress ip(sf::IpAddress::getLocalAddress());
    sf::TcpSocket socket;
    char connectionType, mode;
    std::string text = "Connected to: ";
    char buffer[2000];
    std::size_t received;
    sf::TcpListener listener;

    cout << "(s) server / (c) client : ";
    cin >> connectionType;

    if (connectionType == 's')
    {
        listener.listen(port);
        if(listener.accept(socket)!= sf::Socket::Done)
        {
            std::cerr<<" failed to accept on coming connection" << endl;
        }
        text += "Server";
    }
    else if (connectionType == 'c')
    {
        cout << "connecting to : " << ip.toString() << endl;
        if (socket.connect(ip, port) != sf::Socket::Done)
        {
            std::cerr << "failed to connect to : " << ip.toString() << endl;
        }
        text += "client";
    }
    socket.send(text.c_str(), text.length() + 1);
    socket.receive(buffer, sizeof(buffer), received);
    cout << buffer << endl;

    socket.disconnect();
    listener.close();
    return 0;
}