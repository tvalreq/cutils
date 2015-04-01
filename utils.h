/* 
   Copyright (C) 2015 Tito Valencia

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 3 of the License, or any later version.

   This library is distributed WITHOUT ANY WARRANTY. See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define CONTENT_TYPE uint32_t

/*
 * ==================
 * ====== LIST ======
 * ==================
*/

/*
    List item
*/
typedef struct item{
    CONTENT_TYPE content;
    struct item* next;
} item_t;

/*
  Inserts element node to the end of the list pointed by head
*/
#define LIST_APPEND(head,node)                      \
   ({                                               \
        __typeof__ (head) _head = (head);           \
        __typeof__ (node) _node = (node);           \
        __typeof__ (node) _tmp;                     \
        _node->next = NULL;                         \
        if(_head) {                                 \
            _tmp = _head;                           \
            while(_tmp->next) { _tmp = _tmp->next; }\
            _tmp->next = _node;                     \
        }else { (head) = _node; }                   \
    })

/*
  Removes element node from the list pointed by head.
  Doesn't release the space of the node.
*/
#define LIST_REMOVE(head,node)                              \
   ({                                                       \
        __typeof__ (head) _head = (head);                   \
        __typeof__ (node) _node = (node);                   \
        __typeof__ (node) _tmp;                             \
        if (_head && _node) {                               \
            if (_head == _node) {                           \
                (head) = _node->next;                       \
            }else {                                         \
                _tmp = _head;                               \
                while (_tmp->next && _tmp->next != _node) { \
                    _tmp = _tmp->next;                      \
                }                                           \
                if (_tmp->next)                             \
                    _tmp->next = _node->next;               \
            }                                               \
        }                                                   \
    })


