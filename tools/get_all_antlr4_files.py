# This file for vcpkg

import pathlib

path = pathlib.Path("../include/antlr4-runtime/")

files = [i for i in path.glob("**/*") if i.is_file()]


if __name__ == "__main__":
    for file in files:
        f = open(file, "w")
        f.write(f"#include <antlr4-runtime/{file.name}>")
        f.close()
