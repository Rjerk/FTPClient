#include "FtpClient.h"
#include <cstdlib>

namespace ftpclient {

FtpClient::FtpClient(const std::string& ip, int16_t port)
        : handler(ip, port), ip_(ip), port_(port)
{

}

FtpClient::~FtpClient()
{

}

void FtpClient::connectToServer()
{
    handler.buildControlConnection();
    handler.buildDataTrassfer();
	handler.runShell();
}

void FtpClient::run(int argc, char* argv[])
{
	if (argc == 1) { // ���� shell ʹ�ÿ������ӵ�¼������ 
		handler.runShell();
	} else if (argc == 2) { // ʹ��Ĭ�ϵ� port 21 ���ӷ����� 
		FtpClient(string(argv[1]));
		connectToServer();
	} else if (argc >= 3) { // ָ�� port ���ӷ����� 
		FtpClient(string(argv[1]), atoi(argv[2]));
		connectToServer();
	}
}

}

