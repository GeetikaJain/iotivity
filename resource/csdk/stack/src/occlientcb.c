//******************************************************************
//
// Copyright 2014 Intel Mobile Communications GmbH All Rights Reserved.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=


#include "occlientcb.h"
#include "occoap.h"
#include "utlist.h"
#include "logger.h"
#include "ocmalloc.h"
#include <string.h>

/// Module Name
#define TAG PCF("occlientcb")

struct ClientCB *cbList = NULL;
OCMulticastNode * mcPresenceNodes = NULL;

OCStackResult AddClientCB(ClientCB** clientCB, OCCallbackData* cbData,
        OCCoAPToken * token, OCDoHandle handle, OCMethod method,
        unsigned char * requestUri, unsigned char * resourceType) {
    ClientCB *cbNode;
    cbNode = (ClientCB*) OCMalloc(sizeof(ClientCB));
    if (cbNode) {
        cbNode->callBack = cbData->cb;
        cbNode->context = cbData->context;
        cbNode->deleteCallback = cbData->cd;
        memcpy(&(cbNode->token), token, sizeof(OCCoAPToken));
        cbNode->handle = handle;
        cbNode->method = method;
        cbNode->sequenceNumber = 0;
        #ifdef WITH_PRESENCE
        cbNode->presence = NULL;
        cbNode->filterResourceType = resourceType;
        #endif
        cbNode->requestUri = requestUri;
        LL_APPEND(cbList, cbNode);
        *clientCB = cbNode;
        return OC_STACK_OK;
    }
    *clientCB = NULL;
    return OC_STACK_NO_MEMORY;
}

void DeleteClientCB(ClientCB * cbNode) {
    if(cbNode) {
        LL_DELETE(cbList, cbNode);
        OC_LOG(INFO, TAG, PCF("deleting tokens"));
        OC_LOG_BUFFER(INFO, TAG, cbNode->token.token, cbNode->token.tokenLength);
        OCFree(cbNode->handle);
        OCFree(cbNode->requestUri);
        if(cbNode->deleteCallback)
        {
            cbNode->deleteCallback(cbNode->context);
        }

        #ifdef WITH_PRESENCE
        if(cbNode->presence) {
            OCFree(cbNode->presence->timeOut);
            OCFree(cbNode->presence);
            OCFree(cbNode->filterResourceType);
        }
        #endif
        OCFree(cbNode);
        cbNode = NULL;
    }
}

ClientCB* GetClientCB(OCCoAPToken * token, OCDoHandle handle, unsigned char * requestUri) {
    ClientCB* out = NULL;
    if(token) {
        LL_FOREACH(cbList, out) {
            OC_LOG(INFO, TAG, PCF("comparing tokens"));
            OC_LOG_BUFFER(INFO, TAG, token->token, token->tokenLength);
            OC_LOG_BUFFER(INFO, TAG, out->token.token, out->token.tokenLength);
            if((out->token.tokenLength == token->tokenLength) &&
                (memcmp(out->token.token, token->token, token->tokenLength) == 0) ) {
                return out;
            }
        }
    }
    else if(handle) {
        LL_FOREACH(cbList, out) {
            if(out->handle == handle) {
                return out;
            }
        }
    }
    else if(requestUri) {
        LL_FOREACH(cbList, out) {
            if(out->requestUri && strcmp((char *)out->requestUri, (char *)requestUri) == 0) {
                return out;
            }
        }
    }
    OC_LOG(INFO, TAG, PCF("Callback Not found !!"));
    return NULL;
}


void DeleteClientCBList() {
    ClientCB* out;
    ClientCB* tmp;
    LL_FOREACH_SAFE(cbList, out, tmp) {
        DeleteClientCB(out);
    }
    cbList = NULL;
}

void FindAndDeleteClientCB(ClientCB * cbNode) {
    ClientCB* tmp;
    if(cbNode)
    {
        LL_FOREACH(cbList, tmp)
        {
            if (cbNode == tmp)
            {
                DeleteClientCB(tmp);
                break;
            }
        }
    }
}

OCStackResult AddMCPresenceNode(OCMulticastNode** outnode, unsigned char* uri, uint32_t nonce)
{
    OCMulticastNode *node;

    node = (OCMulticastNode*) OCMalloc(sizeof(OCMulticastNode));

    if (node) {
        node->nonce = nonce;
        node->uri = uri;
        LL_APPEND(mcPresenceNodes, node);
        *outnode = node;
        return OC_STACK_OK;
    }
    *outnode = NULL;
    return OC_STACK_NO_MEMORY;
}

OCMulticastNode* GetMCPresenceNode(unsigned char * uri) {
    OCMulticastNode* out = NULL;

    if(uri) {
        LL_FOREACH(mcPresenceNodes, out) {
            if(out->uri && strcmp((char *)out->uri, (char *)uri) == 0) {
                return out;
            }
        }
    }
    OC_LOG(INFO, TAG, PCF("MulticastNode Not found !!"));
    return NULL;
}
