#include <facebook/aw_clientfactory.h>
#include "aw_client_default.h"

namespace Facebook {
	IClient* CClientFactory::create(ESignInOptions signInOptions) {
		return new CClient_Default();
	}

	void CClientFactory::destroy(IClient* client) {
		delete client;
	}
}
