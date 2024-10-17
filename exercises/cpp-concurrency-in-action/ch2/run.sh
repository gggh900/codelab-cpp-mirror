for i in p13 p16; do
    echo "--------------------------"
    echo "Building and running $i..."
    echo "--------------------------"
    sudo bash ./build.sh $i    
    ./$i.out
done
