
# para1="./"
# para2="-name '*.c'"
# cmd="find $para1 $para2"
# echo $cmd
# nameList=`$cmd`
# echo $nameList

set -x
para1="./"
para2="-name '*.c'"

cmd="find $para1 $para2"
echo $cmd
echo "----------------------"
nameList=$(${cmd})
nameList=$(eval ${cmd})
echo "----------------------"

echo $nameList


