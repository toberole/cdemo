#! /bin/sh

module_name="$1"

cp template.txt template.h

sed 's/{placeholder}/'${module_name}'/gpw '${module_name}'.h' template.h