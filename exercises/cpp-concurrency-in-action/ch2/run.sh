set -x
i=$1
if [[ ! -z $i  ]] ; then
    sudo rm -rf ./$i.out
    sudo bash ./build.sh $i    
    ./$i.out
else
    for i in p13 p16 p18; do
        echo "--------------------------"
        echo "Building and running $i..."
        echo "--------------------------"
        sudo bash ./build.sh $i &&  ./$i.out
    done
fi
