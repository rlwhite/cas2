#include "socketIf.h"

#include "unistd.h"

namespace cas
{
    const SocketIf::Descr SocketIf::INVALID_SOCKET;
    
    SocketIf::Descr SocketIf::createSocket(Domain domain,
					   Type type,
					   int protocol)
    {
	return ::socket(domain, type, protocol);
    }

    int SocketIf::shutdown(Descr sock, How how)
    {
	return ::shutdown(sock, how);
    }

    int SocketIf::close(Descr sock)
    {
	return ::close(sock);
    }

    int SocketIf::bind(Descr sock,
		       Addr* addr,
		       Len length)
    {
	return ::bind(sock, addr, length);
    }

    int SocketIf::listen(Descr sock,
			 int backlog)
    {
	return ::listen(sock, backlog);
    }

    SocketIf::Descr SocketIf::accept(Descr listenSock,
				     Addr* addr,
				     Len* length)
    {
	return ::accept(listenSock, addr, length);
    }

    int SocketIf::connect(Descr sock,
			  Addr* addr,
			  Len length)
    {
	return ::connect(sock, addr, length);
    }

    int SocketIf::getPeerName(Descr sock,
			      Addr* addr,
			      Len* length)
    {
	return ::getpeername(sock, addr, length);
    }

    int SocketIf::getSocketName(Descr sock,
				Addr* addr,
				Len* length)
    {
	return ::getsockname(sock, addr, length);
    }
}
