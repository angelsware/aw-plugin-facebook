#ifndef __AW_FACEBOOK_CLIENT_DEFAULT_H__
#define __AW_FACEBOOK_CLIENT_DEFAULT_H__

#include <facebook/aw_client.h>
#include <facebook/aw_signinoptions.h>

namespace Facebook {
	class IClientListener;

	class CClient_Default
		: public IClient
	{
	private:
		void addListener(IClientListener* listener) override {}
		void removeListener(IClientListener* listener) override {}
		void clearAllListeners() override {}
		void trySilentSignIn() override {}
		void signIn() override {}
		void logOut() override {}
	};
}

#endif
