/* ***** BEGIN LICENSE BLOCK *****
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
 * The Initial Developer of the Original Code is Jan Varga
 * Portions created by the Initial Developer are Copyright (C) 2003
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Valia Vaneeva <fattie@altlinux.ru>
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

#include "nsIGenericFactory.h"
#include "mozSqlService.h"
#ifdef MOZ_ENABLE_PGSQL
#include "mozSqlConnectionPgsql.h"
#endif
#ifdef MOZ_ENABLE_SQLITE
#include "mozSqlConnectionSqlite.h"
#endif
#ifdef MOZ_ENABLE_MYSQL
#include "mozSqlConnectionMysql.h"
#endif

NS_GENERIC_FACTORY_CONSTRUCTOR_INIT(mozSqlService, Init)
#ifdef MOZ_ENABLE_PGSQL
NS_GENERIC_FACTORY_CONSTRUCTOR(mozSqlConnectionPgsql)
#endif
#ifdef MOZ_ENABLE_SQLITE
NS_GENERIC_FACTORY_CONSTRUCTOR(mozSqlConnectionSqlite)
#endif
#ifdef MOZ_ENABLE_MYSQL
NS_GENERIC_FACTORY_CONSTRUCTOR(mozSqlConnectionMysql)
#endif

static nsModuleComponentInfo components[] =
{
  { MOZ_SQLSERVICE_CLASSNAME,
    MOZ_SQLSERVICE_CID,
    MOZ_SQLSERVICE_CONTRACTID,
    mozSqlServiceConstructor
  },
  { MOZ_SQLSERVICE_CLASSNAME,
    MOZ_SQLSERVICE_CID,
    MOZ_SQLDATASOURCE_CONTRACTID,
    mozSqlServiceConstructor
  }
#ifdef MOZ_ENABLE_PGSQL
  ,{ MOZ_SQLCONNECTIONPGSQL_CLASSNAME,
    MOZ_SQLCONNECTIONPGSQL_CID,
    MOZ_SQLCONNECTIONPGSQL_CONTRACTID,
    mozSqlConnectionPgsqlConstructor
  }
#endif
#ifdef MOZ_ENABLE_SQLITE
  ,{ MOZ_SQLCONNECTIONSQLITE_CLASSNAME,
    MOZ_SQLCONNECTIONSQLITE_CID,
    MOZ_SQLCONNECTIONSQLITE_CONTRACTID,
    mozSqlConnectionSqliteConstructor
  }
#endif
#ifdef MOZ_ENABLE_MYSQL
  ,{ MOZ_SQLCONNECTIONMYSQL_CLASSNAME,
    MOZ_SQLCONNECTIONMYSQL_CID,
    MOZ_SQLCONNECTIONMYSQL_CONTRACTID,
    mozSqlConnectionMysqlConstructor
  }
#endif
};

NS_IMPL_NSGETMODULE(mozSqlModule, components)
