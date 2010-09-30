/*
 * author: Max Kellermann <mk@cm4all.com>
 */

#ifndef HTTP_METHOD_H
#define HTTP_METHOD_H

#include <stdbool.h>
#include <assert.h>

typedef enum {
    HTTP_METHOD_NULL = 0,
    HTTP_METHOD_HEAD,
    HTTP_METHOD_GET,
    HTTP_METHOD_POST,
    HTTP_METHOD_PUT,
    HTTP_METHOD_DELETE,
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

#endif
