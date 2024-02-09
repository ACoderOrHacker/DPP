if exist "build/" (
	rmdir /S /Q "build/"
)
mkdir "build"
cd build
cmake ../ -G"NMake Makefiles"
nmake
cd ..
@echo "Build Success"