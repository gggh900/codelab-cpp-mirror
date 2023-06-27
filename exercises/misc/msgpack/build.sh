for i in *.cpp ; do
    echo "building $i...."
    if [[ $i == "lib.cpp" ]] ; then 
        continue
    fi
    g++ -I.. ../lib.cpp $i -o $i.out
done
