/*
 * author: Max Kellermann <mk@cm4all.com>
 */

#ifndef HTTP_HTTP_H
#define HTTP_HTTP_H

#include <http/method.h>
#include <http/status.h>

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>


extern const char *http_status_to_string_data[6][20];

static inline bool
http_status_is_valid(http_status_t status)
{
    return (status / 100) < sizeof(http_status_to_string_data) /
        sizeof(http_status_to_string_data[0]) &&
        status % 100 < sizeof(http_status_to_string_data[0]) /
        sizeof(http_status_to_string_data[0][0]) &&
        http_status_to_string_data[status / 100][status % 100] != NULL;
}

static inline const char *
http_status_to_string(http_status_t status)
{
    assert(http_status_is_valid(status));

    return http_status_to_string_data[status / 100][status % 100];
}

static inline bool
http_status_is_success(http_status_t status)
{
    return status >= 200 && status < 300;
}

static inline bool
http_status_is_redirect(http_status_t status)
{
    return status >= 300 && status < 400;
}

static inline bool
http_status_is_client_error(http_status_t status)
{
    return status >= 400 && status < 500;
}

static inline bool
http_status_is_server_error(http_status_t status)
{
    return status >= 500 && status < 600;
}

static inline bool
http_status_is_error(http_status_t status)
{
    return status >= 400 && status < 600;
}

static inline bool
http_status_is_empty(http_status_t status)
{
    return status == HTTP_STATUS_CONTINUE ||
        status == HTTP_STATUS_NO_CONTENT ||
        status == HTTP_STATUS_RESET_CONTENT ||
        status == HTTP_STATUS_NOT_MODIFIED;
}

/**
 * Determines if the specified name consists only of valid characters
 * (RFC 822 3.2).
 */
bool
http_header_name_valid(const char *name);

/**
 * Determines if the specified name is a hop-by-hop header.  In
 * addition to the list in RFC 2616 13.5.1, "Content-Length" is also a
 * hop-by-hop header according to this function.
 */
bool
http_header_is_hop_by_hop(const char *name);

#endif
