#! /bin/bash

set -o errexit

git pull origin master
git submodule update --init --remote --merge
git submodule foreach --recursive git submodule update --init --remote --merge
