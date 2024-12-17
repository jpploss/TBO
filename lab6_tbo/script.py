import os
import subprocess

inputs_dir = os.listdir("./input")

resultados = open("resultados.txt", "w")
for versao in range(1, 8):
    resultados.write(f"__________Desempenho do merge na versão {versao}__________\n")
    os.system(f"make v{versao}")

    for i in inputs_dir:
        resultados.write(f"\n_____{i}:\n")
        inputs = os.listdir(f"./input/{i}")
        for f in inputs:
            if ".txt" in f:
                N, _ = f.split(".")
                if '_' in N:
                    N = 10000000
                processo = subprocess.run(["./prog", N, f"./input/{i}/{f}"], capture_output=True, text=True)
                resultados.write(processo.stdout)
    resultados.write("\n\n")
                
resultados.close()