#include <facebook/aw_clientfactory.h>
#include "aw_client_android.h"

namespace Facebook {
	IClient* CClientFactory::create(ESignInOptions signInOptions) {
		return new CClient_Android(signInOptions);
	}

	void CClientFactory::destroy(IClient* client) {
		delete client;
	}
}
