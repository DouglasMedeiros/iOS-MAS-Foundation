//
//  MASAuthCredentialsJWT.m
//  MASFoundation
//
//  Created by Hun Go on 2017-05-31.
//  Copyright © 2017 CA Technologies. All rights reserved.
//

#import "MASAuthCredentialsJWT.h"

#import "MASAccessService.h"
#import "MASAuthCredentials+MASPrivate.h"
#import "MASSecurityService.h"
#import "MASModelService.h"
#import "NSError+MASPrivate.h"


@implementation MASAuthCredentialsJWT

@synthesize credentialsType = _credentialsType;
@synthesize canRegisterDevice = _canRegisterDevice;
@synthesize isReuseable = _isReuseable;


# pragma mark - LifeCycle

+ (MASAuthCredentialsJWT *)initWithJWT:(NSString *)jwt tokenType:(NSString *)tokenType
{
    MASAuthCredentialsJWT *authCredentials = [[self alloc] initPrivateWithJWT:jwt tokenType:tokenType];
    
    return authCredentials;
}


- (instancetype)initPrivateWithJWT:(NSString *)jwt tokenType:(NSString *)tokenType
{
    self = [super initPrivate];
    
    if(self) {
        _jwt = jwt;
        _tokenType = tokenType;
        _credentialsType = _tokenType;
        
        if (!_tokenType || [_tokenType length] == 0)
        {
            _tokenType = @"jwt";
        }
        
        _canRegisterDevice = YES;
        _isReuseable = YES;
    }
    
    return self;
}


# pragma mark - Public

- (void)clearCredentials
{
    _jwt = nil;
    _tokenType = nil;
}


# pragma mark - Private

- (void)loginWithCredential:(MASCompletionErrorBlock)completion
{
    __block MASCompletionErrorBlock blockCompletion = completion;
    
    [super loginWithCredential:^(BOOL completed, NSError *error) {
    
        if (error)
        {
            //
            // If there is an error from the server complaining about invalid token,
            // invalidate local id_token and id_token_type and revalidate the user's session.
            //
            [[MASAccessService sharedService] setAccessValueString:nil withAccessValueType:MASAccessValueTypeIdToken];
            [[MASAccessService sharedService] setAccessValueString:nil withAccessValueType:MASAccessValueTypeIdTokenType];
            [[MASAccessService sharedService].currentAccessObj refresh];
        }
        
        if (blockCompletion)
        {
            blockCompletion(completed, error);
        }
    }];
}


- (NSString *)getRegisterEndpoint
{
    return [MASConfiguration currentConfiguration].deviceRegisterEndpointPath;
}


- (NSString *)getTokenEndpoint
{
    return [MASConfiguration currentConfiguration].tokenEndpointPath;
}


- (NSDictionary *)getHeaders
{
    NSMutableDictionary *headerInfo = [NSMutableDictionary dictionary];
    
    //
    //  For device registration headers
    //
    if (![MASDevice currentDevice].isRegistered)
    {
        // Authorization with 'Authorization' header key
        NSString *authorization = [NSString stringWithFormat:@"Bearer %@", _jwt];
        if (_jwt)
        {
            headerInfo[MASAuthorizationRequestResponseKey] = authorization;
        }
        
        if (_tokenType)
        {
            headerInfo[MASAuthorizationTypeRequestResponseKey] = _tokenType;
        }
    }
    //
    //  For user authentication headers
    //
    else {
        
    }
    return headerInfo;
}


- (NSDictionary *)getParameters
{
    NSMutableDictionary *parameterInfo = [NSMutableDictionary dictionary];
    
    //
    //  For device registration parameters
    //
    if (![MASDevice currentDevice].isRegistered)
    {
        // Certificate Signing Request
        MASSecurityService *securityService = [MASSecurityService sharedService];
        [securityService deleteAsymmetricKeys];
        [securityService generateKeypair];
        NSString *certificateSigningRequest = [securityService generateCSRWithUsername:@"socialLogin"];
        
        if (certificateSigningRequest)
        {
            parameterInfo[MASCertificateSigningRequestResponseKey] = certificateSigningRequest;
        }
    }
    //
    //  For user authentication parameters
    //
    else {
        
        // JWT
        if (_jwt)
        {
            parameterInfo[MASAssertionRequestResponseKey] = _jwt;
        }
        
        // token type of JWT
        if (_tokenType)
        {
            parameterInfo[MASGrantTypeRequestResponseKey] = _tokenType;
        }
    }
    
    return parameterInfo;
}

@end
