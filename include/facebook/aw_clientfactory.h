#ifndef __AW_FACEBOOK_CLIENT_FACTORY_H__
#define __AW_FACEBOOK_CLIENT_FACTORY_H__

#include <facebook/aw_signinoptions.h>

namespace Facebook {
	class IClient;

	class CClientFactory {
	public:
		static IClient* create(ESignInOptions signInOptions);
		static void destroy(IClient *client);
	};
}

#endif
