/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit
 *  ==========
 *  Copyright (C) 2015-2017 Treasure Data Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef FLB_FILTER_KUBE_CONF_H
#define FLB_FILTER_KUBE_CONF_H

#include <fluent-bit/flb_info.h>
#include <fluent-bit/flb_filter.h>
#include <fluent-bit/flb_config.h>
#include <fluent-bit/flb_upstream.h>
#include <fluent-bit/flb_macros.h>
#include <fluent-bit/flb_regex.h>

/*
 * Since this filter might get a high number of request per second,
 * we need to keep some cached data to perform filtering, e.g:
 *
 *  tag -> regex: pod name, container ID, container name, etc
 *
 * By default, we define a hash table for 256 entries.
 */
#define FLB_HASH_TABLE_SIZE 256

/* Kubernetes API server info */
#define FLB_API_HOST  "127.0.0.1"
#define FLB_API_PORT  80
#define FLB_API_TLS   FLB_FALSE
#define FLB_API_VER   "v1"

/* Cached metadata */
struct flb_kube_info {

};

/* Filter context */
struct flb_kube {
    /* Configuration parameters */
    char *api_host;
    int api_port;
    int api_https;

    struct flb_regex *regex_tag;

    /* Internal */
    struct flb_config *config;
    struct flb_hash *hash_table;
    struct flb_upstream *upstream;
};

struct flb_kube *flb_kube_conf_create(struct flb_filter_instance *i,
                                      struct flb_config *config);
void flb_kube_conf_destroy(struct flb_kube *ctx);

#endif
