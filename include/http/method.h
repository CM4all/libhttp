// SPDX-License-Identifier: BSD-2-Clause
// Copyright CM4all GmbH
// author: Max Kellermann <mk@cm4all.com>

#pragma once

#include <stdbool.h>
#include <assert.h>

typedef enum {
    HTTP_METHOD_NULL = 0,
    HTTP_METHOD_HEAD,
    HTTP_METHOD_GET,
    HTTP_METHOD_POST,
    HTTP_METHOD_PUT,
    HTTP_METHOD_DELETE,
    HTTP_METHOD_OPTIONS,
    HTTP_METHOD_TRACE,

    /* WebDAV methods */
    HTTP_METHOD_PROPFIND,
    HTTP_METHOD_PROPPATCH,
    HTTP_METHOD_MKCOL,
    HTTP_METHOD_COPY,
    HTTP_METHOD_MOVE,
    HTTP_METHOD_LOCK,
    HTTP_METHOD_UNLOCK,

    /* RFC 5789 */
    HTTP_METHOD_PATCH,

    /* Versioning Extensions to WebDAV methods (RFC3253) */
    HTTP_METHOD_REPORT,

    HTTP_METHOD_INVALID,
} http_method_t;

extern const char *http_method_to_string_data[HTTP_METHOD_INVALID];

static inline bool
http_method_is_valid(http_method_t method)
{
    return method > HTTP_METHOD_NULL && method < HTTP_METHOD_INVALID;
}

static inline bool
http_method_is_empty(http_method_t method)
{
    /* RFC 2616 4.3: "All responses to the HEAD request method MUST
       NOT include a message-body, even though the presence of entity
       header fields might lead one to believe they do." */
    return method == HTTP_METHOD_HEAD;
}

static inline const char *
http_method_to_string(http_method_t method)
{
    assert(method < sizeof(http_method_to_string_data) / sizeof(http_method_to_string_data[0]));
    assert(http_method_to_string_data[method]);

    return http_method_to_string_data[method];
}
