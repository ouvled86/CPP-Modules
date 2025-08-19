import os
import json

workspace = os.path.dirname(os.path.abspath(__file__))
tasks_json_path = os.path.join(workspace, ".vscode", "tasks.json")
makefile_folders = []



for root, dirs, files in os.walk(workspace):
    if "Makefile" in files:
        abs_path = os.path.abspath(root)
        if abs_path != os.path.join(workspace, ".vscode"):
            makefile_folders.append(abs_path)

makefile_folders.sort()

tasks = {
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build C++ Project",
            "type": "shell",
            "command": "make",
            "options": {
                "cwd": "${input:makefileFolder}"
            },
            "group": "build",
            "problemMatcher": ["$gcc"]
        }
    ],
    "inputs": [
        {
            "id": "makefileFolder",
            "type": "pickString",
            "description": "Select the folder containing the Makefile",
            "options": makefile_folders
        }
    ]
}

os.makedirs(os.path.dirname(tasks_json_path), exist_ok=True)
with open(tasks_json_path, "w") as f:
    json.dump(tasks, f, indent=4)

print("tasks.json updated with Makefile folders!")
