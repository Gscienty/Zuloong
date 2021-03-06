#ifndef _ZL_HTTP_INTERFACE_H
#define _ZL_HTTP_INTERFACE_H

#include <uv.h>
#include <openssl/ssl.h>

struct http {
    union {
        struct sockaddr_in v4;
        struct sockaddr_in6 v6;
    } addr;
    unsigned int delay;
    uv_loop_t event_looper;
    uv_tcp_t tcp_handler;
    int backlog;

    SSL_CTX * ctx;
};

/**
 * init http
 * @param http
 * @param fptr
 * 
 */
int zl_http_init(struct http * const http);

/**
 * set no delay
 * @param http
 * 
 */
int zl_http_nodelay(struct http * const http);

/**
 * set keep alive
 * @param http
 * 
 */
int zl_http_keeplive(struct http * const http);

/**
 * simultaneous accepts
 * @param http
 * 
 */
int zl_http_simultaneous(struct http * const http);

/**
 * run
 * @param http
 * 
 */
int zl_http_run(struct http * const http);

#endif
