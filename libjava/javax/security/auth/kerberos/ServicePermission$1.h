
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_security_auth_kerberos_ServicePermission$1__
#define __javax_security_auth_kerberos_ServicePermission$1__

#pragma interface

#include <java/security/PermissionCollection.h>
extern "Java"
{
  namespace java
  {
    namespace security
    {
        class Permission;
    }
  }
  namespace javax
  {
    namespace security
    {
      namespace auth
      {
        namespace kerberos
        {
            class ServicePermission;
            class ServicePermission$1;
        }
      }
    }
  }
}

class javax::security::auth::kerberos::ServicePermission$1 : public ::java::security::PermissionCollection
{

public: // actually package-private
  ServicePermission$1(::javax::security::auth::kerberos::ServicePermission *);
public:
  virtual void add(::java::security::Permission *);
  virtual jboolean implies(::java::security::Permission *);
  virtual ::java::util::Enumeration * elements();
private:
  ::java::util::Vector * __attribute__((aligned(__alignof__( ::java::security::PermissionCollection)))) permissions;
public: // actually package-private
  ::javax::security::auth::kerberos::ServicePermission * this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_security_auth_kerberos_ServicePermission$1__
