#!/bin/bash
# ./du.sh

if (( $# == 0 ))
then
	sudo du -sh /home/*
else

	for user in $#
