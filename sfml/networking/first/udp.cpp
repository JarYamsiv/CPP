////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Network.hpp>
#include <iostream>
#include <string.h>

////////////////////////////////////////////////////////////
/// Launch a server, wait for a message, send an answer.
///
////////////////////////////////////////////////////////////
void runUdpServer(unsigned short port)
{
    // Create a socket to receive a message from anyone
    sf::UdpSocket socket;

    // Listen to messages on the specified port
    if (socket.bind(port) != sf::Socket::Done)
        return;
    //std::cout << "Server is listening to port " << port << ", waiting for a message... " << std::endl;

    // Wait for a message
    char in[128];
    std::size_t received;
    sf::IpAddress sender;
    unsigned short senderPort;
    std::string messageToClient;

    do
    {
        std::cout<<"waiting for client msg.."<<std::endl;
        if (socket.receive(in, sizeof(in), received, sender, senderPort) != sf::Socket::Done)
        {
            std::cerr<<"failed to recieve msg";
            continue;
        }
        std::cout << "Message received from client " << sender << ": \"" << in << "\"" << std::endl;
        if(strcmp(in,"exit")==0)
        {
            std::cout<<"exiting"<<std::endl;
            break;
        }

        std::cout<<" enter the msg to client (type exit to exit):";
        getline(std::cin,messageToClient);
        if (socket.send(messageToClient.c_str(), sizeof(messageToClient), sender, senderPort) != sf::Socket::Done)
        {
            std::cerr<<"failed to send message";
            continue;
        }
        std::cout << "Message sent to the client: \"" << messageToClient << "\"" << std::endl;

    } while (!(strcmp("exit", in) == 0 || strcmp("exit",messageToClient.c_str())==0));
    socket.unbind();
}

////////////////////////////////////////////////////////////
/// Send a message to the server, wait for the answer
///
////////////////////////////////////////////////////////////
void runUdpClient(unsigned short port)
{
    // Ask for the server address
    sf::IpAddress server;
    do
    {
        std::cout << "Type the address or name of the server to connect to (255.255.255.255 for broadcast): ";
        std::cin >> server;
        //getline(std::cin,server);
        std::cin.ignore();
    } while (server == sf::IpAddress::None);

    // Create a socket for communicating with the server
    sf::UdpSocket socket;
    std::string msgToServer;
    char in[128];
    std::size_t received;
    sf::IpAddress sender;
    unsigned short senderPort;

    do
    {
        std::cout<<"enter the msg to server ('exit' to exit) : ";
        getline(std::cin,msgToServer);
        if(strcmp("exit",msgToServer.c_str())==0)
        {
            socket.send(msgToServer.c_str(), sizeof(msgToServer), server, port);
            std::cout<<"exiting"<<std::endl;
            break;
        }
        if (socket.send(msgToServer.c_str(), sizeof(msgToServer), server, port) != sf::Socket::Done)
        {
            std::cerr<<"failed to send msg";
            continue;
        }
        std::cout<<"waiting for msg from server..."<<std::endl;

        if (socket.receive(in, sizeof(in), received, sender, senderPort) != sf::Socket::Done)
        {
            std::cerr<<"failed to recieve msg";
            continue;
        }
        std::cout << "Message received from " << sender << ": \"" << in << "\"" << std::endl;

    

    }while(!(strcmp("exit", in) == 0 || strcmp("exit",msgToServer.c_str())==0));

    
    


    socket.unbind();
}

int main()
{
    char type;
    std::cout << "(s) server / (c) client :";
    std::cin >> type;
    std::cin.ignore();
    if (type == 's')
    {
        runUdpServer(2000);
    }
    else if (type == 'c')
    {
        runUdpClient(2000);
    }
}