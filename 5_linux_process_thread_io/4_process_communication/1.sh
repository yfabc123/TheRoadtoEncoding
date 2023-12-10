a=`ipcs -m  |grep "666"| awk '{print$2}'`
if  [ -n "$a" ] && [ $a -ge 0 ]
then
ipcrm -m $a
fi

# a=$(ipcs -m | grep "666" | awk '{print $2}')
# if [ -n "$a" ] && [ "$a" -ge 0 ]; then
#   ipcrm -m $a
# fi


gcc  20d.c -o send
gcc  20e.c -o recv