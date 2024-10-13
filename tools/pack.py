# Package the generated files to a folder

import os
import shutil
from pathlib import Path

project_root: Path = Path(os.getcwd()).parent
project_name: str = "DPP"
pack_path: str = project_root / "pack" / project_name


def gen_folder(name: str, is_delete: bool = False) -> None:
    if os.path.exists(name) and is_delete:
        shutil.rmtree(name)

    if not os.path.exists(name):
        os.mkdir(name)


def copy_file(file: str) -> None:
    shutil.copy(project_root / file, pack_path)


def copy_folder(folder: str) -> None:
    shutil.copytree(project_root / folder, pack_path)


def pack() -> None:
    if os.path.exists(pack_path):
        shutil.rmtree(project_root / "pack")
    os.makedirs(pack_path)
    os.chdir(pack_path)

    copy_file("LICENSE")
    copy_file("README.md")
    copy_folder("include")


if __name__ == "__main__":
    pack()
    print("Done")
