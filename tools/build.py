# DPP Builder
# Copyright see LICENSE

import os
import sys

AUTO: int = 0
build_type: int = AUTO

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
    if build_type != AUTO:
        makefile_type: str = input("Please input the Makefile type: ")
        return makefile_type
    else:
        return "NMake Makefiles"

def get_makefile_generator():
    if build_type != AUTO:
        gen: str = input("Please input the generator: ")
        return gen
    else:
        return "nmake"

def build():
    path: str = "../"
    build_dir: str = "build/"
    cmake: str = "cmake ../ -G\"{}\" ".format(get_makefile_type())
    cmake_build_args: str = ""

    for arg in sys.argv:
        cmake_build_args.join("-D" + arg)

    mkdir(path, build_dir)
    os.chdir(path + build_dir)
    cmake_ret: int = os.system(cmake)

    if cmake_ret != 0:
        bad_build()
    else:
        gen_ret: int = os.system(get_makefile_generator())
        if gen_ret != 0:
            bad_build()

        print("Done.")
        exit(0)


def main():
    global build_type

    if len(sys.argv) == 0:
        # Auto build
        build_type = AUTO

    elif "-h" in sys.argv or "--help" in sys.argv:
        os.system("cmake --help")
    else:
        build()

if __name__ == "__main__":
    main()
