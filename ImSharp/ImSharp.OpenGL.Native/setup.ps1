if (-not(Test-Path -Path build)) {
  mkdir build
}

cd build

cmake ..

cmake --build . --config Release

cmake --install . --prefix ../install

cd ..
