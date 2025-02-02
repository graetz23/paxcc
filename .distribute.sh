#!/bin/bash
#
# add, commit, and push to all origins ..
#
# Contact Christian (graetz23@gmail.com)
# Created 250202
# Changed 250202
#
SRCDIR=./paxcc
SRCDOC="This is the way: Mando says .."

git add main.cpp
git add $SRCDIR/*.cpp
git add $SRCDIR/*.h

git commit -m "$SRCDOC"

git push origin
git push ugreen
