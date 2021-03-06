#ifndef __APPLEHELPERS_H__
#define __APPLEHELPERS_H__ 1

#define __COREFOUNDATION_CFFILESECURITY__
#include <CoreFoundation/CoreFoundation.h>

#define kDisabledByAdmin               1
#define kDisabledExpired               2
#define kDisabledInactive              3
#define kDisabledTooManyFailedLogins   4
#define kDisabledNewPasswordRequired   5

Entry *odusers_copy_entry(Operation *op);
int odusers_remove_authdata(char *slotid);
int odusers_get_authguid(Entry *e, char *guidstr);
Entry *odusers_copy_authdata(struct berval *dn);
Attribute *odusers_copy_globalpolicy(void);
CFDictionaryRef odusers_copy_effectiveuserpoldict(struct berval *dn);
CFDictionaryRef odusers_copy_defaultglobalpolicy(void);
int odusers_isdisabled(CFDictionaryRef policy);
bool odusers_isadmin(CFDictionaryRef policy);
struct berval *odusers_copy_dict2bv(CFDictionaryRef dict);
int odusers_increment_failedlogin(struct berval *dn);
int odusers_reset_failedlogin(struct berval *dn);
int odusers_successful_auth(struct berval *dn, CFDictionaryRef policy);
char *odusers_copy_saslrealm(void);
char *odusers_copy_suffix(void);
char *odusers_copy_krbrealm(Operation *op);
char *odusers_copy_recname(Operation *op);
char *odusers_copy_primarymasterip(Operation *op);
int odusers_set_password(struct berval *dn, char *password, int isChangingOwnPassword);
CFMutableDictionaryRef CopyPolicyToDict(const char *policyplist, int len);
int odusers_verify_passwordquality(const char *password, const char *username, CFDictionaryRef effectivepolicy, SlapReply *rs);
CFArrayRef odusers_copy_enabledmechs(const char *suffix);
int odusers_krb_auth(Operation *op, char *password);
char *odusers_copy_owner(struct berval *dn);
int odusers_store_history(struct berval *dn, const char *password, CFDictionaryRef policy);
int odusers_check_history(struct berval *dn, const char *password, CFDictionaryRef policy);
char *CopyPrimaryIPv4Address(void);

#endif /* __APPLEHELPERS_H__ */
