sh build.sh
if [ $? -ne 0 ]; then
    echo '## Build error'
    exit 1
fi
echo
./build/gossip
