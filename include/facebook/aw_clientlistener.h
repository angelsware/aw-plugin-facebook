#ifndef __AW_FACEBOOK_CLIENT_LISTENER_H__
#define __AW_FACEBOOK_CLIENT_LISTENER_H__

namespace Facebook {
	class IClientListener
	{
	public:
		virtual void onFacebookSignInSuccess(const char* displayName, const char* email, const char* fbId, const char* accessToken) = 0;
		virtual void onFacebookSignInFailed() = 0;

	protected:
		virtual ~IClientListener() {}
	};
}

#endif
