#if 0
#ifndef AVHNEXUSTUNNELTOSERVER_H
#define AVHNEXUSTUNNELTOSERVER_H

#include <queue>

#include <string>
using std::string;

namespace AvHNexus
{
	class TunnelToServer : public Nexus::TunnelToServer
	{
	public:
		static TunnelToServer* getInstance(void);
		virtual ~TunnelToServer(void);

		virtual Nexus::TunnelToServer* clone(void) const;
		virtual bool send(const std::string &data);
		virtual bool recv(std::string &data);

		virtual bool insertMessage(const std::string &message);	//inserted into queue of messages from server

	private:
		TunnelToServer(void);
		std::deque<const std::string> messages;
	};
}

#endif
#endif