#!/bin/sh

echo ""
echo "Prologue Args:"
echo "Job ID: $1"
echo "User ID: $2"
echo "Group ID: $3"
echo ""

env | sort
hostname
date

exit 0
