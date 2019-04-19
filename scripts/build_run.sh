#!/bin/bash

set -o errexit

WORK_PATH=$(cd $(dirname $0); pwd)
$WORK_PATH/build.sh
$WORK_PATH/run.sh