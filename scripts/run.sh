#!/bin/bash

set -o errexit

WORK_PATH=$(cd $(dirname $0); pwd)
BUILD_PATH=$WORK_PATH/../build

$BUILD_PATH/demo/demo