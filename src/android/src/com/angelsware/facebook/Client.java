package com.angelsware.facebook;

import android.content.Intent;
import android.os.Bundle;

import com.angelsware.engine.ActivityResultListener;
import com.angelsware.engine.AppActivity;
import com.facebook.AccessToken;
import com.facebook.CallbackManager;
import com.facebook.FacebookCallback;
import com.facebook.FacebookException;
import com.facebook.GraphRequest;
import com.facebook.GraphResponse;
import com.facebook.login.LoginManager;
import com.facebook.login.LoginResult;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.Arrays;

public class Client implements ActivityResultListener {
	private CallbackManager mCallbackManager;

	private static native void onSignInSuccess(String displayName, String email, String fbId, String accessToken);
	private static native void onSignInFailed();

	public void create(long signInOptions) {
		AppActivity appActivity = (AppActivity)AppActivity.getActivity();
		appActivity.addActivityResultListener(this);

		mCallbackManager = CallbackManager.Factory.create();

		LoginManager.getInstance().registerCallback(mCallbackManager,
				new FacebookCallback<LoginResult>() {
					@Override
					public void onSuccess(LoginResult loginResult) {
						final AccessToken accessToken = loginResult.getAccessToken();

						GraphRequest request = GraphRequest.newMeRequest(loginResult.getAccessToken(), new GraphRequest.GraphJSONObjectCallback() {
							@Override
							public void onCompleted(JSONObject object, GraphResponse response) {
								if (response.getError() != null) {
									response.getError().getException().printStackTrace();
								}
								try {
									String email = response.getJSONObject().getString("email");
									String id = response.getJSONObject().getString("id");
									String name = response.getJSONObject().getString("name");
									onSignInSuccess(name, email, id, accessToken.getToken());
								} catch (JSONException e) {
									e.printStackTrace();
								}
							}
						});
						Bundle parameters = new Bundle();
						parameters.putString("fields", "id,name,email,picture");
						request.setParameters(parameters);
						request.executeAsync();
					}

					@Override
					public void onCancel() {
						onSignInFailed();
					}

					@Override
					public void onError(FacebookException exception) {
						onSignInFailed();
					}
				});
	}

	public void destroy() {
		AppActivity appActivity = (AppActivity)AppActivity.getActivity();
		appActivity.removeActivityResultListener(this);
	}

	public void trySilentSignIn() {
	}

	public void signIn() {
		LoginManager.getInstance().logInWithReadPermissions(AppActivity.getActivity(),
				Arrays.asList("public_profile", "email")
		);
	}

	public void logOut() {
		LoginManager.getInstance().logOut();
	}

	@Override
	public void onActivityResult(int requestCode, int resultCode, Intent data) {
		mCallbackManager.onActivityResult(requestCode, resultCode, data);
	}
}
