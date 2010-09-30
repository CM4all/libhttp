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
};
