/*
 * author: Max Kellermann <mk@cm4all.com>
 */

#include <http/method.h>

const char *http_method_to_string_data[HTTP_METHOD_INVALID] = {
    [HTTP_METHOD_HEAD] = "HEAD",
    [HTTP_METHOD_GET] = "GET",
    [HTTP_METHOD_POST] = "POST",
    [HTTP_METHOD_PUT] = "PUT",
    [HTTP_METHOD_DELETE] = "DELETE",
    [HTTP_METHOD_OPTIONS] = "OPTIONS",
    [HTTP_METHOD_TRACE] = "TRACE",

    /* WebDAV methods */
    [HTTP_METHOD_PROPFIND] = "PROPFIND",
    [HTTP_METHOD_PROPPATCH] = "PROPPATCH",
    [HTTP_METHOD_MKCOL] = "MKCOL",
    [HTTP_METHOD_COPY] = "COPY",
    [HTTP_METHOD_MOVE] = "MOVE",
    [HTTP_METHOD_LOCK] = "LOCK",
    [HTTP_METHOD_UNLOCK] = "UNLOCK",

    /* RFC 5789 */
    [HTTP_METHOD_PATCH] = "PATCH",
};
