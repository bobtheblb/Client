#include <iostream>

#include <string>

#include <sys/socket.h>

#include <netinet/in.h>

#include <sys/types.h>

#include <unistd.h>

#include <arpa/inet.h>

#include <string.h>

#include <fcntl.h>

#define MAXBUF 256

int main()

{

    int backlog = 3, sends;    

    socklen_t clientlen;

    struct sockaddr_in servaddr;

    struct sockaddr clientaddr;

    int flags;

    char buffer[MAXBUF] = "this is it chief!!!";

    memset(&servaddr, '0', sizeof(servaddr));   

    servaddr.sin_family = AF_INET;

    servaddr.sin_port = htons(5060);

    servaddr.sin_addr.s_addr = INADDR_ANY;    

    int baccept;

    int servsock = socket(AF_INET, SOCK_STREAM, 0);

    

    int clientsock;

    int opt = 1;

    if (servsock < 0)

    {

        std::cout << "Failed to create socket" << std::endl;

    }

    if (setsockopt(servsock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0)

    {

        std::cout<<"Set Sock Opt Fail"<<std::endl;

    }

            bind(servsock, (struct sockaddr *)&servaddr, sizeof(servaddr));

            std::cout<<"Binded"<<std::endl;

            int list = listen(servsock, backlog);

            std::cout<<"Listening"<<std::endl;

            std::cout << "list"<<list << std::endl;            

            if (list >= 0)

            {

                std::cout<<"Listening for Real"<<std::endl;

            baccept = accept(servsock, (struct sockaddr *)&clientaddr, (socklen_t* )&clientlen);
            flags = fcntl(baccept, F_GETFL);

            fcntl(baccept, F_SETFL, flags | O_NONBLOCK);
            if (baccept < 0)

            {

                std::cout<<"Didn't Accept"<<std::endl;

                //return 0;

            }else{


            }

            std::cout << "baccept"<<baccept << std::endl;
            while(1)
            {
            //write(baccept, buffer, MAXBUF);
            int sending = send(baccept , buffer , strlen(buffer) , 0 );
            }
            

            }

        }



