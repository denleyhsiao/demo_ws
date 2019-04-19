#!/bin/bash

set -o errexit

WORK_PATH=$(cd $(dirname $0); pwd)
BUILD_PATH=$WORK_PATH/../build

if [ -z $PROJECT_NAME ]; then
  PROJECT_NAME=demo
fi
if [ -z $PROGRAM_NAME ]; then
  PROGRAM_NAME=$PROJECT_NAME
fi

$BUILD_PATH/$PROJECT_NAME/$PROGRAM_NAME
