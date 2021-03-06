///
/// @file    TcpSever.cc
/// @author  yangyu/Icot(jobyang@163.com)
/// @date    2017-03-18 00:03:52
///
#include "TcpServer.h"

namespace wd
{

int createSocketFd()
{
	int fd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//????????????
	if(fd == -1)
	{
		fprintf(stderr, "create socket fd error\n");
		exit(EXIT_FAILURE);
	}

	return fd;
}

TcpServer::TcpServer(const string & ip, unsigned short port)
: _addr(ip, port)
, _sockfd(createSocketFd())
, _poller(_sockfd.fd())
{
	_sockfd.setTcpNoDelay(false);
	_sockfd.setReusePort(true);
	_sockfd.setReuseAddr(true);
	_sockfd.setKeepAlive(false);

	_sockfd.bindAddress(_addr);
	_sockfd.listen();
}

}
