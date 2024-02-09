if exist "build/" (
	rmdir /S /Q "build/"
)
mkdir "build"
cd build
cmake ../
cd ..
@echo "Build Success"