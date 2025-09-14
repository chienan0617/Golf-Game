import subprocess
from pathlib import Path
import platform

script_dir = Path(__file__).parent
android_dir = script_dir.parent / "android"

gradlew_cmd = "gradlew.bat" if platform.system() == "Windows" else "./gradlew"
gradlew_path = android_dir / gradlew_cmd

# Popen 即時讀取 stdout
process = subprocess.Popen(
    [str(gradlew_path), "build"],
    cwd=android_dir,
    stdout=subprocess.PIPE,
    stderr=subprocess.STDOUT,
    text=True,
    bufsize=1  # 行緩衝
)

# 即時打印
for line in process.stdout:
    print(line, end='')  # 已經有換行

process.wait()
if process.returncode == 0:
    print("✅ Build succeeded !")
else:
    print("❌ Build failed")
