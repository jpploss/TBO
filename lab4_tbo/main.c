#include <stdlib.h>
#include <stdio.h>
#include "canvas.h"
#include "colsys.h"

#define MAX_SIM_TIME 10000
#define GUI 0                // Modifique para 0 se não quiser a janela.

int main(int argc, char* argv[]) {
    int N = 0;
    if(argc <= 1) scanf("%d", &N);
    else N = atoi(argv[1]);

    system_init(N, MAX_SIM_TIME, GUI);

    if (argc == 3) {
        load_particles(argv[2]);
    } else {
        create_random_particles();
    }
    prepare();

    if (GUI) {
        canvas_init(); // Já chama simulate().
    } else {
        simulate();
    }

    system_finish();
}