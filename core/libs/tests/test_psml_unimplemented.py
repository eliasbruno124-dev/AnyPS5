import os
from pathlib import Path
import signal
import subprocess
import sys


FUNCTIONS = (
    "scePsmlMfsrInit",
    "scePsmlMfsrGetDispatchMfsrPacket1000",
    "scePsmlMfsrGetDispatchMfsrPacketSizeInDwords",
    "scePsmlMfsrReleaseContext",
    "scePsmlUnknown__P2KpvixvL6E",
    "scePsmlUnknown_ArakEpzsZo0",
    "scePsmlUnknown_FSGaTQze0UY",
    "scePsmlUnknown_GHna9_MDvnUk",
    "scePsmlUnknown_GJY0MvuTcs8",
    "scePsmlUnknown_LXq_P6mIxpCw",
    "scePsmlUnknown_RUNLFro_Pqok",
    "scePsmlUnknown_eWoKNeB6V_Mk",
    "scePsmlUnknown_gxv3i_PMTEzU",
    "scePsmlUnknown_jEevBXmagOQ",
)


def main():
    executable = Path(sys.argv[1]).resolve(strict=True)
    expected_exit = 0xC0000409 if os.name == "nt" else -signal.SIGABRT
    if os.name == "nt":
        import ctypes
        ctypes.windll.kernel32.SetErrorMode(0x0001 | 0x0002)
    for name in FUNCTIONS:
        child = subprocess.run([str(executable), name], capture_output=True, timeout=30)
        text = (child.stdout + child.stderr).decode("utf-8", errors="replace")
        if child.returncode != expected_exit or name + " not implemented" not in text:
            raise AssertionError(f"{name}: expected explicit unimplemented abort {expected_exit}, got {child.returncode}:\n{text}")
        print(f"PASS {name}: explicit unimplemented abort {child.returncode}")


if __name__ == "__main__":
    main()
