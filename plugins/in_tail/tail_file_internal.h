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

#ifndef FLB_TAIL_INTERNAL_H
#define FLB_TAIL_INTERNAL_H

#include <fluent-bit/flb_input.h>

#include "tail.h"
#include "tail_config.h"

struct flb_tail_file {
    /* Inotify */
    int watch_fd;

    /* file lookup info */
    int fd;
    off_t size;
    off_t offset;
    off_t last_line;
    ino_t inode;
    char *name;
    time_t rotated;

    /* dynamic tag for this file */
    int tag_len;
    char *tag_buf;

    /* buffering */
    off_t parsed;
    off_t buf_len;
    char buf_data[FLB_TAIL_CHUNK];

    /* Opaque data type for specific fs-event backend data */
    void *fs_backend;

    /* reference */
    int tail_mode;
    struct flb_tail_config *config;
    struct mk_list _head;
    struct mk_list _rotate_head;
};

#endif
