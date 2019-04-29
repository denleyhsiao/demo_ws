#!/bin/bash

set -o errexit

WORK_PATH=$(cd $(dirname $0); pwd)
BUILD_PATH=$WORK_PATH/../build

mkdir -p $BUILD_PATH
cd $BUILD_PATH && cmake .. && make && cd $WORK_PATH
