#!/bin/bash

set -o errexit

WORK_PATH=$(cd $(dirname $0); pwd)

if [ -z $PROJECT_NAME ]; then
  PROJECT_NAME=demo
fi
if [ -z $PROGRAM_NAME ]; then
  PROGRAM_NAME=$PROJECT_NAME
fi

$WORK_PATH/build.sh
PROJECT_NAME=$PROJECT_NAME PROGRAM_NAME=$PROGRAM_NAME $WORK_PATH/run.sh
