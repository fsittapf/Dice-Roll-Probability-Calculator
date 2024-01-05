import os
import sys


def safe_delete_exe_files(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".exe"):
                file_path = os.path.join(root, file)
                os.remove(file_path)


if __name__ == "__main__":
    if len(sys.argv) > 1:
        directory = sys.argv[1]
        safe_delete_exe_files(directory)
    else:
        print("Please provide a directory path")
