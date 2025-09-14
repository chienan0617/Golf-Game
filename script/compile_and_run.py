import os
import subprocess
import glob

# Project settings
SRC_DIR = "src"
OUT_EXE = "build/main.exe"
INCLUDE_DIR = "D:/Jimmy/sdl3/x86_64-w64-mingw32/include"
LIB_DIR = "D:/Jimmy/sdl3/x86_64-w64-mingw32/lib"

# Recursively find all .cpp files
sources = glob.glob(os.path.join(SRC_DIR, "**", "*.cpp"), recursive=True)

if not sources:
  print("❌ No .cpp files found in the source directory!")
  exit(1)

# Print the list of files being compiled
print("🔨 Compiling the following files:")
for src in sources:
  print(f"  - {src}")

# g++ compile command
cmd = [
  "g++",
  *sources,
  "-o", OUT_EXE,
  "-I", INCLUDE_DIR,
  "-L", LIB_DIR,
  "-lSDL3",
  "-std=c++17"
]

print("\n⚡ Running compile command:")
print(" ".join(cmd))

# Execute compilation
try:
  subprocess.check_call(cmd)
  print(f"\n✅ Compilation succeeded! Output: {OUT_EXE}")

  # Run the executable if compilation succeeded
  print("\n🏃 Running the program...")
  subprocess.run([OUT_EXE])

except subprocess.CalledProcessError as e:
  print(f"\n❌ Compilation failed with error code: {e.returncode}")
