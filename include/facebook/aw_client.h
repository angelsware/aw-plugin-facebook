#ifndef __AW_FACEBOOK_CLIENT_H__
#define __AW_FACEBOOK_CLIENT_H__

#include <facebook/aw_signinoptions.h>

namespace Facebook {
	class IClientListener;

	class IClient
	{
	public:
		virtual ~IClient() {}

		virtual void addListener(IClientListener* listener) = 0;
		virtual void removeListener(IClientListener* listener) = 0;
		virtual void clearAllListeners() = 0;
		virtual void trySilentSignIn() = 0;
		virtual void signIn() = 0;
		virtual void logOut() = 0;
	};
}

#endif
