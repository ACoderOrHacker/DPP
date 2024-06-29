# The script for clean
# Copyright see LICENSE

import shutil


def clean() -> None:
	"""

	:rtype: object
	"""
	# delete the folders

	try:
		shutil.rmtree("../build/")
		shutil.rmtree("../out/")
		shutil.rmtree("../bin/")
	except FileNotFoundError:
		# Not found the folders
		pass


def main() -> None:
	"""

	:rtype: None
	"""
	clean()


if __name__ == "__main__":
	main()

	print("Done.")
