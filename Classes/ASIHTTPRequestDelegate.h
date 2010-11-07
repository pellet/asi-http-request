//
//  ASIHTTPRequestDelegate.h
//  Part of ASIHTTPRequest -> http://allseeing-i.com/ASIHTTPRequest
//
//  Created by Ben Copsey on 13/04/2010.
//  Copyright 2010 All-Seeing Interactive. All rights reserved.
//

@class ASIHTTPRequest;

@protocol ASIHTTPRequestDelegate <NSObject>

@optional

// These are the default delegate methods for request status
// You can use different ones by setting didStartSelector / didFinishSelector / didFailSelector
- (void)requestStarted:(ASIHTTPRequest *)request;
- (void)requestReceivedResponseHeaders:(ASIHTTPRequest *)request;
- (void)requestFinished:(ASIHTTPRequest *)request;
- (void)requestFailed:(ASIHTTPRequest *)request;

// When a delegate implements this method, it is expected to process all incoming data itself
// This means that responseData / responseString / downloadDestinationPath etc are ignored
// You can have the request call a different method by setting didReceiveDataSelector
- (void)request:(ASIHTTPRequest *)request didReceiveData:(NSData *)data;

// If the delegate implements this method, the will call this method on a time out
// This method is useful when the didReceiveData method was implemented on the delegate and the data 
// is required to be refreshed on before a retry
- (void)requestTimedOut:(ASIHTTPRequest *)request;

// If a delegate implements one of these, it will be asked to supply credentials when none are available
// The delegate can then either restart the request ([request retryUsingSuppliedCredentials]) once credentials have been set
// or cancel it ([request cancelAuthentication])
- (void)authenticationNeededForRequest:(ASIHTTPRequest *)request;
- (void)proxyAuthenticationNeededForRequest:(ASIHTTPRequest *)request;

@end
