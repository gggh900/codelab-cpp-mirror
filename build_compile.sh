set -x
pushd exercises/sams-teach-urself-cpp/L9 
mkdir out
ret=0
for i in ./*.cpp ; do
    echo '--------- building and running $i ... ---------'
    g++ $i -o out/$i.out && ./out/$i.out
    [[ $? -ne 0 ]] && ret=1
done
popd
exit $ret
