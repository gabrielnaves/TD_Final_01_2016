cd build

echo '### Running cmake'
cmake ..
if [ $? -ne 0 ]; then
    echo '## Error while running cmake'
    exit 1
fi

echo '### Running make'
make
if [ $? -ne 0 ]; then
    echo '## Error while running make'
    exit 1
fi

exit 0
