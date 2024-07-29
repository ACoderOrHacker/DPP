# DPP Builder
# Copyright see LICENSE

import os
import sys

import clean

AUTO: int = 0
NOT_AUTO: int = 1
MSBUILD: int = 2
build_type: int = AUTO
is_debug: bool = True
vcpkg_root: str = "D://vcpkg"


def mkdir(parent: str, folder: str):
	old_parent: str = os.getcwd()

	try:
		os.chdir(parent)
		os.mkdir(folder)
	except FileExistsError:
		# The folder exists
		pass

	os.chdir(old_parent)


def bad_build():
	print("Cannot build DPP project")
	exit(1)


def get_makefile_type():
	if build_type != AUTO and build_type != MSBUILD:
		makefile_type: str = input("Please input the Makefile type: ")
		return makefile_type
	elif build_type == AUTO:
		return "NMake Makefiles"
	elif build_type == MSBUILD:
		return "Visual Studio 17 2022"


def get_makefile_generator():
	if build_type != AUTO and build_type != MSBUILD:
		gen: str = input("Please input the generator: ")
		return gen
	elif build_type == AUTO:
		return "nmake"
	elif build_type == MSBUILD:
		return "msbuild DPP.sln"


def build():
	"""

	:rtype: None
	"""

	path: str = "../"
	build_dir: str = "build/"
	cmake: str = "cmake ../ -G\"{}\" ".format(get_makefile_type())
	cmake_build_args: str = ""

	cmake_build_args += "-DCMAKE_TOOLCHAIN_FILE={}//scripts//buildsystems//vcpkg.cmake ".format(vcpkg_root)

	for arg in sys.argv:
		if arg.startswith("-D"):
			cmake_build_args += arg + " "

	if not is_debug:
		print("Mode: Release\n")
		cmake_build_args += "-DCMAKE_BUILD_TYPE=Release"
	else:
		print("Mode: Debug\n")
		cmake_build_args += "-DCMAKE_BUILD_TYPE=Debug"
	# print(cmake_build_args)

	mkdir(path, build_dir)
	os.chdir(path + build_dir)
	cmake_ret: int = os.system(cmake + cmake_build_args)

	if cmake_ret != 0:
		bad_build()
	else:
		gen_ret: int = os.system(get_makefile_generator())
		if gen_ret != 0:
			bad_build()

		print("Done.")

	os.chdir(path)


def main():
	global build_type, is_debug

	clean.clean()

	if "--release" in sys.argv:
		is_debug = False

	if "--msvc" in sys.argv:
		# Auto build
		build_type = AUTO
		build()
	elif len(sys.argv) == 1 or "-h" in sys.argv or "--help" in sys.argv:
		print("Usage:"
			  "\n"
			  "   build [options]"
			  "\n"
			  "Options:"
			  "\n"
			  "   --help, -h             = Get the help of usage\n"
			  "   --msvc                 = Compile by MSVC\n"
			  "   --msbuild              = Compile by MSBuild\n"
			  "   --other-compiler       = Compile by other C/C++ compiler\n"
			  "   --no-clean             = Do not clean all the files\n"
			  "   --release              = Build a release package\n"
			  "   --debug                = Build a debug package\n"
			  "\n"
			  "You can get all the supported makefile types and corresponding make tools from the cmake.org or use cmake --help")

	# os.system("cmake --help")
	elif "--msbuild" in sys.argv:
		build_type = MSBUILD
		build()

	elif "--other-compiler" in sys.argv:
		build_type = NOT_AUTO
		build()

	if "--no-clean" in sys.argv:
		return

	clean.clean()

	exit(0)


if __name__ == "__main__":
	main()
