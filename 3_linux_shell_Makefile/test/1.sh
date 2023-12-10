

para1="/mnt/hgfs/filesharing"
para2="-name '*.c' -o -name '*.cpp' -o -name '*.h' -o -name '*.hpp' -o -name '*.md'"
cmd="find $para1 $para2"
echo $cmd
nameList=$(eval $cmd)

sum=0
for i in $nameList
do
    a=$(wc -l $i|awk '{print$1}')
    sum=$((sum+a))
#  echo $i
done
echo $sum



