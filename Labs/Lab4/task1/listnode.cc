//
//  listnode.cpp
//  EE205_lab2b
//
//  Created by Joseph Felix on 2/11/14.
//  Copyright (c) 2014 Joseph Phillip Felix Jr. All rights reserved.
//

#include "listnode.h"

ListNode::ListNode(Entry x)
{
    entry = x;
    *next = NULL;
}

Entry ListNode::getdata() const
{
    return entry;
}

ListNode* ListNode::getnext() const
{
    return next;
}

void ListNode::setdata(Entry x)
{
    entry = x;
}

void ListNode::setnext(ListNode *n)
{
    next = n;
}
