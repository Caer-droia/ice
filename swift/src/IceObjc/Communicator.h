//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#import "LocalObject.h"

@class ICEObjectPrx;
@class ICEImplicitContext;
@class ICEProperties;
@class ICEObjectAdapter;
@protocol ICELoggerProtocol;
@protocol ICEBlobjectFacade;

NS_ASSUME_NONNULL_BEGIN

@interface ICECommunicator : ICELocalObject
-(void) destroy;
-(void) shutdown;
-(void) waitForShutdown;
-(bool) isShutdown;
-(nullable id) stringToProxy:(NSString*)str error:(NSError**)error;
-(nullable id) propertyToProxy:(NSString*)property error:(NSError**)error
NS_SWIFT_NAME(propertyToProxy(property:));
-(nullable NSDictionary<NSString*, NSString*>*) proxyToProperty:(ICEObjectPrx*)prx property:(NSString*)property error:(NSError**)error;
-(nullable ICEObjectAdapter*) createObjectAdapter:(NSString*)name error:(NSError**)error;
-(nullable ICEObjectAdapter*) createObjectAdapterWithEndpoints:(NSString*)name endpoints:(NSString*)endpoints error:(NSError**)error NS_SWIFT_NAME(createObjectAdapterWithEndpoints(name:endpoints:));;
-(nullable ICEObjectAdapter*) createObjectAdapterWithRouter:(NSString*)name router:(ICEObjectPrx*)router error:(NSError**)error NS_SWIFT_NAME(createObjectAdapterWithRouter(name:router:));
-(ICEImplicitContext*) getImplicitContext;
-(id<ICELoggerProtocol>) getLogger;
-(nullable ICEObjectPrx*) getDefaultRouter;
-(BOOL) setDefaultRouter:(ICEObjectPrx* _Nullable)router error:(NSError**)error;
-(nullable ICEObjectPrx*) getDefaultLocator;
-(BOOL) setDefaultLocator:(ICEObjectPrx* _Nullable)locator error:(NSError**)error;
-(BOOL) flushBatchRequests:(uint8_t)compress error:(NSError**)error;
-(BOOL) flushBatchRequestsAsync:(uint8_t)compress
                      exception:(void (^)(NSError*))exception
                           sent:(void (^_Nullable)(bool))sent
                          error:(NSError**)error;
-(nullable ICEObjectPrx*) createAdmin:(ICEObjectAdapter* _Nullable)adminAdapter
                                 name:(NSString*)name
                             category:(NSString*)category
                                error:(NSError**)error;
-(nullable id) getAdmin:(NSError**)error;
-(BOOL) addAdminFacet:(id<ICEBlobjectFacade>)servant facet:(NSString*)facet error:(NSError**)error;
-(nullable id<ICEBlobjectFacade>) removeAdminFacet:(NSString*)facet error:(NSError**)error;
-(nullable id) findAdminFacet:(NSString*)facet error:(NSError**)error;
-(nullable NSDictionary<NSString*, id<ICEBlobjectFacade>>*) findAllAdminFacets:(NSError**)error;

-(ICEProperties*) getProperties;

// DefaultsAndOverrides
-(void) getDefaultEncoding:(nonnull uint8_t*)major minor:(nonnull uint8_t*)minor
    NS_SWIFT_NAME(getDefaultEncoding(major:minor:));
-(uint8_t) getDefaultFormat;

-(void) setSslCertificateVerifier:(nullable bool (^)(id))verifier;
-(void) setSslPasswordPrompt:(nullable NSString* (^)())prompt;
-(BOOL) initializePlugins: (NSError**)error;
@end

#ifdef __cplusplus

@interface ICECommunicator()
@property (nonatomic, readonly) std::shared_ptr<Ice::Communicator> communicator;
@end

#endif

NS_ASSUME_NONNULL_END
