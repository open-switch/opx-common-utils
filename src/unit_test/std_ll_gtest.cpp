/*
 * Copyright (c) 2018 Dell Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 * FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
 *
 * See the Apache Version 2.0 License for specific language governing
 * permissions and limitations under the License.
 */

/*
 * filename: std_ll_gtest.cpp
 */

/*
 * std_ll_gtest.cpp
 *
 */


#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "gtest/gtest.h"

extern "C" {
#include "std_llist.h"
}

typedef struct my_s {
        std_dll lst;
        int value;
        char *msg;
}my_;

my_* alloc(int id, char *msg) {
        my_ *p = (my_ *) malloc(sizeof(my_)+strlen(msg)+1);
        if (p==NULL) return NULL;
        char *mptr = ( (char*)p ) + sizeof(my_);
        p->msg = mptr;
        p->value = id;
        strcpy(mptr,msg);
        return p;
}

TEST(std_ll_test, Insert)
{
        std_dll_head list;
        my_ *walk = NULL;

        std_dll_init_sort(&list,std_compare_int_function,offsetof(my_,value),sizeof(int));
        std_dll_insert(&list,(std_dll*)alloc(0,(char *)"Clifford"));
        walk = (my_*)std_dll_getfirst(&list);

        ASSERT_TRUE(walk != NULL);
}


TEST(std_ll_test, SortedList)
{
        std_dll_head list;
        std_dll_init_sort(&list,std_compare_int_function,offsetof(my_,value),sizeof(int));

        std_dll_insert(&list,(std_dll*)alloc(0,(char *)"Clifford"));
        std_dll_insert(&list,(std_dll*)alloc(3,(char *)"Clifford"));
        std_dll_insert(&list,(std_dll*)alloc(6,(char *)"Clifford"));
        //std_dll_insert(&list,(std_dll*)alloc(2,(char *)"Clifford"));


        my_* walk = (my_*)std_dll_getfirst(&list);

        ASSERT_TRUE(walk != NULL);


        while (walk != NULL)
        {
                printf("Value is %d\n",walk->value);
                my_* next = (my_*)std_dll_getnext(&list,(std_dll*)walk);
                if(next == NULL) break;
                ASSERT_LT(walk->value, next->value);
                walk = next;
        }
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

