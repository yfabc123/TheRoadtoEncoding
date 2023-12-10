a=`ipcs -s  |grep "777"| awk '{print$2}'`
if [ -n "$a" ] 
then
for i in $a
do
ipcrm -s $i
done
fi


