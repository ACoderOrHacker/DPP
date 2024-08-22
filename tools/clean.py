# The script for clean
# Copyright see LICENSE

import shutil

def delete_dir(path: str) -> None:
	"""

	:param path:
	:rtype: None
	"""
	try:
		shutil.rmtree(path)
	except FileNotFoundError:
		# Not found the folders
		pass

def clean() -> None:
	"""

	:rtype: None
	"""
	# delete the folders

	delete_dir("../__build__/")
	delete_dir("../cmake-build-debug/")
	delete_dir("../out/")
	delete_dir("../bin/")
	delete_dir("../build/")

def main() -> None:
	"""

	:rtype: None
	"""
	clean()


if __name__ == "__main__":
	main()

	print("Done.")
