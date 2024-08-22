#!/bin/bash
echo $0
echo "-------"
echo $1 $2 $3
echo "-------"
echo $#
echo "------"
echo $*
echo
echo "shift"
shift 2
echo $0
echo "-------"
echo $1 $2 $3
echo "-------"
echo $*
