#!/bin/bash


bash_file_name=`basename $0`
#echo bash_file_name=$bash_file_name
bash_folder="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
#echo $bash_folder
bash_file="$bash_folder/$bash_file_name"
#echo bash_file=$bash_file

temp_file="$bash_folder/temp215911"
temp_result="$bash_folder/temp215912"

ecm_config="/ECMConnector/config/"
pem_file="$bash_folder/$ecm_config/cacerts.pem"
java_pem="$bash_folder/$ecm_config/java_cacerts.pem"

java_keystore=$(/usr/libexec/java_home)/lib/security/cacerts
xxxx_keystore="$bash_folder/$ecm_config/xxxx_cacerts"

alias_prefix=xxxx_


function Help 
{
    echo
    echo $bash_file_name usage:
    echo
    echo "   -delete <alias>"
    echo "   -import <file>"
    echo "   -list "
}

# remove the existing files if the xCertMgr.sh is newer than them.
# for the case of reinstallation of XXXX.
#if [ -e "$bash_file" -a -e "$xxxx_keystore" -a \
#    "$bash_file" -nt "$xxxx_keystore" ]; then
#    rm -f "$xxxx_keystore" &> /dev/null
#    rm -f "$pem_file" &> /dev/null
#fi


if [[ -z $1 ]] ; then
    Help
    exit 0
fi

keytool_file=$(/usr/libexec/java_home)/bin/keytool
store_pass=changeit

if [ ! -e  "$keytool_file" ]; then
    echo file \"$keytool_file\" doesn\'t exist.
    exit 1
fi


# usage:
#   ExportKeystoreToPEM <keystore> <pem> 
function ExportKeystoreToPEM
{
    keystore="$1"
    pem="$2"

    if [ -e "$pem" ]; then
        rm -f "$pem" &> /dev/null
    fi
    touch "$pem"

    #echo temt_file= $temp_file
    "$keytool_file"  -list -v -keystore "$keystore"  \
        -storepass $store_pass | grep "Alias name" \
        | cut -d':' -f2 > "$temp_file" 2>/dev/null

    cat "$temp_file" | while read alias;do \
    "$keytool_file"  -exportcert -rfc -keystore \
        "$keystore"  -storepass $store_pass \
        -alias "$alias" >> "$pem" 2>/dev/null
        done

    #echo pem=$pem
    rm -f "$temp_file" &> /dev/null
}

function DoExportForEcm
{
    ExportKeystoreToPEM "$xxxx_keystore" "$pem_file" 
    cat "$java_pem" >> "$pem_file"
}


function DoImport
{
    original_name=$(basename "$1")
    file_name=`echo "$original_name" | tr , .`
    cert_alias=$alias_prefix$file_name

    "$keytool_file" -storepass $store_pass \
    -keystore "$java_keystore" -delete -alias "$cert_alias" &>/dev/null

    "$keytool_file" -storepass $store_pass -keystore "$java_keystore" \
    -importcert -noprompt -trustcacerts -file "$1" -alias "$cert_alias" \
    2>/dev/null 1>"$temp_result"

    if [ 0 -eq $? ]; then
    "$keytool_file" -storepass $store_pass -keystore "$xxxx_keystore" \
        -delete -alias "$cert_alias" &> /dev/null

    "$keytool_file" -storepass $store_pass -keystore "$xxxx_keystore" \
        -importcert -noprompt -trustcacerts -file "$1" \
        -alias "$cert_alias" &> /dev/null

    DoExportForEcm
    else
        cat "$temp_result" 2> /dev/null
    fi

    rm -f "$temp_result" &> /dev/null
}

function DoDelete
{
    "$keytool_file" -storepass $store_pass \
    -keystore "$java_keystore" -delete -alias "$1" 2>/dev/null

    if [ 0 -eq $? ]; then
    "$keytool_file" -storepass $store_pass \
        -keystore "$xxxx_keystore" \
        -delete -alias "$1" &> /dev/null
    DoExportForEcm 
    fi
}

function DoList
{
    printf "\n"

    if [ -e "$xxxx_keystore" ]; then

    "$keytool_file" -storepass $store_pass \
        -keystore "$xxxx_keystore" -list \
        | grep $alias_prefix > "$temp_file"
               
    cat "$temp_file" | grep "$cert_prefix" \
        | awk -F ',' '{printf " %s\n",  $1}'

    rm -f "$temp_file" &> /dev/null
    else
    rm -f "$pem_file" &> /dev/null
    fi
}

function DoExportJavaCerts
{
    ExportKeystoreToPEM "$java_keystore" "$java_pem"
}

import_option="-import"
delete_option="-delete"
list_option="-list"
export_option="-exportforecm"
export_java_certs="-exportjavacerts"

if [ $list_option = $1 ]; then
    DoList
elif [ $import_option = $1 ] && [[ -n $2 ]]; then
    DoImport "$2"
elif [ $delete_option = $1 ] && [[ -n $2 ]]; then
    DoDelete "$2"
elif [ $export_option = $1 ]; then
    DoExportForEcm 
elif [ $export_java_certs = $1 ]; then
    DoExportJavaCerts
else
    Help
    exit 0
fi






