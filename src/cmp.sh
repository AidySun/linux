#!/bin/bash

echo  "$@" "$#"


if [[ -z $2 && -z $3 ]]; then
  echo "two parameters required."
  exit 0
fi


if [ $v3 -gt $v2 ]; then
  echo "v3 > v2"
else
  echo "v3 <= v2"
fi

