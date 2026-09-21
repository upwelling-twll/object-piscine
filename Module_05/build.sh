cmake -S . -B build \
    -DCMAKE_BUILD_TYPE=Debug

cmake --build build

./build/TimerUl test/rail2 test/train2