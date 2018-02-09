//
//  RCBackend.h
//  Purchases
//
//  Created by Jacob Eiting on 9/30/17.
//  Copyright © 2017 RevenueCat, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RCPurchaserInfo, RCHTTPClient;

FOUNDATION_EXPORT NSErrorDomain const RCBackendErrorDomain;

NS_ERROR_ENUM(RCBackendErrorDomain) {
    RCFinishableError = 0,
    RCUnfinishableError,
    RCUnexpectedBackendResponse 
};

typedef void(^RCBackendResponseHandler)(RCPurchaserInfo * _Nullable,
                                        NSError * _Nullable);

@interface RCBackend : NSObject

- (instancetype _Nullable)initWithAPIKey:(NSString *)APIKey;

- (instancetype _Nullable)initWithHTTPClient:(RCHTTPClient *)client
                                      APIKey:(NSString *)APIKey;

- (void)postReceiptData:(NSData *)data
              appUserID:(NSString *)appUserID
              isRestore:(BOOL)isRestore
      productIdentifier:(NSString * _Nullable)productIdentifier
                  price:(NSDecimalNumber * _Nullable)price
      introductoryPrice:(NSDecimalNumber * _Nullable)introductoryPrice
           currencyCode:(NSString * _Nullable)currencyCode
             completion:(RCBackendResponseHandler)completion;

- (void)getSubscriberDataWithAppUserID:(NSString *)appUserID
                            completion:(RCBackendResponseHandler)completion;

@end

NS_ASSUME_NONNULL_END
