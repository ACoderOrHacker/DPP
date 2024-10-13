# Package the generated files to a folder

import os
import sys
import shutil
from pathlib import Path

project_root: Path = Path(os.getcwd()).parent
project_name: str = "DPP"
pack_path: str = project_root / "pack" / project_name
installer_path: str = project_root / "pack" / "installer"


def gen_folder(name: str, is_delete: bool = False) -> None:
    if os.path.exists(name) and is_delete:
        shutil.rmtree(name)

    if not os.path.exists(name):
        os.mkdir(name)


def copy_file(file: str) -> None:
    print(f"Copy '{project_root / file}' to '{pack_path}'")
    shutil.copy(project_root / file, pack_path)


def copy_folder(folder: str) -> None:
    print(f"Copy '{project_root / folder}' to '{pack_path}'")
    shutil.copytree(project_root / folder, pack_path / folder)

def copy_bin_windows():
    bin_dir: Path = project_root / "bin"
    pack_bin_dir: Path = pack_path / "bin"
    os.makedirs(pack_bin_dir)
    files = [i for i in bin_dir.glob("**/*") if i.is_file()]
    for file in files:
        if file.suffix == ".exe" or file.suffix == ".dll" or file.suffix == ".lib":
            print(f"Copy '{file}' to '{pack_bin_dir}'")
            shutil.copy(file, pack_bin_dir)

def pack() -> None:
    if os.path.exists(pack_path):
        shutil.rmtree(project_root / "pack")
    os.makedirs(pack_path)
    os.makedirs(installer_path)
    os.chdir(pack_path)

    copy_file("LICENSE")
    copy_file("README.md")
    copy_folder("include")
    copy_folder("docs")
    copy_folder("examples")
    if sys.platform.startswith("win32"):
        copy_bin_windows()


if __name__ == "__main__":
    pack()
    print("Done")
