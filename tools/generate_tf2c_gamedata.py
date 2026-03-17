import mmap

BIN = "tf/bin/server_srv.so"
OUT = "addons/sourcemod/gamedata/tf2c.gamedata.txt"

PATTERNS = {
    "GiveNamedItem": b"\x55\x48\x89\xe5\x41\x57\x41\x56",
    "EquipWearable": b"\x48\x89\x5c\x24",
    "SetAttribute": b"\x48\x83\xec"
}

def wildcard(sig):
    return " ".join(f"{b:02x}" if i < 6 else "?" for i, b in enumerate(sig))

with open(BIN, "rb") as f:
    data = f.read()

results = {}

for name, pat in PATTERNS.items():
    idx = data.find(pat)
    if idx == -1:
        print(f"[!] {name} not found")
        continue

    sig = data[idx:idx+20]
    results[name] = wildcard(sig)

with open(OUT, "w") as f:
    f.write('"Games"\n{\n  "tf2c"\n  {\n    "Signatures"\n    {\n')

    for k, v in results.items():
        f.write(f'      "{k}"\n      {{\n')
        f.write('        "library" "server"\n')
        f.write(f'        "linux" "{v}"\n')
        f.write('      }\n')

    f.write('    }\n  }\n}\n')

print("[✓] Generated tf2c gamedata")
