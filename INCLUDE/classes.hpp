#include <iostream>
#include <vector> //-> for vector
#include <sys/socket.h> //-> for socket()
#include <sys/types.h> //-> for socket()
#include <netinet/in.h> //-> for sockaddr_in
#include <fcntl.h> //-> for fcntl()
#include <unistd.h> //-> for close()
#include <arpa/inet.h> //-> for inet_ntoa()
#include <poll.h> //-> for poll()
#include <csignal> //-> for signal()

class Client //-> class for client
{
    private:
        int Fd; //-> client file descriptor
        std::string IPadd; //-> client ip address
    public:
        Client(){}; //-> default constructor
        int GetFd(){return Fd;} //-> getter for fd

        void SetFd(int fd)
        {Fd = fd;} //-> setter for fd
        void setIpAdd(std::string ipadd)
        {IPadd = ipadd;} //-> setter for ipadd

    class Server //-> class for server
{
    private:
    int Port; //-> server port
    int SerSocketFd; //-> server socket file descriptor
    static bool Signal; //-> static boolean for signal
    std::vector<Client> clients; //-> vector of clients
    std::vector<struct pollfd> fds; //-> vector of pollfd
    public:
    Server(){SerSocketFd = -1;} //-> default constructor

    void ServerInit(); //-> server initialization
    void SerSocket(); //-> server socket creation
    void AcceptNewClient(); //-> accept new client
    void ReceiveNewData(int fd); //-> receive new data from a registered client

    static void SignalHandler(int signum); //-> signal handler
    
    void CloseFds(); //-> close file descriptors
    void ClearClients(int fd); //-> clear clients
    };

    //-------------------------------------------------------//
    void Server::ClearClients(int fd){ //-> clear the clients
    for(size_t i = 0; i < fds.size(); i++){ //-> remove the client from the pollfd
    if (fds[i].fd == fd)
    {fds.erase(fds.begin() + i); break;}
    }
    for(size_t i = 0; i < clients.size(); i++){ //-> remove the client from the vector of clients
    if (clients[i].GetFd() == fd)
    {clients.erase(clients.begin() + i); break;}
    }
    }
};


 