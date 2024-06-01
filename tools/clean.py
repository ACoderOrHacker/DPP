# The script for clean
# Copyright see LICENSE

import shutil


def main():
    # delete the folders

    try:
        shutil.rmtree("../build/")
        shutil.rmtree("../out/")
    except FileNotFoundError:
        # Not found the folders
        pass


if __name__ == "__main__":
    main()

    print("Done.")
