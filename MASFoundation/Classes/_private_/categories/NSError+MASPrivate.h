//
//  NSError+MASPrivate.h
//  MASFoundation
//
//  Copyright (c) 2016 CA, Inc.
//
//  This software may be modified and distributed under the terms
//  of the MIT license. See the LICENSE file for details.
//

@import Foundation;

#import "MASConstantsPrivate.h"


@interface NSError (MASPrivate)


///--------------------------------------
/// @name Create general errors
///--------------------------------------

# pragma mark - Create general errors


/**
 * Creates a MAS friendly NSError for the given API error code contained within an HTTP
 * response info NSDictionary, if any.  If not it will check the original NSError for
 * other types of errors, i.e. network issues.
 *
 * All errors will include the following standard keys with applicable values:
 *
 *    NSLocalizedDescriptionKey
 *
 * @param responseInfo The HTTP response info NSDictionary.
 * @param error The original NSError.
 * @returns Returns the MAS friendly NSError instance.
 */
+ (NSError *)errorFromApiResponseInfo:(NSDictionary *)responseInfo andError:(NSError *)error;


/**
 *  Creates a MAS friendly NSError for the given NSError with response info NSDictionary from the server.
 *  A NSError will be created based on response info's contents from MAS' standard format of MASResponseInfoHeaderInfoKey and MASResponseInfoBodyInfoKey.
 *  If the response does not contain sufficient information to create an error, the error will be created based on given NSError with given errorDomain.
 *
 *  @param responseInfo The HTTP response info NSDictionary.
 *  @param error        The original NSError.
 *  @param errorDomain  The error domain for this particular error.
 *
 *  @return Returns the MAS friendly NSError instance.
 */
+ (NSError *)errorForFoundationWithResponseInfo:(NSDictionary *)responseInfo error:(NSError *)error errorDomain:(NSString *)errorDomain;


/**
 * Creates an NSError for the given MASFoundationErrorCode.  These errors will fall
 * under the specified domain in parameter.
 *
 * This version is a convenience version without the info:(NSDictionary *)info
 * parameter for those that don't need to add any custom info.
 *
 * All errors will include the following standard keys with applicable values:
 *
 *    NSLocalizedDescriptionKey
 *
 * @param errorCode The MASFoundationErrorCode which identifies the error.
 * @param errorDomain The NSString of error domain.
 * @returns Returns the NSError instance.
 */
+ (NSError *)errorForFoundationCode:(MASFoundationErrorCode)errorCode errorDomain:(NSString *)errorDomain;


/**
 * Creates an NSError for the given MASFoundationErrorCode.  These errors will fall
 * under the sepcified domain in parameter.
 *
 * All errors will include the following standard keys with applicable values:
 *
 *    NSLocalizedDescriptionKey
 *
 * @param errorCode The MASFoundationErrorCode which identifies the error.
 * @param info An additional NSDictionary of custom values that can be included
 * in addition to the defaults included by this method.  Optional, nil is allowed.
 * @param errorDomain The NSString which identifies the domain of the error.
 * @returns Returns the NSError instance.
 */
+ (NSError *)errorForFoundationCode:(MASFoundationErrorCode)errorCode info:(NSDictionary *)info errorDomain:(NSString *)errorDomain;



///--------------------------------------
/// @name Create specific errors
///--------------------------------------

# pragma mark - Create specific error types


/**
 *  Create MASFoundationErrorDomainLocal NSError for MASFoundationErrorCodeInvalidDeviceRegistrationBlock.
 *
 *  @return Returns an NSError instance with the domain MASFoundationErrorDomainLocal and
 *  error code MASFoundationErrorCodeInvalidDeviceRegistrationBlock.
 */
+ (NSError *)errorInvalidDeviceRegistrationBlock;


/**
 *  Create MASFoundationErrorDomainLocal NSError for MASFoundationErrorCodeInvalidUserLoginBlock.
 *
 *  @return Returns an NSError instance with the domain MASFoundationErrorDomainLocal and 
 *  error code MASFoundationErrorCodeInvalidUserLoginBlock.
 */
+ (NSError *)errorInvalidUserLoginBlock;


/**
 *  Create MASFoundationErrorDomainLocal NSError for MASFoundationErrorCodeInvalidNSURL.
 *
 *  @return Retruns an NSError instance with the domain MASFoundationErrorDomainLocal and
 *  error code MASFoundationErrorCodeInvalidNSURL.
 */
+ (NSError *)errorInvalidNSURL;


/**
 *  Create MASFoundationErrorDomainLocal NSError for MASFoundationErrorCodeInvalidNSDictionary.
 *
 *  @return Retruns an NSError instance with the domain MASFoundationErrorDomainLocal and
 *  error code MASFoundationErrorCodeInvalidNSDictionary.
 */
+ (NSError *)errorInvalidNSDictionary;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeApplicationAlreadyRegistered.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeApplicationAlreadyRegistered.
 */
+ (NSError *)errorApplicationAlreadyRegistered;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeApplicationNotRegistered.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeApplicationNotRegistered.
 */
+ (NSError *)errorApplicationNotRegistered;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeConfigurationLoadingFailedFileNotFound.
 *
 * @param fileName The file name of the configuration file which could not be loaded.
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeConfigurationLoadingFailedFileNotFound.
 */
+ (NSError *)errorConfigurationLoadingFailedFileNotFound:(NSString *)fileName;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeConfigurationLoadingFailedJsonSerialization.
 *
 * @param fileName The file name of the configuration file which could not be loaded.
 * @param description The json serialization error description.
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeConfigurationLoadingFailedJsonSerialization.
 */
+ (NSError *)errorConfigurationLoadingFailedJsonSerialization:(NSString *)fileName description:(NSString *)description;


/**
 *  Create MASFoundationLocalErrorDomain NSError for MASFoundationErrorCodeConfigurationLoadingFailedJsonValidation.
 *
 *  @param description The json validation error description
 *
 *  @return Returns an NSerror instance with the domain MASFoundationErrorDomainLocal and error code MASFoundationErrorCodeConfigurationLoadingFailedJsonValidation.
 */
+ (NSError *)errorConfigurationLoadingFailedJsonValidationWithDescription:(NSString *)description;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeDeviceAlreadyRegistered.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeDeviceAlreadyRegistered.
 */
+ (NSError *)errorDeviceAlreadyRegistered;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeDeviceAlreadyRegisteredWithDifferentFlow.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeDeviceRegisteredWithDifferentFlow.
 */
+ (NSError *)errorDeviceAlreadyRegisteredWithDifferentFlow;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeDeviceCouldNotBeDeregistered.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeDeviceCouldNotBeDeregistered.
 */
+ (NSError *)errorDeviceCouldNotBeDeregistered;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeDeviceNotRegistered.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeDeviceNotRegistered.
 */
+ (NSError *)errorDeviceNotRegistered;


/**
 *  Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeDeviceNotLoggedIn
 *
 *  @return Returns an NSError instance with the domain MASFoundationErrorDomain and error code MASFoundationErrorCodeDeviceNotLoggedIn.
 */
+ (NSError *)errorDeviceNotLoggedIn;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeDeviceRegistrationAttempedWithUnregisteredScope.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeDeviceRegistrationAttemptedWithUnregisteredScope.
 */
+ (NSError *)errorDeviceRegistrationAttemptedWithUnregisteredScope;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeDeviceRegistrationWithoutRequiredParameters.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeDeviceWithoutRequiredParameters.
 */
+ (NSError *)errorDeviceRegistrationWithoutRequiredParameters;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeFlowIsNotActive.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeFlowIsNotActive.
 */
+ (NSError *)errorFlowIsNotActive;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeFlowIsNotImplemented.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeFlowIsNotImplemented.
 */
+ (NSError *)errorFlowIsNotImplemented;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeFlowTypeUnsupported.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeFlowTypeUnsupported.
 */
+ (NSError *)errorFlowTypeUnsupported;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeNetworkNotReachable.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeNetworkNotReachable.
 */
+ (NSError *)errorNetworkNotReachable;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeGeolocationIsInvalid.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeGeolocationIsInvalid.
 */
+ (NSError *)errorGeolocationIsInvalid;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeGeolocationIsMissing.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeGeolocationIsMissing.
 */
+ (NSError *)errorGeolocationIsMissing;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeGeolocationServicesAreUnauthorized.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeGeolocationServicesAreUnauthorized.
 */
+ (NSError *)errorGeolocationServicesAreUnauthorized;



/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeNetworkNotStarted.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error code MASFoundationErrorCodeNetworkNotStarted.
 */
+ (NSError *)errorNetworkNotStarted;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeUserAlreadyAuthenticated.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error codeSFoundationErrorCodeUserAlreadyAuthenticated.
 */
+ (NSError *)errorUserAlreadyAuthenticated;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeUserBasicCredentialsNotValid.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error codeSFoundationErrorCodeUserBasicCredentialsNotValid.
 */
+ (NSError *)errorUserBasicCredentialsNotValid;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeUserDoesNotExist.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error codeSFoundationErrorCodeUserDoesNotExist.
 */
+ (NSError *)errorUserDoesNotExist;


/**
 * Create MASFoundationErrorDomain NSError for MASFoundationErrorCodeUserNotAuthenticated.
 *
 * @returns Returns an NSError instance with the domain MASFoundationErrorDomain and
 * error codeSFoundationErrorCodeUserNotAuthenticated.
 */
+ (NSError *)errorUserNotAuthenticated;


/**
 * Create MASFoundationLocalErrorDomain NSError for MASFoundationErrorCodeTokenInvalidIdToken.
 *
 * @returns Returns an NSError instance with the domain MASFoundationLocalErrorDomain and
 * error MASFoundationErrorCodeTokenInvalidIdToken.
 */
+ (NSError *)errorInvalidIdToken;


/**
 * Create MASFoundationLocalErrorDomain NSError for MASFoundationErrorCodeTokenIdTokenExpired.
 *
 * @returns Returns an NSError instance with the domain MASFoundationLocalErrorDomain and
 * error MASFoundationErrorCodeTokenIdTokenExpired.
 */
+ (NSError *)errorIdTokenExpired;


/**
 * Create MASFoundationLocalErrorDomain NSError for MASFoundationErrorCodeTokenIdTokenInvalidSignature.
 *
 * @returns Returns an NSError instance with the domain MASFoundationLocalErrorDomain and
 * error MASFoundationErrorCodeTokenIdTokenInvalidSignature.
 */
+ (NSError *)errorIdTokenInvalidSignature;


/**
 * Create MASFoundationLocalErrorDomain NSError for MASFoundationErrorCodeTokenIdTokenInvalidAzp.
 *
 * @returns Returns an NSError instance with the domain MASFoundationLocalErrorDomain and
 * error MASFoundationErrorCodeTokenIdTokenInvalidAzp.
 */
+ (NSError *)errorIdTokenInvalidAzp;


/**
 * Create MASFoundationLocalErrorDomain NSError for MASFoundationErrorCodeTokenIdTokenInvalidAud.
 *
 * @returns Returns an NSError instance with the domain MASFoundationLocalErrorDomain and
 * error MASFoundationErrorCodeTokenIdTokenInvalidAud.
 */
+ (NSError *)errorIdTokenInvalidAud;


/**
 * Create MASFoundationLocalErrorDomain NSError for MASFoundationErrorCodeEnterpriseBrowserWebAppInvalidURL.
 *
 * @returns Returns an NSError instance with the domain MASFoundationLocalErrorDomain and
 * error MASFoundationErrorCodeEnterpriseBrowserWebAppInvalidURL.
 */
+ (NSError *)errorEnterpriseBrowserWebAppInvalidURL;


/**
 * Create MASFoundationLocalErrorDomain NSError for MASFoundationErrorCodeEnterpriseBrowserNativeAppDoesNotExist.
 *
 * @returns Returns an NSError instance with the domain MASFoundationLocalErrorDomain and
 * error MASFoundationErrorCodeEnterpriseBrowserNativeAppDoesNotExist.
 */
+ (NSError *)errorEnterpriseBrowserNativeAppDoesNotExist;


/**
 * Create MASFoundationLocalErrorDomain NSError for MASFoundationErrorCodeEnterpriseBrowserNativeAppCannotOpen.
 *
 * @returns Returns an NSError instance with the domain MASFoundationLocalErrorDomain and
 * error MASFoundationErrorCodeEnterpriseBrowserNativeAppCannotOpen.
 */
+ (NSError *)errorEnterpriseBrowserNativeAppCannotOpen;


/**
 * Create MASFoundationLocalErrorDomain NSError for MASFoundationErrorCodeEnterpriseBrowserAppDoesNotExist.
 *
 * @returns Returns an NSError instance with the domain MASFoundationLocalErrorDomain and
 * error MASFoundationErrorCodeEnterpriseBrowserAppDoesNotExist.
 */
+ (NSError *)errorEnterpriseBrowserAppDoesNotExist;


/**
 * Create MASFoundationLocalErrorDomain NSError for MASFoundationErrorCodeConfigurationInvalidEndpoint.
 *
 * @returns Returns an NSError instance with the domain MASFoundationLocalErrorDomain and
 * error MASFoundationErrorCodeConfigurationInvalidEndpoint.
 */
+ (NSError *)errorInvalidEndpoint;


/**
 *  Create MASFoundationLocalErrorDomain NSError for MASFoundationErrorCodeSessionSharingAuthorizationInProgress.
 *
 *  @return Returns an NSError instance with the domain MASFoundationLocalErrorDomain and 
 *  error MASFoundationErrorCodeSessionSharingAuthorizationInProgress.
 */
+ (NSError *)errorSessionSharingAuthorizationInProgress;

@end