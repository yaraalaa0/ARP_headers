#include "arpnet/arpnet.h"

/*
	=== IP ADDRESS TABLE ===
*/
// the table
char ip_table[IP_TABLE_LEN][15] = {
	"127.0.0.1",
	"0.0.0.0",
	"255.255.0.255"
}

/*
	=== SOCKET CONNECTION ===
*/
int sockfd;						//socket file descriptor
struct sockaddr_in cli_addr;	//client address structure

/**
 * initialize server connection without accept a client
 */
void server_init(int portno){
	
	//structures server address
	struct sockaddr_in serv_addr;
	
	// Creating socket file descriptor 
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0){ 
        perror("ERROR in creating socket"); 
        exit(-1);  
    } 
    
    //initialize socket address structure
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    //attaching socket to the port passed as parameters 
    if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
		perror("ERROR on binding");
		close(sockfd);
		exit(-1);
	}
	
    //listen for connections with max 5 connection
    if(listen(sockfd, 5) <0){
		perror("ERROR on listen"); 
		close(sockfd);
        exit(-1);  
	}
}

/**
 * function to accept a client
 **/
int accept_client(){
	
	int newsockfd, 	 	//file descriptor result of accept
		clilen;			//client address size
	
	//accept a connection
	clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
   
    if (newsockfd < 0) {
         perror("ERROR on accept");
         close(new_socket);
         close(sockfd);
         exit(-1);
    }
    
    return  newsockfd;
} 


/**
 * function to connect client to server specifying IP address and port num
 */
int client_connection(char *IPaddr, int portno) {
	
	//socket file descriptor
	int socket_fd;

	//structures for socket connection
    struct sockaddr_in serv_addr;
    struct hostent *server;
    
    //create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("ERROR opening socket");
        exit(-1);
	}
	
	//get IP address
	server = gethostbyname(IPaddr);
    if (server == NULL) {
        printf("ERROR, no such host\n");
        exit(-1);
    }
    
    //setting data for socket connection
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server -> h_addr, (char *)&serv_addr.sin_addr.s_addr, server -> h_length);
    serv_addr.sin_port = htons(portno);
    
    //connection
    if (connect(socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR in connecting");
        exit(-1);
	}
        
    return socket_fd;  
}

