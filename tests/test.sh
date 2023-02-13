#!/bin/bash

[ "$(bash -c 'ls -al')" == "$(../minishell -c 'ls -al')" ] && echo OK

