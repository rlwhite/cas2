#ifndef SOCKETIF_H
#define SOCKETIF_H

#include <climits>
#include <sys/types.h>
#include <sys/socket.h>

namespace cas
{
    /*A simple wrapper for the socket API. */
    struct SocketIf
    {
	typedef int Descr;
	typedef sockaddr Addr;
	typedef socklen_t Len;
	typedef size_t Wait;
	
	
	static const Descr INVALID_SOCKET = -1;
	static const Wait FOR_EVER = UINT_MAX;
	
	enum Domain
	{
	    INET = AF_INET,
	    INET6 = AF_INET6,
	    IPX = AF_IPX,
	    NETLINK = AF_NETLINK,
	    X25 = AF_X25,
	    AX25 = AF_AX25,
	    ATMPVC = AF_ATMPVC,
	    APPLETALK = AF_APPLETALK,
	    PACKET = AF_PACKET,
	    ALG = AF_ALG
	};

	enum Type
	{
	    STREAM = SOCK_STREAM,
	    DGRAM = SOCK_DGRAM,
	    SEQPACKET = SOCK_SEQPACKET,
	    RAW = SOCK_RAW,
	    RDM = SOCK_RDM,
	    NONBLOCK = SOCK_NONBLOCK,
	    CLOEXEC = SOCK_CLOEXEC
	};
	    
	enum How
	{
	    RD = SHUT_RD,
	    WR = SHUT_WR,
	    RDWR = SHUT_RDWR
	};
	
	static Descr createSocket(Domain domain,
				  Type type,
				  int protocol = 0);

	static int shutdown(Descr sock,
			    How how);

	static int close(Descr sock);

	static int bind(Descr sock,
			Addr* addr,
			Len length);

	static int listen(Descr sock,
			  int backlog);

	static Descr accept(Descr listenSock,
			    Addr* addr,
			    Len* length);

	static int connect(Descr sock,
			   Addr* addr,
			   Len length);

	static int getPeerName(Descr sock,
			       Addr* addr,
			       Len* length);

	static int getSocketName(Descr sock,
				 Addr* addr,
				 Len* length);

	static int read(const char* msg,
			size_t msgLen,
			Wait timeout = FOR_EVER);
	
    private:
	//No objects
	SocketIf();
	~SocketIf();
    };
}

#endif //SOCKETIF_H
