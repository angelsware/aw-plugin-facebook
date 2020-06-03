#include <facebook/aw_clientfactory.h>
#include "aw_client_android.h"

namespace Facebook {
	IClient* CClientFactory::create(const char* clientId, ESignInOptions signInOptions) {
		return new CClient_Android(clientId, signInOptions);
	}

	void CClientFactory::destroy(IClient* client) {
		delete client;
	}
}
