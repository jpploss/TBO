import os

programs = ["make bubbleSort", "make insertionSort", "make selectionSort", "make shakerSort"]
inputs_dir = os.listdir("./in")

for p in programs:
    os.system(p)

    for d in inputs_dir:
        print(f"----- Rodando {d.upper()} para {p.upper()} -----")

        for in_file in os.listdir(f"./in/{d}"):
            os.system(f"make run ARQ=./in/{d}/{in_file}")

# print(os.listdir("./in/sorted"))