/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 2001
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Javier Delgadillo <javi@netscape.com>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */
#ifndef _nsCrypto_h_
#define _nsCrypto_h_
#include "nsCOMPtr.h"
#include "nsIDOMCRMFObject.h"
#include "nsIDOMCrypto.h"
#include "nsIDOMPkcs11.h"
#include "nsIRunnable.h"
#include "nsString.h"
#include "nsNSSEvent.h"
#include "jsapi.h"
#include "nsIPrincipal.h"
#include "plevent.h"

#define NS_CRYPTO_CLASSNAME "Crypto JavaScript Class"
#define NS_CRYPTO_CID \
  {0x929d9320, 0x251e, 0x11d4, { 0x8a, 0x7c, 0x00, 0x60, 0x08, 0xc8, 0x44, 0xc3} }

#define NS_PKCS11_CLASSNAME "Pkcs11 JavaScript Class"
#define NS_PKCS11_CID \
  {0x74b7a390, 0x3b41, 0x11d4, { 0x8a, 0x80, 0x00, 0x60, 0x08, 0xc8, 0x44, 0xc3} }

#define PSM_VERSION_STRING "2.4"

class nsIPSMComponent;
class nsIDOMScriptObjectFactory;


class nsCRMFObject : public nsIDOMCRMFObject
{
public:
  nsCRMFObject();
  virtual ~nsCRMFObject();

  NS_DECL_NSIDOMCRMFOBJECT
  NS_DECL_ISUPPORTS

  nsresult init();

  nsresult SetCRMFRequest(char *inRequest);
private:

  nsString mBase64Request;
};


class nsCrypto: public nsIDOMCrypto
{
public:
  nsCrypto();
  virtual ~nsCrypto();
  nsresult init();
  
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCRYPTO

private:
  static already_AddRefed<nsIPrincipal> GetScriptPrincipal(JSContext *cx);

  PRBool mEnableSmartCardEvents;
};

class nsPkcs11 : public nsIDOMPkcs11
{
public:
  nsPkcs11();
  virtual ~nsPkcs11();

  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPKCS11

};

//
// This is the class we'll use to post ui events
//
struct CryptoRunnableEvent : PLEvent {
  CryptoRunnableEvent(nsIRunnable* runnable);
  ~CryptoRunnableEvent();

   nsIRunnable* mRunnable;
};


#endif //_nsCrypto_h_




