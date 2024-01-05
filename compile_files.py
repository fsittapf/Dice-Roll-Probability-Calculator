import os
import sys
import subprocess


def compile_files(directory):
    for dirpath, dirnames, filenames in os.walk(directory):
        for file in filenames:
            if file.endswith(".c"):
                output_file = os.path.join(dirpath, "c_" + file[:-2])
                subprocess.run(
                    ["gcc", "-O3", os.path.join(dirpath, file), "-o", output_file]
                )
            elif file.endswith(".cpp"):
                output_file = os.path.join(dirpath, "cpp_" + file[:-4])
                subprocess.run(
                    [
                        "g++",
                        "-std=c++17",
                        "-O3",
                        os.path.join(dirpath, file),
                        "-o",
                        output_file,
                    ]
                )


if __name__ == "__main__":
    if len(sys.argv) > 1:
        directory = sys.argv[1]
        compile_files(directory)
    else:
        print("Please provide a directory path")
