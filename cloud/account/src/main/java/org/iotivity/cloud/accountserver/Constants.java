/*
 * //******************************************************************
 * //
 * // Copyright 2016 Samsung Electronics All Rights Reserved.
 * //
 * //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 * //
 * // Licensed under the Apache License, Version 2.0 (the "License");
 * // you may not use this file except in compliance with the License.
 * // You may obtain a copy of the License at
 * //
 * //      http://www.apache.org/licenses/LICENSE-2.0
 * //
 * // Unless required by applicable law or agreed to in writing, software
 * // distributed under the License is distributed on an "AS IS" BASIS,
 * // WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * // See the License for the specific language governing permissions and
 * // limitations under the License.
 * //
 * //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 */
package org.iotivity.cloud.accountserver;

import org.iotivity.cloud.base.OICConstants;

public class Constants extends OICConstants {

    // Database name

    public static final String DB_NAME               = "ACCOUNTSERVER_DB";

    // Database table

    public static final String USER_TABLE            = "USER_TABLE";

    public static final String TOKEN_TABLE           = "TOKEN_TABLE";

    public static final String GROUP_TABLE           = "GROUP_TABLE";

    public static final String INVITE_TABLE          = "INVITE_TABLE";

    public static final String DEVICE_TABLE          = "DEVICE_TABLE";

    public static final String ACL_TABLE             = "ACL_TABLE";

    public static final String ACLTEMPLATE_TABLE     = "ACLTEMPLATE_TABLE";

    // Database table key

    public static final String KEYFIELD_UUID         = "uuid";

    public static final String KEYFIELD_ACCESSTOKEN  = "accesstoken";

    public static final String KEYFIELD_GID          = "gid";

    public static final String KEYFIELD_DID          = "did";

    public static final String KEYFIELD_ACLID        = "aclid";

    public static final String KEYFIELD_GTYPE        = "gtype";

    public static final String KEYFIELD_GIDLIST      = "gidlist";

    public static final String KEYFIELD_MIDLIST      = "midlist";

    public static final String KEYFIELD_GACL         = "gacl";

    public static final String KEYFIELD_USERID       = "userid";

    public static final String KEYFIELD_PROVIDER     = "provider";

    public static final String KEYFIELD_ISSUED_TIME  = "issuedtime";

    public static final String KEYFIELD_EXPIRED_TIME = "expiredtime";

    public static final String KEYFIELD_INVITE_USER  = "inviteUser";

    public static final String KEYFIELD_INVITED_USER = "invitedUser";

    // Request payload key

    public static final String REQ_DEVICE_ID         = "di";

    public static final String REQ_DEVICE_ID_LIST    = "dilist";

    public static final String REQ_UUID_ID           = "uid";

    public static final String REQ_AUTH_CODE         = "authcode";

    public static final String REQ_AUTH_PROVIDER     = "authprovider";

    public static final String REQ_ACCESS_TOKEN      = "accesstoken";

    public static final String REQ_LOGIN             = "login";

    public static final String REQ_REFRESH_TOKEN     = "refreshtoken";

    public static final String REQ_GRANT_TYPE        = "granttype";

    public static final String REQ_AUTH_OPTIONS      = "options";

    public static final String REQ_SEARCH_CRITERIA   = "search";

    public static final String REQ_GROUP_ID          = "gid";

    public static final String REQ_GROUP_MASTER_ID   = "gmid";

    public static final String REQ_GROUP_TYPE        = "gtype";

    public static final String REQ_MEMBER            = "mid";

    public static final String REQ_MEMBER_LIST       = "midlist";

    public static final String REQ_GTYPE_PRIVATE     = "Private";

    public static final String REQ_GTYPE_PUBLIC      = "Public";

    public static final String REQ_CSR               = "csr";

    public static final String REQ_INVITE            = "invite";

    // Response payload key

    public static final String RESP_ACCESS_TOKEN     = "accesstoken";

    public static final String RESP_REFRESH_TOKEN    = "refreshtoken";

    public static final String RESP_TOKEN_TYPE       = "tokentype";

    public static final String RESP_EXPIRES_IN       = "expiresin";

    public static final String RESP_REDIRECT_URI     = "redirecturi";

    public static final String RESP_CERTIFICATE      = "certificate";

    public static final String RESP_SERVER_ID        = "sid";

    public static final String RESP_DEVICES          = "devices";

    public static final String RESP_UUID             = "uid";

    public static final String RESP_USER_INFO        = "uinfo";

    public static final String RESP_USER_LIST        = "ulist";

    public static final String RESP_DEVICE_ID        = "di";

    public static final String RESP_CERT             = "cert";

    public static final String RESP_CACERT           = "cacert";

    public static final String RESP_INVITE           = "invite";

    public static final String RESP_INVITED          = "invited";

    // static token type

    public static final String TOKEN_TYPE_BEARER     = "bearer";

    public static final int    TOKEN_INFINITE        = -1;

    // auth servers

    public static final String GITHUB                = "Github";

    public static final String SAMSUNG               = "Samsung";
}
